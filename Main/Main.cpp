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

int main()
{
  GLFWwindow* window = Init();
  // Init have to declare the window
  if (window == nullptr) {
    return -1;
  }

  string vertexPath = "Shaders/VertexShader.txt";
  string fragmentPath = "Shaders/FragmentShader.txt";
  PathShaders pathShaders(vertexPath, fragmentPath);

  Circle&& circle = CreateCircle(EDimension::_3D, pathShaders);

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  while (!glfwWindowShouldClose(window))
  {
    ProcessInput(window);

    glClearColor(0.2f, 0.4f, 0.6f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    circle.Draw();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
    
