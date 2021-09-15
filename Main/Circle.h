#pragma once
#include "Shape.h"

namespace TopSystem
{
  class Circle : public Shape
  {
  public:
	Circle(GLuint		   colorDimension,
		   GLuint		   vertexDimension,
		   string		   vertexFilePath,
		   string		   fragmentFilePath,
		   vector<GLfloat> container,
		   vector<GLint>   indices		   );
	
	virtual void Draw() override;

  };
}