#include <stdio.h>
#include <ncurses.h>
#include "levels.h"
#include "game.h"
#define MAX_HEIGHT 100
#define MAX_WIDTH 100
#define MAX_LENGTH 30

void level(WINDOW *win, const int levelNum) {

	//char maze[MAX_HEIGHT][MAX_WIDTH];
	//char filename[MAX_LENGTH];
	//snprintf(filename, MAX_LENGTH, "maze%d.txt", levelNum);
	//int rows, cols;

	//readMazeFromFile(maze, &rows, &cols, filename);
	char maze[11][19] = {
    "##################",
    "|     #   #      #",
    "####  #   #     ##",
    "#           |---|#",
    "####  #    #######",
    "#     #    []    #",
    "#  #  #T   #  #  #",
    "#  #  #    #  #  #",
    "#######    ####  #",
    "#       T     #  |",
    "##################"
	};
	wprintw(win,"%c",maze[10][10]);
	wrefresh(win);
	getch();
	drawMaze(win, maze, 11, 19);

	getch();

}


