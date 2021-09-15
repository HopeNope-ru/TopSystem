#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Defs.h"
#include "Shader.h"
#include "UtilityFunctions.h"
#include "VertexArrayObject.h"
#include "VertexBufferObject.h"
#include "ElemetBufferObject.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "PathShaders.h"

using namespace TopSystem;

int main()
{
  GLFWwindow* window = Init();
  // Init ������� ���������� ����
  if (window == nullptr) {
    return -1;
  }

  std::vector<GLfloat> container
  {
     // coord            color
     0.5f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f,  // top right
     0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f,  0.0f, 1.0f, 0.0f   // top left 
  };

  std::vector<GLint>   indices
  {
    0, 1, 3,
    1, 2, 3
  };

  string vertexPath = "Shaders/VertexShader.txt";
  string fragmentPath = "Shaders/FragmentShader.txt";

  std::vector<GLfloat> circleCont;
  std::vector<GLint>   circleInd;
  Circle&& circle = CreateCircle(EDimension::_3D, PathShaders(vertexPath, fragmentPath), circleCont, circleInd);

  std::vector<GLfloat> vertexTriangle;
  std::vector<GLint>   indicesTriangle;
  CreateTriangle(triangleVertex, sizeof(triangleVertex) / sizeof(GLfloat), vertexTriangle, indicesTriangle);

  Rectangle rectangle(3, 3, vertexPath, fragmentPath, container, indices);
  //Circle    circle(3, 3, vertexPath, fragmentPath, circleCont, circleInd);
  Triangle  triangle(3, 3, vertexPath, fragmentPath, vertexTriangle, indicesTriangle);

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  while (!glfwWindowShouldClose(window))
  {
    ProcessInput(window);

    glClearColor(0.2f, 0.4f, 0.6f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //rectangle.Draw();
    circle.Draw();
    //triangle.Draw();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
    
