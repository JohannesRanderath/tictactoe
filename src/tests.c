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

#include "test_game.h"
#include <stdio.h>

void test_game() { 
	test_get_n_rows();
	test_get_n_cols();
	test_set();
	test_check_rows();
	test_check_cols();
	test_check_diags_fixed_row_fwd();
	test_check_diags_fixed_col_fwd();
	test_check_diags_fixed_row_bwd();
	test_check_diags_fixed_col_bwd();
	test_check_diags();
	test_check();
}

void test_all() {
	test_game();
}

int main() {
	test_all();
	return 0;
}
