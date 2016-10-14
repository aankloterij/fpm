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

#include <GL/glew.h>
#include <GL/gl.h>

#include "fpm/fpm.h"
#include "fpm/config.h"
#include "fpm/error.h"
#include "fpm/input.h"
#include "fpm/render.h"
#include "fpm/shaders.h"

#include <stdlib.h>
#include <stdio.h>

static double time, old_time;
static int no_frames;
static GLuint program_id;

void init(int argc, char* const* argv) {
	GLenum glew_err;

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

	glewExperimental = GL_TRUE;

	glew_err = glewInit();

	if(glew_err != GLEW_OK) {
		fprintf(stderr, "GLEW: %s\n", glewGetErrorString(glew_err));
	}

	time = glfwGetTime();

	program_id = glCreateProgram();

	fpm_load_vertex_shader("../res/shaders/vertex_shader.vert");
	fpm_load_fragment_shader("../res/shaders/fragment_shader.frag");

	fpm_link_shaders();
}

void loop() {
	init_render();

	while(!glfwWindowShouldClose(window)) {

		no_frames++;

		time = glfwGetTime();

		// FPS Counter
		if(time - old_time >= 1.0) {
			printf("%.2f ms/frame, %.1f fps\n", (1000 / ((double) no_frames)), (((double) no_frames)));
			no_frames = 0;
			old_time += 1.0;
		}

		render(time);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}
}

void stop() {
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(0);
}

GLuint get_program_id() {
	return program_id;
}
