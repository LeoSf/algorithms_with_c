/*
 ============================================================================
 Name        : basic_05_pointer_reverse_string.c
 Author      : Leandro Medus
 Version     :
 Copyright   : MIT license
 Description : C Program to Reverse a String using Pointer
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	puts("-- program -- \n"); /* prints -- program -- */

	char str[100] = "Nuevo mensaje desde el source code.";
	char rev[100];
	char *sptr = str; 	/* sptr stores the base address of the str */
	char *rptr = rev; 	/* rptr stores the base address of the reverse */

	int i = -1;

	printf("Original string is: \t\t%s \n", str);	/* printing the reverse string */

	strcpy(str, "Not so new message from the source code.");

	while(*sptr)	/* storing the ending address of str in sptr */
	{
		sptr++;
		i++; 		/* i is the index of the end location */
	}

	while(i >= 0)	/* storing the string str in rev in reverse order */
	{
		/*
			First decrementing then using as it stores
			the location after the end location due to above while loop
		*/
		sptr--;
		*rptr = *sptr;  /* storing the value in sptr in rptr*/
		rptr++; 		/* pointing to next location */
		i--;    		/* decrementing the index */
	}

	/*
		String should always end with '\0' so explicitly
		putting it at the end of the string
	*/
	*rptr = '\0';
	rptr = rev; 	/* restoring the base address of the reverse string */

	while(*rptr)	/* storing the reverse string in the original string */
	{
		*sptr = *rptr;
		sptr++;
		rptr++;
	}

	printf("Reverse of the string is: \t%s \n", str);	/* printing the reverse string */


	return EXIT_SUCCESS;
}
