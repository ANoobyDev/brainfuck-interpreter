#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 80000

// Calcula estimacion del inicio del bucle
int loop(char src[], int pos);

// Busca errores en el codigo
// void checkErrors(char src[], char args[]);

// Interpretador
int main(int argc, char *argv[]){
    
    // Comprueba que los argumentos sean los correctos
    if (argc < 2 || argc > 3){
        fputs("usage: ./brainfuck [path/to/file.bf] [args]\n", stderr);
        return 1;
    }

    // Obtener el codigo fuente del archivo e imprimirlo
    char source[LEN]="";
    FILE *file = fopen(argv[1], "r");
    if (file == NULL){
        printf("\n\nFile \"%s\" was not found.\n", argv[1]);
        exit(1);
    }
    printf("\nSource code:\n %s", fgets(source, LEN, file));
    fclose(file);

    // Obtiene los argumentos
    if (argc == 3){
        char args = *argv[1];
        printf("\n\nArguments:   %s", args);
    }

    puts("\n\n");

    // Busca errores simples (no es 100% necesario para el funcionamiento del programa)
    // FIXME:
    // checkErrors(source, args);

    puts("\n\nCode returned 0");
    return 0;
}

int loop(char src[], int pos){
    int endLoop;
    char item;
    for(;;){
        item = src[--pos];
        if (item == ']'){
            endLoop++;
        } else if (item == '[' && endLoop != 0){
            endLoop--;
        } else if (item == '[' && endLoop == 0){
            break;
        }
    }
    return pos;
}

// FIXME: Saltan errores que no deberan
/*void checkErrors(char src[], char args[]){
    int lpStat, clStat, getInp, err;
    for (int i; i != strlen(src); i++){
        switch(src[i]){
            case('['):
                lpStat++;

            case(']'):
                lpStat--;

            case('>'):
                clStat++;

            case('<'):
                clStat--;

            case(','):
                getInp++;
        }
    }
    
    if (lpStat != 0){
        err += 1;
    }

    if (clStat < 0){
        err += 2;
    }

    // Si no hay argumentos pero el programa pregunta por ellos o si no hay suficientes argumentos
    if (strlen(*argv) == 3){
        if (strlen(*argv) < getInp){
            err += 4;
        }
    } else if (getInp != 0){                    
        err += 4;
    }

    if (err > 0){
        printf("\n\nCode returned %i\n", err);
        exit(err);
    }
}*/
