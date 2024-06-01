#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <fstream>
#include <iostream>
#include <string>

#include "utils.h"
using namespace std;

#define numVAOs 1

GLuint renderingProgram;
GLuint vao[numVAOs];

float x = 0.0f;     // location of triangle on x axis
float inc = 0.01f;  // offset for moving the triangle

void init(GLFWwindow* window) {
  renderingProgram = Utils::createShaderProgram("vertShader.glsl", "fragShader.glsl");
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
  GLuint offsetLoc =
      glGetUniformLocation(renderingProgram, "offset");  // get ptr to "offset"
  glProgramUniform1f(renderingProgram, offsetLoc,
                     x);  // send value in "x" to "offset"

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
      glfwCreateWindow(600, 600, "Chapter2 - program 7", NULL, NULL);
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