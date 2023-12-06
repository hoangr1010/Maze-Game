#include <stdio.h>
#include <ncurses.h>
#include "levels.h"
#include "game.h"
#include <stdlib.h>
#include <unistd.h>
#define MAX_HEIGHT 100
#define MAX_WIDTH 100
#define MAX_LENGTH 100


void level(WINDOW *win, struct Character *player, const int levelNum) {
	char maze[MAX_HEIGHT][MAX_WIDTH];
	int rows, cols;
	int ch;
	char hiddenBlock;
	// resultRow, resultCol is coords of target block we check around player
	int resultRow, resultCol;

	getch();

	char filename[MAX_LENGTH];
	snprintf(filename, MAX_LENGTH, "maze%d.txt", levelNum);

	readMazeFromFile(maze, &rows, &cols, filename);

	do {
		if (maze[player->positionY][player->positionX] != 'P') {
			hiddenBlock = maze[player->positionY][player->positionX];
		}
		maze[player->positionY][player->positionX] = 'P';
		drawMaze(win,maze,rows,cols);
	        playerInfo(win,player);
		wrefresh(win);

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

			case ' ':
			// open the door
				if (checkAround(maze, '|', player->positionY, player->positionX, &resultRow, &resultCol)) {
					// delete door block
					maze[resultRow][resultCol] = ' ';
				}

				if (checkAround(maze, 'S', player->positionY, player->positionX, &resultRow, &resultCol)) {
					player->sword=1;
					maze[resultRow][resultCol] = ' ';
				}

				break;

			case KEY_UP:
				if (player->positionY > 0 && maze[player->positionY-1][player->positionX] == ' ') {
                                        maze[player->positionY][player->positionX] = hiddenBlock;
					(player->positionY)--;
				}
				break;
			case KEY_DOWN:
				if (player->positionY < rows - 1 && maze[player->positionY+1][player->positionX] == ' ') {
                                        maze[player->positionY][player->positionX] = hiddenBlock;
					(player->positionY)++;
				}
				break;
			case KEY_LEFT:
				if (player->positionX > 0 && maze[player->positionY][player->positionX-1] == ' ') {
                                        maze[player->positionY][player->positionX] = hiddenBlock;
 					player->positionX--;
				}
				break;
			case KEY_RIGHT:
				if (player->positionX < cols-1 && maze[player->positionY][player->positionX+1] == ' ') {
					maze[player->positionY][player->positionX] = hiddenBlock;
					player->positionX++;
				}
				break;
		}
		if (player->positionX==cols-1 && player->positionY==rows-2) {
			break;
		}
	} while (1);

	wclear(win);
	mvwprintw(win,rows/2,cols/2, "Congrats! You successfully pass level %d\n", levelNum);
	wrefresh(win);

	//reset player coordinates
	player->positionY = 1;
	player->positionX = 1;

	getch();
}



