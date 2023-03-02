#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *multiply_string(char *s, int times) {
	char *result = calloc(times * strlen(s), sizeof(char));
	for (int i = 0; i < times; i++) {
		sprintf(result, "%s%s", result, s);
	}
	return result;
}

int min(int a, int b) {
	return a < b ? a : b;
}

int max(int a, int b) {
	return a > b ? a : b;
}
