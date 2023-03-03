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
