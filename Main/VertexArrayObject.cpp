#include "VertexArrayObject.h"


namespace TopSystem 
{
  VertexArrayObject::VertexArrayObject(VBO vbo, EBO ebo) 
  {
	glGenVertexArrays(1, &_vertexArray);
	Bind();
	ebo.Bind();
	vbo.Bind();

	const vector<GLfloat>& container = vbo.GetContainer();

	GLsizei stride = 3 * sizeof(GLfloat);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void*)0);
	glEnableVertexAttribArray(0);
	// Add color!!!!!!!

	UnBind();
	vbo.UnBind();
	ebo.UnBind();
  }
}