#include <stdio.h>
#include <ncurses.h>
#include "levels.h"
#include "game.h"
#include <stdlib.h>
#include <unistd.h>
#define MAX_HEIGHT 100
#define MAX_WIDTH 100
#define MAX_LENGTH 100


void level(WINDOW *win, const int levelNum) {
	char maze[MAX_HEIGHT][MAX_WIDTH];
	int rows, cols;
	int ch;
	int testI = 5;

	char filename[MAX_LENGTH];
	snprintf(filename, MAX_LENGTH, "maze%d.txt", levelNum);

	readMazeFromFile(maze, &rows, &cols, filename);

	int playerX=1;
	int playerY=1;

	do {
		maze[playerY][playerX] = 'P';
		drawMaze(win,maze,rows,cols);

		ch = getch();

		switch (ch) {
			case 'q':
				wclear(win);
				mvwprintw(win,rows/2,cols/2, "Quit? y/n\n");
				wrefresh(win);
				do {
					ch = getch();
					switch(ch){
						case 'y':
							mvwprintw(win,rows/2,cols/2, "Goodbye\n");
							wrefresh(win);
							sleep(3);
							endwin();
							exit(EXIT_SUCCESS);
						case 'n':
							wclear(win);
							break;
					}
				} while(ch != 'y' && ch != 'n');
				break;
	
			case 'p':
				wclear(win);
				mvwprintw(win,rows/2,cols/2, "Game Pause. Press 'p' to resume");
				wrefresh(win);
				while (getch() != 'p') {}
				wclear(win);
				break;
			case KEY_UP:
				if (playerY > 0 && maze[playerY-1][playerX] != '#' && maze[playerY-1][playerX] != 'T') {
					maze[playerY][playerX] = ' ';
					playerY--;
				}
				break;
			case KEY_DOWN:
				if (playerY < rows - 1 && maze[playerY+1][playerX] != '#' && maze[playerY+1][playerX] != 'T') {
					maze[playerY][playerX] = ' ';
					playerY++;
				}
				break;
			case KEY_LEFT:
				if (playerX > 0 && maze[playerY][playerX-1] != '#' && maze[playerY][playerX-1] != 'T') {
                                        maze[playerY][playerX] = ' ';
					playerX--;
				}
				break;
			case KEY_RIGHT:
				if (playerX < cols-1 && maze[playerY][playerX+1] != '#' && maze[playerY][playerX+1] != 'T') {
					maze[playerY][playerX] = ' ';
					playerX++;
				}
				break;
		}
		if (playerX==cols-1 && playerY==rows-2) {
			break;
		}
	} while (1);

	wclear(win);
	mvwprintw(win,rows/2,cols/2, "Congrats! You successfully pass level %d\n", levelNum);
	wrefresh(win);

	getch();
}


