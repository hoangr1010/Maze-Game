#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "levels.h"
#include "game.h"

struct Character player = {1, 1, 0, 100};

void readMazeFromFile(char maze[MAX_HEIGHT][MAX_WIDTH], int *rows, int *cols, const char *filename) {

	char filepath[] = "data/";
	strcat(filepath, filename);

	FILE *file = fopen(filepath, "r");

	if (file == NULL) {
		fprintf(stderr, "Error opening file: %s\n", filepath);
		exit(EXIT_FAILURE);
	}

	*rows = *cols = 0;
	int c;

	while ((c=fgetc(file)) != EOF) {
		if (c=='\n') {
			(*cols) = 0;
			(*rows)++;
		} else {
			maze[(*rows)][(*cols)] = c;
			(*cols)++;
		}
	}
	fclose(file);

	(*cols) = strlen(maze[0]);

	/*
	for (int i=0;i<(*rows);i++) {
               	for (int j=0; j<(*cols); j++) {
                       	printf("%c", maze[i][j]);
               	}
               	printf("\n");
       	}

		fclose(file);
	*/
}

void drawMaze(WINDOW *win, char maze[MAX_HEIGHT][MAX_WIDTH], int rows, int cols) {
	wclear(win);

	for (int i=0;i<rows;i++) {
		for (int j=0; j<cols; j++) {
			wprintw(win,"%c", maze[i][j]);
		}
		wprintw(win,"\n");
	}

	wprintw(win,"\nHEALTH PORTION: +++++++++++++++++++++\n");
	wprintw(win,"items: none");

	wrefresh(win);
}

void splash_screen(){

    if (has_colors()){
        init_pair(1, COLOR_GREEN, COLOR_BLACK);
        attron(COLOR_PAIR(1));
        printw("___  ___               ______\n");
        printw("|  \\/  |               | ___ \\\n");
        printw("| .  . | __ _ _______  | |_/ /   _ _ __  \n");
        printw("| |\\/| |/ _` |_  / _ \\ |    / | | | '_ \\\n");
	printw("| |  | | (_| |/ /  __/ | |\\ \\ |_| | | | |\n");
        printw("\\_|  |_/\\__,_/___\\___| \\_| \\_\\__,_|_| |_|\n");
        attroff(COLOR_PAIR(1));
        printw("\nEscape the maze.\n");
        printw("Arrow keys to move, SPACE to attack and Q to use items");
        printw("\npress any key to continue.....");
        refresh();

	getch();
	//clear();
	//refresh();
        /*
	int ch;

        while((ch = getch()) == err()){
            printw("\npress any key to continue...");
            refresh();
        }
        */
    }
    return;
}
