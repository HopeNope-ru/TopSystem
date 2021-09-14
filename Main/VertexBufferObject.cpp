#include "VertexBufferObject.h"
#include "UtilityFunctions.h"

namespace TopSystem
{
  VertexBufferObject::VertexBufferObject(const vector<GLfloat>& container)
	: _container(container)
  {
	GenerateBuffer(_targetBuffer, _buffer, _container);
  }

  const GLenum VertexBufferObject::_targetBuffer = GL_ARRAY_BUFFER;
}