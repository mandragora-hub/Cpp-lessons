
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
          "  -x [=number]\t\t"
          "First number.\n");
  fprintf(fp,
          "  -y [=number]\t\t"
          "Second number.\n");
  fprintf(fp, "Math operation available: \n");
  fprintf(fp, "  -a, --addition\n");
  fprintf(fp, "  -s, --subtract\n");
  fprintf(fp, "  -m, --multiply\n");
  fprintf(fp, "  -d, --divide\n");
}
