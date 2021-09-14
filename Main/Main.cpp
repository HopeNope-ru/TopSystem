#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Shader.h"
#include "UtilityFunctions.h"
#include "VertexArrayObject.h"
#include "VertexBufferObject.h"
#include "ElemetBufferObject.h"
#include "Rectangle.h"

using namespace TopSystem;

int main()
{
  GLFWwindow* window = Init();
  // Init обязует определить окно
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

  Shader shader("Shaders/VertexShader.txt", "Shaders/FragmentShader.txt");
  Rectangle rectangle(3, 3, shader, container, indices);

  while (!glfwWindowShouldClose(window))
  {
    ProcessInput(window);

    glClearColor(0.2f, 0.4f, 0.6f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    rectangle.Draw();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
    
