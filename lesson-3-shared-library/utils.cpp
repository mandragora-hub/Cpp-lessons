
#include "utils.h"

/* print a description of all supported options */
void Utils::printUsage(FILE *fp, const char *path) {
  /* take only the last portion of the path */
  const char *basename = strrchr(path, '/');
  basename = basename ? basename + 1 : path;

  fprintf(fp, "usage: %s [OPTION]\n", basename);
  fprintf(fp,
          "  -h, --help\t\t"
          "Print this help and exit.\n");
  fprintf(fp,
          "  -f [=filename]\t\t"
          "Input file path.\n");
  fprintf(fp,
          "  -o [=filename]\t\t"
          "Output file path.\n");
  fprintf(fp,
          "  -k --key [=number] [DEFAULT = 1]\t\t"
          "Key used for the algorithm.\n");
  fprintf(fp, "operation available: \n");
  fprintf(fp, "  -d, --decrypt\n");
  fprintf(fp, "  -e, --encrypt  [DEFAULT]\n");
}
