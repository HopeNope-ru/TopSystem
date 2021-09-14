#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "UtilityFunctions.h"

namespace TopSystem 
{
  class VertexBufferObject 
  {
  public:
	VertexBufferObject(const vector<GLfloat>& containter);
	VertexBufferObject() : _buffer(0)
	{ }

	void   Bind()	const { glBindBuffer(_targetBuffer, _buffer); }
	void   UnBind() const { glBindBuffer(_targetBuffer, _buffer); }
	GLuint GetBuffer()	  { return _buffer; }

	const vector<GLfloat>& GetContainer() const { return _container; }

  private:
	GLuint			_buffer;
	vector<GLfloat> _container;

	static const GLenum _targetBuffer;
  };

  using VBO = VertexBufferObject;
}