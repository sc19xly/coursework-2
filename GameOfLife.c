#include"GameofLife.h"

board*creat(int i,int j){
	if(i<=0||j<=0)
		return 0;
	board*b=(board *)malloc(sizeof(board));
	if(!b)
		return 0;
	b->box=(char*)calloc(i*j,sizeof(char));
	if(!(b->box))
	{
		free(b);
		return 0;
	}
	b->width=i;
	b->height=h;
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
				(now->box)[i+j*next->width]==0;
			else if((next->box)[i+j*next->width]==1&&count>3)
				(now->box)[i+j*next->width]=0;
			else if((next->box)[i+j*next->width]==1&&count<=3)
				(now->box)[i+j*next->width]=1;
			else if((next->box)[i+j*next->width]==0&&count==3)
				(now->box)[i+j*next->width]=1;
		}
	}
}
