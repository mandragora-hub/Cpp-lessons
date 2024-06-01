#include <GL/glew.h>

#include <string>

using namespace std;

class Utils {
 public:
  static GLuint createShaderProgram(const char *vp, const char *fp);

 private:
  static string readShaderSource(const char *filePath);

  // function to catch OpenGL and GLSL errors
  static void printShaderLog(GLuint shader);
  static void printProgramLog(int prog);
  static bool checkOpenGLError();
  //
};