#include "ElemetBufferObject.h"

namespace TopSystem
{
  ElementBufferObject::ElementBufferObject(GLenum targetBuffer, const vector<GLint>& indices)
	: _targetBuffer(targetBuffer), _indices(indices)
  {
	glGenBuffers(1, &_buffer);
	glBindBuffer(_targetBuffer, _buffer);

	GLsizei size = sizeof(GLint) * _indices.size();
	glBufferData(_targetBuffer, size, _indices.data(), GL_STATIC_DRAW);
  }
}