#include "fpm/render.h"

#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

static GLuint vertex_array_object, vertex_buffer;

static const GLfloat vert_buffer_data[] = {
	-1.0f, -1.0f, 0.0f,
	1.0f, -1.0f, 0.0f,
	0.0f,  1.0f, 0.0f
};

void init_render() {

	glGenVertexArrays(1, &vertex_array_object);

	glBindVertexArray(vertex_array_object);

	glGenBuffers(1, &vertex_buffer);

	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vert_buffer_data), vert_buffer_data, GL_STATIC_DRAW);
}

void render(double time) {

	glClear(GL_COLOR_BUFFER_BIT);

	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *) 0);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glDisableVertexAttribArray(0);
}
