#include"Monster.h"
#include"Dragon.h"
#include"Invaders.h"
class Enemy
{
public :
    Monster* monster;
	    Dragon* dragon;
	   Invaders* invaders[20];    

	Enemy(int a,int b,string path)
	{
	monster=NULL;
	dragon=NULL;
	for(int i=0;i<20;i++)
        {
         invaders[i]=NULL;
        }
	}
	
void set_enemies(int phase)
{
	if (phase==1)
   {
 		  int a=0;
         	 int x1=200,y1=10;
		for(int i=0;i<5;i++)
		{
		 invaders[i]=new Invaders("Beta",x1+=a,y1,"img/enemy_2.png");
		 a=100;
		}
		a=0;
		for(int i=5;i<10;i++)
		{
		 invaders[i]=new Invaders("Alpha",x1+100,y1+=a,"img/enemy_1.png");
		 a=100;
		}
		a=0;
		x1=100;
		y1=10;
		for(int i=10;i<15;i++)
		{
		 invaders[i]=new Invaders("Alpha",x1,y1+=a,"img/enemy_1.png");
		 a=100;
		}
		a=100;
		for(int i=15;i<20;i++)
		{
		 invaders[i]=new Invaders("Gamma",x1+=a,y1,"img/enemy_3.png");
		 a=100;
		}
	}
	else if(phase==2)
	 {
	  int a=0;
	  int x1=780/2,y1=10;
	    for(int i=0;i<4;i++)
	     {
	      		 invaders[i]=new Invaders("Beta",x1+=a,y1+=a,"img/enemy_2.png");
	      		 a=100;
	     }
	    for(int i=4;i<9;i++)
	     {
	       		 invaders[i]=new Invaders("Gamma",x1-=a,y1,"img/enemy_3.png");
	     }
	     x1-=200;y1+=100;
	     for(int i=9;i<13;i++)
	      {
	        invaders[i]=new Invaders("Alpha",x1+=a,y1-=a,"img/enemy_1.png");
	      }
	 }
	else if (phase == 3 )
	 {
	  int a=0;
	  int x1=780/2,y1=10;
	   for(int i=0;i<5;i++)
	   {
	      invaders[i]=new Invaders("Gamma",x1,y1+=a,"img/enemy_3.png");
	      a=100;
	   }
	   a=0;
	   x1=780/4;y1=200;
	   for(int i=5;i<10;i++)
	   {
	      invaders[i]=new Invaders("Beta",x1+=a,y1,"img/enemy_2.png");
	      a=100;
	   }
	   
	 }
}

void set_Dragon()
{
 dragon=new Dragon(0,0,"img/dragon.png","img/addon/dragon1.png",780/2,10);
}
void set_monster()
{
	monster=new Monster(0,0,"img/monster.png","img/PNG/Lasers/laserRed09.png",780/2,10);
}
	
};
