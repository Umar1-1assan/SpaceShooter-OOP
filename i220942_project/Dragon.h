

class Dragon
{

 public:
 Texture l;
 Sprite laser;
 int x1,y1;
 bool laser_s;
 int tm;
 //////
Texture t;
Sprite spt;
int x,y;
int time;
 	Dragon(int a,int b,string path,string las,int c,int d)
 	{
 		x1=c-50;
 		y1=d;
 		laser_s=1;
 		tm=1;
 		l.loadFromFile(las);
 		laser.setTexture(l);
 		laser.setPosition(x1,y1);
 		spt.setScale(1, 1);
 		////////////////////
 		x=a;y=b;
	  t.loadFromFile(path);
	  spt.setTexture(t);
	  spt.setPosition(x,y);
 	}
 	
void add_laser()
{
 	x1=x+40;y1=y;
 	laser.setPosition(x,y);
} 	
void update_laser()
{
 y1+=1;
  laser.setPosition(x1,y1);
}
void update_dragon(int a=1)
{
if(tm)
 x+=a;
else
 x-=a;
 
 if(x==700)
  {
   tm=0;
  }
 else if(x==10)
  {
   tm=1;
  }
 spt.setPosition(x,y);
 
}
};
