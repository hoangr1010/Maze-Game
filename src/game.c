#include <ncurses.h>
#include <stdio.h>
#include <string.h>
#include "game.h"

void readMazeFromFile(char maze[MAX_HEIGHT][MAX_WIDTH], int *rows, int *cols, const char *filename) {

	char filepath[] = "/data/";
	strcat(filepath, filename); 
	FILE *file = fopen(filepath, "r");

	*rows = *cols = 0;
	int c;
	while ((c=fgetc(file)) != EOF && *rows < MAX_HEIGHT) {
		if (c=='\n') {
			*cols = 0;
			(*rows)++;
		} else {
			maze[*rows][(*cols)] = c;
			(*cols)++;
		}
	}

	fclose(file);
}

void drawMaze(WINDOW *win, char maze[MAX_HEIGHT][MAX_WIDTH], int rows, int cols) {
	wclear(win);

	for (int i=0;i<rows;i++) {
		for (int j=0; i<cols; j++) {
			wprintw(win, "%c", maze[i][j]);
		}
		wprintw(win,"\n");
	}
	wrefresh(win);
}


