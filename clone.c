#include <copyfile.h>
#include <stdio.h>

int main(int argc, char **argv) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s [from] [to]\n", argv[0]);
    return 1;
  }

  copyfile(argv[1], argv[2], NULL, COPYFILE_CLONE);
  return 0;
}
