#ifndef PROGRAM_OPTIONS_H
#define PROGRAM_OPTIONS_H

#include <string>

enum OperationFlag {
  ENCRYPT = 'e',
  DECRYPT = 'd',
};

class ProgramOptions {
 public:
  ProgramOptions(int argc, char *argv[]);
  ~ProgramOptions();

  std::string getInputFilename();
  std::string getOutputFilename();
  
  int getKey();
  
  OperationFlag getOperationFlag();

  void usage();
 private:
  OperationFlag operationFlag;
  std::string inputFilename;
  std::string outputFilename;
  
  int key;

  const char *basename; // arguments
  
};

#endif /*PROGRAM_OPTIONS_H*/