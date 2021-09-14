#include "VertexBufferObject.h"

namespace TopSystem
{
  VertexBufferObject::VertexBufferObject(const vector<GLfloat>& container)
	: _targetBuffer(GL_ARRAY_BUFFER), _container(container)
  {
	GenerateBuffer(_targetBuffer, _container);
  }
}