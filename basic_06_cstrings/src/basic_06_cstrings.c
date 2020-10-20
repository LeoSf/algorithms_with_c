/**
 * ============================================================================
 * @file	basic_06_cstrings.c
 * @author	Leandro Medus
 * @date	10/2020
 * @brief  	Multiple functions related to cstrings
 *
 * Version	:
 * Copyright	: MIT license
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include<string.h>    	/**< to use strcpy() function */

/* strcpy example */
void string_copy(void);
/* strcmp example */
void string_comparison(void);


/**
  * @brief Main program
  */
int main(void) {
 
	puts("-- Main program to test multiple functions related to cstrings --\n"); /* prints intro*/

	string_copy();
    string_comparison();

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

/**
 * @brief Use case to compare strings using strcmp() function defined in the string.h library.
 * 
 * strcmp(a, b) returns 0 if both the strings a and b are exactly same else returns -1.
 * It is case sensitive so 'ABC' and 'abc' are considered to be different strings. It can be used 
 * with with strrev() function(function to reverse a string) to check whether a given string is a 
 * Pallindrome or not.
 */
void string_comparison(void){
    
    char aj1[100] = "Primer c-string";
    char aj2[100] = "Segundo c-string";
    int compare;

    printf("------------------------------------------------------------------\n");
    printf("strcmp(a,b) returns : 0 if both the strings are exactly same and -1 otherwise.\n");
    printf("strcmp(a,b) is Case Sensitive.\n\n");

    printf("First case: \n");
    compare = strcmp(aj1, aj2);
    if(compare == 0)
        printf("Both the strings are exactly same.\n");
    else
        printf("Both the strings are different.\n");

    printf("Second case: \n");
    /* 
        The second case is important due to the fact there is a direct comparison with a c-string
        without the same length of aj1.
    */
    compare = strcmp(aj1, "Primer c-string");
    if(compare == 0)
        printf("Both the strings are exactly same.\n");
    else
        printf("Both the strings are different.\n");
}
