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

int check_diags_fixed_row_fwd() {
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

int check_diags_fixed_col_fwd() {
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

int check_diags_fixed_row_bwd() {
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

int check_diags_fixed_col_bwd() {
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

int check_diags() {
	int r;
	if ((r = check_diags_fixed_row_fwd())) return r;
	if ((r = check_diags_fixed_col_fwd())) return r;
	if ((r = check_diags_fixed_row_bwd())) return r;
	return check_diags_fixed_col_bwd();
}

int board_full() {
	for (int i = 0; i < n_rows; i++) {
		for (int j = 0; j < n_cols; j++) {
			if (board[i][j] == 0) return 0;
		}
	}
	return 1;
}

// Public functions

int get_n_rows() {
	return n_rows;
}

int get_n_cols() {
	return n_cols;
}

int get_n_players() {
	return n_players;
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
	if (player < 1 || !is_free(row, col) || player > n_players) return 0;
	board[row][col] = player;
	return 1;
}

int check() {
	int r;
	if ((r = check_rows())) return r;
	if ((r = check_cols())) return r;
	if ((r = check_diags())) return r;
	return board_full() ? -1 : 0;
}

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