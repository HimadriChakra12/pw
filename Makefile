CC      ?= clang
PKGS    := wayland-client cairo xkbcommon
CFLAGS  += -O2 -Wall -Wextra -std=c11 $(shell pkg-config --cflags $(PKGS))
LDLIBS  += $(shell pkg-config --libs $(PKGS)) -lrt

PREFIX  ?= /usr/local
BINDIR  := $(PREFIX)/bin

all: pw

pw: main.c
	$(CC) $(CFLAGS) -o $@ main.c $(LDLIBS)

install: pw
	install -Dm755 pw $(DESTDIR)$(BINDIR)/pw

uninstall:
	rm -f $(DESTDIR)$(BINDIR)/pw

clean:
	rm -f pw

.PHONY: all install uninstall clean
