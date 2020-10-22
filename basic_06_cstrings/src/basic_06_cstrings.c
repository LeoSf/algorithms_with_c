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

#include<string.h>    	        /**< to use strcpy() function */

/* strcpy example */
void string_copy(void);
/* strcmp example */
void string_comparison(void);
/* strrev example */
void string_reverse(void);
/* basic method to remove whitespaces */
void remove_whitespaces(void);
/* basic example for console input */
void console_input(void);
/* example of difference between strlen and sizeof */
void len_and_sizeof(void);



/**
  * @brief Main program
  */
int main(void) {
 
	puts("-- Main program to test multiple functions related to cstrings --\n"); /* prints intro*/

	string_copy();
    string_comparison();
    string_reverse();
    remove_whitespaces();
    /*
        the console_input function is working but it is avoided to not interact with the console 
    */
    // console_input();
    len_and_sizeof();


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

	printf("\n------------------------------------------------------------------\n");
    printf("strcpy(destination, source): is a system defined method used to \ncopy the source string into the destination.\n");

    strcpy(aj, "Nuevo mensaje");
    strcpy(mj, aj);
    printf("The copied string is: %s\n", mj);
}

/**
 * @brief Use case to compare c-strings using strcmp() function defined in the string.h library.
 * 
 * strcmp(a, b) returns 0 if both the strings a and b are exactly same else returns -1.
 * It is case sensitive so 'ABC' and 'abc' are considered to be different strings. It can be used 
 * with with strrev() function(function to reverse a string) to check whether a given string is a 
 * Pallindrome or not.
 */
void string_comparison(void)
{
    
    char aj1[100] = "Primer c-string";
    char aj2[100] = "Segundo c-string";
    int compare;

    printf("\n------------------------------------------------------------------\n");
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

/**
 * @brief Use case to reverse a c-string
 *
 * This function compare c-strings using the strrev() defined within the string.h library. It can be used
 * to check if the string is pallindrome or not by using this function along with the strcmp() function.
 */

void string_reverse(void)
{
	
    printf("\n------------------------------------------------------------------\n");
	printf("strrev(string): Function to reverse the string and storing in the same string.\n");
	
    char aj[1000] = "testing a cstring as an input";
    printf("Original cstring is: %s\n", aj);

	/*
		system defined function to reverse the string
		and storing in the same string
	*/
	strrev(aj);
	printf("Reverse of entered cstring is: %s\n", aj);
}

/**
 * @brief Removing Whitespaces in a cstring
 * 
 * Basic method to remove whitespaces in a cstring
 */
void remove_whitespaces(void)
{
    printf("\n------------------------------------------------------------------\n");
	printf("Removing Whitespaces in a cstring.\n");

    char aj[1000] = "cstring with a lot of whitespaces to test"; 
    char mj[1000];      /**< buffer */
    
    int i = 0;          /**< index for the original string */
    int j = 0;          /**< index for the buffer */
    int len;            /**< len of the input cstring*/

    printf("Original cstring is: %s\n", aj);

    len = strlen(aj);   // len stores the length of the input cstring
    printf("Length of the original cstring is: %d\n", len);

    while(aj[i] != '\0')    // till string doesn't terminate
    {
        if(aj[i] != ' ')  // if the char is not a white space
        {
            /* 
                incrementing index j only when 
                the char is not space
            */
            mj[j++] = aj[i];
        }
        /*
            i is the index of the actual string and 
            is incremented irrespective of the spaces
        */
        i++;
    }
    mj[j] = '\0';

    printf("The modified cstring is: %s\n", mj);
    len = strlen(mj);   // len stores the length of the input cstring
    printf("Length of the modified cstring is: %d\n", len);
}

/**
 * @brief Basic example of console input using cstrings
 * 
 */
void console_input(void)
{
    char a[100];
    int length;
    printf("\n------------------------------------------------------------------\n");
	printf("Calculating the length of a cstring as a input from the console.\n");

    printf("Enter a string you wish to calculate the length of :   ");
    /*
        to take a single string (including spaces) 
        as input at a time
    */
    gets(a);
    /*
        Return the length of the string 
        or the number of characters in the string
    */
    length = strlen(a);

    printf("\nThe length of the input string is: %d\n", length);
}

/**
 * @brief 
 * 
 */
void len_and_sizeof(void)
{
    printf("\n------------------------------------------------------------------\n");
	printf("-- Difference between strlen and size of ---\n");

    char aj[] = "StringToTest";
    int length1, length2;

    length1 = sizeof(aj);
    length2 = strlen(aj);

    // need to put in backslash infront to print the quote symbol
    printf("sizeof() of string \"%s\" returns %d and strlen() returns %d.\n", aj, length1, length2);
    printf("sizeof() also considers \'\\0\' as a part of the string.\n");
    printf("Hence, for a predefined string: sizeof() = strlen() + 1 \n");

}
