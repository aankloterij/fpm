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

#ifndef FPM_FPM_H
#define FPM_FPM_H

#include <GLFW/glfw3.h>

#define FPM_OPENGL_MAJOR 2
#define FPM_OPENGL_MINOR 1

struct fpm_config *config;

GLFWwindow *window;

void init(int argc, char* const *argv);

void loop();

void stop();

#endif // FPM_FPM_H
