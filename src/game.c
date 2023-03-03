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

// Main game backend. No entire game logic but possible actions.

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "game_intern.h"
#include "helpers.h"


// Private functions

// Check if board[row][col] is already set.
int is_free(int row, int col) {
	return !(row >= n_rows || row < 0 || col >= n_cols || col < 0) && board[row][col] == 0;
}

// Check if there is a valid horizontal set 
/* 
   ---
   xxx
   ---
*/
int check_rows() {
	for (int i = 0; i < n_rows; i++) { 
		int len_set = 0; // Length of current set until cursor position
		int player_set = 0; // Owner of last field
		for (int j = 0; j < n_cols; j++) { // Every row starts in the first column
			if (board[i][j] && player_set == board[i][j]) { // if the current field belongs to the same player as the previous, we are still in the same set.
				len_set++; // So the set is longer.
				if (len_set >= n_set) return player_set; // If the set is valid, the player won.
			}
			else { // The current field belongs to no one or someone else than the previous one
				player_set = board[i][j]; // so reset current set owner
				len_set = (board[i][j] ? 1 : 0); // If it belongs to no one, there is no set, else it is the first field of a new set
			}
		}
	}
	return 0; // No one won, go on playing.
}

// Check if there is a valid vertical set
/* 
   -x-
   -x-
   -x-
*/
int check_cols() {
	// Uses same principle as check_rows but inverts row and column cursors
	for (int i = 0; i < n_cols; i++) {
		int len_set = 0;
		int player_set = 0;
		for (int j = 0; j < n_rows; j++) {
			if (board[j][i] && player_set == board[j][i]) {
				len_set++;
				if (len_set >= n_set) return player_set;
			}
			else {
				player_set = board[j][i];
				len_set = (board[j][i] ? 1 : 0);
			}
		}
	}
	return 0;
}

// Check if there is a valid diagonal set starting in the first row iterating down and right
/* 
   -x-
   --x
   ---
*/
int check_diags_fixed_row_fwd() {
	// Uses same principle as check_rows but iterates both row and column
	for (int i = 0; i <= n_cols - n_set; i++) {
		int len_set = 0;
		int player_set = 0;
		int j = 0;
		while (i+j < n_cols && j < n_rows) {
			if (board[j][i+j] && player_set == board[j][i+j]) {
				len_set++;
				if (len_set >= n_set) return player_set;
			}
			else {
				player_set = board[j][i+j];
				len_set = board[j][i+j] ? 1 : 0;
			}
			j++;
		}
	}
	return 0;
}

// Check if there is a valid diagonal set starting in the first column iterating down and right
/* 
   ---
   x--
   -x-
*/
int check_diags_fixed_col_fwd() {
	// Uses same principle as check_rows but iterates both row and column
	for (int i = 0; i <= n_rows - n_set; i++) {
		int len_set = 0;
		int player_set = 0;
		int j = 0;
		while (i+j < n_rows && j < n_cols) {
			if (board[i+j][j] && player_set == board[i+j][j]) {
				len_set++;
				if (len_set >= n_set) return player_set;
			}
			else {
				player_set = board[i+j][j];
				len_set = board[i+j][j] ? 1 : 0;
			}
			j++;
		}
	}
	return 0;
}

// Check if there is a valid diagonal set starting in the first row iterating down and left
/* 
   -x-
   x--
   ---
*/
int check_diags_fixed_row_bwd() {
	// Uses same principle as check_rows but iterates both row and column, while column is iterated backwards
	for (int i = n_cols-1; i >= n_set-1; i--) {
		int len_set = 0;
		int player_set = 0;
		int j = 0;
		while (i-j >= 0) {
			if (board[j][i-j] && player_set == board[j][i-j]) {
				len_set++;
				if (len_set >= n_set) return player_set;
			}
			else {
				player_set = board[j][i-j];
				len_set = (board[j][i-j] ? 1 : 0);
			}
			j++;
		}
	}
	return 0;
}

// Check if there is a valid diagonal set starting in the first column iterating up and right
/* 
   ---
   --x
   -x-
*/
int check_diags_fixed_col_bwd() {
	// Uses same principle as check_rows but iterates both row and column, while column is iterated backwards
	for (int i = 0; i <= n_rows - n_set; i++) { // Iterate forwards over rows
		int len_set = 0;
		int player_set = 0;
		int j = 0; // Fix last column as start point for diagonal
		while (i+j < n_rows && j < n_cols) { // Iterate backwards over columns. As we go diagonally, the number of elements in the diagonal row is determined by both, row and column starting point.
			int field = board[i+j][n_cols-j-1];
			if (field && player_set == field) {
				len_set++;
				if (len_set >= n_set) return player_set;
			}
			else {
				player_set = field;
				len_set = (field ? 1 : 0);
			}
			j++;
		}
	}
	return 0;
}

// check for a valid diagonal set
int check_diags() {
	int r;
	if ((r = check_diags_fixed_row_fwd())) return r;
	if ((r = check_diags_fixed_col_fwd())) return r;
	if ((r = check_diags_fixed_row_bwd())) return r;
	return check_diags_fixed_col_bwd();
}

// Check if there is any blank field left
int board_full() {
	for (int i = 0; i < n_rows; i++) {
		for (int j = 0; j < n_cols; j++) {
			if (board[i][j] == 0) return 0;
		}
	}
	return 1;
}

// Public functions

// Return the number of rows on the board
int get_n_rows() {
	return n_rows;
}

// Return the number of columns on the board
int get_n_cols() {
	return n_cols;
}

// Return the number of players in the game
int get_n_players() {
	return n_players;
}

// Initialize instance variables for a new game. Validate that given parameters are valid
void new_game(int rows, int cols, int len_set, int players) {
	assert(rows > 0 && cols > 0 && len_ set > 0 && players > 0);
	n_rows = rows;
	n_cols = cols;
	n_set = len_set;
	n_players = players;
	board = calloc(n_rows, sizeof(int*));
	for (int i = 0; i < n_rows; i++) {
		board[i] = calloc(n_cols, sizeof(int*));
		for (int j = 0; j < n_cols; j++) {
			board[i][j] = 0;
		}
	}
}

// Free dynamically allocated memory
void end_game() {
	free(board);
}

// Occupy field by player if it is not yet owned by anyone. Return 1 if successful, 0 otherwise.
int set(int row, int col, int player) {
	if (player < 1 || !is_free(row, col) || player > n_players) return 0;
	board[row][col] = player;
	return 1;
}

// Check if there is a valid set on the board and return the player owning it, -1 if there is a tie, 0 otherwise.
int check() {
	int r;
	if ((r = check_rows())) return r;
	if ((r = check_cols())) return r;
	if ((r = check_diags())) return r;
	return board_full() ? -1 : 0;
}

// Print a visual representation of the board to stdout. If there is 2 players, player 1 is represented by X, player 2 by O.
void print_board() {
	char *line = multiply_string("-", n_cols * 2 + 1);
	for (int i = 0; i < n_rows; i++) {
		printf("%s\n", line);
		for (int j = 0; j < n_cols; j++) {
			if (!board[i][j]) printf("| ");
			else if (n_players == 2) {
				if (board[i][j] == 1) printf("|X");
				else printf("|O");
			}
			else printf("|%d", board[i][j]);
		}
		printf("|\n");
	}
	printf("%s\n", line);
	free(line);
}