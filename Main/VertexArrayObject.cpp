#include "VertexArrayObject.h"


namespace TopSystem 
{
  VertexArrayObject::VertexArrayObject(GLuint	  vertexDimension, 
									   GLuint	  colorDimension, 
									   const VBO& vbo, 
									   const EBO& ebo) 
  {
	glGenVertexArrays(1, &_vertexArray);
	Bind();
	vbo.Bind();
	ebo.Bind();

	// add color dimension
	GLsizei stride = vertexDimension * sizeof(GLfloat);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void*)0);
	glEnableVertexAttribArray(0);
	// Add color!!!!!!!

	UnBind();
  }
}