#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Defs.h"
#include "Shader.h"
#include "UtilityFunctions.h"
#include "VertexArrayObject.h"
#include "VertexBufferObject.h"
#include "ElemetBufferObject.h"
#include "CreateFunctions.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "PathShaders.h"

using namespace TopSystem;
using spShape = shared_ptr<Shape>;
int main()
{
  GLFWwindow* window = Init();
  // Init have to declare the window
  if (window == nullptr) {
    return -1;
  }

  string      vertexPath    = "Shaders/VertexShader.txt";
  string      fragmentPath  = "Shaders/FragmentShader.txt";
  PathShaders pathShaders(vertexPath, fragmentPath);

  vector<spShape> shapes
  {
    CreateCircle    (EDimension::_3D, 20, pathShaders),
    CreateTriangle  (EDimension::_3D, pathShaders),
    CreateRectangle (EDimension::_3D, pathShaders)
  };

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

  RenderLoop(window, shapes);

  glfwTerminate();
  return 0;
}
    
