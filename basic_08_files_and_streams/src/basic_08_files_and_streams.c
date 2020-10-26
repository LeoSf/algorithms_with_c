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
/* example to find the size of a file */
void size_of_a_file(char* path);
/* example to write a dummy text file */
void write_a_text_file(char* path);
/*  */
/*  */

int main(void) {
	puts("-- Set of functions to test file and streams operations. --\n");

	char path[100] = "..";
	// list_files_in_directory(path);

	strcpy(path, ".");
	list_files_in_directory(path);

	strcpy(path, ".cproject");
	size_of_a_file(path);

	strcpy(path, ".//Debug//new_text_file.txt");
	write_a_text_file(path);

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

/**
 * @brief Example to find the size of a file
 * 
 * @param path Relative or absolute path to the file to be analyzed.
 * 
 * We will be using fseek() and ftell() functions to find the size of the file. There 
 * are others ways to find the file size as well, like looping on the whole content of 
 * file and finding out the size, but the File Handling functions makes it a lot easier.
 * 
 * int fseek( std::FILE* stream, long offset, int origin );
 * origin = {
 * 		SEEK_SET (Beginning of file)
 * 		SEEK_CUR (Current position of the file pointer)
 * 		SEEK_END (End of file)
 * }
 * 
 * ftell(): It tells the byte location of current position of cursor in file pointer.
 * long ftell( std::FILE* stream ); 
 * Returns the current value of the file position indicator for the file stream stream.
 */
void size_of_a_file(char* path){

	printf("\n------------------------------------------------------------------\n");
    printf("Example to find the size of a file\n");

	FILE *fp;		/**< file pointer */
    int size;

    fp = fopen(path, "r");
    if (fp == NULL)
    {
        printf("File unable to open...\n");
    }
    else
    {	
        printf("File opened: %s\n", path);
    }

    fseek(fp, 0, SEEK_END);    /* File pointer at the end of file */
    size = ftell(fp);   /* Take a position of file pointer in size variable */

    printf("The size of given file is: %d bytes\n", size);
    fclose(fp);

}

/**
 * @brief Example to write a dummy text file
 * 
 * @param path Relative or absolute path to the file to be created with some text.
 * 
 * *fp = FILE *fopen(const char *filename, const char *mode);
 * 
 * 		Here, *fp is the FILE pointer (FILE *fp), which will hold the reference to the opened
 * 		(or created) file. 
 * 
 * 		filename is the name of the file to be opened and mode specifies the purpose of opening the 
 * 		file. Mode can be of following types,
 * 
 * 		mode	description
 * 		r		opens a text file in reading mode
 * 		w		opens or create a text file in writing mode.
 * 		a		opens a text file in append mode
 * 		r+		opens a text file in both reading and writing mode
 * 		w+		opens a text file in both reading and writing mode
 * 		a+		opens a text file in both reading and writing mode
 * 		rb		opens a binary file in reading mode
 * 		wb		opens or create a binary file in writing mode
 * 		ab		opens a binary file in append mode
 * 		rb+		opens a binary file in both reading and writing mode
 * 		wb+		opens a binary file in both reading and writing mode
 * 		ab+		opens a binary file in both reading and writing mode
 */
void write_a_text_file(char* path)
{
	printf("\n------------------------------------------------------------------\n");
    printf("Example: writing a text file.\n");

	FILE *fptr;
    char name[] = "Leandro";
    int age = 60;
    float salary = 1000;

    /* open for writing */
    fptr = fopen(path, "w");

    if (fptr == NULL)
    {
        printf("File does not exist.\n");
        return;
    }
	else
    {	
        printf("File opened: %s\n", path);
    }

	/*
		data to write 
	*/
    fprintf(fptr, "Name  = %s\n", name);
    fprintf(fptr, "Age  = %d\n", age);
    fprintf(fptr, "Salary  = %.2f\n", salary);

    fclose(fptr);
	printf("File closed: %s\n", path);
}