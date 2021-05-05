#include"GameOfLife.h"
#include"main.h"

//return 0 if it runs successfully otherwise return 1
int run(){

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
	if(initial==1||initial==3){
	if(initial==3)
	now=creat(WIDTH/CELLSIZE,HEIGHT/CELLSIZE);
	init();
	while(initial==3){
		int x,y,mouseX,mouseY;
	SDL_PollEvent(&e);
	if(e.type==SDL_MOUSEMOTION){
	SDL_PollEvent(&e);
	SDL_GetMouseState(&mouseX,&mouseY);
	if(e.button.button==SDL_BUTTON_LEFT){
		SDL_PollEvent(&e);
		x=mouseX/CELLSIZE;y=mouseY/CELLSIZE;
		(now->box)[x+y*WIDTH/CELLSIZE]=1;
		display();
		SDL_GL_SwapWindow(window);
		}
		}
		if(e.type== SDL_KEYDOWN){
		if(e.key.keysym.sym==SDLK_e)
			break;
		}
		if(e.type==SDL_QUIT){
			output();
			return 0;
		}
	if(e.type==SDL_MOUSEBUTTONDOWN){
	SDL_GetMouseState(&mouseX,&mouseY);
	SDL_PollEvent(&e);
		x=mouseX/CELLSIZE;y=mouseY/CELLSIZE;
		(now->box)[x+y*WIDTH/CELLSIZE]=1;
		display();
		SDL_GL_SwapWindow(window);
	}
	}
	}
	if(initial==2){
	int b_width = WIDTH/CELLSIZE;
        int b_height = HEIGHT/CELLSIZE;
        glClearColor(0.0,0.0,0.0,0.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0,WIDTH,HEIGHT,0,-1,1);
        glMatrixMode(GL_MODELVIEW);
		
	next=creat(b_width,b_height);
	}
	if(flag==1){
	i=0;
	while(i<times&&e.type!=SDL_QUIT){
		SDL_PollEvent(&e);
		newTime=SDL_GetTicks();
        	deltaTime=(double)(newTime-lastTime)/10;
        	if(deltaTime>=DTIME){
                        generate(now,next);
                        lastTime=newTime;
				i++;
                }
                display();
                SDL_GL_SwapWindow(window);
		if(e.type==SDL_QUIT)
		{
			output();
			break;
		}
		if(e.type== SDL_KEYDOWN){
		if(e.key.keysym.sym==SDLK_e)
		{
			output();
			break;
		}
		if(e.key.keysym.sym==SDLK_p)
		{
			while(1){
			SDL_PollEvent(&e);
			if(e.type==SDL_KEYDOWN){
				if(e.key.keysym.sym==SDLK_e){
					output();
					return 0;
				}
				if(e.key.keysym.sym==SDLK_p)
					break;
				else
					display();
			}
			if(e.type==SDL_QUIT){
				output();
				return 0;
			}
		}
		}
	}
	}
	}
	if(flag==2){
	newTime=SDL_GetTicks();
        deltaTime=(double)(newTime-lastTime)/10;
        if(deltaTime>=DTIME){
                generate(now,next);
                lastTime=newTime;
        }
        display();
        SDL_GL_SwapWindow(window);
	while (e.type!=SDL_QUIT){
	SDL_PollEvent(&e);
	if(e.type== SDL_KEYDOWN){
		if(e.key.keysym.sym==SDLK_e)
		{
			output();
			break;
		}
		if(e.key.keysym.sym==SDLK_p)
		{
			while(1){
			SDL_PollEvent(&e);
			if(e.type==SDL_KEYDOWN){
				if(e.key.keysym.sym==SDLK_e){
					output();
					return 0;
				}
				if(e.key.keysym.sym==SDLK_p)
					break;
				else
					display();
			}
			if(e.type==SDL_QUIT){
				output();
				return 0;
			}
		}
		}
	}
		newTime=SDL_GetTicks();
                deltaTime=(double)(newTime-lastTime)/10;
                if(deltaTime>=DTIME){
                        generate(now,next);
                        lastTime=newTime;
		}
                display();
                SDL_GL_SwapWindow(window);
		if(e.type==SDL_QUIT){
			output();
			break;
		}
	}
	}
	SDL_GL_DeleteContext(glcontext);
	SDL_DestroyWindow(window);
	SDL_Quit();
	output();
	return 0;
}

int main(){
		printf("Choose your initial state:\n1.saved state\n2.last time state\n3.selfdefine whole world\n");
	scanf("%d",&initial);
	if(initial==3){
		printf("Enter the width:\n");
		scanf("%d",&WIDTH);
		printf("Enter the height:\n");
		scanf("%d",&HEIGHT);
	}
	if(initial==2){
	load();
	if(WIDTH<=0||HEIGHT<=0)
	{
		printf("Invalid input\n");
		return 1;
	}
	}
	if(initial==1){
		printf("Enter the width and height you want:\n1.2000*2000\n2.1000*1000\n3.500*500\n");
		scanf("%d",&wch);
		if(wch==1)
		{
			WIDTH=2000;
			HEIGHT=2000;
		}
		if(wch==2)
		{
			WIDTH=1000;
			HEIGHT=1000;
		}
		if(wch==3)
		{
			WIDTH=500;
			HEIGHT=500;
		}
		now=creat(WIDTH,HEIGHT);
		printf("Enter the figure you want:\n1.Blinker\n2.Toad\n3.Block\n4.Glider\n5.Gosper-glider-gun\n");
		scanf("%d",&fch);
		switch(fch){
			case 1:
				if(wch==1)
					loadsaved("Blinker2k*2k.txt");
				if(wch==2)
					loadsaved("Blinker1k*1k.txt");
				if(wch==3)
					loadsaved("Blinker500*500.txt");
				break;
			case 2:
				if(wch==1)
					loadsaved("Toad2k*2k.txt");
				if(wch==2)
					loadsaved("Toad1k*1k.txt");
				if(wch==3)
					loadsaved("Toad500*500.txt");
				break;
			case 3:
				if(wch==1)
					loadsaved("Block2k*2k.txt");
				if(wch==2)
					loadsaved("Block1k*1k.txt");
				if(wch==3)
					loadsaved("Block500*500.txt");
				break;
			case 4:
				if(wch==1)
					loadsaved("Glider2k*2k.txt");
				if(wch==2)
					loadsaved("Glider1k*1k.txt");
				if(wch==3)
					loadsaved("Glider500*500.txt");
				break;
			case 5:
				if(wch==1)
					loadsaved("Gosper-glider-gun2k*2k.txt");
				if(wch==2)
					loadsaved("Gosper-glider-gun1k*1k.txt");
				if(wch==3)
					loadsaved("Gosper-glider-gun500*500.txt");
				break;
	}
}
	printf("Choose your mode:(1.selfdefine 2.autoplay)\n");
	scanf("%i",&flag);
	if(flag==1){
	printf("Enter the times you want:");
	scanf("%d",&times);
	}
	run();
	return 0;
}

