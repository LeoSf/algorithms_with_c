/*
 ============================================================================
 Name        : basic_04_array_delete_duplicates.c
 Author      : Leandro Medus
 Version     :
 Copyright   : MIT license
 Description : Basic program to delete duplicates in an array
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include<conio.h>


int main()
{

	puts("-- Basic program to delete duplicates in an array --");

    int i, j, k, n;
    const int size = 10;		/* array size */

    int a[size];

    printf("\nArray size: %d", size);

    /* populating the vector */
    for(i = 0; i < size; i++)
    {
        a[i] = i;
    }

    a[3] = 4;
    a[8] = 9;

    printf("\nOriginal array is: ");
    for(i = 0; i < size; i++)
    {
        printf(" %d", a[i]);
    }

    n = size;

    printf("\nNew array is: ");
    for(i = 0; i < n; i++)
    {
        for(j = i+1; j < n; )
        {
            if(a[j] == a[i])
            {
                for(k = j; k < n; k++)
                {
                    a[k] = a[k+1];
                }
                n--;
            }
            else
            {
                j++;
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }


    return EXIT_SUCCESS;
}
