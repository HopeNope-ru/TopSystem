#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>

#include "Defs.h"
#include "PathShaders.h"

namespace TopSystem
{
  class Circle;
  class Triangle;
  class Rectangle;

  using std::shared_ptr;

  shared_ptr<Circle>	CreateCircle	(		EDimension	 dimension,
										  const PathShaders& pathShaders);

  shared_ptr<Triangle>	CreateTriangle	(		EDimension	 dimension,
										  const PathShaders& pathShaders);

  shared_ptr<Rectangle> CreateRectangle	(		EDimension   dimension,
										  const PathShaders& pathShaders);
}