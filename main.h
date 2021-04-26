#ifndef MAIN_H
#define MAIN_H

//#include<linux/delay.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_opengl.h>
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
//#include<windows.h>
//#define WIDTH 1000
//#define HEIGHT 1000
#define CELLSIZE 5
#define DTIME 100.0
//int WIDTH,HEIGHT;
board*next;
board*now;
int lastTime;
int newTime;
double deltaTime;
int WIDTH;
int HEIGHT;

void init();
void shutdown();
void display();
void output();
void load();

#endif
