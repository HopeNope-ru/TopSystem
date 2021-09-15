#pragma once
#include <vector>

#include "VertexArrayObject.h"
#include "VertexBufferObject.h"
#include "ElemetBufferObject.h"
#include "UtilityFunctions.h"
#include "Shader.h"
#include "PathShaders.h"
#include "Defs.h"
#include "Objects.h"

namespace TopSystem
{
  class Shape : public Objects
  {
  public:
	Shape(		GLuint			colorDimension,
				GLuint			vertexDimension,
		  const PathShaders&	pathShaders,
				vector<GLfloat> container,
				vector<GLint>	indices			);

	Shape()
	{ }

	virtual ~Shape() = 0
	{ }

	virtual void Draw() const = 0;

	// Getter
	const VBO& GetVertexBufferObject()  const { return _vbo; }
	const EBO& GetEelemntBufferObject() const { return _ebo; }
	const VAO& GetVertexArrayObject()   const { return _vao; }

  protected:
	VBO	   _vbo;
	EBO	   _ebo;
	VAO	   _vao;
	Shader _shader;
  };
}