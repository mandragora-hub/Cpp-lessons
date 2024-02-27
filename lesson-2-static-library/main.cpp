#include <getopt.h>
#include <string.h>

#include <iostream>

#include "math.h"
#include "program_options.h"
#include "utils.h"

using namespace rgm;

int main(int argc, char *argv[]) {
  ProgramOptions options(argc, argv);

  switch (options.getOperationFlag()) {
    case ADD:
      printf("Result: %d\n", Math::addition(options.getX(), options.getY()));
      break;
    case SUBTRACT:
      printf("Result: %d\n", Math::subtract(options.getX(), options.getY()));
      break;
    case MULTIPLY:
      printf("Result: %d\n", Math::multiply(options.getX(), options.getY()));
      break;
    case DIVIDE:
      printf("Result: %d\n", Math::divide(options.getX(), options.getY()));
      break;

    default:
      Utils::printUsage(stderr, argv[0]);
      exit(1);
      break;
  }

  return 0;
}
