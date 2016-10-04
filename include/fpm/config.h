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

// Basic configuration options
// Can be fairly easily expanded
struct fpm_config {

	// The width of the game window in pixels
	unsigned int width;

	// The height of the window in pixels
	unsigned int height;

	// > 0 if the game should be run in fullscreen mode
	short fullscreen;
};

#endif // FPM_CONFIG_H
