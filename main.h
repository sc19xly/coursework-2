#include<SDL2/SDL.h>
#include<SDL2/SDL_opengl.h>
#include<stdio.h>
#include<stdlib.h>

#define WIDTH 400
#define HEIGHT 400
#define CELLSIZE 5
#define DTIME 1.0/10.0

extern board*next;
extern board*now;
extern int lastTime;
extern int newTime;
double deltaTime;

void init();
void shutdown();
void display();
