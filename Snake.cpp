#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<windows.h>
#include<string>
#include<cstring>
#include<iomanip>
using namespace std;

void draw();

void setup();

void input();

void play();

void mane();

void setup1();

void draw1();

void input1();

void play1();

void finish();

void finish1();

int height ;

int width ;

int x2 , y2 , sx , sy , xmane , ymane , score1 , score2 , x1 , y1 ;

enum eDirecto { STOP=0 , LEFT , RIGHT , UP , DOWN };

eDirecto direct2;

eDirecto direct1;

bool GameOver;

int domx2[100];

int domy2[100];

int domx1[100];

int domy1[100];

int ndom2;

int ndom1;

int main()
{
	start:
		
	system("cls");
		
	system("color A0");
	
	cout<<setw(32)<<"Snake"<<endl;
	cout<<setw(30)<<"Size : ";
	cin>>width>>height;
	cout<<setw(37)<<"1- Single player"<<endl<<setw(37)<<"2-Couple player"<<endl;
	
	
	fstream in("snake.txt", ios::in);
	
	string snake;
	
	if(in)
	{
		while(!in.eof())
		{
			getline(in,snake);
			
			cout<<snake<<endl;
		}
	}
	adadgir:
	char adad;
	adad = getch();
	if( adad == '2' )
	{
		setup();
		
   		while ( !GameOver )
    	{
    		system( "color A0" );
    		
    	    draw();
    	    
    	    input();
    	    
    	    play();
    	    
    	    if( (300 - ( ndom1 + ndom2 )*10 ) >= 0 )
    	    	Sleep(300 - ( ndom1 + ndom2 )*10 );
    	}
    	if ( GameOver )
    		finish();
    }
    else if ( adad == '1' )
    {
    	setup1();
    	
    	while ( !GameOver )
    	{
    		system ( "color A0" );
    		
    		draw1();
    		
    		input1();
    		
    		play1();
    		
    		if( (300-score1) >= 0  )
    		Sleep( 300-score1 );
		}
		if ( GameOver )
			finish1();
	}
	else if ( adad != '1' && adad !='2' )
	{
		cout<<setw(35)<<"please choose 1 or 2"<<endl;
		goto adadgir;
	}
	switch( getch() )
	{
		case 'r' :
			
		goto start;
	}
	
}

void setup()
{
    srand(time(NULL)) ;
    
    GameOver = false;
    
    direct1 = STOP ;
    
    direct2 = STOP ;
    
    x2 = (width / 2)-1 ;
    
    y2 = height / 2 ;
    
    x1 = (width / 2)+1 ;
    
    y1 = height / 2 ;
    
    sx = (rand() % (width-3))+2 ;
    
	sy = (rand() % (height-3))+2 ;
	
	xmane = (rand() % (width-3)) +2;
			
	ymane = (rand() % (height-3)) +2; 
	//bug in mane 
	//bug mane: bazi moqe ha mane mire goshe va vaqti mire onja bazi moqe ha mar nemitone be fazaye beinesh bere;
	while( ( xmane == x1 && ymane == y1 )
		 || ( xmane == x1 && ymane+1 == y1 )
		 || ( xmane == x1 && ymane-1 == y1 )
		 || ( xmane == x1 && ymane-2 == y1)
		 || ( xmane == x1 && ymane-3 == y1 )
		 || ( xmane+1 == x1 && ymane == y1 )
		 || ( xmane+2 == x1 && ymane == y1 )
		 
		 ||( xmane == x2 && ymane == y2 )
		 || ( xmane == x2 && ymane+1 == y2 )
		 || ( xmane == x2 && ymane-1 == y2 )
		 || ( xmane == x2 && ymane-2 == y2 )
		 || ( xmane == x2 && ymane-3 == y2 )
		 || ( xmane+1 == x2 && ymane == y2 )
		 || ( xmane+2 == x2 && ymane == y2 ) )
	{
			xmane = (rand() % (width-3)) +2;
			
			ymane = (rand() % (height-3)) +2; 
	}
	
    score1 = 0 ;
    
    score2 = 0 ;
    
    ndom1 = 0 ;
    
    ndom2 = 0 ;
}

