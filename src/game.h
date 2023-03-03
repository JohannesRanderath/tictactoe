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

void new_game(int rows, int cols, int len_set, int player); // Initialize instance variables for new game
void end_game(); // Free dynamically allocated memory
int get_n_rows(); // Return number of rows on the board
int get_n_cols(); // Return number of columns on the board
int get_n_players(); // Return number of players in the game
int set(int row, int col, int player); // Occupy field on the board if it is not yet. Return 1 if successful, 0 otherwise
int check(); // Check if there is a valid set on the board. Return -1 if there is a tie, 0 if there is no set nor tie, the number of the player if there is a tie
void print_board(); // Print a visual representation of the current game state to stdout