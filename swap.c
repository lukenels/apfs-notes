#include <stdio.h>

int main(int argc, char **argv) {
  int err;

  if (argc < 3) {
    fprintf(stderr, "Usage: %s [A] [B]\n", argv[0]);
    return 1;
  }

  err = renamex_np(argv[1], argv[2], RENAME_SWAP);
  if (err < 0) {
    perror(argv[0]);
    return 1;
  }
  return 0;
}
