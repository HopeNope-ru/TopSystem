#include "Circle.h"

namespace TopSystem
{
  Circle::Circle(GLuint		     colorDimension,
				 GLuint		     vertexDimension,
				 string		     vertexFilePath,
				 string		     fragmentFilePath,
				 vector<GLfloat> container,
				 vector<GLint>   indices		  )
	: Shape(colorDimension, 
			vertexDimension, 
			vertexFilePath, 
			fragmentFilePath, 
			container,		
			indices			 )
  { }

  void Circle::Draw()
  {
	_shader.Use();
	_vao.Bind();

	GLsizei amountIndices = _ebo.GetIndices().size();
	glDrawElements(GL_TRIANGLES, amountIndices, GL_UNSIGNED_INT, 0);
  }
}