#include "Window.h"

Window::Window() { this->init(); }

Window::~Window() {}

void Window::getResolution(int* width, int* height) { glfwGetFramebufferSize(this->window, width, height); }

GLFWwindow* Window::getWindow() { return this->window; }

void Window::init()
{
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		exit(EXIT_FAILURE);
	}
	this->window = glfwCreateWindow(800, 600, "ZPG_PRO0255", NULL, NULL);
	if (!this->window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(this->window);
	glfwSwapInterval(1);
	// start GLEW extension handler
	glewExperimental = GL_TRUE;
	glewInit();

	int major, minor, revision;
	glfwGetVersion(&major, &minor, &revision);
	printf("Using GLFW %i.%i.%i\n", major, minor, revision);
	int width, height;
	glfwGetFramebufferSize(this->window, &width, &height);
	float ratio = width / (float)height;
	glViewport(0, 0, width, height);

	//glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE);
	glEnable(GL_NORMALIZE);
	glEnable(GL_STENCIL_TEST); //indentifikace objektu
	glEnable(GL_TEXTURE_2D);

	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
}