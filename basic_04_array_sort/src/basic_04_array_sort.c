/*
 ============================================================================
 Name        : basic_04_array_sort.c
 Author      : Leandro Medus
 Version     :
 Copyright   : MIT license
 Description : basic example to sort element in an array
 ============================================================================
 */

#include<stdio.h>
#include <stdlib.h>

void sorting(int *x, int y);

int main(void)
{
	const int N = 10;		// number of element to
	int a[N];				// vector to store data
	int i;					// counter

	printf("-- Sort elements in vector ---\n");

   for(i=0; i<N; i++)
	   a[i] = N-i ;

    printf("Number of elements to sort: %d \n", N);

    for(i = 0; i <N; i++)
        printf("%d\t", a[i]);
    printf("\n");

    sorting(a, N);

    for(i = 0; i <N; i++)
    	printf("%d\t", a[i]);


    return EXIT_SUCCESS;
}

void sorting(int *x, int y)
{
    int i, j, temp;
    for(i = 1; i <= y-1; i++)
    {
        for(j = 0; j < y-i; j++)
        {
            if(*(x+j) > *(x+j+1))
            {
                temp = *(x+j);
                *(x+j) = *(x+j+1);
                *(x+j+1) = temp;
            }
        }
    }
}
