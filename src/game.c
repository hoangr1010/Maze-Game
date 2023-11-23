#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "levels.h"
#include "game.h"

void readMazeFromFile(char maze[MAX_HEIGHT][MAX_WIDTH], int *rows, int *cols, const char *filename) {

	char filepath[] = "/data/";
	strcat(filepath, filename); 
	char filepath[] = "./data/";
	strcat(filepath, filename);

	FILE *file = fopen(filepath, "r");

	if (file == NULL) {
      		fprintf(stderr, "\n");
		endwin();
		exit(EXIT_FAILURE);
	}

	*rows = *cols = 0;
	int c;
	while ((c=fgetc(file)) != EOF && *rows < MAX_HEIGHT) {
@@ -27,22 +35,23 @@ void readMazeFromFile(char maze[MAX_HEIGHT][MAX_WIDTH], int *rows, int *cols, co

void drawMaze(WINDOW *win, char maze[MAX_HEIGHT][MAX_WIDTH], int rows, int cols) {
	wclear(win);

	printw("%c", maze[rows][cols]);
	for (int i=0;i<rows;i++) {
		for (int j=0; i<cols; j++) {
			wprintw(win, "%c", maze[i][j]);
			wprintw(win,"%c", maze[i][j]);
		}
		wprintw(win,"\n");
	}

	wrefresh(win);
}

void splash_screen(){
    

    if (has_colors()){
        init_pair(1, COLOR_GREEN, COLOR_BLACK);
        attron(COLOR_PAIR(1));
        printw("___  ___               ______\n");            
        printw("___  ___               ______\n");
        printw("|  \\/  |               | ___ \\\n");
        printw("| .  . | __ _ _______  | |_/ /   _ _ __  \n");
        printw("| |\\/| |/ _` |_  / _ \\ |    / | | | '_ \\\n");
@@ -53,6 +62,9 @@ void splash_screen(){
        printw("Arrow keys to move, SPACE to attack and Q to use items");
        printw("\npress any key to continue.....");
        refresh();

	getch();
	clear();
        /*
	int ch;
