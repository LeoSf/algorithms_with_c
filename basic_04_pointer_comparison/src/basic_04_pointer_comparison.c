/*
 ============================================================================
 Name        : basic_04_pointer_comparison.c
 Author      : Leandro Medus
 Version     :
 Copyright   : MIT license
 Description : Pointer Comparison

 In C language pointers can be compared if the two pointers are pointing to
 the same array.
 All relational operators can be used for pointer comparison, but a pointer
 cannot Multiplied or Divided.
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
