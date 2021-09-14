#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace TopSystem
{
  using EBO = ElementBufferObject;

  class ElementBufferObject 
  {
  public:


	void Bind()	  { glBindBuffer(_targetBuffer, _buffer); }
	void UnBind() { glBindBuffer(_targetBuffer, 0); }
  private:
	GLuint _buffer;
	GLuint _targetBuffer;
  };
}