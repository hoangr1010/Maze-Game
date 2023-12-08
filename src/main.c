#include <stdio.h>
#include <ncurses.h>
#include "game.h"
#include "levels.h"

int main(void){

    initscr();
    start_color();  // Enable colour support
    cbreak();
    keypad(stdscr, TRUE);   // Enable special keys
    nodelay(stdscr, TRUE);  // Removes delay for getch() to return ERR
    //timeout(50); // Adds 10 millisecond delay
    noecho();   // Do not display input characters
    //Display splash screen

    splash_screen();
    // Create a window
    WINDOW *mainWin = newwin(30, 80, 0, 0);
    box(mainWin,0,0);
    refresh();

    // Game start with levels
    level(mainWin, &player, 1);

    level(mainWin, &player, 2);

    level(mainWin, &player, 3);

    getch();

    delwin(mainWin);

    int height, width;
    getmaxyx(stdscr, height, width);

    clear();
    mvprintw(height/2, (width/2)-20, "Congrats, you win the game!\n");
    refresh();

    getch();
    endwin();

    return 0;
}


