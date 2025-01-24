#include "game.h"
class Menu{
public:

//add menu attributes here
Menu()
{

//constructors body
}

void display_menu()
{
  		mainmenu:
	RenderWindow window(VideoMode(780, 780), title);
	Texture bg,menu,help,hs;
	bg.loadFromFile("img/background.jpg");
	menu.loadFromFile("img/Menu.png");
	help.loadFromFile("img/Instruction.png");
	hs.loadFromFile("img/High_Score.png");
	Font font;
	font.loadFromFile("img/text.ttf");
	
	Sprite background,meno,hlp,highscore(hs);

	background.setTexture(bg);
	background.setScale(2, 1.5);

	meno.setTexture(menu);
	hlp.setTexture(help);

	bool h=0,gm=0,m=1,h_s=0;
	///////////////////////////high score menu//////////////////////////////
	ifstream inFile1("scores.txt"),inFile2("scores.txt"),inFile3("scores.txt");
	   	/////////////////////set text///////////////////////////
	   	Text first,second,third;
	   		     first.setFillColor(Color::White);
       			     first.setCharacterSize(40);
      			      first.setFont(font);
	   		    second.setFillColor(Color::White);
       			     second.setCharacterSize(40);
      			      second.setFont(font);
	   		    third.setFillColor(Color::White);
       			     third.setCharacterSize(40);
      			      third.setFont(font);
	   	
  		  char Fst[200],Snd[200],Trd[200];
  		  /////////////////set string///////////////

	 ///////////////////////////finding first//////////////
		   int max=0,res=0;
	 	int strt=19;
	 	///find max//
	 while(inFile1.getline(Fst, 200))
	    {
	      ////////converting to number//////////
	      res=0;
	      		for (int i=strt;Fst[i]!='\0'; ++i) 
	      		{
       			 if (Fst[i] >= '0' && Fst[i] <= '9') 
       			 {
		            res = res * 10 + (Fst[i] - '0');
        		 }
		        }
		if(max<res)
		 {
		  max=res;
		 }
		
	    }
	    string maximum=to_string(max);
	    ///geting max record//
	    		  	inFile1.close();
	    		  	ifstream temp("scores.txt");
	    while(temp.getline(Fst, 200))
	    {
	     bool con=1;
	     int i=0,a=19;
		for(;Fst[a]!='\0'&&maximum[i]!='\0';a++,i++)
		  {
		    if(Fst[a]==maximum[i])
		     {
		      con=con&&1;
		     }
		     else
		      con=con&&0;
		  }
		 if(maximum[i]=='\0')
		 {
		 if(con)
		  first.setString(Fst);
		  }
	    }
	 /////////////////////finding second/////////////////////////////////
	 int max2=0;
	 res=0;
	 	///find max2//
	 while(inFile2.getline(Snd, 200))
	    {
	      ////////converting to number//////////
	      res=0;
	      		for (int i=strt;Snd[i]!='\0'; ++i) 
	      		{
       			 if (Snd[i] >= '0' && Snd[i] <= '9') 
       			 {
		            res = res * 10 + (Snd[i] - '0');
        		 }
		        }
		if(max2<res && res<max)
		 {
		  max2=res;
		 }
		
	    }
	    maximum=to_string(max2);
	    ///geting max2 record//
	    		  	inFile2.close();
	    		  	ifstream temp2("scores.txt");
	    while(temp2.getline(Snd, 200))
	    {
	     bool con=1;
	     int i=0,a=19;
		for(;Snd[a]!='\0'&&maximum[i]!='\0';a++,i++)
		  {
		    if(Snd[a]==maximum[i])
		     {
		      con=con&&1;
		     }
		     else
		      con=con&&0;

		  }
		  if(maximum[i]=='\0')
		  {
			 if(con)
				second.setString(Snd);
		}
	    }
	 
	 /////////////////////////////////////////////////////
	 int max3=0;
	 res=0;
	 	///find max3//
	 while(inFile3.getline(Trd, 200))
	    {
	      ////////converting to number//////////
	      res=0;
	      		for (int i=strt;Trd[i]!='\0'; ++i) 
	      		{
       			 if (Trd[i] >= '0' && Trd[i] <= '9') 
       			 {
		            res = res * 10 + (Trd[i] - '0');
        		 }
		        }
		if(max3<res && res<max && res<max2)
		 {
		  max3=res;
		 }
		
	    }
	    maximum=to_string(max3);
	    ///geting max3 record//
	    		  	inFile3.close();
	    		  	ifstream temp3("scores.txt");
	    while(temp3.getline(Trd, 200))
	    {
	     bool con=1;
	     int i=0,a=19;
		for(;Trd[a]!='\0'&&maximum[i]!='\0';a++,i++)
		  {
		    if(Trd[a]==maximum[i])
		     {
		      con=con&&1;
		     }
		     else
		      con=con&&0;

		  }
		  if(maximum[i]=='\0')
		  {
			 if(con)
				third.setString(Trd);
		}
	    }

	//////////////////////////////////////////////////
		  	temp.close();
		  	temp2.close();
		  	temp3.close();
		///////////////////////set position//////////
		
		first.setPosition(100,150);
		second.setPosition(100,250);
		third.setPosition(100,350);
	///////////////////////////////////////////////////////////////////////
   while(window.isOpen())
	{
 	Event e;
	while (window.pollEvent(e))
        {  
            if (e.type == Event::Closed) 
                window.close();                         	    
        }
          
	if (Keyboard::isKeyPressed(Keyboard::P)) 
	{
		gm=1;	
	}   
	if (Keyboard::isKeyPressed(Keyboard::H)) 
            {
            	h=1;	
            	m=0;
            }
	if (Keyboard::isKeyPressed(Keyboard::B)) 
            {
            	h=0; m=1; h_s=0;
            }   
            if (Keyboard::isKeyPressed(Keyboard::Escape)) 
            {
            	window.close();
            } 
        if (Keyboard::isKeyPressed(Keyboard::S)) 
            {
            	h_s=1; m=0;
            }  


	window.clear(Color::Black); //clears the screen
	window.draw(background);  // setting background
	if(m==1)
	{
	window.draw(meno);
	}
	else if(h==1)
	{
	window.draw(hlp);
	}
	else if(h_s==1)
	 window.draw(highscore);
	
	//display menu screen here
	///////////////////////////High scoring Menu //////////////////////////////////////////////////////
	 if(h_s==1)
	  {
	   	
					
		window.draw(first);
		window.draw(second);
		window.draw(third);
	    	
	  }
	////////////////////////////////////////////////////////////////////////////////


	// add functionality of all the menu options here

	//if Start game option is chosen 
	if(gm)
	{
			window.close();
	///////////////////////////////////asking user name////////////////////////////////////
	
		RenderWindow win(VideoMode(780, 780), title);
		    win.setFramerateLimit(60);
		
		Text 	label,uname;
		string name;
		
	    label.setFillColor(Color::White);
            label.setCharacterSize(35);
            label.setFont(font);
             uname.setFillColor(Color::White);
            uname.setCharacterSize(35);
            uname.setFont(font);
            
            label.setPosition(150,200);
            uname.setPosition(370,200);
            
             label.setString("Enter Name  :  ");
		
		while(win.isOpen())
		{
		Event event;
        	while (win.pollEvent(event))
  	      {
        	    if (event.type == sf::Event::Closed)
        	        win.close();
	
        	    if (event.type == sf::Event::TextEntered)
        	    {
        	        if (event.text.unicode < 128)
        	        {
        	            if (event.text.unicode == '\b' && !name.empty())
        	                name.pop_back();
        	            else if (event.text.unicode != '\b')
        	                name += static_cast<char>(event.text.unicode);
	
        	            uname.setString(name);
        	        }
        	    }
        	}
		if (Keyboard::isKeyPressed(Keyboard::Enter)) 
            		{
		  		win.close();	
		            } 
		            
		win.clear(Color::Black);            
		win.draw(background);
		win.draw(label);	
		win.draw(uname);
		win.display();
		
	
	}
	
	char Name[20]={};
	int i;
	  for (i=0;i<name.length()-1;i++)
	   {
	    Name[i]=name[i];
	   }
	  for(;i<20-1;i++)
	  {
	    Name[i]=' ';
	  }
	  Name[i]='\0';
	///////////////////////////////////////////////////////////////////////////////////////
		newgame:
		char ch;
		Game g;
		gm=0;
   		ch=g.start_game();
   		//////////////////////////////////saving in file/////////////////////////////////////
   		
   		 ofstream outfile("scores.txt",ios::app);
    		    outfile<<Name<<g.p->score<<endl;
        		outfile.close();	
   		//////////////////////////////////////////////////////////////////////
   		
   		 if(ch=='N')
   		  {
   		   goto newgame;
   		  }
   		  else if(ch=='M')
   		  {
   		   goto mainmenu;
   		  }
   		  
   	}
   		window.display();  //Displying all the sprites

   }
}


};
