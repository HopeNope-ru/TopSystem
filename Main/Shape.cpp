#include "Shape.h"

namespace TopSystem
{
  Shape::Shape(GLuint		   colorDimension,
			   GLuint		   vertexDimension,
			   string		   vertexFilePath,
			   string		   fragmentFilePath,
			   vector<GLfloat> container,
			   vector<GLint>   indices		  )
	: _vbo(container),
	  _ebo(indices),
	  _vao(vertexDimension, colorDimension, _vbo, _ebo),
	  _shader(vertexFilePath, fragmentFilePath)
  { }
}