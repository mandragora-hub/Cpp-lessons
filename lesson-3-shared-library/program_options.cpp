#include "program_options.h"

#include <getopt.h>
#include <string.h>

#include <iostream>

#include "utils.h"

ProgramOptions::ProgramOptions(int argc, char *argv[]) : basename(argv[0]) {
  int help_flag = 0;
  int opt;
  operationFlag = ENCRYPT;  // default operation
  key = 1;                  // default key

  struct option longopts[] = {{"help", no_argument, &help_flag, 1},
                              {"encrypt", no_argument, NULL, 'e'},
                              {"decrypt", no_argument, NULL, 'd'},
                              {"file", required_argument, NULL, 'f'},
                              {"output", required_argument, NULL, 'o'},
                              // {"key", required_argument, NULL, 'k'},
                              {0}};

  while ((opt = getopt_long(argc, argv, "hedf:k:o:", longopts, 0)) != -1) {
    switch (opt) {
      case 'h':
        help_flag = 1;
        break;
      case 'e':
        operationFlag = ENCRYPT;
        break;
      case 'd':
        operationFlag = DECRYPT;
        break;
      case 'f':
        inputFilename = optarg;
        break;
      case 'o':
        outputFilename = optarg;
        break;
      case 'k':
        char *error;
        key = strtol(optarg, &error, 10);
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

std::string ProgramOptions::getInputFilename() { return inputFilename; }
std::string ProgramOptions::getOutputFilename() { return outputFilename; }
OperationFlag ProgramOptions::getOperationFlag() { return operationFlag; }
int ProgramOptions::getKey() { return key; }

void ProgramOptions::usage() { return Utils::printUsage(stderr, basename); }