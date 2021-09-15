#include "UtilityFunctions.h"
#include "Shader.h"
#include "PathShaders.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Shape.h"

namespace TopSystem {
  GLFWwindow* Init()
  {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGLSurprise", NULL, NULL);

	if (window == NULL)
	{
	  std::cout << "Failed to create GLFW window" << std::endl;
	  glfwTerminate();
	  return nullptr;
	}

	glfwMakeContextCurrent(window);

	glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
	  std::cout << "Failed to initialize GLAD" << std::endl;
	  glfwTerminate();
	  return nullptr;
	}

	return window;
  }

  EShapes eShape = EShapes::Circle;

  void RenderLoop(GLFWwindow* window, const std::vector<std::shared_ptr<IDrawable>>& shapes)
  {
	while (!glfwWindowShouldClose(window))
	{
	  ProcessInput(window);

	  glClearColor(0.2f, 0.4f, 0.6f, 1.0f);
	  glClear(GL_COLOR_BUFFER_BIT);

	  switch (eShape)
	  {
	  case EShapes::Circle:
		shapes[(GLint)eShape]->Draw();
		break;
	  case EShapes::Triangle:
		shapes[(GLint)eShape]->Draw();
		break;
	  case EShapes::Rectangle:
		shapes[(GLint)eShape]->Draw();
		break;
	  }

	  glfwSwapBuffers(window);
	  glfwPollEvents();
	}
  }

  void FramebufferSizeCallback(GLFWwindow* window, int width, int height)
  {
	glViewport(0, 0, width, height);
  }

  void ProcessInput(GLFWwindow* window)
  {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
		eShape = EShapes::Circle;
	if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
		eShape = EShapes::Triangle;
	if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
		eShape = EShapes::Rectangle;
  }
}