void draw()
{
    system("cls");
    for (int i = 1; i <= height; ++i) {
        for (int j = 1; j <= width; ++j) {
            if ( i==y1 && j==x1 )
            {
                cout<<"O ";
            }
            else if( i==y2 && j==x2 )
            {
            	cout<<"@ ";
			}
            else if ( i==sy && j==sx )
            {
                cout<<"o ";
            }
            else{

                if ( i==1 || i==height )
                {
                    cout<<"= ";
                }

                else if(j == 1 || j == width )
				{	
                    cout << "| ";
                }
                
                else if ( i==ymane && j==xmane )
                {
                	cout<<"# ";
				}
				else if ( i==ymane+1 && j==xmane )
                {
                	cout<<"# ";
				}
				else if ( i==ymane && j==xmane+1 )
                {
                	cout<<"# ";
				}
				else if ( i==ymane-1 && j==xmane )
                {
                	cout<<"# ";
				}
				else if ( i==ymane && j==xmane+2 )
                {
                	cout<<"# ";
				}
				else if ( i==ymane-2 && j==xmane )
                {
                	cout<<"# ";
				}
				else if ( i==ymane-3 && j==xmane )
                {
                	cout<<"# ";
				}
				
                else
				{
					bool chap=false;
					
                	for( int k=0 ; k<ndom1 ; k++ )
                	{
						if( domx1[k] == j && domy1[k] == i )
						{
							cout<<"o ";
							
							chap = true;
						}
					}
					for( int k=0 ; k<ndom2 ; k++ )
                	{
						if( domx2[k] == j && domy2[k] == i )
						{
							cout<<"@ ";
						
							chap = true;
						}
					}
					if( !chap )
                    	cout << "  "; 
                }
            }
        }
        
        cout << "\n";
        
    }
    
		cout << "SCORE1: "<<score1<<endl<<"SCORE2: "<<score2<<endl;
}
void finish()
{		
	if( GameOver )
	{
		system("cls");
		
		cout<<setw(30)<<"Game Over"<<endl<<setw(27)<<"score1: "<<score1<<endl<<setw(27)<<"score2: "<<score2<<endl;
		
		if( score1 == score2 )
		{
			cout<<setw(32)<<"DRAW"<<endl;
		}
		else if ( score1>score2 )
		{
			cout<<setw(32)<<"CHAMP : PLAYER 1"<<endl;
		}
		else 
		{
			cout<<setw(32)<<"CHAMP : PLAYER 2"<<endl;
		}
		
		cout<<setw(30)<<setw(36)<<"play again : press r"<<endl;
	}
}
		

