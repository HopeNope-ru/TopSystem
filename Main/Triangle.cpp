#include "Triangle.h"

namespace TopSystem
{
  void Triangle::Draw()
  {
	_shader.Use();
	_vao.Bind();

	GLsizei amountIndices = _ebo.GetIndices().size();
	glDrawElements(GL_TRIANGLES, amountIndices, GL_UNSIGNED_INT, 0);
  }
}