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

// Test different public and private functions of game.c. 

#include "game_intern.h"
#include <assert.h>
#include <stdio.h>

void test_get_n_rows() {
	new_game(3,3,3,2);
	assert(get_n_rows() == 3);
	end_game();
	new_game(1,5,3,2);
	assert(get_n_rows() == 1);
	end_game();
	new_game(9,1,3,2);
	assert(get_n_rows() == 9);
	end_game();
	new_game(8,7,3,2);
	assert(get_n_rows() == 8);
	end_game();
	printf("get_n_rows OK.\n");
}

void test_get_n_cols() {
	new_game(3,3,3,2);
	assert(get_n_cols() == 3);
	end_game();
	new_game(1,5,3,2);
	assert(get_n_cols() == 5);
	end_game();
	new_game(1,9,3,2);
	assert(get_n_cols() == 9);
	end_game();
	new_game(7,7,3,2);
	assert(get_n_cols() == 7);
	end_game();
	printf("get_n_cols OK.\n");
}

void test_set() {
	new_game(5,7,3,2);
	assert(set(0,0,1) == 1);
	assert(board[0][0] == 1);
	assert(set(0,0,2) == 0);
	assert(board[0][0] == 1);
	assert(set(0,3,1) == 1);
	assert(board[0][3] == 1);
	assert(set(3,5,4) == 0);
	assert(set(6,0,1) == 0);
	end_game();
	printf("set OK.\n");
}

void test_check_rows() {
	new_game(3,3,2,2);
	set(0,0,0); set(0,1,0); set(0,2,0);
	set(1,0,0); set(1,1,0); set(1,2,0);
	set(2,0,0); set(2,1,2); set(2,2,2);
	assert(check_rows() == 2);
	end_game();
	new_game(3,3,2,2);
	set(0,0,1); set(0,1,1); set(0,2,0);
	set(1,0,0); set(1,1,0); set(1,2,0);
	set(2,0,0); set(2,1,0); set(2,2,2);
	assert(check_rows() == 1);
	end_game();
	new_game(3,3,2,2);
	set(0,0,0); set(0,1,1); set(0,2,1);
	set(1,0,0); set(1,1,0); set(1,2,0);
	set(2,0,0); set(2,1,0); set(2,2,2);
	assert(check_rows() == 1);
	end_game();
	new_game(3,3,2,2);
	set(0,0,0); set(0,1,1); set(0,2,0);
	set(1,0,0); set(1,1,0); set(1,2,1);
	set(2,0,0); set(2,1,2); set(2,2,2);
	assert(check_rows() == 2);
	end_game();
	new_game(3,3,2,2);
	set(0,0,0); set(0,1,0); set(0,2,0);
	set(1,0,0); set(1,1,0); set(1,2,2);
	set(2,0,0); set(2,1,0); set(2,2,2);
	assert(check_rows() == 0);
	end_game();
	new_game(3,3,2,2);
	set(0,0,0); set(0,1,0); set(0,2,0);
	set(1,0,2); set(1,1,0); set(1,2,0);
	set(2,0,0); set(2,1,2); set(2,2,0);
	assert(check_rows() == 0);
	end_game();
	new_game(6,5,3,4);
	set(0,0,0); set(0,1,0); set(0,2,0); set(0,3,0); set(0,4,0);
	set(1,0,0); set(1,1,0); set(1,2,0); set(1,3,0); set(1,4,0);
	set(2,0,0); set(2,1,0); set(2,2,2); set(2,3,0); set(2,4,0);
	set(3,0,0); set(3,1,0); set(3,2,0); set(3,3,0); set(3,4,0);
	set(4,0,0); set(4,1,1); set(4,2,1); set(4,3,1); set(4,4,0);
	set(5,0,0); set(5,1,2); set(5,2,0); set(5,3,0); set(5,4,0);
	assert(check_rows() == 1);
	end_game();
	new_game(6,5,3,4);
	set(0,0,1); set(0,1,2); set(0,2,3); set(0,3,4); set(0,4,1);
	set(1,0,2); set(1,1,3); set(1,2,4); set(1,3,1); set(1,4,2);
	set(2,0,3); set(2,1,4); set(2,2,4); set(2,3,4); set(2,4,1);
	set(3,0,4); set(3,1,3); set(3,2,2); set(3,3,1); set(3,4,1);
	set(4,0,2); set(4,1,1); set(4,2,1); set(4,3,1); set(4,4,1);
	set(5,0,4); set(5,1,2); set(5,2,2); set(5,3,1); set(5,4,2);
	assert(check_rows() == 4);
	end_game();
	new_game(6,5,3,4);
	set(0,0,0); set(0,1,0); set(0,2,0); set(0,3,0); set(0,4,0);
	set(1,0,0); set(1,1,0); set(1,2,0); set(1,3,0); set(1,4,0);
	set(2,0,0); set(2,1,1); set(2,2,2); set(2,3,1); set(2,4,0);
	set(3,0,0); set(3,1,0); set(3,2,1); set(3,3,1); set(3,4,0);
	set(4,0,0); set(4,1,0); set(4,2,1); set(4,3,1); set(4,4,0);
	set(5,0,0); set(5,1,2); set(5,2,0); set(5,3,0); set(5,4,0);
	assert(check_rows() == 0);
	end_game();
	printf("check_rows OK.\n");
}