void input()
{
    if( kbhit() )
    {
        switch (getch())
        {
            case 'a' :
                direct2 = LEFT; break;
            case 'w' :
                direct2 = UP; break;
            case 'd' :
                direct2 = RIGHT; break;
            case 's' :
                direct2 = DOWN; break;
            case 'x' :
                exit (0);
        }
    }
    if ( kbhit() )
    {
    	switch ( getch() )
    	{
    		case 72 :
            	direct1 = UP; break;
            case 77 :
            	direct1 = RIGHT; break;
            case 80 :
            	direct1 = DOWN; break;
            case 75 :
            	direct1 = LEFT; break;
            case 'x' :
            	exit (0);
		}
	}
}
void play()
{
	int qablx2 = domx2[0];
	
	int qablx1 = domx1[0];
	
	int qably2 = domy2[0];
	
	int qably1 = domy1[0];
	
	int qabl2x1 , qabl2y1 , qabl2x2 , qabl2y2;
	
	domx2[0] = x2;
	
	domx1[0] = x1;
	
	domy2[0] = y2;
	
	domy1[0] = y1;
	
	for( int i=1 ; i<ndom2 ; i++ )
	{
		qabl2x2 = domx2[i];
		
		qabl2y2 = domy2[i];
		
		domx2[i] = qablx2;
		
		domy2[i] = qably2;
		
		qablx2 = qabl2x2;
		
		qably2 = qabl2y2; 
	}
	for( int i=1 ; i<ndom1 ; i++ )
	{
		qabl2x1 = domx1[i];
		
		qabl2y1 = domy1[i];
		
		domx1[i] = qablx1;
		
		domy1[i] = qably1;
		
		qablx1 = qabl2x1;
		
		qably1 = qabl2y1;
	}
    switch (direct1)
    {
    		return;
        case LEFT:
            (x1)--;
            cout<<"PLAYER 1 : LEFT"<<endl;
            break;
        case RIGHT:
            (x1)++;
            cout<<"PLAYER 1 : RIGHT"<<endl;
            break;
        case UP:
            (y1)--;
            cout<<"PLAYER 1 : UP"<<endl;
            break;
        case DOWN:
            (y1)++;
            cout<<"PLAYER 1 : DOWN"<<endl;
            break;
        default:
            break;
    }
    switch (direct2)
    {
        case LEFT:
            (x2)--;
            cout<<"PLAYER 2 : LEFT";
            break;
        case RIGHT:
            (x2)++;
            cout<<"PLAYER 2 : RIGHT";
            break;
        case UP:
            (y2)--;
            cout<<"PLAYER 2 : UP";
            break;
        case DOWN:
            (y2)++;
            cout<<"PLAYER 2 : DOWN";
            break;
        default:
            break;
    }
    if ( x1<2 || x1>width-1 || y1<2 || y1>height-1 || x2<2 || x2>width-1 || y2<2 || y2>height-1 )
    {
        GameOver= true;
    }
    for( int i=0 ; i<ndom2 ; i++ )
    {
    	if( domx2[i] == x2 && domy2[i] == y2 )
    	{
    		GameOver = true;
		}
	}
	for( int i=0 ; i<ndom1 ; i++ )
    {
    	if( domx1[i] == x1 && domy1[i] == y1 )
    	{
    		GameOver = true;
		}
	}
    if( x2==sx && y2==sy )
    {
    	ndom2+=1;
    	
        score2+=10;
        
        sx = (rand() % (width-3))+2 ;
        
        sy = (rand() % (height-3))+2 ;
        
        if( ( sx == xmane && sy == ymane ) || ( sx == xmane && sy == ymane+1 ) || ( sx == xmane && sy == ymane-1 ) || ( sx == xmane && sy == ymane-2 ) || ( sx == xmane && sy == ymane-3 ) || ( sx == xmane+1 && sy == ymane ) || ( sx == xmane+2 && sy == ymane ) )
        {
        	sx = (rand() % (width-3))+2 ;
        
        	sy = (rand() % (height-3))+2 ;
		}
        
        while ( true )
        {
        	int maxdom ;
        	if( ndom1 > ndom2 )
        	{
        		maxdom = ndom1;
			}
			else
			{
				maxdom = ndom2;
			}
        	for ( int i=0 ; i<=maxdom ; i++ )
        	{
        		if( ( sx==domx2[i] && sy==domy2[i] ) || ( sx==domx1[i] && sy==domy1[i] ) )
        		{
        			sx = (rand() % (width-3))+2 ;
        			sy = (rand() % (height-3))+2 ;
        			break;
				}
			}
			break;
		}
	}
    if( x1==sx && y1==sy )
    {
    	ndom1+=1;
    	
        score1+=10;
        
        sx = (rand() % (width-3))+2 ;
        
        sy = (rand() % (height-3))+2 ;
        
        while ( true )
        {
        	int maxdom ;
        	if( ndom1>ndom2 )
        	{
        		maxdom = ndom1;
			}
			else
			{
				maxdom = ndom2;
			}
        	for ( int i=0 ; i<=maxdom ; i++ )
        	{
        		if( ( sx==domx2[i] && sy==domy2[i] ) || ( sx==domx1[i] && sy==domy1[i] ) )
        		{
        			sx = (rand() % (width-3))+2 ;
        			sy = (rand() % (height-3))+2 ;
        			break;
				}
			}
			break;
		}    
    }
    if( xmane == x1 && ymane == y1 )
    {
    	GameOver = true ;
	}
	else if ( xmane == x1 && ymane+1 ==y1 )
	{
		GameOver = true;
	}
	else if ( xmane == x1 && ymane-1 ==y1 )
	{
		GameOver = true;
	}
	else if ( xmane == x1 && ymane-2 ==y1 )
	{
		GameOver = true;
	}
	else if ( xmane == x1 && ymane-3 ==y1 )
	{
		GameOver = true;
	}
	else if ( xmane+1 == x1 && ymane ==y1 )
	{
		GameOver = true;
	}
	else if ( xmane+2 == x1 && ymane ==y1 )
	{
		GameOver = true;
	}
	else if( xmane == x2 && ymane == y2 )
    {
    	GameOver = true ;
	}
	else if ( xmane == x2 && ymane+1 ==y2 )
	{
		GameOver = true;
	}
	else if ( xmane == x2 && ymane-1 ==y2 )
	{
		GameOver = true;
	}
	else if ( xmane == x2 && ymane-2 ==y2 )
	{
		GameOver = true;
	}
	else if ( xmane == x2 && ymane-3 ==y2 )
	{
		GameOver = true;
	}
	else if ( xmane+1 == x2 && ymane ==y2 )
	{
		GameOver = true;
	}
	else if ( xmane+2 == x2 && ymane ==y2 )
	{
		GameOver = true;
	}
	for( int i=0 ; i<=ndom1 ; i++ )
	{
		if ( x2==domx1[i] && y2==domy1[i] )
		{
			GameOver = true ;
		}
	}
	for( int i=0 ; i<=ndom2 ; i++ )
	{
		if ( x1==domx2[i] && y1==domy2[i] )
		{
			GameOver = true ;
		}
	}
	
	if( ( xmane==sx && ymane==sy ) 
	|| ( xmane+1== sx && ymane==sy )
	|| ( xmane+2==sx && ymane==sy )
	|| ( xmane==sx && ymane+1==sy )
	|| ( xmane==sx && ymane-1==sy )
	|| ( xmane==sx && ymane-2==sy )
	|| ( xmane==sx && ymane==sy ) )
	{
		sx = (rand() % (width-3))+2 ;
    	sy = (rand() % (height-3))+2 ;
	}
	
}
void setup1()
{
    srand(time(NULL)) ;
    
    GameOver = false;
    
    direct1 = STOP ;
    
    x1 = width / 2 ;
    
    y1 = height / 2 ;
    
    sx = (rand() % (width-3))+2 ;
    
	sy = (rand() % (height-3))+2 ;
	
	xmane = (rand() % (width-3)) +2;
			
	ymane = (rand() % (height-3)) +2; 
	
	while( ( xmane == x1 && ymane == y1 )
		 || ( xmane == x1 && ymane+1 == y1 )
		 || ( xmane == x1 && ymane-1 == y1 )
		 || ( xmane == x1 && ymane-2 == y1 )
		 || ( xmane == x1 && ymane-3 == y1 )
		 || ( xmane+1 == x1 && ymane == y1 )
		 || ( xmane+2 == x1 && ymane == y1 ) )
	{
	
			xmane = (rand() % (width-3)) +2;
			
			ymane = (rand() % (height-3)) +2; 
			
	}
	
    score1 = 0 ;
    
    ndom1=0 ;
}

