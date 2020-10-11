/*
 ============================================================================
 Name        : ch2_02_void_ptr.c
 Author      : Leandro Medus
 Version     :
 Copyright   : MIT License
 Description : basic swapping example with pointers
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define LEN 3

int swap2(void *x, void *y, int size) {

	void *tmp;

	if ((tmp = malloc(size)) == NULL)
		return -1;
	
	memcpy(tmp, x, size); 
	memcpy(x, y, size); 
	memcpy(y, tmp, size);
	
	free(tmp);
	
	return 0;
}

int main(void) {
	puts("-- Void pointer example --");

	int array_a[LEN] = {9,2,3};
	int array_b[LEN] = {4,5,6};

	array_a[0] = 1;

	printf("a[0]: %p\n", &array_a[0]);

	printf("a[0]: %d - a[1]: %d - a[2]: %d\n", array_a[0], array_a[1], array_a[2]);

	int result = swap2(&array_a, array_b, (int) LEN);
	printf("operation result: %d \n", result);

	printf("a[0]: %d - a[1]: %d - a[2]: %d\n", array_a[0], array_a[1], array_a[2]);



	return EXIT_SUCCESS;
}
