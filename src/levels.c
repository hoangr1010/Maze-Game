#include <stdio.h>
#include <ncurses.h>
#include "levels.h"
#include "game.h"
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX_HEIGHT 100
#define MAX_WIDTH 100
#define MAX_LENGTH 100


void level(WINDOW *win, const int levelNum) {
	char maze[MAX_HEIGHT][MAX_WIDTH];
	int rows, cols;
	int ch;
	//int testI = 5;

	char filename[MAX_LENGTH];
	snprintf(filename, MAX_LENGTH, "maze%d.txt", levelNum);

	readMazeFromFile(maze, &rows, &cols, filename);

	struct Enemy Enemies[10];
	int eCounter = createEnemies(filename, Enemies);

	int playerX=1;
	int playerY=1;
	
	srand((unsigned int)time(NULL));
	
	maze[playerY][playerX] = 'P';
	drawMaze(win,maze,rows,cols);
	//int safe = 0;
	
	do {
		/* Move Enemies while player is not inputting */
		while ((ch=getch()) == ERR && eCounter > 0){
			/* Move Enemies */
			timeout(450);
			for (int i = 0; i<eCounter; i++ ){
				/* Generate random num */
				int randomNum = rand() % 4 + 1;
				switch (randomNum){
					/* Move up */
					case 1:
						if (maze[Enemies[i].row+1][Enemies[i].col] != '#' && maze[Enemies[i].row+1][Enemies[i].col] != 'T' && maze[Enemies[i].row+1][Enemies[i].col] != '|') {
							maze[Enemies[i].row][Enemies[i].col] = ' ';
							Enemies[i].row++;
							maze[Enemies[i].row][Enemies[i].col] = 'E';
						}
						break;
					/* Move down */
					case 2:
						if (maze[Enemies[i].row-1][Enemies[i].col] != '#' && maze[Enemies[i].row-1][Enemies[i].col] != 'T' && maze[Enemies[i].row-1][Enemies[i].col] != '|') {
							maze[Enemies[i].row][Enemies[i].col] = ' ';
							Enemies[i].row--;
							maze[Enemies[i].row][Enemies[i].col] = 'E';
						}
						break;
					/* Move right */
					case 3:
						if (maze[Enemies[i].row][Enemies[i].col+1] != '#' && maze[Enemies[i].row][Enemies[i].col+1] != 'T' && maze[Enemies[i].row][Enemies[i].col+1] != '|') {
							maze[Enemies[i].row][Enemies[i].col] = ' ';
							Enemies[i].col++;
							maze[Enemies[i].row][Enemies[i].col] = 'E';
						}
						break;
					/* Move left */
					case 4:
						if (maze[Enemies[i].row][Enemies[i].col-1] != '#' && maze[Enemies[i].row][Enemies[i].col-1] != 'T' && maze[Enemies[i].row][Enemies[i].col-1] != '|') {
							maze[Enemies[i].row][Enemies[i].col] = ' ';
							Enemies[i].col--;
							maze[Enemies[i].row][Enemies[i].col] = 'E';
						}
						break;
				}
			}
			drawMaze(win,maze,rows,cols);
		}
		timeout(10);
		//ch = getch();
		/* Handle user input */
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
					/*
					maze[playerY][playerX] = 'P';
					drawMaze(win,maze,rows,cols);*/
				}
				break;
			case KEY_DOWN:
				if (playerY < rows - 1 && maze[playerY+1][playerX] != '#' && maze[playerY+1][playerX] != 'T') {
					maze[playerY][playerX] = ' ';
					playerY++;
					/*
					maze[playerY][playerX] = 'P';
					drawMaze(win,maze,rows,cols);*/
				}
				break;
			case KEY_LEFT:
				if (playerX > 0 && maze[playerY][playerX-1] != '#' && maze[playerY][playerX-1] != 'T') {
                    maze[playerY][playerX] = ' ';
					playerX--;
					/*
					maze[playerY][playerX] = 'P';
					drawMaze(win,maze,rows,cols);*/
				}
				break;
			case KEY_RIGHT:
				if (playerX < cols-1 && maze[playerY][playerX+1] != '#' && maze[playerY][playerX+1] != 'T') {
					maze[playerY][playerX] = ' ';
					playerX++;
					/*
					maze[playerY][playerX] = 'P';
					drawMaze(win,maze,rows,cols);*/
				}
				break;
		}

		/* Check end condition for level */
		if (playerX==cols-1 && playerY==rows-2) {
			break;
		}
		maze[playerY][playerX] = 'P';

		/* Move Enemies */
		/* Draw the new maze */
		drawMaze(win,maze,rows,cols);
		
	} while (1);

	wclear(win);
	mvwprintw(win,rows/2,cols/2, "Congrats! You successfully pass level %d\n", levelNum);
	wrefresh(win);

	getch();
}


