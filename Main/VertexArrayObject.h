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
	VertexArrayObject(GLuint	 vertexDimension,
					  GLuint	 colorDimension,
					  const VBO& vbo,
					  const EBO& ebo			);

	VertexArrayObject() : _vertexArray(0)
	{ }

	void   Bind() const		{ glBindVertexArray(_vertexArray); }
	void   UnBind()			{ glBindVertexArray(0); }
	GLuint GetVertexArray() { return _vertexArray; }

  private:
	GLuint _vertexArray;
  };

  using VAO = VertexArrayObject;
}