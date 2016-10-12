
#include "fpm/input.h"

#include <stdlib.h>

void fpm_glfw_key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {

	if(action == GLFW_PRESS) {
		switch(key) {
			case GLFW_KEY_ESCAPE:
			case GLFW_KEY_DELETE:
				exit(0);
				break;
		}
	}
}

void fpm_glfw_mouse_pos_callback(GLFWwindow *window, double x, double y) {
	//
}

void fpm_glfw_mouse_button_callback(GLFWwindow *window, int button, int action, int mods) {
	//
}
