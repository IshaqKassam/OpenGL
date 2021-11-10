#include <stdio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../External Resources/GLFW/include/GLFW/glfw3.h"
#include "../External Resources/GLEW/include/GL/glew.h"

//window dimensions
const GLint WIDTH = 800, HEIGHT = 600;

int main() {
	//initialize glfw
	if (!glfwInit()) {
		printf("GLFW initialisation failed");
		glfwTerminate();
		return 1;
	}

	//setup GLFW window properties
	//OpenGL version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//core profile = No backwards compatibility
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);//So that depracated feaures are not used
	//Allow forward compatibility
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "My Window", NULL, NULL);

	if (!mainWindow) {
		printf("window creation failed");
		glfwTerminate();
		return 1;
	}

	//Get buffer size information
	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);


	//Set context for GLEW to use
	glfwMakeContextCurrent(mainWindow);

	//Allow modern extension features
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK) {
		printf("glew initializing failed");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	//Setup Viewport size

	glViewport(0, 0, bufferWidth, bufferHeight);

	//Loop until window closed
	while (!glfwWindowShouldClose(mainWindow)) {
		//Get + Handle user input events

		glfwPollEvents();

		//Clear window
		glClearColor(1.0f, 0.0f, 0.0f, 0.5f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(mainWindow);
	}

	return 0;
}