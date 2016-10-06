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

#ifndef FPM_UTILS_H
#define FPM_UTILS_H

#include <stdio.h>

/**
 * @brief    Get the size of a file
 *
 * @param    file  The file descriptor
 *
 * @return   The size of the file
 */
long fpm_get_file_size(FILE *file);

/**
 * @brief    Read a file into memory
 *
 * @param    filename  Path to the file
 *
 * @return   A pointer to the file in memory
 */
char *fpm_read_file(const char *filename);

#endif // FPM_UTILS_H
