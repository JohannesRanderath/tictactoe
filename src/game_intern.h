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

// Exposing all - public and private - functions of game backend. For test suites.

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

int is_free(int row, int col); // Check if there is any blank field on the board
int check_rows(); // Check if there is a horizontal set
int check_cols(); // Check if there is a vertical set
int check_diags(); // Check if there is a diagonal set
int check_diags_fixed_row_fwd(); 
int check_diags_fixed_col_fwd();
int check_diags_fixed_row_bwd();
int check_diags_fixed_col_bwd();