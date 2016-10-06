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

#ifndef FPM_CONFIG_H
#define FPM_CONFIG_H

#define FPM_CONFIG_DEFAULT_HEIGHT 800
#define FPM_CONFIG_DEFAULT_WIDTH 600
#define FPM_CONFIG_DEFAULT_FULLSCREEN 0

/**
 * @brief    A config structure
 */
struct fpm_config {

	// The width of the game window in pixels
	unsigned int width;

	// The height of the window in pixels
	unsigned int height;

	// > 0 if the game should be run in fullscreen mode
	short fullscreen;
};

/**
 * @brief    Get or create the config folder of the current user
 *           The config folder is `~/.config/fpm/`
 *
 * @param    buffer  A pointer to a reserved character array
 */
void fpm_get_config_folder(char *buffer);

/**
 * @brief    Write the default config to the config file
 *
 * @param    conf  A pointer to a `fpm_config` structure
 */
void fpm_write_config(const struct fpm_config *conf);

/**
 * @brief    Read config from the config file and write them to the structure
 *
 * @param    fpm_config  The `fpm_config` structure to write to
 */
void fpm_read_config(struct fpm_config *config);

#endif // FPM_CONFIG_H
