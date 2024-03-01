#include <getopt.h>
#include <string.h>

#include <iostream>

#include "program_options.h"
#include "shared/simple_encoder.h"
#include "utils.h"

int main(int argc, char *argv[]) {
  ProgramOptions options(argc, argv);

  switch (options.getOperationFlag()) {
    case ENCRYPT:
      std::cout << "Input file: " << options.getInputFilename() << std::endl;
      std::cout << "Output file: " << options.getOutputFilename() << std::endl;
      SimpleEncoder::encryptFile(options.getInputFilename(),
                                 options.getOutputFilename(), options.getKey());
      break;
    case DECRYPT:
      // printf("Result: %s\n", options.getInputFilename().c_str());
      SimpleEncoder::decryptFile(options.getInputFilename(),
                                 options.getOutputFilename(), options.getKey());
      break;

    default:
      Utils::printUsage(stderr, argv[0]);
      exit(1);
      break;
  }

  return 0;
}
