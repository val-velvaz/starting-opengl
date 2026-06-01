#pragma once 
#include "initializator.hpp"
#include "Triangle.hpp"

void renderingCommands(GLFWwindow* window) {
	// here goes the rendering commands
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT); // can also use glclearcolor

	{// first ogl object
		unsigned int VBO;
		glGenBuffers(1, &VBO);

		//bind the newly created buffer 
		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		Triangle little_bich;

		// copy the vertex into the buffers memory
		glBufferData(GL_ARRAY_BUFFER, sizeof(Triangle::vertices), little_bich.vertices.data(), GL_STATIC_DRAW);
	}

	glfwSwapBuffers(window);

}
