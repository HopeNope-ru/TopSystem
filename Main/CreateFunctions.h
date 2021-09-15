#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Defs.h"
#include "PathShaders.h"

namespace TopSystem
{
  class Circle;
  class Triangle;
  class Rectangle;

  Circle	CreateCircle  (		EDimension	 dimension,
							const PathShaders& pathShaders);

  Triangle	CreateTriangle(	EDimension	 dimension,
							const PathShaders& pathShaders);

  Rectangle CreateRectangle(	  EDimension   dimension,
							const PathShaders& pathShaders);
}