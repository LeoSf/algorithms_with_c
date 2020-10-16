/*
 ============================================================================
 Name        : basic_05_pointer_malloc.c
 Author      : Leandro Medus
 Version     :
 Copyright   : MIT license
 Description : Program for Dynamic Memory Allocation using malloc()

 Program on dynamic memory allocation using malloc() and clearing out memory
 space using free().
 sizeof() returns the number of bytes occupied by any data type, in this case
 by an integer.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("-- Program for Dynamic Memory Allocation using malloc() -- \n\n");

    int i, *ptr, sum = 0;

    int n = 10;

    printf("Number of elements allocated %d: \n", n);

    // dynamic memory allocation using malloc()
    ptr = (int *) malloc(n * sizeof(int));

    if(ptr == NULL) // if empty array
    {
        printf("\n\nError! Memory not allocated\n");
        return 0;   // end of program
    }

    
    for(i = 0; i < n; i++)
    {
        ptr[i] = rand() % 10;       // storing elements at contiguous memory locations
        sum = sum + *(ptr + i);     // summation
    }

    // printing the array elements using pointer to the location
    printf("The elements of the array are: ");
    for(i = 0; i < n; i++)
    {
        printf("%d  ",ptr[i]);    // ptr[i] is same as *(ptr + i)
    }

    /*
        freeing memory of ptr allocated by malloc
        using the free() method
    */
    free(ptr);

    return EXIT_SUCCESS;
}


/*
    An alternative to fill the data with the pointer is:
        scanf("%d", ptr+i);
*/
