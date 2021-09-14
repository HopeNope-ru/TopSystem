#pragma once
#include "Shape.h"

namespace TopSystem
{
  class Rectangle : public Shape
  {
  public:
	Rectangle(GLbyte		   colorDimension,
			  GLbyte		   vertexDimension,
			  Shader		   shader,
			  vector<GLfloat>  container,
			  vector<GLint>    indices)
	  : Shape(colorDimension, vertexDimension, shader, container, indices)
	{ }

	virtual void Draw() override;
  };
}