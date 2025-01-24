
#include <SFML/Graphics.hpp>
#include <time.h>
#include<fstream>
#include "player.h"
#include"Enemy.h"

const char title[] = "OOP-Project, Spring-2023";
using namespace sf;

class Game
{
public:
Sprite background; //Game background sprite
Texture bg_texture;
Player* p; //player 
// add other game attributes
Enemy* enemy;



Font font;	
     int choice=rand()%10;   
     int phase;
     int level;

Game()
{
p=new Player("img/player_ship.png","img/PNG/Lasers/laserGreen11.png");
bg_texture.loadFromFile("img/background.jpg");
background.setTexture(bg_texture);
background.setScale(2, 1.5);
///text////
enemy=new Enemy(0,0,"");

font.loadFromFile("img/text.ttf");
        phase=0;
        level=1;

}
char start_game()
{
    srand(time(0));
    RenderWindow window(VideoMode(780, 780), title);
    Clock clock;
    float timer=0;
    int tb=0;
    int power_up_time=100;
    int tt=0;
    

    int tm=0,td=0;
    bool pause =0;
    bool gameover=0;

				
				Texture ps;
				ps.loadFromFile("img/Pause.png");
				Sprite pau(ps);
				Texture gm;
				gm.loadFromFile("img/Game_over.png");
				Sprite gameov(gm);
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds(); 
        clock.restart();
        timer += time;   
        
        /////////////

        ///////////
 	Event e;
        while (window.pollEvent(e))
        {  
            if (e.type == Event::Closed) // If cross/close is clicked/pressed
                window.close(); //close the game                        	    
        }
        
        if(pause==0)
        {
        if (Keyboard::isKeyPressed(Keyboard::Right) && Keyboard::isKeyPressed(Keyboard::Up)) // If right key is pressed
            p->move("ur");  //player will move to right
        if (Keyboard::isKeyPressed(Keyboard::Left) && Keyboard::isKeyPressed(Keyboard::Up)) // If right key is pressed
            p->move("ul");
          
	if (Keyboard::isKeyPressed(Keyboard::Left)) //If left key is pressed
            p->move("l");    // Player will move to left
	if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
            p->move("r");  //player will move to right
	if (Keyboard::isKeyPressed(Keyboard::Up)) //If up key is pressed
            p->move("u");    //playet will move upwards
	if (Keyboard::isKeyPressed(Keyboard::Down)) // If down key is pressed
            p->move("d");  //player will move downwards
           
            
        if (tt%9000==0) 
            p->pup();   
         else if (tt%17000==0) 
            p->dngr();  
         else if (tt%23000==0) 
            p->lvs(); 
         else if (tt%28000==0) 
            p->fre();
        
         if (Keyboard::isKeyPressed(Keyboard::O)&&enemy->monster==NULL) 
         {
         	enemy->set_enemies(phase);
         }
       }
       if (Keyboard::isKeyPressed(Keyboard::P)) 
        	pause=1;
       if (Keyboard::isKeyPressed(Keyboard::C)) 
            pause=0;
       if (Keyboard::isKeyPressed(Keyboard::N)) 
       {
        	window.close();
            return 'N';
            }
       	if (Keyboard::isKeyPressed(Keyboard::M)) 
       {
        	window.close();
            return 'M';
            }    
         if (Keyboard::isKeyPressed(Keyboard::Escape)) 
            {
            	window.close();
            }    
            //////////////////////////////////////randomization//////////////////////////////////////////////////
             	if (Keyboard::isKeyPressed(Keyboard::O)&&enemy->monster==NULL&&enemy->dragon==NULL) 
     		    {
        		   enemy->set_monster();
				tm=5000;         
      			   }
        	else if (Keyboard::isKeyPressed(Keyboard::I)&&enemy->dragon==NULL&&enemy->monster==NULL) 
         		{
           			enemy->set_Dragon();
				td=5000;         
         		}
         	tt++;
	////////////////////////////////////////////////
	/////  Call your functions here            ////
	if(pause==0&&gameover==0)
	{
	int con=1;
		for(int i=0;i<20;i++)
		{
		  if(enemy->invaders[i]==NULL)
		   con=con&&1;
		  else
		   con=con&&0;
		}
			if(con)
			 {
			 phase++;
			 enemy->set_enemies(phase);
			 }

	p->update_power_up();
	{

	}
	p->update_danger();
	p->update_lives();
	p->update_fire();
		
		if(p->player_lives<=0)
		 {
			gameover=1;
		 }
		 
	p->update_bullet();	 
	p->powerup_effect();
	if(tb>=200)
	{ 
		tb=0;
		p->fire();	
	}
	else 
	{
	 tb++;
	}
	
	//////////////////////////dragon////////////////////////////
	
	if(enemy->dragon!=NULL)
	{
	 if(enemy->dragon->y1>=760)
		{
	   enemy->dragon->add_laser();
	  }
	 enemy->dragon->update_laser();
	 enemy->dragon->update_dragon();
	}
	
	if(td<=0&&enemy->dragon!=NULL)
	{
	  p->score+=50;
	 delete enemy->dragon;
	 enemy->dragon=NULL;
	 }
	 else if(enemy->dragon!=NULL)
	  td--;
	if(enemy->dragon!=NULL)
	 {
	   if(enemy->dragon->x==p->x && enemy->dragon->y==p->y)
	    {
	     delete enemy->dragon;
	      enemy->dragon=NULL;
	      p->player_lives-=1;
	    }
	    else if(enemy->dragon->x1==p->x && enemy->dragon->y1==p->y)
	     {
	     	delete enemy->dragon;
	      enemy->dragon=NULL;
	      p->player_lives-=1;
	     }
	 }
	
	//////////////////////////monster///////////////////////////
	
	if(enemy->monster!=NULL)
	{
	 if(enemy->monster->y1>=760)
		{
	   enemy->monster->add_laser();
	  }
	 enemy->monster->update_laser();
	 enemy->monster->update_monster();
	}
	
	if(tm<=0&&enemy->monster!=NULL)
	{
	  p->score+=40;
	 delete enemy->monster;
	 enemy->monster=NULL;
	 }
	 else if(enemy->monster!=NULL)
	  tm--;
	if(enemy->monster!=NULL)
	 {
	   if(enemy->monster->x==p->x && enemy->monster->y==p->y)
	    {
	     delete enemy->monster;
	      enemy->monster=NULL;
	      p->player_lives-=1;
	    }
	    else if(enemy->monster->x1==p->x && enemy->monster->y1==p->y)
	     {
	     	delete enemy->monster;
	      enemy->monster=NULL;
	      p->player_lives-=1;
	     }
	 }
	 ////////////////////////////enemies bomb////////////////////////
	 
		  
		  if(enemy->invaders[choice]!=NULL)
		  {
		   enemy->invaders[choice]->update_bomb();
		   
		     if(enemy->invaders[choice]->bomb->yb>=780)
		      {
		        enemy->invaders[choice]->bomb->yb=enemy->invaders[choice]->y;
		        enemy->invaders[choice]->bomb->sptb.setPosition(enemy->invaders[choice]->bomb->xb,enemy->invaders[choice]->y);
		        choice=rand()%10;
		      }
		      
		    }
		 
		 
	check_collisions();
		} 
	/////////////////////////
	   
	//////////////////////////////////////////////

	window.clear(Color::Black); //clears the screen
	window.draw(background);  // setting background
	window.draw(p->sprite);   // setting player on screen
	///////////////////////////////////////
	
	///////////////////Draw Bullets///////////////
	for(int i=0;i<p->total_bullet;i++)
	{
	 window.draw(p->bullet[i].blt);
	}
	
	////////////////draw addons/////////////
	if(p->powerup!=NULL)
	window.draw(p->powerup->spt);
	if(p->danger!=NULL)
	window.draw(p->danger->spt);
	if(p->lives!=NULL)
	window.draw(p->lives->spt);
	if(p->fires!=NULL)
	window.draw(p->fires->spt);
	////////////////////draw power up bullets////////////////
	if(p->bullets1!=NULL)
	{
		for(int i=0;i<p->p_bullets;i++)
		{
		 window.draw(p->bullets1[i].blt);
		 window.draw(p->bullets2[i].blt);
		 window.draw(p->bullets3[i].blt);
		 window.draw(p->bullets4[i].blt);
		 window.draw(p->bullets5[i].blt);
		 window.draw(p->bullets6[i].blt);
		 }
		
	}
	/////////////////////draw monster/////////////////
	if(enemy->monster!=NULL)
	{
		  window.draw(enemy->monster->laser);
	  window.draw(enemy->monster->spt);
	}
	
	/////////////////draw dragon/////////////////
	if(enemy->dragon!=NULL)
	{
		  window.draw(enemy->dragon->laser);
	  window.draw(enemy->dragon->spt);
	}
	
	///////////////////draw invaders////////////////
	for(int i=0;i<20;i++)
	{
	  if(enemy->invaders[i]!=NULL&&enemy->monster==NULL&&enemy->dragon==NULL)
	   {
	    	     window.draw(enemy->invaders[i]->bomb->sptb);
	     window.draw(enemy->invaders[i]->spt);
	   }
	}
		Text t,l,scr,st;       
            t.setFillColor(Color::White);
            t.setCharacterSize(35);
            t.setFont(font);
            
            l.setFillColor(Color::White);
            l.setCharacterSize(35);
            l.setFont(font);
            
            scr.setFillColor(Color::White);
            scr.setCharacterSize(35);
            scr.setFont(font);
            
            st.setFillColor(Color::White);
            st.setCharacterSize(35);
            st.setFont(font);
            
            
            t.setPosition(120,0);
            l.setPosition(0,0);
            scr.setPosition(150,30);
            st.setPosition(0,30);
            
            t.setString(to_string(p->player_lives)); 
            l.setString("LIVES = ");          
            scr.setString(to_string(p->score));
            st.setString("Scores = ");
            
            window.draw(t);
            window.draw(l);
            
            window.draw(scr);
            window.draw(st);
	
	//////////////////pause///////////////
	if(pause)
	 {
	   window.draw(pau);
	 }
	 if(gameover)
	 {
	   window.draw(gameov);
	 }
	
	window.display();  //Displying all the sprites
    }
    return 'b';
}


