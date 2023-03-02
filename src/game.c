#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "game_intern.h"
#include "helpers.h"


// Private functions
int is_free(int row, int col) {
	return !(row >= n_rows || row < 0 || col >= n_cols || col < 0) && board[row][col] == 0;
}

int check_rows() {
	for (int i = 0; i < n_rows; i++) {
		int len_set = 0;
		int player_set = 0;
		for (int j = 0; j < n_cols; j++) {
			if (board[i][j] && player_set == board[i][j]) {
				len_set++;
				if (len_set >= n_set) return player_set;
			}
			else {
				player_set = board[i][j];
				len_set = (board[i][j] ? 1 : 0);
			}
		}
	}
	return 0;
}

int check_cols() {
	for (int i = 0; i < n_cols; i++) {
		int len_set = 0;
		int player_set = 0;
		for (int j = 0; j < n_rows; j++) {
			if (player_set == board[j][i]) {
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

int check_diags() {
	for (int i = 0; i < n_cols - n_set; i++) {
		int len_set = 0;
		int player_set = 0;
		int j = 0;
		while (i+j < n_cols && j < n_rows) {
			if (player_set == board[j][i+j]) {
				len_set++;
				if (len_set >= n_set) return player_set;
			}
			else {
				player_set = board[j][i+j];
				len_set = (board[j][i+j] ? 1 : 0);
			}
			j++;
		}
	}
	for (int i = 0; i < n_cols - n_set; i++) {
		int len_set = 0;
		int player_set = 0;
		int j = 0;
		while (i+j < n_rows && j < n_cols) {
			if (player_set == board[i+j][j]) {
				len_set++;
				if (len_set >= n_set) return player_set;
			}
			else {
				player_set = board[i+j][j];
				len_set = (board[i+j][j] ? 1 : 0);
			}
			j++;
		}
	}
	for (int i = n_cols-1; i >= n_set; i--) {
		int len_set = 0;
		int player_set = 0;
		int j = 0;
		while (j-i >= 0) {
			if (player_set == board[j][i-j]) {
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
	for (int i = n_cols-1; i >= n_set; i--) {
		int len_set = 0;
		int player_set = 0;
		int j = 0;
		while (j-i >= 0) {
			if (player_set == board[j][i-j]) {
				len_set++;
				if (len_set >= n_set) return player_set;
			}
			else {
				player_set = board[i-j][j];
				len_set = (board[i-j][j] ? 1 : 0);
			}
			j++;
		}
	}
	return 0;
}

// Public functions

int get_n_rows() {
	return n_rows;
}

int get_n_cols() {
	return n_cols;
}

void new_game(int rows, int cols, int len_set, int players) {
	assert(rows > 0 && cols > 0 && set > 0);
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

void end_game() {
	free(board);
}

int set(int row, int col, int player) {
	if (player < 1 || !is_free(row, col)) return -1;
	board[row][col] = player;
	return 0;
}

int check() {
	int rows = check_rows();
	if (rows) return rows;
	int cols = check_cols();
	if (cols) return cols;
	return check_diags();
}

void print_board() {
	char *line = multiply_string("-", n_cols * 2 + 1);
	for (int i = 0; i < n_rows; i++) {
		printf("%s\n", line);
		for (int j = 0; j < n_cols; j++) {
			printf("|%d", board[i][j]);
		}
		printf("|\n");
	}
	printf("%s\n", line);
	free(line);
}