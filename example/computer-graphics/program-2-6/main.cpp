#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#define numVAOs 1

GLuint renderingProgram;
GLuint vao[numVAOs];

string readShaderSource(const char* filePath) {
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

// function to catch OpenGL and GLSL errors
void printShaderLog(GLuint shader) {
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
void printProgramLog(int prog) {
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
bool checkOpenGLError() {
  bool foundError = false;
  int glErr = glGetError();
  while (glErr != GL_NO_ERROR) {
    cout << "glError: " << glErr << endl;
    foundError = true;
    glErr = glGetError();
  }
  return foundError;
}

//

GLuint createShaderProgram() {
  GLint vertCompiled;
  GLint fragCompiled;
  GLint linked;

  GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
  GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);

  string vertShaderStr = readShaderSource("vertShader.glsl");
  string fragShaderStr = readShaderSource("fragShader.glsl");

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

float x = 0.0f;     // location of triangle on x axis
float inc = 0.01f;  // offset for moving the triangle

void init(GLFWwindow* window) {
  renderingProgram = createShaderProgram();
  glGenVertexArrays(numVAOs, vao);
  glBindVertexArray(vao[0]);
}

void display(GLFWwindow* window, double currentTime) {
  glClear(GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);  // clear the background to black, each time

  glUseProgram(renderingProgram);

  x += inc;                    // move the triangle along x axis
  if (x > 1.0f) inc = -0.01f;  // switch to moving the triangle to the left
  if (x < -1.0f) inc = 0.01f;  // switch to moving the triangle to the right
  GLuint offsetLoc = glGetUniformLocation(renderingProgram, "offset");  // get ptr to "offset"
  glProgramUniform1f(renderingProgram, offsetLoc, x);  // send value in "x" to "offset"
  
  // set size of vertex to 30 pixels. In Rasterization stage
  // glPointSize(30.0f);
  glDrawArrays(GL_TRIANGLES, 0, 3);
}

int main(void) {
  if (!glfwInit()) {
    exit(EXIT_FAILURE);
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  GLFWwindow* window =
      glfwCreateWindow(600, 600, "Chapter2 - program 6", NULL, NULL);
  glfwMakeContextCurrent(window);
  if (glewInit() != GLEW_OK) {
    exit(EXIT_FAILURE);
  }
  glfwSwapInterval(1);
  init(window);
  while (!glfwWindowShouldClose(window)) {
    display(window, glfwGetTime());
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  glfwDestroyWindow(window);
  glfwTerminate();
  exit(EXIT_SUCCESS);
}