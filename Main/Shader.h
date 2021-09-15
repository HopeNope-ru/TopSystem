#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Defs.h"
#include "PathShaders.h"

namespace TopSystem {
  enum class EShaderPipeline : GLbyte
  {
	VERTEX,
	FRAGMENT,
	PROGRAM
  };

  using ESP = EShaderPipeline;

  class Shader
  {
  private:
	GLuint ID;

	void CheckCompile(GLuint keyShader, EShaderPipeline shader);

  public:
	Shader(const PathShaders& pathShaders);
	Shader() : ID(0) 
	{ }

	~Shader() { glDeleteProgram(ID); }

	void Use() const { glUseProgram(ID); }
  };
}