void draw1()
{
    system("cls");
    for (int i = 1; i <= height; ++i) 
	{
        for (int j = 1; j <= width; ++j) 
		{
            if ( i==y1 && j==x1 )
            {
                cout<<"O ";
            }
            else if ( i==sy && j==sx )
            {
                cout<<"o ";
            }
            else{

                if ( i==1 || i==height )
                {
                    cout<<"= ";
                }

                else if(j == 1 || j == width ){
                	
                    cout << "| ";
                }
                
                else if ( i==ymane && j==xmane )
                {
                	cout<<"# ";
				}
				else if ( i==ymane+1 && j==xmane )
                {
                	cout<<"# ";
				}
				else if ( i==ymane && j==xmane+1 )
                {
                	cout<<"# ";
				}
				else if ( i==ymane-1 && j==xmane )
                {
                	cout<<"# ";
				}
				else if ( i==ymane && j==xmane+2 )
                {
                	cout<<"# ";
				}
				else if ( i==ymane-2 && j==xmane )
                {
                	cout<<"# ";
				}
				else if ( i==ymane-3 && j==xmane )
                {
                	cout<<"# ";
				}

                else
				{
					bool chap=false;
					
					
					
                	for( int k=0 ; k<ndom1 ; k++ )
                	{
                	
                		if ( domx1[k] == j && domy1[k] == i )
                		{
                			cout<<"o ";
                			
                			chap = true;
						}
					}
					if( !chap )
                    	cout << "  "; 
                }
            }
        }
        
        cout << "\n";
        
    }
    
		cout << "SCORE: "<<score1<<endl;
}
		
