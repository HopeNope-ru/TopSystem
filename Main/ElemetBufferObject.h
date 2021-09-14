#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "UtilityFunctions.h"

namespace TopSystem
{
  class ElementBufferObject 
  {
  public:
	ElementBufferObject(const vector<GLint>& indices);

	void Bind()	  const { glBindBuffer(_targetBuffer, _buffer); }
	void UnBind() const { glBindBuffer(_targetBuffer, 0); }

	const vector<GLint>& GetIndices() { return _indices; }

  private:
	GLuint		  _buffer;
	vector<GLint> _indices;

	static const GLuint _targetBuffer;
  };

  using EBO = ElementBufferObject;
}