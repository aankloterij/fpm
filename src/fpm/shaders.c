#include <GL/glew.h>
#include <GL/gl.h>

#include "fpm/shaders.h"
#include "fpm/utils.h"
#include "fpm/fpm.h"

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <string.h>

void fpm_load_shader(GLenum type, const char *path) {
	GLuint shader_id;
	char *buffer;
	char const *shader_source;
	GLint result;
	int info_log_len;
	GLint prog_id;

	result = GL_FALSE;

	info_log_len = 0;

	shader_id = glCreateShader(type);

	buffer = fpm_read_file(path);

	shader_source = buffer;

	glShaderSource(shader_id, 1, &shader_source, NULL);

	glCompileShader(shader_id);

	// Check for compilation errors
	glGetShaderiv(shader_id, GL_COMPILE_STATUS, &result);
	glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &info_log_len);

	if(result == GL_TRUE) {
		char *shader_err = malloc((info_log_len + 1) * sizeof(char));

		if(shader_err == NULL) {
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		glGetShaderInfoLog(shader_id, info_log_len, NULL, shader_err);

		printf("Error compiling %s shaders: %s\n", type == FPM_SHADER_TYPE_VERTEX ? "vertex" : "fragment", shader_err);

		free(shader_err);

		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	prog_id = get_program_id();

	glAttachShader(prog_id, shader_id);

	free(buffer);
}

void fpm_load_vertex_shader(const char *path) {
	fpm_load_shader(FPM_SHADER_TYPE_VERTEX, path);
}

void fpm_load_fragment_shader(const char *path) {
	fpm_load_shader(FPM_SHADER_TYPE_FRAGMENT, path);
}

void fpm_link_shaders(void) {
	GLuint prog_id;
	GLint result;
	int info_log_len;

	result = GL_FALSE;

	info_log_len = 0;

	prog_id = get_program_id();

	glLinkProgram(prog_id);

	glGetProgramiv(prog_id, GL_LINK_STATUS, &result);
	glGetProgramiv(prog_id, GL_INFO_LOG_LENGTH, &info_log_len);

	if(result == GL_TRUE) {
		printf("%d\n", info_log_len);

		char *shader_err = malloc(info_log_len * sizeof(char));

		glGetProgramInfoLog(prog_id, info_log_len, NULL, shader_err);

		fprintf(stderr, "Error linking shaders: %s\n", shader_err);

		free(shader_err);

		glfwTerminate();
		exit(EXIT_FAILURE);
	}
}
