#include "Shader.h"
#include <fstream>
#include <iostream>
#include <sstream>

namespace TopSystem
{
  // В конструкторе создается шейдерный конвеер
  Shader::Shader(const std::string& vertexFilePath, const std::string& fragmentFilePath)
  {
	std::string	vShaderCode, fShaderCode;
	std::ifstream vShaderFile, fShaderFile;

	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	// Производится загрузка содержимого файла в строку
	try
	{
	  std::stringstream vShaderStream, fShaderStream;

	  vShaderFile.open(vertexFilePath);
	  fShaderFile.open(fragmentFilePath);

	  vShaderStream << vShaderFile.rdbuf();
	  fShaderStream << fShaderFile.rdbuf();

	  vShaderCode = vShaderStream.str();
	  fShaderCode = fShaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
	  std::cout << "ERROR::FILE::OPEN_FAILED\n";
	}

	const char* vShaderSource = vShaderCode.c_str();
	const char* fShaderSource = fShaderCode.c_str();

	GLuint vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vShaderSource, NULL);
	glCompileShader(vertexShader);
	CheckCompile(vertexShader, ESP::VERTEX);

	GLuint fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fShaderSource, NULL);
	glCompileShader(fragmentShader);
	CheckCompile(fragmentShader, ESP::FRAGMENT);

	ID = glCreateProgram();
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);
	CheckCompile(ID, ESP::PROGRAM);
  }

  void Shader::CheckCompile(GLuint keyShader, EShaderPipeline shader) 
  {
	int success;
	char infoLog[1024];
	std::string shaderName;

	switch (shader) 
	{
	case ESP::FRAGMENT: 
	  shaderName = "FRAGMENT"; 
	  break;
	case ESP::VERTEX:
	  shaderName = "VERTEX";
	  break;
	case ESP::PROGRAM:
	  shaderName = "PROGRAM";
	}

	if(shader != ESP::PROGRAM) 
	{
	  glGetShaderiv(keyShader, GL_COMPILE_STATUS, &success);
	  if (!success) 
	  {
		glGetShaderInfoLog(keyShader, 1024, NULL, infoLog);
		std::cout << "ERROR::SHADER::" << shaderName << "::COMPILE_FAILED\n" << infoLog << std::endl;
	  }
	}
	else 
	{
	  glGetProgramiv(keyShader, GL_LINK_STATUS, &success);
	  if (!success) 
	  {
		glGetProgramInfoLog(keyShader, 1024, NULL, infoLog);
		std::cout << "ERROR::SHADER::" << shaderName << "::LINK_FAILED\n" << infoLog << std::endl;
	  }
	}
  }
}