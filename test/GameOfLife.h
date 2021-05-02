#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H
#define TEST

#include<stdlib.h>
#include<string.h>

//struct the board
typedef struct board{
	char *box;
	int width;
	int height;
} board;

board* creat(int i,int j);//used to creat the board,return NULL if things go wrong
//check the number of neighbors return 0 if things go wrong
int check(board*p,int i,int j);
//generate the cells
void generate(board*now,board*next);
void init();
void shutdown();
void display();
void output();
void load();
void loadsaved();

int WIDTH;
int HEIGHT;
board*now;
board*next;

#endif