void finish1()
{	
		while( GameOver )
	{
		system("cls");
		
		cout<<setw(30)<<"Game Over"<<endl<<setw(27)<<"score: "<<score1<<endl;
		
		cout<<setw(30)<<setw(36)<<"play again : press r"<<endl;
		
		
		break;
	}
}
		

void input1()
{
    if( kbhit() )
    {
        switch (getch())
        {
            case 'a' :
                direct1 = LEFT; break;
            case 'w' :
                direct1 = UP; break;
            case 'd' :
                direct1 = RIGHT; break;
            case 's' :
                direct1 = DOWN; break;
            case 'x' :
                exit (0);
        }
    }
}
void play1()
{
	int qablx1 = domx1[0];
	
	int qably1 = domy1[0];
	
	int qabl2x1 , qabl2y1;
	
	domx1[0] = x1;
	
	domy1[0] = y1;
	
	for( int i=1 ; i<ndom1 ; i++ )
	{
		qabl2x1 = domx1[i];
		
		qabl2y1 = domy1[i];
		
		domx1[i]=qablx1;
		
		domy1[i]=qably1;
		
		qablx1 = qabl2x1;
		
		qably1 = qabl2y1; 
	}
    switch (direct1)
    {
        case LEFT:
            x1--;
            cout<<"LEFT"<<endl;
            break;
        case RIGHT:
            x1++;
            cout<<"RIGHT"<<endl;
            break;
        case UP:
            y1--;
            cout<<"UP"<<endl;
            break;
        case DOWN:
            y1++;
            cout<<"DOWN"<<endl;
            break;
        default:
            break;
    }
    if ( x1<2 || x1>width-1 || y1<2 || y1>height-1 )
    {
        GameOver= true;
    }
    for( int i=0 ; i<ndom1 ; i++ )
    {
    	if( domx1[i] == x1 && domy1[i] == y1 )
    	{
    		GameOver = true;
		}
	}
    if( x1==sx && y1==sy )
    {
    	ndom1+=1;
    	
        score1+=10;
        
        sx = (rand() % (width-3))+2 ;
        
        sy = (rand() % (height-3))+2 ;
        
        if( ( sx == xmane && sy == ymane ) || ( sx == xmane && sy == ymane+1 ) || ( sx == xmane && sy == ymane-1 ) || ( sx == xmane && sy == ymane-2 ) || ( sx == xmane && sy == ymane-3 ) || ( sx == xmane+1 && sy == ymane ) || ( sx == xmane+2 && sy == ymane ) )
        {
        	sx = (rand() % (width-3))+2 ;
        
        	sy = (rand() % (height-3))+2 ;
		}
        
        while ( true )
        {
        	for ( int i=0 ; i<=ndom1 ; i++ )
        	{
        		if( sx==domx1[i] && sy==domy1[i] )
        		{
        			sx = (rand() % (width-3))+2 ;
        			sy = (rand() % (height-3))+2 ;
        			break;
				}
			}
			break;
		}
    }
    if( xmane == x1 && ymane == y1 )
    {
    	GameOver = true ;
	}
	else if ( xmane == x1 && ymane+1 ==y1 )
	{
		GameOver = true;
	}
	else if ( xmane == x1 && ymane-1 ==y1 )
	{
		GameOver = true;
	}
	else if ( xmane == x1 && ymane-2 ==y1 )
	{
		GameOver = true;
	}
	else if ( xmane == x1 && ymane-3 ==y1 )
	{
		GameOver = true;
	}
	else if ( xmane+1 == x1 && ymane ==y1 )
	{
		GameOver = true;
	}
	else if ( xmane+2 == x1 && ymane ==y1 )
	{
		GameOver = true;
	}
}
