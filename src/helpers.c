/*  A simple Tic Tac Toe implementation in the C language + a command line interface.
    Copyright (C) 2023 Johannes Randerath

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

// Simple auxiliary functions to use

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Concat string n times with itself.
char *multiply_string(char *s, int n) {
	char *result = calloc(n * strlen(s), sizeof(char));
	for (int i = 0; i < n; i++) {
		sprintf(result, "%s%s", result, s);
	}
	return result;
}

// Return smaller of two values
int min(int a, int b) {
	return a < b ? a : b;
}

// Return greater of two values
int max(int a, int b) {
	return a > b ? a : b;
}
