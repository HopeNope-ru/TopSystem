#include "UtilityFunctions.h"
#include "Shader.h"
#include "PathShaders.h"
#include "Circle.h"

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

  Circle CreateCircle(const PathShaders& pathShaders, vector<GLfloat>& container, vector<GLint>& indices)
  {
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
	while(i <= amountOfPoint)
	{
	  indices.push_back(0);
	  indices.push_back(i - 1);
	  indices.push_back(i);
	  ++i;
	}

	// ��������� �� 1, ��� �� ��������� � �������� ��������, ....
	// ....������� �������� � ������� ��������
	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(--i);

	return Circle(3, 3, pathShaders.GetVertexFilePath(), pathShaders.GetFragmentFilePath(), container, indices);
  }
  
  void CreateTriangle(const GLfloat*		   triangleVertex,
							  GLsizei		   sizeTriangleVertex,
							  vector<GLfloat>& container, 
							  vector<GLint>&   indices			 ) 
  {
	for (int i = 0; i < sizeTriangleVertex; ++i) 
	{
	  container.push_back(triangleVertex[i]);
	}

	for (int i = 0; i < 3; ++i)
	{
	  indices.push_back(i);
	}
  }
}