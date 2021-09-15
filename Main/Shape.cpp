#include "Shape.h"

namespace TopSystem
{
  Shape::Shape(		  GLuint			colorDimension,
					  GLuint			vertexDimension,
				const PathShaders&		pathShaders,
					  vector<GLfloat>	container,
					  vector<GLint>		indices			)
	: _vbo(container),
	  _ebo(indices),
	  _vao(vertexDimension, colorDimension, _vbo, _ebo),
	  _shader(pathShaders)
  { }
}