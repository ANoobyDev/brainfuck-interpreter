#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 9999

int main(int argc, char *argv[]){
    
    // Check if all the needed arguments are provided
    if (argc != 2){
        fputs("usage: ./brainfuck [path/to/file.bf]\n", stderr);
        return 1;
    }

    // Get the source code from the file provided
    char source[LENGTH];
    strcpy(source, "");
    FILE *file;
    file=fopen(argv[1], "r");
    fgets(source, LENGTH, file);
    fclose(file);


    printf("Source code: %s\n", source);
}