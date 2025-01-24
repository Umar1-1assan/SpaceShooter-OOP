#include <SFML/Graphics.hpp>
#include<string.h>
#include<iostream>
#include"Bullet.h"
#include"power_up.h"

#include"Danger.h"
#include"Lives.h"
#include"Fire.h"
using namespace std;
using namespace sf;

class Player{
public:
Texture tex;
Sprite sprite;

int player_lives;
float speed=0.2;
float x,y;
Bullet* bullet;
int total_bullet;
int n;

power_up* powerup;
Bullet* bullets1,*bullets2,*bullets3,*bullets4,*bullets5,*bullets6;
int p_bullets;
bool pu;
int c;
float ptime;


Danger* danger;

Lives* lives;

Fire* fires;
////////////////////
int score;
///////////////////////////////////////////////////////////
Player(std::string png_path,string blt_path)
{
tex.loadFromFile(png_path);
sprite.setTexture(tex);
x=340;y=700;
sprite.setPosition(sf::Vector2f(x,y));
sprite.setScale(0.75,0.75);


powerup=NULL;
ptime=5000;
pu=0;
bullets1=NULL;
bullets3=NULL;
bullets4=NULL;
bullets5=NULL;
bullets2=NULL;
bullets6=NULL;
p_bullets=0;

danger=NULL;
lives=NULL;
fires=NULL;

player_lives=3;
/////////////////////////////////////
bullet=NULL;
total_bullet=0;
//count=0;
c=0;
score=0;
}
///////////////////////////////////////////////////////
void fire()
{
 // cout<<total_bullet<<endl;
	total_bullet+=1;
	Bullet* new_bullet=new Bullet(x+35,y,"img/PNG/Lasers/laserGreen11.png");
	Bullet* t=new Bullet[total_bullet];
	for(int i=0;i<total_bullet-1;i++)
	{
	//cout<<"here"<<i<<endl;
	 	t[i]=bullet[i];
	}
	t[total_bullet-1]=*new_bullet;
		delete new_bullet;
	if(bullet!=NULL)
	delete[] bullet;
	bullet=t;
     
}
void update_bullet()
{

    if(bullet!=NULL)
		{
	  for(int i=0;i<total_bullet;i++)
  	{	
 	  bullet[i].move();
  	}

  
  		}	
	
}

///////////////////////////power up ///////////////////////////

