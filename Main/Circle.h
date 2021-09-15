#pragma once
#include "Shape.h"

namespace TopSystem
{
  class Circle : public Shape
  {
  public:
	Circle(		  GLuint		  colorDimension,
				  GLuint		  vertexDimension,
			const PathShaders&	  pathShaders,
				  vector<GLfloat> container,
				  vector<GLint>	  indices		   );
	
	virtual void Draw() const override;

  };
}