
all: swap clone modify

swap: swap.c
	clang "$^" -o "$@"

clone: clone.c
	clang "$^" -o "$@"

modify: modify.c
	clang "$^" -o "$@"

clean:
	rm -f clone
	rm -f swap
	rm -f modify

.PHONY: clean all
