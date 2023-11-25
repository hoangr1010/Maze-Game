#include <stdio.h>
#include <ncurses.h>
#include "levels.h"
#include "game.h"
#include <stdlib.h>
#define MAX_HEIGHT 100
#define MAX_WIDTH 100
#define MAX_LENGTH 100


void level(WINDOW *win, const int levelNum) {
	FILE *file;
	char maze[MAX_HEIGHT][MAX_WIDTH];
	char filename[MAX_LENGTH];
	snprintf(filename, MAX_LENGTH, "data/maze%d.txt", levelNum);
	//int rows, cols;
	file = fopen(filename, "r");
	//check if file is readable
	if (file == NULL){
		endwin();
		fprintf(stderr, "Error opening file.\n");
		exit(EXIT_FAILURE);
	}
	
	
	//readMazeFromFile(maze, &rows, &cols, filename);
	printFileContents(file, win);
	fclose(file);
	refresh();
	move(0,0);
	getch();
}


