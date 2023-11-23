#define MAX_WIDTH 100
#define MAX_HEIGHT 100

#ifndef GAME_H
#define GAME_H

void readMazeFromFile(char maze[MAX_HEIGHT][MAX_WIDTH], int *rows, int *cols, const char *filename);
void drawMaze(WINDOW *win, char maze[MAX_HEIGHT][MAX_WIDTH], int rows, int cols);
void drawLevel(WINDOW *win, char level[MAX_HEIGHT][MAX_WIDTH], int rows, int cols);
void level1(WINDOW *win);
void level2(WINDOW *win);
void level3(WINDOW *win);

#endif
