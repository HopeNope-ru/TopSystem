#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "UtilityFunctions.h"

namespace TopSystem
{
  using EBO = ElementBufferObject;

  class ElementBufferObject 
  {
  public:
	ElementBufferObject(GLenum targetBuffer, const vector<GLint>& indices);

	void Bind()	  { glBindBuffer(_targetBuffer, _buffer); }
	void UnBind() { glBindBuffer(_targetBuffer, 0); }

	const vector<GLint>& GetIndices() { return _indices; }
  private:
	GLuint _buffer;
	GLuint _targetBuffer;

	vector<GLint> _indices;
  };
}