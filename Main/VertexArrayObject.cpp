#include "VertexArrayObject.h"


namespace TopSystem 
{
  VertexArrayObject::VertexArrayObject(GLuint vertexDimension, GLuint colorDimension) 
  {
	glGenVertexArrays(1, &_vertexArray);
	Bind();

	// add color dimension
	GLsizei stride = vertexDimension * sizeof(GLfloat);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void*)0);
	glEnableVertexAttribArray(0);
	// Add color!!!!!!!

	UnBind();
  }
}