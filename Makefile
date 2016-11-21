clone: clone.c
	clang "$^" -o "$@"

clean:
	rm -f clone

.PHONY: clean
