#include"GameOfLife.h"

#include<SDL2/SDL.h>
#include<SDL2/SDL_opengl.h>
#include<stdio.h>
#include<stdlib.h>

#define WIDTH 400
#define HEIGHT 400
#define CELLSIZE 5
#define DTIME 1.0/10.0

board*next=NULL;
board*now=NULL;
int lastTime=0;
int newTime=0;
double deltaTime=0.0;

void init();
void shutdown();
void display();

//return 0 if it runs successfully otherwise return 1
int main(int argc,char** argv){
	SDL_Window *window;
	SDL_GLContext glcontext;
	SDL_Event e;
	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER)!=0){
		fprintf(stderr,"\nUnable to initialize SDL: %s\n",SDL_GetError());
		return 1;
	}
	window=SDL_CreateWindow(
	"GAME OF LIFE",
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,
	WIDTH,
	HEIGHT,
	SDL_WINDOW_OPENGL
	);
	if(window ==NULL){
		fprintf(stderr,"\nCould not create window: %s\n",SDL_GetError());
		SDL_Quit();
		return 1;
	}
	glcontext=SDL_GL_CreateContext(window);
	init();
	while(e.type!=SDL_QUIT){
		SDL_PollEvent(&e);
		newTime=SDL_GetTicks();
		deltaTime=(double)(newTime-lastTime)/1000;
		if(deltaTime>=DTIME){
			generate(now,next);
			lastTime=newTime;
		}
		display();
		SDL_GL_SwapWindow(window);
	}
	SDL_GL_DeleteContext(glcontext);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

void init(){
	int b_width = WIDTH/CELLSIZE;
	int b_height = HEIGHT/CELLSIZE;
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,WIDTH,HEIGHT,0,-1,1);
	glMatrixMode(GL_MODELVIEW);
	now=creat(b_width,b_height);
	(now->box)[1+5*b_width]=1;
	(now->box)[2+5*b_width]=1;
	(now->box)[1+6*b_width]=1;
	(now->box)[2+6*b_width]=1;
	(now->box)[35+3*b_width] = 1;
	(now->box)[36+3*b_width] = 1;
	(now->box)[35+4*b_width] = 1;
	(now->box)[36+4*b_width] = 1;

	(now->box)[13+3*b_width] = 1;
	(now->box)[14+3*b_width] = 1;
	(now->box)[12+4*b_width] = 1;
	(now->box)[16+4*b_width] = 1;
	(now->box)[11+5*b_width] = 1;
	(now->box)[17+5*b_width] = 1;
	(now->box)[11+6*b_width] = 1;
	(now->box)[15+6*b_width] = 1;
	(now->box)[17+6*b_width] = 1;
	(now->box)[18+6*b_width] = 1;
   	(now->box)[11+7*b_width] = 1;
   	(now->box)[17+7*b_width] = 1;
   	(now->box)[12+8*b_width] = 1;
   	(now->box)[16+8*b_width] = 1;
   	(now->box)[13+9*b_width] = 1;
   	(now->box)[14+9*b_width] = 1;

   	(now->box)[21+3*b_width] = 1;
   	(now->box)[22+3*b_width] = 1;
   	(now->box)[21+4*b_width] = 1;
   	(now->box)[22+4*b_width] = 1;
   	(now->box)[21+5*b_width] = 1;
   	(now->box)[22+5*b_width] = 1;
   	(now->box)[23+2*b_width] = 1;
   	(now->box)[23+6*b_width] = 1;
   	(now->box)[25+2*b_width] = 1;
   	(now->box)[25+6*b_width] = 1;
   	(now->box)[25+1*b_width] = 1;
   	(now->box)[25+7*b_width] = 1;
	next=creat(b_width,b_height);
}

void display(){
	int i,j,x,y;
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	for(i=0;i<now->width;i++){
		for(j=0;j<now->height;j++){
			x=i*CELLSIZE;
			y=j*CELLSIZE;
			if((now->box)[i+j*now->width]==1)
			{
				glBegin(GL_QUADS);
				glColor3f(1.0,1.0,1.0);
				glVertex2d(x,y);
				glVertex2d(x+CELLSIZE,y);
				glVertex2d(x+CELLSIZE,y+CELLSIZE);
				glVertex2d(x,y+CELLSIZE);
				glEnd();
			}
		}
	}
}

void shutdown(){
}
