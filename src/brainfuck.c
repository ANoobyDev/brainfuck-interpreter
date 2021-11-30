#include <stdio.h>
#include <string.h>
#include "../headers/brainfutils.h"

/*
 * How does brainfuck work?
 * +   -> changes the value of the cell by 1
 * -   -> changes the value of the cell by -1
 * >   -> changes the cell by 1
 * <   -> changes the cell by -1
 * .   -> prints the value of the cell
 * ,   -> accepts input and adds it to the cell
 * []  -> loops if the value of the cell it ends on isn't 0
 */

int main(int argc, char *argv[]){
	if (argc != 2){
		printf("Usage: %s [brainfuck file]\n", argv[0]);
		return 1;
	}
	int pos=0, progress=0;
	char script[strlen(argv[2])]; strcpy(script, argv[2]);
	char cells[atoi()], error[200] = "Don't know what you did, but hope you are happy.\n";
	printf("Script: %s\n\n", script);
	do{
		
		// When it ends reading the script, it kills itself
		if (progress > strlen(script)){
			printf("\n\n\t***\tEND\t***\n\n");
			return 0;
		}

		// A fancier error handler
		if (pos < 0){
			strcpy(error, "Out of cells(left)");
			break;
		}
		if (pos > strlen(cells)){
			strcpy(error, "Out of cells(right)");
			break;
		}

		// Read the character and perform an action based on it
		#include "../headers/brainfutils.h"
		progress++;
	}while(1);
	printf("Error: %s", error); 
	return 0;
}