void test_check_cols() {
	new_game(3,3,2,2);
	set(0,0,0); set(0,1,0); set(0,2,0);
	set(1,0,0); set(1,1,2); set(1,2,0);
	set(2,0,0); set(2,1,2); set(2,2,0);
	assert(check_cols() == 2);
	end_game();
	new_game(3,3,2,2);
	set(0,0,2); set(0,1,1); set(0,2,0);
	set(1,0,0); set(1,1,1); set(1,2,0);
	set(2,0,0); set(2,1,0); set(2,2,2);
	assert(check_cols() == 1);
	end_game();
	new_game(3,3,2,2);
	set(0,0,2); set(0,1,2); set(0,2,0);
	set(1,0,0); set(1,1,1); set(1,2,2);
	set(2,0,0); set(2,1,0); set(2,2,2);
	assert(check_cols() == 2);
	end_game();
	new_game(3,3,2,2);
	set(0,0,0); set(0,1,0); set(0,2,0);
	set(1,0,0); set(1,1,0); set(1,2,0);
	set(2,0,0); set(2,1,2); set(2,2,2);
	assert(check_cols() == 0);
	end_game();
	new_game(3,3,2,2);
	set(0,0,0); set(0,1,0); set(0,2,0);
	set(1,0,2); set(1,1,0); set(1,2,0);
	set(2,0,0); set(2,1,2); set(2,2,0);
	assert(check_cols() == 0);
	end_game();
	new_game(6,5,3,4);
	set(0,0,0); set(0,1,0); set(0,2,0); set(0,3,0); set(0,4,0);
	set(1,0,1); set(1,1,1); set(1,2,0); set(1,3,0); set(1,4,0);
	set(2,0,0); set(2,1,4); set(2,2,2); set(2,3,2); set(2,4,0);
	set(3,0,0); set(3,1,4); set(3,2,0); set(3,3,0); set(3,4,1);
	set(4,0,0); set(4,1,4); set(4,2,1); set(4,3,1); set(4,4,0);
	set(5,0,0); set(5,1,2); set(5,2,0); set(5,3,0); set(5,4,1);
	assert(check_cols() == 4);
	end_game();
	new_game(6,5,3,4);
	set(0,0,1); set(0,1,2); set(0,2,3); set(0,3,4); set(0,4,1);
	set(1,0,2); set(1,1,3); set(1,2,4); set(1,3,1); set(1,4,2);
	set(2,0,3); set(2,1,4); set(2,2,4); set(2,3,4); set(2,4,3);
	set(3,0,4); set(3,1,3); set(3,2,2); set(3,3,1); set(3,4,3);
	set(4,0,2); set(4,1,1); set(4,2,1); set(4,3,2); set(4,4,3);
	set(5,0,4); set(5,1,2); set(5,2,2); set(5,3,1); set(5,4,2);
	assert(check_cols() == 3);
	end_game();
	new_game(6,5,3,4);
	set(0,0,0); set(0,1,0); set(0,2,0); set(0,3,0); set(0,4,0);
	set(1,0,0); set(1,1,0); set(1,2,0); set(1,3,0); set(1,4,0);
	set(2,0,0); set(2,1,1); set(2,2,2); set(2,3,1); set(2,4,0);
	set(3,0,0); set(3,1,0); set(3,2,1); set(3,3,0); set(3,4,0);
	set(4,0,0); set(4,1,0); set(4,2,1); set(4,3,1); set(4,4,0);
	set(5,0,0); set(5,1,2); set(5,2,2); set(5,3,2); set(5,4,0);
	assert(check_cols() == 0);
	end_game();
	printf("check_cols OK.\n");
}

