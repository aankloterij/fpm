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

#include "fpm/utils.h"

#include <stdlib.h>

/**
 * @brief    Get the size of a file
 *
 * @param    file  The file descriptor
 *
 * @return   The size of the file
 */
long fpm_get_file_size(FILE *file) {
	long file_size;

	// Set the cursor to the end of the file
	if(fseek(file, 0, SEEK_END) != 0) {
		perror("fseek");
		exit(EXIT_FAILURE);
	}

	// Get the cursor position of the file
	file_size = ftell(file);

	if(file_size == -1) {
		perror("ftell");
		exit(EXIT_FAILURE);
	}

	// Reset the cursor position
	if(fseek(file, 0, SEEK_SET) != 0) {
		perror("fseek");
		exit(EXIT_FAILURE);
	}

	return file_size;
}

/**
 * @brief    Read a file into memory
 *
 * @param    filename  Path to the file
 * @param    buffer    A buffer to write the file to
 */
char *fpm_read_file(const char *filename) {
	FILE *file;
	long file_size;
	char *buffer;
	size_t read_length;

	// Open the file in read-only mode
	file = fopen(filename, "r");

	// Can't open the file
	if(file == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	// Get the file size
	file_size = fpm_get_file_size(file);

	// Allocate memory to store the file
	buffer = malloc((file_size) * sizeof(char));

	if(buffer == NULL) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	// Read the file into memory
	read_length = fread(buffer, sizeof(char), file_size, file);

	if(ferror(file) != 0) {
		perror("fread");
		exit(EXIT_FAILURE);
	}

	// Add a null terminator just to be sure
	buffer[read_length] = '\0';

	// Close the file descriptor
	fclose(file);

	return buffer;
}
