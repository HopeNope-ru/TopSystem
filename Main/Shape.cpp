#include "Shape.h"

namespace TopSystem
{
  Shape::Shape(GLbyte		   colorDimension,
			   GLbyte		   vertexDimension,
			   Shader		   shader,
			   vector<GLfloat> container,
			   vector<GLint>   indices		  )
  {
	_vbo	= VBO(container);
	_ebo	= EBO(indices);
	_vao	= VAO(vertexDimension, colorDimension, _vbo, _ebo);
	_shader = shader;
  }
}