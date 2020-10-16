/*
 ============================================================================
 Name        : basic_04_pointer_comparison.c
 Author      : Leandro Medus
 Version     :
 Copyright   : MIT license
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	puts("-- program --"); /* prints -- program -- */

	int *ptrA,*ptrB;

	ptrA = (int *)1;
	ptrB = (int *)2;

	if(ptrB > ptrA)
		printf("PtrB is greater than ptrA");

	return EXIT_SUCCESS;
}
