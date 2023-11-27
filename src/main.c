#include <stdio.h>
#include <ncurses.h>
#include "game.h"
#include "levels.h"

int main(void){

    initscr();
    start_color();  // Enable colour support
    cbreak();   // Disable line buffering
    raw();
    keypad(stdscr, TRUE);   // Enable special keys
    noecho();   // Do not display input characters
    //Display splash screen

    splash_screen();
    // Create a window
    WINDOW *mainWin = newwin(30, 80, 0, 0);
    box(mainWin,0,0);
    refresh();

    // Game start with levels
    level(mainWin, 1);

    level(mainWin, 2);

    level(mainWin, 3);

    getch();

    delwin(mainWin);

    int height, width;
    getmaxyx(stdscr, height, width);

    clear();
    mvprintw(height, width-20, "Congrats, you win the game!\n");
    refresh();

    getch();
    endwin();

    return 0;
}


