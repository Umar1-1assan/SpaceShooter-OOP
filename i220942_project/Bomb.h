
class Bomb
{
public:
 Texture t;
 Sprite sptb;
 int xb,yb;
   Bomb(int a,int b)
   {
    xb=a;yb=b;
    t.loadFromFile("img/bomb.png");
    sptb.setTexture(t);
    sptb.setPosition(xb,yb);
   }
   
   void bomb_move()
   {
    yb+=1;
     
    sptb.setPosition(xb,yb);
   }
   
 
};
