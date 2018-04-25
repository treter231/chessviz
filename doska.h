#ifndef __BOARD_H__
    #define __BOARD_H__

    #define RESET "\033[0m"
    #define GREEN "\033[1;32m"
    #define BLUE  "\033[34m"
    #define RED   "\033[1;31m"
    #define CYAN  "\033[1;36m"
    #define GRAY  "\033[2m"
    #define BLACK "\033[30m"

    void print_new_board();
    int board_func(char *places);
    void print_board();
#endif