void test_check_diags_fixed_row_fwd() {
	new_game(3,3,2,2);
	set(0,0,2); set(0,1,0); set(0,2,0);
	set(1,0,0); set(1,1,2); set(1,2,0);
	set(2,0,0); set(2,1,1); set(2,2,0);
	assert(check_diags_fixed_row_fwd() == 2);
	end_game();
	new_game(3,3,2,2);
	set(0,0,1); set(0,1,2); set(0,2,0);
	set(1,0,0); set(1,1,1); set(1,2,0);
	set(2,0,0); set(2,1,0); set(2,2,1);
	assert(check_diags_fixed_row_fwd() == 1);
	end_game();
	new_game(3,3,2,2);
	set(0,0,0); set(0,1,2); set(0,2,0);
	set(1,0,1); set(1,1,0); set(1,2,2);
	set(2,0,0); set(2,1,1); set(2,2,1);
	assert(check_diags_fixed_row_fwd() == 2);
	end_game();
	new_game(3,3,2,2);
	set(0,0,0); set(0,1,1); set(0,2,0);
	set(1,0,0); set(1,1,0); set(1,2,1);
	set(2,0,0); set(2,1,2); set(2,2,2);
	assert(check_diags_fixed_row_fwd() == 1);
	end_game();
	new_game(3,3,2,2);
	set(0,0,0); set(0,1,0); set(0,2,0);
	set(1,0,2); set(1,1,0); set(1,2,0);
	set(2,0,2); set(2,1,0); set(2,2,0);
	assert(check_diags_fixed_row_fwd() == 0);
	end_game();
	printf("check_diags_fixed_row_fwd OK.\n");
}

void test_check_diags_fixed_col_fwd() {
	new_game(3,3,2,2);
	set(0,0,2); set(0,1,0); set(0,2,0);
	set(1,0,0); set(1,1,2); set(1,2,0);
	set(2,0,0); set(2,1,0); set(2,2,2);
	assert(check_diags_fixed_col_fwd() == 2);
	end_game();
	new_game(3,3,2,2);
	set(0,0,0); set(0,1,0); set(0,2,0);
	set(1,0,1); set(1,1,2); set(1,2,0);
	set(2,0,0); set(2,1,1); set(2,2,0);
	assert(check_diags_fixed_col_fwd() == 1);
	end_game();
	new_game(3,3,2,2);
	set(0,0,2); set(0,1,2); set(0,2,0);
	set(1,0,0); set(1,1,2); set(1,2,2);
	set(2,0,0); set(2,1,0); set(2,2,1);
	assert(check_diags_fixed_col_fwd() == 2);
	end_game();
	new_game(3,3,2,2);
	set(0,0,0); set(0,1,0); set(0,2,0);
	set(1,0,0); set(1,1,2); set(1,2,0);
	set(2,0,0); set(2,1,1); set(2,2,2);
	assert(check_diags_fixed_col_fwd() == 2);
	end_game();
	new_game(3,3,2,2);
	set(0,0,0); set(0,1,1); set(0,2,0);
	set(1,0,2); set(1,1,0); set(1,2,1);
	set(2,0,0); set(2,1,2); set(2,2,0);
	assert(check_diags_fixed_col_fwd() == 2);
	end_game();
	printf("check_diags_fixed_col_fwd OK.\n");
}

