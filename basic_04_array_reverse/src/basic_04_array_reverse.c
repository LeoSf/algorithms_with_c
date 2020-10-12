/*
 ============================================================================
 Name        : basic_04_array_reverse.c
 Author      : Leandro Medus
 Version     :
 Copyright   : MIT license
 Description : basic example to reverse an array
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int reverse_array()
{
    int c, d, n, a[100], b[100];

    n = 10;

    for(c = 0; c < n; c++)
    	a[c] = c;

    /*
        temporarily storing elements into array b
        starting from end of array a
    */
    for(c = n-1, d = 0; c >= 0; c--, d++)
        b[d] = a[c];

    /*
        copying reversed array into original.
        Here we are modifying original array to reverse it.
    */

    for(c = 0; c < n; c++)
        a[c] = b[c];

    printf("\n\n Resultant array is: ");
    for(c = 0; c < n; c++)
        printf("%d", a[c]);


    return 0;
}


int main(void) {

	/* calling the function to test*/
	reverse_array();

	return EXIT_SUCCESS;
}


