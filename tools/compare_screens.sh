#!/bin/bash
# Render static htop screens with the original and the rebuilt binary in tmux and diff them.
# usage: compare_screens.sh ORIGINAL REBUILT
cd "$(dirname "$0")/.."
ORIG=$(realpath "$1"); NEW=$(realpath "$2")
TMP=$(mktemp -d)
# screen name -> keys (tmux send-keys syntax)
declare -A SCREENS=(
  [help]="h"
  [setup_meters]="F2"
  [setup_display]="F2 Down"
  [setup_colors]="F2 Down Down"
  [setup_columns]="F2 Down Down Down Down"
  [sortby]="F6"
  [signals]="k"
  [setup_colors_mono]="F2 Down Down Right Down Down Down Down Down Space"
  [procs]="P1"
  [procs_tree]="P1 t"
  [procs_io]="P1 Tab"
  [procs_sorted]="P1 M"
)
fail=0
for name in "${!SCREENS[@]}"; do
  for which in orig new; do
    bin=$ORIG; [ $which = new ] && bin=$NEW
    home=$TMP/home-$which-$name; mkdir -p "$home"
    s=htopcmp-$which-$$
    # "P1": show only PIDs 1 and 2 (stable) instead of filtering to user nobody
    args="-u nobody"; keys=${SCREENS[$name]}
    if [[ $keys == P1* ]]; then args="-p 1,2"; keys=${keys#P1}; fi
    tmux new-session -d -s $s -x 140 -y 45 "env HOME=$home TERM=xterm-256color $bin -d 100 $args; echo exit \$? > $TMP/$name.$which.exit; sleep 2"
    sleep 1.5
    for k in $keys; do tmux send-keys -t $s $k; sleep 0.4; done
    sleep 1
    # CPU rows (bars in stock htop, history heatmap in the rebuilt one) differ by design
    tmux capture-pane -p -t $s | grep -vE '^ +[0-9]+ *[[▁▂▃▄▅▆▇█.:=+*#@-]|^[ 0-9]+$' > "$TMP/$name.$which"
    [ -f $TMP/$name.$which.exit ] && echo "$which $name: htop ended early ($(cat $TMP/$name.$which.exit))"
    tmux kill-session -t $s
  done
  if diff -q "$TMP/$name.orig" "$TMP/$name.new" > /dev/null; then
    echo "same     $name"
  else
    echo "DIFFERS  $name"; diff "$TMP/$name.orig" "$TMP/$name.new" | head -${DIFFLINES:-10}; fail=1
  fi
done
rm -rf "$TMP"
exit $fail
