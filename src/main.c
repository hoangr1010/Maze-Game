#include <stdio.h>
#include <ncurses.h>
#include "game.h"

int main(void){

    initscr();
    start_color();  // Enable colour support
    cbreak();   // Disable line buffering
    raw();
    keypad(stdscr, TRUE);   // Enable special keys
    noecho();   // Do not display input characters

    /* Display splash screen */
    splash_screen();

    getchar();
    endwin();

    return 0;
}
