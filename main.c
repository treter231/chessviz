#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "doska.h"

void help_print();
void info_print();
int board_main();

int main() {
    system("clear");
    char q;
    info_print();
    scanf("%c", &q);
    if (q == 's') {
        board_main();
        return 0;
    } else if (q == 'q'){
        system("clear");
        printf("%sGoodbye!%s\n",BLACK, RESET);
        return 0;
    } else {
        system("clear");
        main();
    }
    return 0;
}

char places[6];
int exitt = 0;

int board_main() {
    system("clear");
    print_new_board();
    
    while (exitt == 0) {
        help_print();
        printf("Введите координаты перехода \n."
        "Пример a2-c8\n""\t\t%sCommand:\n\t\t ", GREEN);
        scanf("%s", places);
        printf("%s", RESET);
        if (places[0] == 'r') {
            system("clear");
            exitt = 1;
            board_main();
        } else if (places[0] == 'q') {
            system("clear");
            printf("%sGoodbye!%s\n",BLACK, RESET);
            return 0;
        }
        system("clear");
        exitt = board_func(places);
        if (exitt == -1) {
            print_board();
            if (places[0] == 'r') {
                printf("%s\t\tRestart!\n%s", GREEN, RESET);
            } else {
                printf("%s\tНеправильные координаты\n%s", RED, RESET);
            }
            exitt = 0;
        }
    }
    return 0;
}
