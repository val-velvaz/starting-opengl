#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


#include "initializator.hpp"	
#include "input.hpp"
#include "rendering_commands.hpp"


// resize a window
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void renderLoop(GLFWwindow* window) {
	while (!glfwWindowShouldClose(window)) {
		//input
		inputProcessing(window);

		//rendering commands 
		renderingCommands(window);

		//check and call events and swap the buffers
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
}

int inicializator() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//windowing data & glfws functions
	GLFWwindow* window = glfwCreateWindow(800, 600, "Window", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	//calling glad before opengl
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}


	//rendering window size
	glViewport(0, 0, 800, 600); // px
	// set equal to glfws window sie

	// could make a window object

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// RENDER LOOP
	renderingCommands(window);

	glfwTerminate(); // raii
}
