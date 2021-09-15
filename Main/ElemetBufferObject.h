#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "Defs.h"
#include "UtilityFunctions.h"

namespace TopSystem
{
  class ElementBufferObject 
  {
  public:
	ElementBufferObject(const vector<GLint>& indices);
	ElementBufferObject() : _buffer(0)
	{ }

	void Bind()	  const { glBindBuffer(_targetBuffer, _buffer); }
	void UnBind() const { glBindBuffer(_targetBuffer, 0); }

	const vector<GLint>& GetIndices() const { return _indices; }

  private:
	GLuint		  _buffer;
	vector<GLint> _indices;

	static const GLuint _targetBuffer;
  };

  using EBO = ElementBufferObject;
}