#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "UtilityFunctions.h"

namespace TopSystem 
{
  using VBO = VertexBufferObject;

  class VertexBufferObject 
  {
  public:
	VertexBufferObject(const vector<GLfloat>& containter);

	void   Bind()	   { glBindBuffer(_targetBuffer, _buffer); }
	void   UnBind()	   { glBindBuffer(_targetBuffer, _buffer); }
	GLuint GetBuffer() { return _buffer; }

	const vector<GLfloat>& GetContainer() { return _container; }

  private:
	GLuint _buffer;
	GLenum _targetBuffer;

	vector<GLfloat> _container;
  };
}