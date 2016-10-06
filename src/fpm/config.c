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
#include <sys/stat.h>

// TODO This is a mess, fix it

static void fpm_write_default_config(void) {
	FILE *file;
	char *buffer;
	struct fpm_config default_config = {800, 600, 0};

	buffer = malloc(32 * sizeof(char));

	snprintf(buffer, 32, "%s/.config/fpm", getenv("HOME"));

	// Create the fpm config directory
	if(mkdir(buffer, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) != 0) {
		perror("mkdir");
		exit(EXIT_FAILURE);
	}

	snprintf(buffer, 32, "%s/.config/fpm/fpm.conf", getenv("HOME"));

	// Open the configuration file in write mode
	file = fopen(buffer, "w");

	if(file == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	snprintf(buffer, 32, "width=%d\n", default_config.width);
	fwrite(buffer, sizeof(char), 32, file);

	snprintf(buffer, 32, "height=%d\n", default_config.height);
	fwrite(buffer, sizeof(char), 32, file);

	snprintf(buffer, 32, "fullscreen=%d\n", default_config.fullscreen);
	fwrite(buffer, sizeof(char), 32, file);

	fclose(file);

	free(buffer);
}

void fpm_read_config(struct fpm_config *config) {
	FILE *file;
	char buffer[128];
	char *split_str;
	int line_no;

	// Open the configuration file in read-only mode
	file = fopen("~/.config/fpm/fpm.conf", "r");

	// The file doesn't exist
	if(file == NULL)
		fpm_write_default_config();

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
}
