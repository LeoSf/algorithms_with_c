/*!
 * ============================================================================
 * @file		basic_06_cstrings.c
 * @author	Leandro Medus
 * @date		10/2020
 * @brief  	Multiple functions related to cstrings
 *
 * Version	:
 * Copyright	: MIT license
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include<string.h>    	/**< for using strcpy() function */

void string_copy(void);

int main(void) {
 /**
  * @brief Main program
  */
	puts("-- Main program to test multiple functions related to cstrings --\n"); /* prints intro*/

	string_copy();

	return EXIT_SUCCESS;
}

/**
 * \brief Function to copy one string into another, using the strcpy() method defined under the string.h library.
 *
 * strcpy(destination, source) is a system defined method used to copy the source string into the destination
 * variable.
 */
void string_copy(void)
{
	char mj[100];
    char aj[100];

	printf("------------------------------------------------------------------\n");
    printf("strcpy(destination, source): is a system defined method used to \ncopy the source string into the destination.\n");

    strcpy(aj, "Nuevo mensaje");
    strcpy(mj, aj);
    printf("The copied string is: %s\n", mj);
}
