#!/usr/bin/env python3
"""Drive htop in a pseudo-terminal with key sequences and report whether it survives each one.

usage: smoke_test.py BINARY [SCENARIO ...]
HOME is pointed at a throw-away directory so the user's htoprc is never touched.
"""
import os
import pty
import select
import signal
import struct
import sys
import tempfile
import termios
import time
import fcntl

ESC = "\x1b"
UP, DOWN, LEFT, RIGHT = "\x1b[A", "\x1b[B", "\x1b[D", "\x1b[C"
F = {1: "\x1bOP", 2: "\x1bOQ", 3: "\x1bOR", 4: "\x1bOS", 5: "\x1b[15~", 6: "\x1b[17~", 7: "\x1b[18~",
     8: "\x1b[19~", 9: "\x1b[20~", 10: "\x1b[21~"}

# each step: (keys, seconds to wait afterwards)
SCENARIOS = {
    "idle": [("", 3)],
    "help": [("h", 1), (" ", 1), (F[1], 1), (ESC, 1)],
    "tree": [("t", 1.5), (DOWN * 5, 0.5), ("-", 0.5), ("+", 0.5), ("*", 0.5), ("t", 1), (F[5], 1), (F[5], 1)],
    "sort": [("M", 1), ("P", 1), ("T", 1), ("N", 1), ("I", 1), (F[6], 1), (DOWN * 3, 0.3), ("\r", 1), (">", 1), (ESC, 1)],
    "search": [("/", 0.5), ("sh", 1), (F[3], 0.5), ("\r", 1), ("\\", 0.5), ("bash", 1.5), ("\r", 1), ("\\", 0.5), (ESC, 1)],
    "setup": [(F[2], 1.5), (DOWN, 0.5), (RIGHT, 0.5), (DOWN * 3, 0.5), (" ", 0.5), (" ", 0.5), (LEFT, 0.3),
              (DOWN, 0.5), (RIGHT, 0.5), (DOWN * 4, 0.5), (LEFT, 0.3), (DOWN, 0.5), (RIGHT, 0.5), (DOWN * 2, 0.5),
              (LEFT, 0.3), (DOWN, 0.5), (RIGHT, 0.5), (LEFT, 0.3), (ESC, 1.5)],
    "screens": [("\t", 1.5), ("\t", 1.5), ("H", 1), ("K", 1), ("p", 1), ("H", 1), ("K", 1)],
    "env": [("e", 1.5), (DOWN * 3, 0.3), (ESC, 1)],
    "lsof": [("l", 2), (DOWN * 3, 0.3), (ESC, 1)],
    "locks": [("x", 1.5), (ESC, 1)],
    "strace": [("s", 1.5), (ESC, 1)],
    "panels": [("u", 1), (DOWN * 2, 0.3), (ESC, 1), ("a", 1), (ESC, 1), ("k", 1), (DOWN, 0.3), (ESC, 1),
               ("i", 1), (ESC, 1), ("]", 0.5), ("[", 0.5), ("F", 1), (" ", 0.5), ("c", 0.5), ("U", 0.5),
               ("Z", 1), ("Z", 1), ("m", 0.5), ("#", 1), ("#", 1)],
    "resize": [("", 1), ("RESIZE", 1.5), ("", 1)],
}


def run(binary, steps, cols=160, rows=48):
    home = tempfile.mkdtemp(prefix="htop-home-")
    pid, fd = pty.fork()
    if pid == 0:
        os.environ.update(HOME=home, TERM="xterm-256color", LANG="C.UTF-8", LC_ALL="C.UTF-8")
        if os.environ.get("SMOKE_GDB"):
            log = os.environ["SMOKE_GDB"]
            os.execvp("gdb", ["gdb", "-q", "-batch", "-ex", f"set logging file {log}", "-ex", "set logging redirect off",
                              "-ex", "set logging enabled on", "-ex", "run", "-ex", "bt 30", "-ex", "info registers rip",
                              "--args", binary, "-d", "5"])
        os.execv(binary, [binary, "-d", "5"])
    fcntl.ioctl(fd, termios.TIOCSWINSZ, struct.pack("HHHH", rows, cols, 0, 0))
    out = bytearray()

    def pump(t):
        end = time.time() + t
        while time.time() < end:
            r, _, _ = select.select([fd], [], [], 0.05)
            if r:
                try:
                    out.extend(os.read(fd, 65536))
                except OSError:
                    return False
            if os.waitpid(pid, os.WNOHANG)[0]:
                return False
        return True

    alive = pump(2)
    for keys, wait in steps:
        if not alive:
            break
        if keys == "RESIZE":
            fcntl.ioctl(fd, termios.TIOCSWINSZ, struct.pack("HHHH", 30, 90, 0, 0))
            os.kill(pid, signal.SIGWINCH)
        elif keys:
            os.write(fd, keys.encode())
        alive = pump(wait)
    if alive:
        os.write(fd, b"q")
        alive = pump(3)
    try:
        wpid, status = os.waitpid(pid, os.WNOHANG)
        if wpid == 0:
            os.kill(pid, signal.SIGKILL)
            os.waitpid(pid, 0)
            return "hung", out
    except ChildProcessError:
        return "?", out
    if os.WIFSIGNALED(status):
        return f"killed by signal {os.WTERMSIG(status)}", out
    return f"exit {os.WEXITSTATUS(status)}", out


def main():
    binary = os.path.abspath(sys.argv[1])
    names = sys.argv[2:] or list(SCENARIOS)
    failed = 0
    for name in names:
        result, out = run(binary, SCENARIOS[name])
        ok = result == "exit 0"
        failed += not ok
        print(f"{name:10s} {result:24s} {len(out):7d} bytes of output")
        if not ok:
            with open(os.path.join(tempfile.gettempdir(), f"htop-smoke-{name}.out"), "wb") as f:
                f.write(out)
    sys.exit(1 if failed else 0)


if __name__ == "__main__":
    main()
