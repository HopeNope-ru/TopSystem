#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include <iostream>

namespace TopSystem
{
  using std::vector;
  using std::string;

  enum class EDimension : GLbyte
  {
	_2D = 2,
	_3D
  };

  const unsigned int SCR_WIDTH = 800;
  const unsigned int SCR_HEIGHT = 600;

  const GLfloat triangleVertex[] = 
  {  
	 // coord			  color
	 0.0f,  0.5f, 0.0f,	  0.0f, 0.0f, 1.0f,
	 0.5f, -0.5f, 0.0f,	  0.0f, 1.0f, 0.0f,
	-0.5f, -0.5f, 0.0f,	  1.0f, 0.0f, 0.0f
  };
}