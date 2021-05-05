#include"GameOfLife.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include"main.h"
#define	correct 1

const int width=200;
const int height=200;
int score;
int stage=1;
int c;
board*b;
board*nexta;
board*t;
//int returnnum;

void tell(char*s){
	if(correct==1&&stage==1)
	printf("%s\n",s);
}
void pass(int m){
	tell("Pass");
	c++;
//	return m;
}
// test check()
int t_check(){
	int a;
	c=0;
	a=check(b,200,100);
	if(a==0)
		pass(c);
	else
		tell("Failed");
	a=check(b,100,200);
	if(a==0)
		pass(c);
	else
		tell("Failed");
	a=check(b,-1,100);
	if(a==0)
		pass(c);
	else
		tell("Failed");
	a=check(b,100,-1);
	if(a==0)
		pass(c);
	else
		tell("Failed");
	a=check(b,10,2);
	if(a==2)
		pass(c);
	else
		tell("Failed");
	printf("%i/5 for the check function\n",c);
	return c;
}

//test the function creat()
void t_creat(){
	board*a;
	c=0;
	a=creat(100,90);
	if(a!=NULL)
		pass(c);
	else
		tell("Failed");
	if(a->width==100)
		pass(c);
	else
		tell("Failed, wrong width");
	if(a->height==90)
		pass(c);
	else 
		tell("Failed,wrong height");
	printf("%i/3 for the creat function\n",c);
}

//test the function generate()
void t_generate(){
	board*a;
	board*e;
	c=0;
	int i,j,flag=0;
	a=creat(100,100);
	e=creat(100,100);
	for(i=0;i<100;i++){
                for(j=0;j<100;j++){
                        (a->box)[i+j*100]=(b->box)[i+j*100];
                }
        }
	generate(a,e);
	for(i=0;i<100;i++){
		for(j=0;j<100;j++){
			if((a->box)[i+j*100]!=(nexta->box)[i+j*100])
				flag=1;
		}
	}
	if(flag==0)
		pass(c);
	else
		tell("Failed");
	printf("%i/1 for the  generate function\n",c);
}	
		
//test the function load()
void t_load(){
	c=0;
	int i,j,flag=0;
	//int WIDTH=0;
	//int HEIGHT=0;
	//board*now;
	now=creat(width,height);
	load();
	if(WIDTH==1000&&HEIGHT==1000)
	{
		pass(c);
		c++;
	}
	else
		printf("Failed,wrong WIDTH and HEIGHT\n");
	for(i=0;i<200;i++){
                for(j=0;j<200;j++){
                        if((now->box)[i+j*200]!=(t->box)[i+j*200])
                        {        
				flag=1;
			//	printf("1");
			}
                }
        }
        if(flag==0)
                pass(c);

	else
		printf("Failed,wrong to load cells\n");
	printf("%i/3 for the load function\n",c);
}

//test function loadsaved(char*filename)
void t_loadsaved(){
	loadsaved("store.txt");
	c=0;
	int i,j,flag=0;
	for(i=0;i<width;i++){
                for(j=0;j<height;j++){
                        if((now->box)[i+j*width]!=(t->box)[i+j*width])
                        {        
				flag=1;
			//	printf("1");
			}
                }
        }
        if(flag==0)
                pass(c);
	else
		tell("Failed");
	printf("%i/1 for the loadsaved function\n",c);
}
// test function output()
void t_output(){
	output();
	t_load();
}
	
int main(){
	//board*b=(board *)malloc(sizeof(board));
	//b->box=(char*)calloc(i*j,sizeof(char));
	//printf("%d",creat(1,0));
	t_creat();
	if(c==0)
		tell("Wrong,the test can not run");
	b=creat(100,100);
	(b->box)[10+1*100] = 1;
        (b->box)[10+2*100] = 1;
        (b->box)[10+3*100] = 1;

        (b->box)[10+20*100] = 1;
        (b->box)[11+20*100] = 1;
        (b->box)[12+20*100] = 1;
	t_check();
	nexta=creat(100,100);
	(nexta->box)[9+2*100]=1;
	(nexta->box)[10+2*100]=1;
	(nexta->box)[11+2*100]=1;
	(nexta->box)[11+19*100]=1;
	(nexta->box)[11+20*100]=1;
	(nexta->box)[11+21*100]=1;
	t_generate();
	t=creat(width,height);
	(t->box)[10+1*width] = 1;
        (t->box)[10+2*width] = 1;
        (t->box)[10+3*width] = 1;

        (t->box)[10+20*width] = 1;
        (t->box)[11+20*width] = 1;
        (t->box)[12+20*width] = 1;
	t_load();
	t_loadsaved();
	t_output();
	return 0;
}
