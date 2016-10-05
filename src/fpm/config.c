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

#include "fpm/config.h"

#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void read_config(const char *path, struct fpm_config *config) {
	FILE *file;
	char buffer[128];
	char *split_str;
	int line_no;

	// Open the configuration file in read-only mode
	file = fopen(path, "r");

	if(file == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	line_no = 1;

	// While we can still read from the file
	while(!feof(file)) {
		if(fgets(buffer, sizeof(buffer), file)) {
			split_str = strtok(buffer, "=");

			if(split_str == NULL) {
				printf("Failed to parse config file on line %d\n", line_no);
				exit(EXIT_FAILURE);
			}

			else if(strcmp(split_str, "width") == 0)
				config->width = atoi(strtok(NULL, "="));

			else if(strcmp(split_str, "height") == 0)
				config->height = atoi(strtok(NULL, "="));

			else if(strcmp(split_str, "fullscreen") == 0)
				config->fullscreen = atoi(strtok(NULL, "="));

			else continue;

			line_no++;
		}
	}

	printf("%d, %d, %d\n", config->width, config->height, config->fullscreen);

}
