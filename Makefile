all: build
build:
	meson compile -C builddir/
run: build
	builddir/pong
setup:
	meson setup builddir/