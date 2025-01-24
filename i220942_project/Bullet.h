
#include <SFML/Graphics.hpp>
using namespace sf;
#include<iostream>
using namespace std;
#include<cstring>

class Bullet
{
 public:
 int x,y;
 Texture bt;
 Sprite blt;
 Bullet()
 {
 }
	Bullet(int x,int y,string path)
	{
		this->x=x; this->y=y;
		bt.loadFromFile(path);
		blt.setTexture(bt);
		blt.setPosition(x,y);
		
	}
 void move()
 {
  y-=1;
  blt.setPosition(x,y);
 }
 Bullet& operator=(Bullet& rhs)
 {
  x=rhs.x;
  y=rhs.y;

	  bt.loadFromFile("img/PNG/Lasers/laserGreen11.png");
	blt.setTexture(bt);
	blt.setPosition(x,y);
	return *this;
 }
};
