#pragma once
#include "Shape.h"

namespace TopSystem
{
  class Rectangle : public Shape
  {
  public:
	Rectangle( GLuint			colorDimension,
			  GLuint			vertexDimension,
			  const PathShaders&	pathShaders,
			  vector<GLfloat> container,
			  vector<GLint>   indices		   )
	: Shape(colorDimension, 
			vertexDimension, 
			pathShaders,
			container,		
			indices			 )
	{ }

	virtual void Draw() const override;
  };
}