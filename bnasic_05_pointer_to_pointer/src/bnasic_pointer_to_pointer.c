/*
 ============================================================================
 Name        : bnasic_pointer_to_pointer.c
 Author      : Leandro Medus
 Version     :
 Copyright   : MIT license
 Description : Basic C Program for Pointer to a Pointer

 A pointer variable stores the address of a value. Similarly, a pointer to a
 pointer stores the address of the pointer variable. Pointer to a pointer is
 executed making use of **.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	puts("-- program --"); /* prints -- program -- */

	int var;		/* integer variable which stores value. */
	int *ptr;		/* pointer variable which stores the address of an integer variable. */
	int **pptr;		/* pointer to a pointer variable which stores the address of a pointer variable */

	var = 50;
	ptr = &var;		/* take the address of the variable var */
	pptr = &ptr;	/* taking the address of ptr using address of operator-& */

	printf("Value of var = %d\n\n", var); /* take the value using the pptr */

	printf("Value available at *ptr = %d\n\n", *ptr);

	printf("Value available at **pptr = %d\n\n", **pptr);

	return EXIT_SUCCESS;
}
