#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 9999

/*
 * How does brainfuck work?
 * +   -> changes the value of the cell by 1
 * -   -> changes the value of the cell by -1
 * >   -> changes the cell by 1
 * <   -> changes the cell by -1
 * .   -> prints the int value of the cell
 * :   -> prints the ascii value of the cell
 * ,   -> accepts int input and adds it to the cell
 * ;   -> gets the ascii input and adds its number to the cell
 * []  -> loops if the value of the cell it ends on isn't 0
 */

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