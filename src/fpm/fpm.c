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
#include "fpm/input.h"

#include <stdlib.h>
#include <stdio.h>
#include <GL/gl.h>

static double time, old_time;
static int no_frames;

void init(int argc, char* const* argv) {

	config = malloc(sizeof(struct fpm_config));

	// Set the GLFW callback
	glfwSetErrorCallback(fpm_glfw_error_callback);

	// Initialize GLFW
	if(!glfwInit())
		exit(EXIT_FAILURE);

	fpm_read_config(config);

	glfwWindowHint(GLFW_SAMPLES, config->samples);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, FPM_OPENGL_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, FPM_OPENGL_MAJOR);

	if(config->fullscreen > 0)
		window = glfwCreateWindow(config->width, config->height, "FPM", glfwGetPrimaryMonitor(), NULL);
	else
		window = glfwCreateWindow(config->width, config->height, "FPM", NULL, NULL);

	glfwMakeContextCurrent(window);

	glfwSetKeyCallback(window, fpm_glfw_key_callback);
	glfwSetCursorPosCallback(window, fpm_glfw_mouse_pos_callback);
	glfwSetMouseButtonCallback(window, fpm_glfw_mouse_button_callback);

	time = glfwGetTime();
}

void loop() {
	while(!glfwWindowShouldClose(window)) {

		render(time);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}
}

void render(double time) {
	no_frames++;

	time = glfwGetTime();

	if(time - old_time >= 1.0) {
		printf("%.2f ms/frame, %.1f fps\n", (1000 / ((double) no_frames)), (((double) no_frames)));
		no_frames = 0;
		old_time += 1.0;
	}

	glClear(GL_COLOR_BUFFER_BIT);

	glClearColor(0.98, 0.625, 0.12, 1);

}

void stop() {
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(0);
}
