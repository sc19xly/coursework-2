#include"GameOfLife.h"
#include"main.h"

//return 0 if it runs successfully otherwise return 1
int main(){
	int times,i,flag,initial;
	printf("Choose your initial state:\n1.saved state\n2.last time state\n");
	scanf("%d",&initial);
	if(initial==2){
	load();
	}
	printf("Choose your mode:(1.selfdefine 2.autoplay\n)");
	scanf("%i",&flag);
	if(initial==1){
	printf("Enter the WIDTH:");
	scanf("%d",&WIDTH);
	printf("Enter the HEIGHT:");
	scanf("%d",&HEIGHT);}
	if(flag==1){
	printf("Enter the times you want:");
	scanf("%d",&times);
	}
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
	if(initial==1)
	init();
	if(initial==2){
	int b_width = WIDTH/CELLSIZE;
        int b_height = HEIGHT/CELLSIZE;
        glClearColor(0.0,0.0,0.0,0.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0,WIDTH,HEIGHT,0,-1,1);
        glMatrixMode(GL_MODELVIEW);
        now=creat(b_width,b_height);
	int a,b,v;
	FILE*f;
	f=fopen("store.txt","r");
	for(a=0;a<b_width;a++){
		for(b=0;b<b_height;b++){
			fscanf(f,"%d,",&v);
			if(v==1)
			(now->box)[b+a*b_width]=v;
		}
	}
	fclose(f);
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
		if(e.type==SDL_KEYDOWN||e.type==SDL_QUIT)
		{
			output();
			break;
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
			sleep(3);
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
	(now->box)[10+1*b_width] = 1;
      (now->box)[10+2*b_width] = 1;
      (now->box)[10+3*b_width] = 1;

        (now->box)[10+20*b_width] = 1;
        (now->box)[11+20*b_width] = 1;
        (now->box)[12+20*b_width] = 1;
	/*(now->box)[1+5*b_width]=1;
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
   	(now->box)[25+7*b_width] = 1;*/
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

void output(){
	int x,y;
	x=WIDTH/CELLSIZE;
	y=HEIGHT/CELLSIZE;
	FILE*fop;
	fop=fopen("store.txt","w");
	int i,j;
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			fprintf(fop,"%d,",(now->box)[j+i*x]);
		}
	}
	fclose(fop);
	FILE*fp;
        fp=fopen("storesize.txt","w");
        fprintf(fp,"%d,",WIDTH);
        fprintf(fp,"%d",HEIGHT);
        fclose(fp);
}


void load(){
	FILE*fp;
	fp=fopen("storesize.txt","r");
	int value,num=0;  
	while( !feof(fp) )
	{
		fscanf(fp,"%d,",&value);
		if(num==0)
		{
			WIDTH=value;
		}
		if(num==1)
			HEIGHT=value;
		num++;
	}
	fclose(fp);
	}
