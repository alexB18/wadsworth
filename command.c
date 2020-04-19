#include "command.h"
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Helper function for counting number of characters in a string */
ssize_t numCharacters(char* inputStr){
    size_t i = 0;
    size_t count = 0;

    while (inputStr[i] != '\0'){
        count++;
        i++;
    }

    return count;
}

/*for the ls command*/
void listDir(){

    // Declare pointer which will hold current entry in directory
    struct dirent* directoryEntryPtr;

    // Attempt to open the current directory
    DIR* directoryStream = opendir(".");
    if(directoryStream == NULL){
        perror("Failed to open current directory.\n");
        exit(EXIT_FAILURE);
        return;
    }

    size_t count;
    while((directoryEntryPtr = readdir(directoryStream)) != NULL){

        //Retrieve number of characters in the name of directory item
        count = numCharacters(directoryEntryPtr->d_name);

        //write contents name of current directory item to stdout
        if( write(1, directoryEntryPtr->d_name, count) == -1){
            perror("Error writing directory item name to stdout.\n");
            return;
        }
        write(1, "\n", 1);
    }

    //Close directory
    closedir(directoryStream);
}

/*for the pwd command*/
void showCurrentDir(){

        
    // Initialize function variables
    char* pathBufferPtr;
    ssize_t pathBufferSize = 100;
    size_t count;

    // Allocate memory for the pathBufferPtr
    pathBufferPtr = (char*) malloc(pathBufferSize * sizeof(char));

    // Get current working directory and store in pathBufferPtr
    getcwd(pathBufferPtr, pathBufferSize);
    
    // Retrieve number of characters in the directory
    count = numCharacters(pathBufferPtr);

    // write contents of directory to stdout
    if( write(1, pathBufferPtr, count) == -1){
        perror("Error writing cwd to stdout.\n");
        return;
    }
    write(1, "\n", 1);

    // Free allocated memory
    free(pathBufferPtr);

}

/*for the mkdir command*/
void makeDir(char *dirName){

}

/*for the cd command*/
void changeDir(char *dirName){
    
}

/*for the cp command*/
void copyFile(char *sourcePath, char *destinationPath){

}

/*for the mv command*/
void moveFile(char *sourcePath, char *destinationPath){

}

/*for the rm command*/
void deleteFile(char *filename){

}

/*for the cat command*/
void displayFile(char *filename){

}