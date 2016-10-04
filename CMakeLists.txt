# FPM -  First Person Marc
# Because no existing genre can satisfy Marc's wishes -  probably for good reason
#
# Copyright (C) 2016  Max Verbeek & Sibren Talens
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http:#www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 2.8)

project(fpm C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m64")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -Wall -Wextra -Wpedantic -Wfatal-errors -pedantic -Wno-unused-parameter")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O3")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

file(GLOB_RECURSE FPM_TARGETS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")

add_executable(fpm ${FPM_TARGETS})

target_link_libraries(fpm
	glfw
	GLEW
	GL
)
