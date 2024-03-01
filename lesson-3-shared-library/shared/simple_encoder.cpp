#include "simple_encoder.h"

#include <fstream>
#include <iostream>
#include <string>

bool SimpleEncoder::encryptFile(const string &inputFilePath,
                                const string &outputFilePath, int key) {
  ifstream inputFile(inputFilePath, std::ios::binary);
  ofstream outputFile(outputFilePath, std::ios::binary);

  char ch;
  while (inputFile.get(ch)) {
    outputFile.put(ch + key);
  }

  inputFile.close();
  outputFile.close();

  return true;
}

bool SimpleEncoder::decryptFile(const string &inputFilePath,
                                const string &outputFilePath, int key) {
  ifstream inputFile(inputFilePath, std::ios::binary);
  ofstream outputFile(outputFilePath, std::ios::binary);

  char ch;
  while (inputFile.get(ch)) {
    outputFile.put(ch - key);
  }

  inputFile.close();
  outputFile.close();

  return true;
}