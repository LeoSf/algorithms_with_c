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

#define N_vector 5

/* example: list files in a specific path */
void list_files_in_directory(char* path);
/* example to find the size of a file */
void size_of_a_file(char* path);
/* example to write a dummy text file */
void write_a_text_file(char* path);
/* example to read and write a file */
void read_and_write(char* path);
/* helper function to count the amount of characters in a file */
long count_characters(FILE *f);
/* example to copy the content from one file to another */
void copy_content(char* source, char* destination);
/* example to read and write a file line to line */
void write_and_read(char* path);
/* example to write a binary file */
void write_binary(char* path);
/* example to read a binary file */
void read_binary(char* path);



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

	strcpy(path, ".//Debug//new_text_file.txt");
	read_and_write(path);

	char path_source[] = ".//Debug//new_text_file.txt";
	char path_desteny[] = ".//Debug//desteny_file.txt";
	copy_content(path_source, path_desteny);

	strcpy(path, ".//Debug//new_text_file.txt");
	write_and_read(path);

	strcpy(path, ".//Debug//new_text_file.bin");
	write_binary(path);

	read_binary(path);

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

/**
 * @brief example to read and write a file
 * 
 * This program reverse the contents of a file.
 * 
 * @param path Relative or absolute path to the file to work with.
 */
void read_and_write(char* path)
{
	printf("\n------------------------------------------------------------------\n");
    printf("Example: reverting the content of a file.\n");

    long cnt;
	long i = 0;
    char ch;
    FILE *fp1, *fp2;

	fp1 = fopen(path, "r");
    if (fp1 != NULL)
    {
        printf("The FILE has been opened...\n");
        fp2 = fopen("reverted_content.txt", "w");
        cnt = count_characters(fp1);

        /*
            Make the pointer fp1 to point at the
            last character of the file
        */
        fseek(fp1, 0, 2);
        printf("Number of characters to be copied %li\n", ftell(fp1));

        while (cnt)
        {
            ch = fgetc(fp1);
            fputc(ch, fp2);
            // fseek(fp1, cnt , SEEK_SET); // from the begining
            // fseek(fp1, -1L, SEEK_CUR); // seek_cur not working
            fseek(fp1, -i-1, SEEK_END); // shifts the pointer to the previous character
			i++;
            cnt--;
        }
        printf("\n**File copied successfully in reverse order**\n");
    }
    else
    {
        perror("Error occured\n");
		return;
    }
    fclose(fp1);
    fclose(fp2);
}

/**
 * @brief Count the total number of characters in the file that *f points to
 * 
 * int fseek( std::FILE* stream, long offset, int origin );
 * origin = {
 * 		SEEK_SET (Beginning of file)
 * 		SEEK_CUR (Current position of the file pointer)
 * 		SEEK_END (End of file)
 * }
 * 
 * @param f file pointer
 * @return long number of characters in a text file
 */
long count_characters(FILE *f)
{
    fseek(f, 0, SEEK_END);
    // fseek(f, -1L, SEEK_END);
    /*
        returns the position of the 
        last element of the file
    */
    long last_pos = ftell(f);
    last_pos++;

    return last_pos;
}

/**
 * @brief example to copy the content from one file to another
 * 
 * @param source file with content
 * @param destination file in which content of source will be copied.
 */
void copy_content(char* source, char* destination)
{
	printf("\n------------------------------------------------------------------\n");
    printf("Example: copy the content of a file.\n");

    FILE *fp1, *fp2;
    char ch;
    int pos;

    if ((fp1 = fopen(source, "r")) == NULL)
    {
        printf("\nFile cannot be opened.");
        return;
    }
    else
    {
        printf("\nFile opened for copy...\n ");
    }
    fp2 = fopen(destination, "w");
    
	fseek(fp1, 0L, SEEK_END);   // File pointer at end of file
    pos = ftell(fp1);
    
	fseek(fp1, 0L, SEEK_SET);   // File pointer set at start
    
	while (pos--)
    {
        ch = fgetc(fp1);    // Copying file character by character
        fputc(ch, fp2);
    }
    
	printf("**File copied successfully from origin to destination**\n");
	// fcloseall();
	fclose(fp1);
	fclose(fp2);
}

struct emp
{
    char name[10];
    int age;
};

/**
 * @brief example to read and write a file line to line
 * 
 * @param path 
 */
void write_and_read(char* path)
{
	printf("\n------------------------------------------------------------------\n");
    printf("Example: copy the content of a file.\n");

	struct emp e;

    FILE *fp_out,*fp_in;

    fp_out = fopen(path, "w");
    fp_in = fopen(path, "r");

	strcpy(e.name, "Leandro");
	e.age = 60;

    fprintf(fp_out,"%s %d", e.name, e.age);
    fclose(fp_out);
    do
    {
        fscanf(fp_in,"%s %i", e.name, &e.age);
        printf("%s %d", e.name, e.age);
    }
    while(!feof(fp_in));

	printf("\n");
}

/**
 * @brief example to write and read in binary
 * 
 * fread() and fwrite() functions are used to read and write is a binary file.
 * fwrite(	data-element-to-be-written, size_of_elements, number_of_elements, 
 * 			pointer-to-file);
 * 
 * size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
 * 
 * Parameters
 * 		ptr − This is the pointer to the array of elements to be written.
 * 		size − This is the size in bytes of each element to be written.
 * 		nmemb − This is the number of elements, each one with a size of size bytes.
 * 		stream − This is the pointer to a FILE object that specifies an output stream.
 * 
 * @param path 
 */
void write_binary(char* path)
{
	printf("\n------------------------------------------------------------------\n");
    printf("Example: write file in binary format\n");

	// const char *mytext = "this is a sentence to test";   

	long int vector[N_vector] = {1,2,3,4,5};

	FILE *bfp = fopen(path, "wb");   

	if (bfp) 
	{
		// fwrite(mytext, sizeof(char), strlen(mytext), bfp);  

		/* little endian by default -- first LSB */   
		fwrite(vector, sizeof(long int), sizeof(vector)/sizeof(long int), bfp);     

		fclose(bfp);   
		printf("File has been written successfully\n");
	}
	else
	{
		printf("Error opening the file\n");
	}
	
}


/**
 * @brief example to read a binary file
 * 
 * The C library function size_t fread(void *ptr, size_t size, size_t nmemb, 
 * FILE *stream) reads data from the given stream into the array pointed to, 
 * by ptr.
 * 
 * size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)
 * 
 * Parameters
 * 		ptr − This is the pointer to the array of elements to be written.
 * 		size − This is the size in bytes of each element to be written.
 * 		nmemb − This is the number of elements, each one with a size of size bytes.
 * 		stream − This is the pointer to a FILE object that specifies an output stream.
 * 
 * @param path 
 */
void read_binary(char* path)
{
	printf("\n------------------------------------------------------------------\n");
    printf("Example: read a file in binary format\n");

	int i;
	FILE *fp;

	long int buffer[N_vector];

	/* Open file for both reading and writing */
	fp = fopen(path, "rb");

	/* Seek to the beginning of the file */
	fseek(fp, 0, SEEK_SET);

	/* Read and display data */
	fread(buffer, sizeof(long int), N_vector, fp);
	// printf("%li\n", buffer);

	for(i = 0; i < N_vector; i++)
        printf("%li ", buffer[i]);
	
	printf("\n");

	fclose(fp);
	
}