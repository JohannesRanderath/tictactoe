#include "game_intern.h"
#include <assert.h>
#include <stdio.h>

void test_get_n_rows() {
	new_game(3,3);
	assert(get_n_rows() == 3);
	end_game();
	new_game(1, 5);
	assert(get_n_rows() == 1);
	end_game();
	new_game(9, 1);
	assert(get_n_rows() == 9);
	end_game();
	new_game(8,7);
	assert(get_n_rows() == 8);
	end_game();
	printf("get_n_rows OK.\n");
}

void test_get_n_cols() {
	new_game(3,3);
	assert(get_n_cols() == 3);
	end_game();
	new_game(1, 5);
	assert(get_n_cols() == 5);
	end_game();
	new_game(1, 9);
	assert(get_n_cols() == 9);
	end_game();
	new_game(7,7);
	assert(get_n_cols() == 7);
	end_game();
	printf("get_n_cols OK.\n");
}

void test_set() {
	new_game(5, 7);
	assert(set(0,0,1) == 0);
	assert(board[0][0] == 1);
	assert(set(0,0,2) == -1);
	assert(board[0][0] == 1);
	assert(set(0,3,1) == 0);
	assert(board[0][3] == 1);
	assert(set(3,5,4) == 0);
	assert(board[3][5] == 4);
	assert(set(6,0,1) == -1);
	end_game();
	printf("set OK.\n");
}

void test_check() {
	new_game(3,3);

	end_game();
}
