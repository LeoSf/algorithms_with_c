/*
 ============================================================================
 Name        : ch2_02_ptr_swap.c
 Author      : Leo
 Version     :
 Copyright   : MIT License
 Description : basic swapping example with pointers
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void swap2(int *x, int *y) {
	int tmp;
	
	tmp = *x; 
	
	*x = *y; 
	*y = tmp;

	return;
}

int main(void) {
	puts("Swapping values");

	int a = 4;
	int b = 5;

	printf("a: %d - b: %d\n", a, b);
	swap2(&a, &b);

	printf("a: %d - b: %d\n", a, b);

	return EXIT_SUCCESS;
}
