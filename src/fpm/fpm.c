// FPM -  First Person Marc
// Because no existing genre can satisfy Marc's wishes -  probably for good reason
//
// Copyright (C) 2016  Max Verbeek & Sibren Talens
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "fpm/fpm.h"
#include "fpm/config.h"
#include "fpm/error.h"

#include <stdlib.h>
#include <GL/gl.h>

void init(int argc, char* const* argv) {

	config = malloc(sizeof(struct fpm_config));

	// Set the GLFW callback
	glfwSetErrorCallback(glfw_error_callback);

	// Initialize GLFW
	if(!glfwInit())
		exit(EXIT_FAILURE);

	glfwWindowHint(GLFW_SAMPLES, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, FPM_OPENGL_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, FPM_OPENGL_MINOR);

	read_config("../res/fpm.conf", config);

	if(config->fullscreen > 0)
		window = glfwCreateWindow(config->width, config->height, "FPM", glfwGetPrimaryMonitor(), NULL);
	else
		window = glfwCreateWindow(config->width, config->height, "FPM", NULL, NULL);

	glfwMakeContextCurrent(window);

}

void loop() {
	while(!glfwWindowShouldClose(window)) {

		glClear(GL_COLOR_BUFFER_BIT);

		glClearColor(1, 1, 1, 1);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}
}

void stop() {
	glfwTerminate();
}