void test_check_diags_fixed_row_bwd() {
	new_game(3,3,2,2);
	set(0,0,0); set(0,1,0); set(0,2,2);
	set(1,0,0); set(1,1,2); set(1,2,0);
	set(2,0,0); set(2,1,2); set(2,2,0);
	assert(check_diags_fixed_row_bwd() == 2);
	end_game();
	new_game(3,3,2,2);
	set(0,0,2); set(0,1,2); set(0,2,0);
	set(1,0,0); set(1,1,1); set(1,2,0);
	set(2,0,1); set(2,1,0); set(2,2,2);
	assert(check_diags_fixed_row_bwd() == 1);
	end_game();
	new_game(3,3,2,2);
	set(0,0,0); set(0,1,2); set(0,2,0);
	set(1,0,2); set(1,1,1); set(1,2,2);
	set(2,0,0); set(2,1,0); set(2,2,2);
	assert(check_diags_fixed_row_bwd() == 2);
	end_game();
	new_game(3,3,2,2);
	set(0,0,0); set(0,1,0); set(0,2,0);
	set(1,0,0); set(1,1,0); set(1,2,2);
	set(2,0,0); set(2,1,2); set(2,2,2);
	assert(check_diags_fixed_row_bwd() == 0);
	end_game();
	new_game(3,3,2,2);
	set(0,0,0); set(0,1,0); set(0,2,1);
	set(1,0,2); set(1,1,0); set(1,2,1);
	set(2,0,0); set(2,1,2); set(2,2,2);
	assert(check_diags_fixed_row_bwd() == 0);
	end_game();
	printf("check_diags_fixed_row_bwd OK.\n");
}

void test_check_diags_fixed_col_bwd() {
	new_game(3,3,2,2);
	set(0,0,0); set(0,1,0); set(0,2,0);
	set(1,0,0); set(1,1,1); set(1,2,0);
	set(2,0,1); set(2,1,2); set(2,2,0);
	assert(check_diags_fixed_col_bwd() == 1);
	end_game();
	new_game(3,3,2,2);
	set(0,0,1); set(0,1,1); set(0,2,2);
	set(1,0,0); set(1,1,2); set(1,2,0);
	set(2,0,0); set(2,1,0); set(2,2,2);
	assert(check_diags_fixed_col_bwd() == 2);
	end_game();
	new_game(3,3,2,2);
	set(0,0,2); set(0,1,2); set(0,2,0);
	set(1,0,0); set(1,1,2); set(1,2,1);
	set(2,0,0); set(2,1,1); set(2,2,2);
	assert(check_diags_fixed_col_bwd() == 1);
	end_game();
	new_game(3,3,2,2);
	set(0,0,0); set(0,1,1); set(0,2,0);
	set(1,0,1); set(1,1,0); set(1,2,0);
	set(2,0,0); set(2,1,2); set(2,2,2);
	assert(check_diags_fixed_col_bwd() == 0);
	end_game();
	new_game(3,3,2,2);
	set(0,0,2); set(0,1,1); set(0,2,1);
	set(1,0,2); set(1,1,0); set(1,2,1);
	set(2,0,2); set(2,1,2); set(2,2,2);
	assert(check_diags_fixed_col_bwd() == 0);
	end_game();
	printf("check_diags_fixed_col_bwd OK.\n");
}

