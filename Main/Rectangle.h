#pragma once
#include "Shape.h"

namespace TopSystem
{
  class Rectangle : public Shape
  {
  public:
	Rectangle(GLuint		   colorDimension,
			  GLuint		   vertexDimension,
			  string		   vertexFilePath,
			  string		   fragmentFilePath,
			  vector<GLfloat>  container,
			  vector<GLint>    indices)
	  : Shape(colorDimension, vertexDimension,  vertexFilePath, fragmentFilePath, container, indices)
	{ }

	virtual void Draw() override;
  };
}