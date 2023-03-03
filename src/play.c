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

#include "game.h"
#include <stdio.h>
#include <stdlib.h>

int turn;

void start_game() {
	int rows = 3;
	int cols = 3;
	int set = 3;
	int players = 2;
	char *buff = calloc(4, sizeof(char*));

	printf("Number of players [%d]: ", players);
	fgets(buff, 4, stdin);
	if (sscanf(buff, "%d", &players) != 1) printf("Defaulting to %d.\n", players);
	printf("Board width [%d]: ", cols);
	fgets(buff, 4, stdin);
	if(sscanf(buff, "%d", &cols) != 1) printf("Defaulting to %d.\n", cols);
	printf("Board height [%d]: ", rows);
	fgets(buff, 4, stdin);
	if(sscanf(buff, "%d", &rows) != 1) printf("Defaulting to %d.\n", rows);
	printf("Length of set to win [%d]: ", set);
	fgets(buff, 4, stdin);
	if(sscanf(buff, "%d", &set) != 1) printf("Defaulting to %d.\n", set);
	new_game(rows, cols, set, players);
	printf("Game started.\n");
	print_board();
	turn = 1;
}

int move() {
	printf("It's your turn, Player %d", turn);
	if (get_n_players() == 2) printf(" [%c]", turn == 1 ? 'X' : 'O');
	printf("!\n");
	char *buff = calloc(20, sizeof(char*));
	int row;
	int col;
	do {
		printf("Play on (x y): ");
		fgets(buff, 20, stdin);
	}while(sscanf(buff, "%d%d", &col, &row) != 2 || !set(row, col, turn));
	print_board();
	int winner = check();
	if (winner) {
		if (winner == -1) printf("It's a tie!\n");
		else {
			printf("Congratulations, Player %d", winner);
			if (get_n_players() == 2) printf(" [%c]", turn == 1 ? 'X' : 'O');
			printf(", you won!\n");
		}
		return 0;
	}
	turn++;
	if (turn > get_n_players()) turn = 1;
	return 1;
}

int main() {
	start_game();
	while (move()) {}
	end_game();
	return 0;
}