void check_collisions()
{

  for(int i=0;i<20;i++)
  {
    if(enemy->invaders[i]!=NULL)
     {
       if(p->x>=enemy->invaders[i]->x && p->x<=enemy->invaders[i]->x+30 && p->y>=enemy->invaders[i]->y && p->y<=enemy->invaders[i]->y+30) 
        {
          p->player_lives-=1;
           delete enemy->invaders[i];
            enemy->invaders[i]=NULL;
        }
       else if(p->x>=enemy->invaders[i]->bomb->xb && p->x<=enemy->invaders[i]->bomb->xb+5 && p->y>=enemy->invaders[i]->bomb->yb && p->y<=enemy->invaders[i]->bomb->yb+5) 
        {
          p->player_lives-=1;
        }
       else
        {
        for(int j=0;j<p->total_bullet;j++)
         {
           if(p->bullet[j].x>=enemy->invaders[i]->x && p->bullet[j].x<=enemy->invaders[i]->x+30 && p->bullet[j].y>=enemy->invaders[i]->y && p->bullet[j].y<=enemy->invaders[i]->y+30)
           {
           		if(enemy->invaders[i]->type=="Alpha")
           		 {
           		   p->score+=10*level;
           		 }
           		else if(enemy->invaders[i]->type=="Beta")
           		 {
           		  p->score+=20*level;
           		 }
           		else if(enemy->invaders[i]->type=="Gamma")
           		 {
           		   p->score+=30*level;
           		 }
           		
           		
               if(enemy->invaders[i]!=NULL)
             	delete enemy->invaders[i];
            	enemy->invaders[i]=NULL;
            	break;
            }
         }
       }
        
     }
  }
  
}
~Game()
{
  if(p!=NULL)
   {
    delete p;
   }
   p=NULL;
   if(enemy!=NULL)
   {
    delete enemy;
   }
   enemy=NULL;
}

};

