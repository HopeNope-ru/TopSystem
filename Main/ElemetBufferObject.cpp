#include "ElemetBufferObject.h"

namespace TopSystem
{
  ElementBufferObject::ElementBufferObject(const vector<GLint>& indices)
	: _indices(indices)
  {
	GenerateBuffer(_targetBuffer, _buffer, _indices);
  }

  const GLenum ElementBufferObject::_targetBuffer = GL_ELEMENT_ARRAY_BUFFER;
}