 void pup()
 {
  powerup=new power_up(rand()%770+1,0,"img/PNG/Power-ups/powerupGreen.png");
 }
 void update_power_up()
 {
 if(powerup!=NULL)
 {
  powerup->move();
  if(powerup->y>=y)
  {
  pu=1;
			
 power_up_bullets();
  	  
   delete powerup;
   powerup=NULL;
   }
   else if(powerup->y>=780)
    {
    	delete powerup;
   	powerup=NULL;
    }
  }
   
 }
 void power_up_bullets()
 {
  	p_bullets++;
   	Bullet* new_bullet=new Bullet(x,y,"img/PNG/Lasers/laserGreen11.png");
	Bullet* t=new Bullet[p_bullets];
	for(int i=0;i<p_bullets-1;i++)
	{
	 	t[i]=bullets1[i];
	}
	t[p_bullets-1]=*new_bullet;
		delete new_bullet;
	if(bullets1!=NULL)
	delete[] bullets1;
	bullets1=t;
	
	 new_bullet=new Bullet(x+50,y,"img/PNG/Lasers/laserGreen11.png");
	  t=new Bullet[p_bullets];
	for(int i=0;i<p_bullets-1;i++)
	{
	 	t[i]=bullets2[i];
	}
	t[p_bullets-1]=*new_bullet;
		delete new_bullet;
	if(bullets2!=NULL)
	delete[] bullets2;
	bullets2=t;	
	
	new_bullet=new Bullet(x-50,y,"img/PNG/Lasers/laserGreen11.png");
	  t=new Bullet[p_bullets];
	for(int i=0;i<p_bullets-1;i++)
	{
	 	t[i]=bullets3[i];
	}
	t[p_bullets-1]=*new_bullet;
		delete new_bullet;
	if(bullets3!=NULL)
	delete[] bullets3;
	bullets3=t;
	
	new_bullet=new Bullet(x-70,y,"img/PNG/Lasers/laserGreen11.png");
	  t=new Bullet[p_bullets];
	for(int i=0;i<p_bullets-1;i++)
	{
	 	t[i]=bullets4[i];
	}
	t[p_bullets-1]=*new_bullet;
		delete new_bullet;
	if(bullets4!=NULL)
	delete[] bullets4;
	bullets4=t;
	
	new_bullet=new Bullet(x+70,y,"img/PNG/Lasers/laserGreen11.png");
	  t=new Bullet[p_bullets];
	for(int i=0;i<p_bullets-1;i++)
	{
	 	t[i]=bullets5[i];
	}
	t[p_bullets-1]=*new_bullet;
		delete new_bullet;
	if(bullets5!=NULL)
	delete[] bullets5;
	bullets5=t;
	
	new_bullet=new Bullet(x+100,y,"img/PNG/Lasers/laserGreen13.png");
	  t=new Bullet[p_bullets];
	for(int i=0;i<p_bullets-1;i++)
	{
	 	t[i]=bullets6[i];
	}
	t[p_bullets-1]=*new_bullet;
		delete new_bullet;
	if(bullets6!=NULL)
	delete[] bullets6;
	bullets6=t;
	
 }
 void powerup_effect()
 {
  	if(pu)
  	{
  	 if(ptime>=0)
  	 {
  	 	c++;
		//cout<<ptime<<endl;
		if(c>=200)
		{
  			   power_up_bullets();
  			   c=0;   
  		}
  		 // if(bullets1!=NULL)
		{
		  for(int i=0;i<p_bullets;i++)
  		{	
 		  bullets1[i].move();
 		  bullets2[i].move();
 		  bullets3[i].move();
 		  bullets4[i].move();
 		  bullets5[i].move();
 		  bullets6[i].move();
  		}
  		}
  	   ptime-=1;
  	 }
  	 else 
  	 { 
  	         if(bullets1!=NULL)
  	         {
  	   	  delete[] bullets1;
  	   	  delete[] bullets2;
  	   	  delete[] bullets3;
  	   	  delete[] bullets4;
  	   	    	   	  delete[] bullets5;
  	   	    	   	  delete[] bullets6;
  	   	    	   	  
  	   	  }
  	    	  bullets1=NULL;	
  	    	  bullets2=NULL; 
  	    	  bullets3=NULL; 	
  	    	    	    	  bullets4=NULL; 	  
  	    	    	    	    	    	  bullets5=NULL; 	  
  	    	    	    	    	    	    	    	  bullets6=NULL; 	    
  	    	  ptime=5000;
  	    	  pu=0;
  	    	  p_bullets=0;
  	 }
  	}
 }
///////////////////////////////////////////////////////

void dngr()
{
   danger=new Danger(rand()%770+1,0,"img/PNG/Power-ups/powerupRed_bolt.png");
}
void update_danger()
 {
 if(danger!=NULL)
 {
  danger->move();
  if(danger->y>=y)
  {	  
   player_lives-=1;
   delete danger;
   danger=NULL;
   }
   else if(danger->y>=780)
    {
       
    	delete danger;
   	danger=NULL;
    }
  
  }
}
///////////////////////////////////////////////
void lvs()
{
   lives=new Lives(rand()%770+1,0,"img/PNG/Power-ups/powerupBlue_shield.png");
}
void update_lives()
 {
 if(lives!=NULL)
 {
  lives->move();
  if(lives->y>=y)
  {	  
   player_lives+=1;
   delete lives;
   lives=NULL;
   }
   else if(lives->y>=780)
    {
    	delete lives;
   	lives=NULL;
    }
  
  }
}
///////////////////////////////////////////////////////////
void fre()
{
   fires=new Fire(rand()%770+1,0,"img/PNG/Power-ups/bolt_gold.png");
}
void update_fire()
 {
 if(fires!=NULL)
 {
  fires->move();
  if(fires->y>=y)
  {	  
  //////////////////////fire effect 
   delete fires;
   fires=NULL;
   }
   else if(fires->y>=780)
    {
    	delete fires;
   	fires=NULL;
    }
  
  }
}

//////////////////////////////////////////////////////////
void move(std::string s)
{
	float delta_x=0,delta_y=0;
	if (s=="ur")
	{
	tex.loadFromFile("img/addon/Player1.png");
	sprite.setTexture(tex);
	//	sprite.Origin(x+20.f,y+20.f);
	}
	else if (s=="ul")
	{
	tex.loadFromFile("img/addon/Player2.png");
	sprite.setTexture(tex);
	//sprite.Origin(sf::Vector2f(x+20,y+20));
	}
	else if(s=="l")
	{
		delta_x=-1;
		x-=1;
	}
	else if(s=="r")
	{
		delta_x=1;
		x+=1;
		}
	else if(s=="u")
	{
		delta_y=-1;
		y-=1;
	}
	else if(s=="d")
	{
	tex.loadFromFile("img/player_ship.png");
	sprite.setTexture(tex);
		delta_y=1;
		y=y+1;
	}

	delta_x*=speed;
	delta_y*=speed;

	if(x>=780)
		x=0;
	else if (x<=0)
		x=780;
	if(y>=780)
		y=0;
	else if(y<=0)
	 y=780;

	sprite.setPosition(sf::Vector2f(x,y));

}

};
