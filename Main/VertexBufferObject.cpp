#include "VertexBufferObject.h"

namespace TopSystem
{
  VertexBufferObject::VertexBufferObject(const vector<GLfloat>& container)
	: _targetBuffer(GL_ARRAY_BUFFER), _container(container)
  {
	glGenBuffers(1, &_buffer);
	glBindBuffer(_targetBuffer, _buffer);
	glBufferData(_targetBuffer, sizeof(GLfloat) * _container.size(), _container.data(), GL_STATIC_DRAW);
	glBindBuffer(_targetBuffer, 0);
  }
}