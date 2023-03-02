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
	if (get_n_players() == 2) printf("[%c]", turn == 1 ? 'X' : 'O');
	printf("!\n");
	char *buff = calloc(20, sizeof(char*));
	int row;
	int col;
	do {
		printf("Play on (x y): ");
		fgets(buff, 20, stdin);
	}while(sscanf(buff, "%d%d", &col, &row) != 2 || !set(row, col, turn));
	print_board();
	if (!check()) return 1;
	return 0;
}

int main() {
	start_game();
	while (move()) {}
	end_game();
	return 0;
}
