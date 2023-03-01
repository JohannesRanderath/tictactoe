#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "game.h"
#include "helpers.h"


extern int **board;
int **board;
extern int n_rows;
int n_rows;
extern int n_cols;
int n_cols;

// Private functions
int is_free(int row, int col) {
	return !(row >= n_rows || row < 0 || col >= n_cols || col < 0) && board[row][col] == 0;
}

// Public functions

int get_n_rows() {
	return n_rows;
}

int get_n_cols() {
	return n_cols;
}

void new_game(int rows, int cols) {
	assert(rows > 0 && cols > 0);
	n_rows = rows;
	n_cols = cols;
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
	if (!is_free(row, col)) return -1;
	board[row][col] = player;
	return 0;
}

int check() {
	return -1;
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