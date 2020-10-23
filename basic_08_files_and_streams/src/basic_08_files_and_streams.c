/*
 ============================================================================
 Name        : basic_08_files_and_streams.c
 Author      : Leandro Medus
 Version     : 1.0
 Copyright   : MIT license
 Description : Set of functions to test file and strems operations.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include<dirent.h>

/* example: list files in the current*/
void list_files_in_directory(void);

int main(void) {
	puts("-- Set of functions to test file and streams operations. --\n");

	list_files_in_directory();


	return EXIT_SUCCESS;
}

/**
 * @brief Use case to list all the files in a directory
 * 
 */
void list_files_in_directory(void)
{
    DIR *ptrFd;					/**< pointer to the file descriptor */

    struct dirent *dir;

    ptrFd = opendir(".");

    if (ptrFd)
    {
        while ((dir = readdir(ptrFd)) != NULL)
        {
            printf("%s\n", dir->d_name);
        }
        closedir(ptrFd);
    }

}
