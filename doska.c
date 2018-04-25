#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "check_pozishion.h"
#include "doska.h"

char **container;

char **_board() {
    int i,j;
    container = (char**)malloc(8 * sizeof(char*));
    for (i = 0; i < 8; i++) {
        container[i] = (char*)malloc(8 * sizeof(char));
        for (j = 0; j < 8; j++) {
            container[i][j] = ' ';
        }
    }
    char gl[] = {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'};
    char p = 'p';

    for (i = 0; i < 8; i++) {
        container[0][i] = gl[i];
        container[7][i] = gl[i] - 32;
        container[1][i] = p;
        container[6][i] = p - 32;
    }    
    return container; 
}

void print_new_board() {
    container = _board();
    print_board(container);
}

void print_board() {
    system("clear");
    printf("\n");
    for (int i = 0; i < 8; i++) {
        printf("\t  %s%d%s",CYAN, 8 - i, RESET);
        for (int j = 0; j < 8; j++) {
            printf(" %c", container[i][j]);
        }
        printf("\n");
    }
    printf("\t   %s",CYAN);
    for (char p = 'a'; p <= 'h'; p++) {
        printf(" %c", p);
    }
    printf("%s\n", RESET);
}
