/*
 ============================================================================
 Name        : basic_05_pointer_to_a_function.c
 Author      : Leandro Medus
 Version     :
 Copyright   : MIT license
 Description : C program for Pointer to a Function
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void func(int a, int b)  // function definition
{
    printf(" a = %d \n", a);
    printf(" b = %d \n", b);
}


int main(void) {
	puts("-- Pointer to a Function program --");

	void(*fptr)(int , int);		/* function pointer*/

	fptr = func;				/* assign address to function pointer */

	func(2,3);					/* calling the main function */
	fptr(2,3);  				/* calling a function referring to pointer to a function */



	return EXIT_SUCCESS;
}
