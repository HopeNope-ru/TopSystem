#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "ElemetBufferObject.h"
#include "VertexBufferObject.h"

namespace TopSystem
{
  class VertexArrayObject
  {
  public:
	VertexArrayObject(GLuint vertexDimension, GLuint colorDimension);

	void   Bind()			{ glBindVertexArray(_vertexArray); }
	void   UnBind()			{ glBindVertexArray(0); }
	GLuint GetVertexArray() { return _vertexArray; }

  private:
	GLuint _vertexArray;
  };
}