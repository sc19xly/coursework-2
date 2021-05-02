#include"GameOfLife.h"
#include"main.h"

board*creat(int i,int j){
	//board*b=(board *)malloc(sizeof(board));
	//b->box=(char*)calloc(i*j,sizeof(char));
	board*b=(board *)malloc(sizeof(board));
	b->box=(char*)calloc(i*j,sizeof(char));
	if(!(b->box))
	{
		free(b);
	}
	b->width=i;
	b->height=j;
	return b;
}

int check(board*p,int i,int j){
	int x,y,num=0;
	if(i>=p->width||j>=p->height||i<0||j<0)
		return 0;
	for(x=-1;x<=1;x++) {
		for(y=-1;y<=1;y++){
			if(i+x>=0&&i+x<p->width&&j+y>=0&&j+y<p->height&&!(x==0&&y==0)){
				if(p->box[(x+i)+(j+y)*p->width]==1)
					num++;
				}
			}
		}
	return num;
}

void generate(board*now,board*next){
	int i,j,num;
	memcpy(next->box,now->box,(now->width*now->height)*sizeof(char));
	for(i=0;i<next->width;i++){
		for(j=0;j<next->height;j++){
			num=check(next,i,j);
			if((next->box)[i+j*next->width]==1&&num<2)
				(now->box)[i+j*next->width]=0;
			else if((next->box)[i+j*next->width]==1&&num>3)
				(now->box)[i+j*next->width]=0;
			else if((next->box)[i+j*next->width]==1&&num<=3)
				(now->box)[i+j*next->width]=1;
			else if((next->box)[i+j*next->width]==0&&num==3)
				(now->box)[i+j*next->width]=1;
		}
	}
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
	int b_width = WIDTH/CELLSIZE;
        int b_height = HEIGHT/CELLSIZE;
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
}

void loadsaved(char*filename){
	FILE*fp;
	fp=fopen(filename,"r");
	int a,b,v;
	int b_width=WIDTH/CELLSIZE;
	int b_height=HEIGHT/CELLSIZE;
	now=creat(b_width,b_height);
	for(a=0;a<b_width;a++){
		for(b=0;b<b_height;b++){
			fscanf(fp,"%d,",&v);
			if(v==1)
				(now->box)[b+a*b_width]=v;
		}
	}
	fclose(fp);
}
