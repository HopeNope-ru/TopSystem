#pragma once
#include <vector>

#include "VertexArrayObject.h"
#include "VertexBufferObject.h"
#include "ElemetBufferObject.h"
#include "UtilityFunctions.h"

namespace TopSystem
{
  class Shape
  {
  public:
	Shape(GLbyte		  colorDimension,
		  GLbyte		  vertexDimension,
		  vector<GLfloat> container,
		  vector<GLint>	  indices		 );

	virtual ~Shape() 
	{ }

	virtual void Draw() = 0;

  private:
	VBO _vbo;
	EBO _ebo;
	VAO _vao;
  };
}