#ifndef SIMPLE_ENCODER_H
#define SIMPLE_ENCODER_H

#include <string>

using namespace std;

class SimpleEncoder {
 public:
  static bool encryptFile(const string &inputFilePath,
                          const string &outputFilePath, int key);
  static bool decryptFile(const string &inputFilePath,
                          const string &outputFilePath, int key);
};

#endif /*SIMPLE_ENCODER_H*/