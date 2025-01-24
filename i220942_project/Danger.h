


class Danger : public Addons
{
public:
float x;
    float y;
    int duration;

	Danger(int a,int b,string path)
	{
	x=a;y=b;
	 txt.loadFromFile(path);
	 spt.setTexture(txt);
	}
	void move()
	{
	   y+=0.1;
	   spt.setPosition(x,y);
	}
};
