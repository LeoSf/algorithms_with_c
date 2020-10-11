/*
 ============================================================================
 Name        : ch2_01_ptr.c
 Author      : Leandro Medus
 Version     :
 Copyright   : MIT License
 Description : basic example of a pointer
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int g(int **iptr) {
	/***/

	if ((*iptr = (int *)malloc(sizeof(int))) == NULL)
		return -1;

	return 0;
}

int main(void) {
	puts("-- Main program example --");

	int * ptr = NULL;
	int result = g(&ptr);

	printf("Operation result: %d", result);


	return EXIT_SUCCESS;
}
