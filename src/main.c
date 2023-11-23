#include <stdio.h>
#include <ncurses.h>
#include "game.h"
#include "levels.h"

int main(void){

int main(void) {
    initscr();
    start_color();  // Enable colour support
    cbreak();   // Disable line buffering
    /* Display splash screen */
    splash_screen();

    getchar();
    // Create a window
    WINDOW *mainWin = newwin(30, 30, 0, 0);
    box(mainWin,0,0);
    refresh();

    // Game start with levels
    level(mainWin, 1);

    level(mainWin, 2);

    level(mainWin, 3);

    getch();

    delwin(mainWin);
    endwin();

    return 0;