void test_check_diags() {
	new_game(3,3,2,2);
	set(0,0,0); set(0,1,0); set(0,2,0);
	set(1,0,0); set(1,1,2); set(1,2,0);
	set(2,0,0); set(2,1,0); set(2,2,2);
	assert(check_diags() == 2);
	end_game();
	new_game(3,3,2,2);
	set(0,0,2); set(0,1,0); set(0,2,0);
	set(1,0,1); set(1,1,1); set(1,2,0);
	set(2,0,0); set(2,1,1); set(2,2,0);
	assert(check_diags() == 1);
	end_game();
	new_game(3,3,2,2);
	set(0,0,2); set(0,1,1); set(0,2,0);
	set(1,0,1); set(1,1,1); set(1,2,0);
	set(2,0,0); set(2,1,0); set(2,2,0);
	assert(check_diags() == 1);
	end_game();
	new_game(3,3,2,2);
	set(0,0,0); set(0,1,0); set(0,2,0);
	set(1,0,0); set(1,1,2); set(1,2,0);
	set(2,0,0); set(2,1,2); set(2,2,2);
	assert(check_diags() == 2);
	end_game();
	new_game(3,3,2,2);
	set(0,0,0); set(0,1,0); set(0,2,0);
	set(1,0,1); set(1,1,0); set(1,2,0);
	set(2,0,1); set(2,1,2); set(2,2,0);
	assert(check_diags() == 0);
	end_game();
	new_game(3,3,3,2);
	set(0,0,2); set(0,1,0); set(0,2,0);
	set(1,0,0); set(1,1,2); set(1,2,0);
	set(2,0,0); set(2,1,0); set(2,2,2);
	assert(check_diags() == 2);
	end_game();
	new_game(3,3,3,2);
	set(0,0,2); set(0,1,0); set(0,2,0);
	set(1,0,1); set(1,1,1); set(1,2,0);
	set(2,0,0); set(2,1,1); set(2,2,0);
	assert(check_diags() == 0);
	end_game();
	new_game(3,3,3,2);
	set(0,0,2); set(0,1,1); set(0,2,0);
	set(1,0,1); set(1,1,1); set(1,2,0);
	set(2,0,0); set(2,1,0); set(2,2,0);
	assert(check_diags() == 0);
	end_game();
	new_game(6,5,3,4);
	set(0,0,0); set(0,1,0); set(0,2,0); set(0,3,0); set(0,4,0);
	set(1,0,1); set(1,1,1); set(1,2,0); set(1,3,0); set(1,4,0);
	set(2,0,0); set(2,1,4); set(2,2,2); set(2,3,2); set(2,4,0);
	set(3,0,0); set(3,1,4); set(3,2,4); set(3,3,0); set(3,4,0);
	set(4,0,0); set(4,1,4); set(4,2,1); set(4,3,4); set(4,4,0);
	set(5,0,0); set(5,1,2); set(5,2,0); set(5,3,0); set(5,4,0);
	assert(check_diags() == 4);
	end_game();
	new_game(6,5,3,4);
	set(0,0,0); set(0,1,0); set(0,2,0); set(0,3,0); set(0,4,0);
	set(1,0,1); set(1,1,1); set(1,2,0); set(1,3,0); set(1,4,0);
	set(2,0,0); set(2,1,4); set(2,2,2); set(2,3,4); set(2,4,0);
	set(3,0,0); set(3,1,4); set(3,2,4); set(3,3,0); set(3,4,0);
	set(4,0,0); set(4,1,4); set(4,2,1); set(4,3,3); set(4,4,0);
	set(5,0,0); set(5,1,2); set(5,2,0); set(5,3,0); set(5,4,0);
	assert(check_diags() == 4);
	end_game();
	new_game(6,5,3,4);
	set(0,0,1); set(0,1,2); set(0,2,3); set(0,3,4); set(0,4,1);
	set(1,0,2); set(1,1,3); set(1,2,4); set(1,3,1); set(1,4,2);
	set(2,0,3); set(2,1,4); set(2,2,4); set(2,3,4); set(2,4,3);
	set(3,0,4); set(3,1,3); set(3,2,2); set(3,3,1); set(3,4,3);
	set(4,0,2); set(4,1,1); set(4,2,1); set(4,3,2); set(4,4,3);
	set(5,0,4); set(5,1,2); set(5,2,2); set(5,3,1); set(5,4,2);
	assert(check_diags() == 2);
	end_game();
	new_game(6,5,3,4);
	set(0,0,0); set(0,1,0); set(0,2,0); set(0,3,0); set(0,4,0);
	set(1,0,0); set(1,1,0); set(1,2,0); set(1,3,0); set(1,4,0);
	set(2,0,0); set(2,1,1); set(2,2,2); set(2,3,1); set(2,4,0);
	set(3,0,0); set(3,1,0); set(3,2,2); set(3,3,2); set(3,4,2);
	set(4,0,0); set(4,1,0); set(4,2,1); set(4,3,1); set(4,4,0);
	set(5,0,0); set(5,1,2); set(5,2,2); set(5,3,2); set(5,4,0);
	assert(check_diags() == 0);
	end_game();
	printf("check_diags OK.\n");
}

