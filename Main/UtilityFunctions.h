#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

namespace TopSystem
{
  using std::vector;

  const unsigned int SCR_WIDTH = 800;
  const unsigned int SCR_HEIGHT = 600;

  GLFWwindow* Init();

  void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
  void ProcessInput(GLFWwindow* window);
  void RenderLoop(GLFWwindow* window);

  template<class T>
  void GenerateBuffer(GLenum targetBuffer, vector<T> container);
}