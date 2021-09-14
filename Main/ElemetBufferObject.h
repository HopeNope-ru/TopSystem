#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace TopSystem
{
  using std::vector;
  using EBO = ElementBufferObject;

  class ElementBufferObject 
  {
  public:
	ElementBufferObject(const vector<GLfloat>& indices);

	void Bind()	  { glBindBuffer(_targetBuffer, _buffer); }
	void UnBind() { glBindBuffer(_targetBuffer, 0); }

	const vector<GLfloat>& GetIndices() { return _indices; }
  private:
	GLuint _buffer;
	GLuint _targetBuffer;

	vector<GLfloat> _indices;
  };
}