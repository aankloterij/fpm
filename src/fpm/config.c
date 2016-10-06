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

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

/**
 * @brief    Get or create the config folder of the current user
 *           The config folder is `~/.config/fpm/`
 *
 * @param    buffer  A pointer to a reserved character array
 */
void fpm_get_config_folder(char *buffer) {
	char *home_folder;
	struct stat st;

	// The home folder to write config in
	home_folder = getenv("HOME");

	// If somehow the $HOME enviroment variable was not defined
	if(home_folder == NULL) {
		fprintf(stderr, "getenv: $HOME was not defined\n");
		exit(EXIT_FAILURE);
	}

	// Write `home_folder` to the buffer
	sprintf(buffer, "%s/.config/fpm", home_folder);

	// The directory doesn't exist (yet)
	if(stat(buffer, &st) == -1) {

		// Create the directory with the right permissions
		if(mkdir(buffer, 0755) != 0) {
			perror("mkdir");
			exit(EXIT_FAILURE);
		}

	}

}

/**
 * @brief    Write the default config to the config file
 *
 * @param    conf  A pointer to a `fpm_config` structure
 */
void fpm_write_config(const struct fpm_config *conf) {
	FILE *file;
	char buffer[64];

	fpm_get_config_folder(buffer);

	sprintf(buffer, "%s/fpm.conf", buffer);

	file = fopen(buffer, "w");

	// If opening a file fails
	if(file == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	// Write the config to the file
	sprintf(buffer, "width=%d\n", conf->width);
	fwrite(buffer, sizeof(char), strlen(buffer), file);

	sprintf(buffer, "height=%d\n", conf->height);
	fwrite(buffer, sizeof(char), strlen(buffer), file);

	sprintf(buffer, "fullscreen=%d\n", conf->fullscreen);
	fwrite(buffer, sizeof(char), strlen(buffer), file);

	// Close the file
	fclose(file);
}

/**
 * @brief    Read config from the config file and write them to the structure
 *
 * @param    fpm_config  The `fpm_config` structure to write to
 */
void fpm_read_config(struct fpm_config *config) {
	FILE *file;
	char buffer[64];
	char *split_str;
	int line_no;

	fpm_get_config_folder(buffer);

	sprintf(buffer, "%s/fpm.conf", buffer);

	// The file doesn't exist
	if(access(buffer, F_OK) != 0) {
		struct fpm_config default_config = {
			FPM_CONFIG_DEFAULT_HEIGHT,
			FPM_CONFIG_DEFAULT_WIDTH,
			FPM_CONFIG_DEFAULT_FULLSCREEN
		};

		fpm_write_config(&default_config);
	}

	// Open the configuration file in read-only mode
	file = fopen(buffer, "r");

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
}
