CC      ?= gcc
CFLAGS  ?= -O1 -g
CFLAGS  += -std=gnu17 -Iinclude -fno-strict-aliasing -fwrapv -fno-delete-null-pointer-checks \
           -fno-builtin -w -fcommon
LDLIBS  = -lncursesw -ltinfo -lm -l:libnl-3.so.200 -l:libnl-genl-3.so.200 -ldl

SRCS = $(shell find src -name '*.c')
OBJS = $(SRCS:src/%.c=build/%.o) build/data.o

htop: $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDLIBS) -rdynamic

build/%.o: src/%.c include/*.h | build
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

build/data.o: src/data.S | build
	$(CC) -c -o $@ $<

build:
	mkdir -p build

clean:
	rm -rf build htop

.PHONY: clean
