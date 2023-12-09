#define MAX_WIDTH 100
#define MAX_HEIGHT 100

#ifndef GAME_H
#define GAME_H

struct Character {
    int positionX;
    int positionY; 
    int sword; // 0: no item, 1: sword
    int health; //range: 0-20
} player;

void readMazeFromFile(char maze[MAX_HEIGHT][MAX_WIDTH], int *rows, int *cols, const char *filename);
void drawMaze(WINDOW *win, char maze[MAX_HEIGHT][MAX_WIDTH], int rows, int cols);
void splash_screen();
void printFileContents(FILE *file, WINDOW *win);
void printObject(WINDOW *win, int x, int y, char ch);
//void moveEnemy(Enemy enemy);

struct Enemy{
	int row;
	int col;
};
// Row and col
struct Enemy createEnemy(int row, int col);

int createEnemies(const char *filename, struct Enemy enemies[]);

void moveEnemy(char maze[MAX_HEIGHT][MAX_WIDTH],struct Enemy enemy);

int checkAround(char maze[MAX_HEIGHT][MAX_WIDTH], char checkChar, int playerY, int playerX, int *resultRow, int *resultCol);
void playerInfo(WINDOW *win, struct Character *player);

#endif
