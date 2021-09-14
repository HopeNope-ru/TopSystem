#include "Rectangle.h"

namespace TopSystem
{
  void Rectangle::Draw() 
  {
	_vao.Bind();
	_shader.Use();

	GLsizei amountIndices = _ebo.GetIndices().size();
	glDrawElements(GL_TRIANGLES, amountIndices, GL_UNSIGNED_INT, 0);
  }
}