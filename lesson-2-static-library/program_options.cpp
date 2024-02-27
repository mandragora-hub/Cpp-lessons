#include "program_options.h"

#include <getopt.h>
#include <string.h>

#include <iostream>

#include "utils.h"

using namespace rgm;

int stringToLong(char *str) {
  char *output;
  int number = strtol(str, &output, 10);
  if (*output) {
    printf("Error occurred on parse char to number.");
    exit(1);
  }

  return number;
}

ProgramOptions::ProgramOptions(int argc, char *argv[]) : basename(argv[0]) {
  int help_flag = 0;
  int opt;

  struct option longopts[] = {{"help", no_argument, &help_flag, 1},
                              {"addition", no_argument, NULL, 'a'},
                              {"subtract", no_argument, NULL, 's'},
                              {"multiply", no_argument, NULL, 'm'},
                              {"divide", no_argument, NULL, 'd'},
                              {0}};

  while ((opt = getopt_long(argc, argv, "hasmdx:y:", longopts, 0)) != -1) {
    switch (opt) {
      case 'h':
        help_flag = 1;
        break;
      case 'a':
        operationFlag = ADD;
        break;
      case 's':
        operationFlag = SUBTRACT;
        break;
      case 'm':
        operationFlag = MULTIPLY;
        break;
      case 'd':
        operationFlag = DIVIDE;
        break;
      case 'x':
        x = stringToLong(optarg);
        break;
      case 'y':
        y = stringToLong(optarg);
        break;
      case '?':
        /* a return value of '?' indicates that an option was malformed.
         * this could mean that an unrecognized option was given, or that an
         * option which requires an argument did not include an argument.
         */
        usage();
      default:
        break;
    }
  }

  if (help_flag) {
    usage();
  }
};

ProgramOptions::~ProgramOptions() {}

int ProgramOptions::getX() { return x; }
int ProgramOptions::getY() { return y; }
OperationFlag ProgramOptions::getOperationFlag() { return operationFlag; }

void ProgramOptions::usage() { return Utils::printUsage(stderr, basename); }