void test_check() {
	new_game(3,3,2,2);
	set(0,0,0); set(0,1,0); set(0,2,0);
	set(1,0,0); set(1,1,2); set(1,2,0);
	set(2,0,0); set(2,1,0); set(2,2,2);
	assert(check() == 2);
	end_game();
	new_game(3,3,2,2);
	set(0,0,2); set(0,1,1); set(0,2,0);
	set(1,0,0); set(1,1,1); set(1,2,0);
	set(2,0,0); set(2,1,1); set(2,2,0);
	assert(check() == 1);
	end_game();
	new_game(3,3,2,2);
	set(0,0,0); set(0,1,0); set(0,2,0);
	set(1,0,0); set(1,1,1); set(1,2,0);
	set(2,0,0); set(2,1,2); set(2,2,2);
	assert(check() == 2);
	end_game();
	new_game(3,3,2,2);
	set(0,0,2); set(0,1,1); set(0,2,2);
	set(1,0,0); set(1,1,0); set(1,2,0);
	set(2,0,1); set(2,1,2); set(2,2,1);
	assert(check() == 0);
	end_game();
	new_game(6,5,3,4);
	set(0,0,0); set(0,1,0); set(0,2,0); set(0,3,0); set(0,4,0);
	set(1,0,1); set(1,1,1); set(1,2,0); set(1,3,0); set(1,4,0);
	set(2,0,0); set(2,1,4); set(2,2,2); set(2,3,2); set(2,4,0);
	set(3,0,0); set(3,1,4); set(3,2,2); set(3,3,0); set(3,4,0);
	set(4,0,0); set(4,1,4); set(4,2,1); set(4,3,4); set(4,4,0);
	set(5,0,0); set(5,1,2); set(5,2,0); set(5,3,0); set(5,4,0);
	assert(check() == 4);
	end_game();
	new_game(6,5,3,4);
	set(0,0,1); set(0,1,2); set(0,2,1); set(0,3,4); set(0,4,1);
	set(1,0,2); set(1,1,3); set(1,2,4); set(1,3,1); set(1,4,2);
	set(2,0,3); set(2,1,1); set(2,2,4); set(2,3,4); set(2,4,3);
	set(3,0,4); set(3,1,3); set(3,2,2); set(3,3,1); set(3,4,1);
	set(4,0,2); set(4,1,1); set(4,2,1); set(4,3,2); set(4,4,3);
	set(5,0,4); set(5,1,2); set(5,2,2); set(5,3,1); set(5,4,2);
	assert(check() == 2);
	end_game();
	new_game(6,5,3,4);
	set(0,0,0); set(0,1,0); set(0,2,0); set(0,3,0); set(0,4,0);
	set(1,0,0); set(1,1,0); set(1,2,0); set(1,3,0); set(1,4,0);
	set(2,0,0); set(2,1,1); set(2,2,2); set(2,3,1); set(2,4,0);
	set(3,0,0); set(3,1,0); set(3,2,3); set(3,3,2); set(3,4,2);
	set(4,0,0); set(4,1,0); set(4,2,1); set(4,3,1); set(4,4,0);
	set(5,0,0); set(5,1,2); set(5,2,3); set(5,3,2); set(5,4,0);
	assert(check() == 0);
	end_game();
	new_game(6,5,3,4);
	set(0,0,1); set(0,1,2); set(0,2,1); set(0,3,4); set(0,4,1);
	set(1,0,2); set(1,1,3); set(1,2,4); set(1,3,1); set(1,4,2);
	set(2,0,3); set(2,1,1); set(2,2,4); set(2,3,4); set(2,4,3);
	set(3,0,4); set(3,1,3); set(3,2,2); set(3,3,1); set(3,4,1);
	set(4,0,2); set(4,1,1); set(4,2,1); set(4,3,2); set(4,4,3);
	set(5,0,4); set(5,1,2); set(5,2,2); set(5,3,1); set(5,4,1);
	//print_board();
	assert(check() == -1);
	end_game();
	printf("check OK.\n");
}
