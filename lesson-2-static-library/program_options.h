#ifndef PROGRAM_OPTIONS_H
#define PROGRAM_OPTIONS_H

namespace rgm {

enum OperationFlag {
  ADD = 'a',
  SUBTRACT = 's',
  MULTIPLY = 'm',
  DIVIDE = 'd',
};

class ProgramOptions {
 public:
  ProgramOptions(int argc, char *argv[]);
  ~ProgramOptions();

  int getX();
  int getY();
  OperationFlag getOperationFlag();

  void usage();

 private:
  OperationFlag operationFlag;
  int x, y;
  
  const char *basename; // arguments
  
};
};  // namespace rgm

#endif /*PROGRAM_OPTIONS_H*/