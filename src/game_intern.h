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

// Public
#include "game.h"

// Private
extern int **board;
int **board;
extern int n_rows;
int n_rows;
extern int n_cols;
int n_cols;
extern int n_set;
int n_set;
extern int n_players;
int n_players;

int is_free(int row, int col);
int check_rows();
int check_cols();
int check_diags();
int check_diags_fixed_row_fwd();
int check_diags_fixed_col_fwd();
int check_diags_fixed_row_bwd();
int check_diags_fixed_col_bwd();