#include "CreateFunctions.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"

namespace TopSystem
{
  shared_ptr<Circle>   CreateCircle(EDimension	 dimension,
	const PathShaders& pathShaders)
  {
	vector<GLfloat> container;
	vector<GLint>	indices;
	auto AddColorToVertex = [&](GLfloat R, GLfloat G, GLfloat B)
	{
	  container.push_back(R);
	  container.push_back(G);
	  container.push_back(B);
	};

	container.push_back(0.0f);
	container.push_back(0.0f);
	container.push_back(0.0f);
	AddColorToVertex(0.0f, 1.0f, 0.0f);

	int amountOfPoint = 0;
	for (int angle = 45, i = 1; angle <= 360; angle += 45, i++) {
	  float radian = angle * (3.14f / 180.0f);
	  container.push_back(std::cos(radian) / 2);
	  container.push_back(std::sin(radian) / 2);
	  container.push_back(0.0f);
	  amountOfPoint++;

	  AddColorToVertex(0.0f, 0.0f, 1.0f);
	}

	int i = 2;
	while (i <= amountOfPoint)
	{
	  indices.push_back(0);
	  indices.push_back(i - 1);
	  indices.push_back(i);
	  ++i;
	}

	// Уменьшаем на 1, что бы вернуться к прошлому значению, ....
	// ....которое свяжется в цепочку индексов
	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(--i);

	auto cir = std::make_shared<Circle>
	(
	  (GLuint)dimension,
	  (GLuint)dimension,
	  pathShaders,
	  container,
	  indices
	);
	return cir;
  }

  shared_ptr<Triangle> CreateTriangle(EDimension	 dimension,
	const PathShaders& pathShaders)
  {
	const vector<GLfloat> container
	{
	  // coord			  color
	  0.0f,  0.5f, 0.0f,	  0.0f, 0.0f, 1.0f,
	  0.5f, -0.5f, 0.0f,	  0.0f, 1.0f, 0.0f,
	 -0.5f, -0.5f, 0.0f,	  1.0f, 0.0f, 0.0f
	};

	vector<GLint>	indices;
	for (int i = 0; i < 3; ++i)
	{
	  indices.push_back(i);
	}

	auto tri = std::make_shared<Triangle>
	(
	  (GLuint)dimension,
	  (GLuint)dimension,
	  pathShaders,
	  container,
	  indices
	);
	return tri;
  }

  shared_ptr<Rectangle> CreateRectangle(EDimension   dimension,
	const PathShaders& pathShaders)
  {
	std::vector<GLfloat> container
	{
	  // coord            color
	  0.5f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f,  // top right
	  0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom right
	 -0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom left
	 -0.5f,  0.5f, 0.0f,  0.0f, 1.0f, 0.0f   // top left 
	};

	std::vector<GLint>   indices
	{
	  0, 1, 3,
	  1, 2, 3
	};

	auto rec = std::make_shared<Rectangle>
	(
	  (GLuint)dimension,
	  (GLuint)dimension,
	  pathShaders,
	  container,
	  indices
	);
	return rec;
  }
}