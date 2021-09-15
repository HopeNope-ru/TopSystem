#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>

#include "Defs.h"
#include "PathShaders.h"

namespace TopSystem
{
  class Shape;
  class Circle;
  class Triangle;
  class Rectangle;

  GLFWwindow* Init();

  void FramebufferSizeCallback(	GLFWwindow* window, int width, int height);
  void ProcessInput			  (	GLFWwindow* window);

  void RenderLoop			  (		  GLFWwindow* window, 
								const std::vector<std::shared_ptr<Shape>>& shapes);

  template<typename T>
  void GenerateBuffer(GLenum targetBuffer, GLuint& buffer, std::vector<T> container)
  {
	glGenBuffers(1, &buffer);
	glBindBuffer(targetBuffer, buffer);
	GLsizei size = sizeof(T) * container.size();
	glBufferData(targetBuffer, size, container.data(), GL_STATIC_DRAW);
	glBindBuffer(targetBuffer, 0);
  }
}