#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    
    // Check if all the needed arguments are provided
    if (argc != 2){
        fputs("usage: ./brainfuck [path/to/file.bf]\n", stderr);
        return 1;
    }

    // Get the source code from the file provided and print it
    char source[LENGTH]="";
    FILE *file = fopen(argv[1], "r");
    printf("Source code: %s\n", fgets(source, LENGTH, file));


    return 0;
}
