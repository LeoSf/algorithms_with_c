/*
 ============================================================================
 Name        : basic_04_square_matric_symmetric.c
 Author      : Leandro Medus
 Version     :
 Copyright   : MIT license
 Description : Program to check whether given Square Matrix is symmetric or not.

 Notes: 
 A Square Matrix is said to be symmetric if it is equal to it's transpose.
 Transpose of a matrix is achieved by exchanging indices of rows and columns.
 Transpose is only defined for a square matrix.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void )
{

    int i;              /* counter iterator over rows */
    int j;              /* counter iterator over rcolumns */

    const int n = 3;	/* matrix dimmension */

    int a[n][n];
    int b[n][n];

    time_t t;
    srand((unsigned) time(&t));		/* Intializes random number generator */


    printf("\nDimension of the matrix: (%d x %d)", n, n);

    printf("\nEnter the %d elements of the matrix: \n\n",n*n);
    for(i = 0; i < n; i++) // to iterate the rows
        for(j = 0; j < n; j++) // to iterate the columns
            a[i][j] = rand() % 10;
            // scanf("%d", &a[i][j]);

    // finding transpose of a matrix and storing it in b[][]
    for(i = 0; i < n; i++) // to iterate the rows
        for(j = 0; j < n; j++) //to iterate the columns
            b[j][i] = a[i][j];

    // printing the original matrix
    printf("\n\nThe original matrix is: \n\n");
    for(i = 0; i < n; i++)   // to iterate the rows
    {
        for(j = 0; j < n; j++)   // to iterate the columns
        {
            printf("%d\t", a[i][j]);
        }
    printf("\n");
    }

    // printing the transpose of the entered matrix
    printf("\n\nThe Transpose matrix is: \n\n");
    for(i = 0; i < n; i++) // to iterate the rows
    {
        for(j = 0; j < n; j++)   // to iterate the columns
        {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }

    // checking if the original matrix is same as its transpose
    for(i = 0; i < n; i++)   // to iterate the rows
    {
        for(j = 0; j < n; j++)   // to iterate the columns
        {
            /*
                even if they differ by a single element,
                the matrix is not symmetric
            */
            if(a[i][j] != b[i][j])
            {
                printf("\n\nMatrix is not Symmetric\n\n");
                exit(0);    // a system defined method to terminate the program
            }
        }
    }

    /*
        if the program is not terminated yet,
        it means the matrix is symmetric
    */
    printf("\n\nMatrix is Symmetric\n\n");
    printf("\n\n\t\t\tCoding is Fun !\n\n\n");
    return EXIT_SUCCESS;
}
