#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Defs.h"
#include "PathShaders.h"

namespace TopSystem
{
  class Circle;

  GLFWwindow* Init();

  void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
  void ProcessInput			  (GLFWwindow* window);
  void RenderLoop			  (GLFWwindow* window);

  Circle CreateCircle(EDimension dimension, const PathShaders& pathShaders, vector<GLfloat>& container, vector<GLint>& indices);

  void CreateTriangle(const GLfloat*		   triangleVertex,
							  GLsizei		   sizeTriangleVertex,
							  vector<GLfloat>& container, 
							  vector<GLint>&   indices			 );

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