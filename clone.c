#include <copyfile.h>
#include <stdio.h>

/*
 * Copy, but use COW on APFS
 */

int main(int argc, char **argv) {
  int err;

  if (argc < 3) {
    fprintf(stderr, "Usage: %s [from] [to]\n", argv[0]);
    return 1;
  }

  err = copyfile(argv[1], argv[2], NULL, COPYFILE_CLONE);
  if (err) {
    perror(argv[0]);
    return 1;
  }
  return 0;
}
