#include "test_game.h"
#include <stdio.h>

void test_game() { 
	 test_get_n_rows();
	 test_get_n_cols();
	 test_set();
	 test_check();
}

void test_all() {
	return test_game();
}

int main() {
	test_all();
	return 0;
}
