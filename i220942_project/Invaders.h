
#include"Bomb.h"
class Invaders
{
 public: 
   string type;
   Bomb* bomb;
   Texture t;
Sprite spt;
int x,y;
int time;
   Invaders(string ty,int a,int b,string path)
   {
  		 x=a;y=b;
	  t.loadFromFile(path);
	  spt.setTexture(t);
	  spt.setPosition(x,y);
     type=ty;
     if(ty=="Gamma")
       spt.setScale(0.5,0.5);
     else
     spt.setScale(0.7,0.7);
     bomb=new Bomb (a+30,b);
   }

void update_bomb()
{
 bomb->bomb_move();
  //if(bomb->yb>=780)
     {
    //   bomb->yb=y;
      //  bomb->sptb.setPosition(bomb->xb,bomb->yb);
    // }
}
}
 
};
