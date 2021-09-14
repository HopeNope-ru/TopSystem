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

	GLsizei stride = (vertexDimension + colorDimension) * sizeof(GLfloat);
	glVertexAttribPointer(0, vertexDimension, GL_FLOAT, GL_FALSE, stride, (void*)0);
	glEnableVertexAttribArray(0);
	
	GLsizei offset = sizeof(GLfloat) * vertexDimension;
	glVertexAttribPointer(1, colorDimension, GL_FLOAT, GL_FALSE, stride, (void*)offset);
	glEnableVertexAttribArray(1);

	UnBind();
	vbo.UnBind();
	ebo.UnBind();
  }
}