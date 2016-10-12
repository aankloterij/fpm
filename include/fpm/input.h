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

#ifndef FPM_INPUT_H
#define FPM_INPUT_H

#include <GLFW/glfw3.h>

void fpm_glfw_key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

void fpm_glfw_mouse_pos_callback(GLFWwindow *window, double x, double y);

void fpm_glfw_mouse_button_callback(GLFWwindow *window, int button, int action, int mods);

#endif // FPM_INPUT_H
