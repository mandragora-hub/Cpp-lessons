#include "utils.h"

#include <GLFW/glfw3.h>

#include <fstream>
#include <iostream>

GLuint Utils::createShaderProgram(const char* vp, const char* fp) {
  GLint vertCompiled;
  GLint fragCompiled;
  GLint linked;

  GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
  GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);

  string vertShaderStr = readShaderSource(vp);
  string fragShaderStr = readShaderSource(fp);

  const char* vertShaderSrc = vertShaderStr.c_str();
  const char* fragShaderSrc = fragShaderStr.c_str();
  glShaderSource(vShader, 1, &vertShaderSrc, NULL);
  glShaderSource(fShader, 1, &fragShaderSrc, NULL);

  // catch errors while compiling shaders
  glCompileShader(vShader);
  checkOpenGLError();
  glGetShaderiv(vShader, GL_COMPILE_STATUS, &vertCompiled);
  if (vertCompiled != 1) {
    cout << "vertex compilation failed" << endl;
    printShaderLog(vShader);
  }
  glCompileShader(fShader);
  checkOpenGLError();
  glGetShaderiv(fShader, GL_COMPILE_STATUS, &fragCompiled);
  if (fragCompiled != 1) {
    cout << "fragment compilation failed" << endl;
    printShaderLog(fShader);
  }

  GLuint vfProgram = glCreateProgram();

  // catch errors while linking shaders
  glAttachShader(vfProgram, vShader);
  glAttachShader(vfProgram, fShader);
  glLinkProgram(vfProgram);
  checkOpenGLError();
  glGetProgramiv(vfProgram, GL_LINK_STATUS, &linked);
  if (linked != 1) {
    cout << "linking failed" << endl;
    printProgramLog(vfProgram);
  }
  return vfProgram;
}

string Utils::readShaderSource(const char* filePath) {
  string content;
  ifstream fileStream(filePath, ios::in);
  string line = "";
  if (!fileStream.is_open()) {
    cout << "Cannot open file: " << filePath << endl;
    return NULL;
  }

  while (!fileStream.eof()) {
    getline(fileStream, line);
    content.append(line + "\n");
  }
  fileStream.close();
  return content;
}

void Utils::printShaderLog(GLuint shader) {
  int len = 0;
  int chWrittn = 0;
  char* log;
  glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
  if (len > 0) {
    log = (char*)malloc(len);
    glGetShaderInfoLog(shader, len, &chWrittn, log);
    cout << "Shader Info Log: " << log << endl;
    free(log);
  }
}
void Utils::printProgramLog(int prog) {
  int len = 0;
  int chWrittn = 0;
  char* log;
  glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &len);
  if (len > 0) {
    log = (char*)malloc(len);
    glGetProgramInfoLog(prog, len, &chWrittn, log);
    cout << "Program Info Log: " << log << endl;
    free(log);
  }
}
bool Utils::checkOpenGLError() {
  bool foundError = false;
  int glErr = glGetError();
  while (glErr != GL_NO_ERROR) {
    cout << "glError: " << glErr << endl;
    foundError = true;
    glErr = glGetError();
  }
  return foundError;
}
