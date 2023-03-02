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