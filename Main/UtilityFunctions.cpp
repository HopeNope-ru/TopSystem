#include "UtilityFunctions.h"
#include "Shader.h"
#include "PathShaders.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"

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


  Circle   CreateCircle(	  EDimension	 dimension, 
						const PathShaders&	 pathShaders  )
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
	while(i <= amountOfPoint)
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

	return Circle((GLuint)dimension, 
				  (GLuint)dimension, 
				  pathShaders.GetVertexFilePath(), 
				  pathShaders.GetFragmentFilePath(), 
				  container, 
				  indices			);
  }
  
  Triangle CreateTriangle(		EDimension	 dimension, 
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

	return Triangle((GLuint)dimension, 
					(GLuint)dimension, 
					"", 
					"", 
					container, 
					indices			 );
  }
  
  Rectangle CreateRectangle(	  EDimension   dimension, 
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

	return Rectangle((GLuint)dimension, 
					 (GLuint)dimension, 
					 "", 
					 "", 
					 container, 
					 indices		  );
  }
}