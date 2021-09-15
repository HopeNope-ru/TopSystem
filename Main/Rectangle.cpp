#include "Rectangle.h"

namespace TopSystem
{
  void Rectangle::Draw() const
  {
	_shader.Use();
	_vao.Bind();

	GLsizei amountIndices = _ebo.GetIndices().size();
	glDrawElements(GL_TRIANGLES, amountIndices, GL_UNSIGNED_INT, 0);
  }
}