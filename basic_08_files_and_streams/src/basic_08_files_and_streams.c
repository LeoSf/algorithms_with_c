/*
 ============================================================================
 Name        : basic_08_files_and_streams.c
 Author      : Leandro Medus
 Version     : 1.0
 Copyright   : MIT license
 Description : Set of functions to test file and streams operations.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include<dirent.h>
#include<string.h>

/* example: list files in a specific path */
void list_files_in_directory(char* path);

int main(void) {
	puts("-- Set of functions to test file and streams operations. --\n");

	char path[] = "..";
	list_files_in_directory(path);

	strcpy(path, ".");
	list_files_in_directory(path);

	return EXIT_SUCCESS;
}

/**
 * @brief Use case to list all the files in a directory
 * 
 * @param path Relative or absolute path to the directory to be analyzed.
 */
void list_files_in_directory(char* path)
{

	printf("\n------------------------------------------------------------------\n");
    printf("List of files in the directory: %s\n", path);

    DIR *ptrFd;					/**< pointer to the file descriptor */

    struct dirent *dir;

    ptrFd = opendir(path);

    if (ptrFd)
    {
        while ((dir = readdir(ptrFd)) != NULL)
        {
            printf("%s\n", dir->d_name);
        }
        closedir(ptrFd);
    }

}
