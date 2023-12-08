#define MAX_WIDTH 100
#define MAX_HEIGHT 100

#ifndef GAME_H
#define GAME_H

void readMazeFromFile(char maze[MAX_HEIGHT][MAX_WIDTH], int *rows, int *cols, const char *filename);
void drawMaze(WINDOW *win, char maze[MAX_HEIGHT][MAX_WIDTH], int rows, int cols);
void splash_screen();
void printFileContents(FILE *file, WINDOW *win);
//void moveEnemy(Enemy enemy);

struct Enemy{
	int row;
	int col;
};
// Row and col
struct Enemy createEnemy(int row, int col);

int createEnemies(const char *filename, struct Enemy enemies[]);

void moveEnemy(char maze[MAX_HEIGHT][MAX_WIDTH],struct Enemy enemy);

#endif
