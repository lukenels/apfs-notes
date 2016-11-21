#include <stdio.h>

int main(int argc, char **argv) {
  FILE *f;
  size_t w;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s [file]\n", argv[0]);
    return 1;
  }

  f = fopen(argv[1], "r+");
  if (!f) {
    perror(argv[0]);
    return 1;
  }

  rewind(f);
  w = fwrite("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 1, 26, f);
  fclose(f);

  return 0;
}
