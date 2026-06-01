#pragma once 
#include "initializator.hpp"

void renderingCommands(GLFWwindow* window) {
	// here goes the rendering commands
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT); // can also use glclearcolor

	glfwSwapBuffers(window);

}
