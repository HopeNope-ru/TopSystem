#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Defs.h"

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
	Shader(const std::string& vertexFilePath, const std::string& fragmentFilePath);
	Shader() : ID(0) 
	{ }

	~Shader() { glDeleteProgram(ID); }

	void Use() { glUseProgram(ID); }
  };
}