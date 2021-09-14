#include "UtilityFunctions.h"
#include "Shader.h"

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

  void RenderLoop(GLFWwindow* window)
  {
	Shader shader("Shaders/VertexShader.txt", "Shaders/FragmentShader.txt");

	while (!glfwWindowShouldClose(window))
	{
	  ProcessInput(window);

	  glClearColor(0.2f, 0.4f, 0.6f, 1.0f);
	  glClear(GL_COLOR_BUFFER_BIT);

	  shader.Use();

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
  }
}