#include<iostream.h>//cin cout
#include<conio.h>//clrscr getch
#include<stdio.h>//gets puts
#include<graphics.h>
#include<dos.h>//delay
#include<stdlib.h>//random
#include<string.h>//str...
#include<fstream.h>//files
#include<math.h>//sin


int snake(int);// returns the score


int mf=1,qf,x=getmaxx()/2,y=getmaxy()/2,i,j;
char mc,qc;


struct player
{char name[20];
int score;}play;


struct snake1
{int x,y,tn,d;//x nd y r the coordinates of the ball, tn has the no of turns,d denotes the direction in which the ball is moving,the array t has the pattern in which the ball should turn,t gives entire pattern whereas p gives one particular pattern
char t[50],p;}s1[25];//the snake can be at the maximum of size 25

struct snake2
{int x,y,tn,d;
char t[50],p;}s2[25];


struct control
{
char a[2],s[2],d[2],w[2];//when we display the control menu for single player to display the letters in graphics mode its given in a string for eg: "a\0"
char p[2],r[2],c[2],m[2],l[2];
}c;



void main()
{
int gdriver = DETECT, gmode;
initgraph(&gdriver, &gmode, "C:\\turboc3\\bgi");
char tz;

int f=1,chc,score;
int n,k;
char ch=1,cht;


gamezone://to know which screen the user is viewing
ch=1;
cht=1;
f=1;
int fs=0;
x=getmaxx()/2;
y=getmaxy()/2;


f=0;

// 6,1 to 6,10 and 18,8 to 18,17// all definitions below are for creating characteristic blocks/pattern in each level
#define    level2()    bar(6*25+19-9,1*25+14-15,6*25+19+9,10*25+14+9);\
		       bar(18*25+19-9,8*25+14-9,18*25+19+9,17*25+14+15);
// 12,4 to 12,14 and 5,9 to 19,9
#define    level3()    bar(12*25+19-9,4*25+14-9,12*25+19+9,14*25+14+9);\
		       bar(5*25+19-9,9*25+14-9,19*25+19+9,9*25+14+9);
// 4,4 to 4,14 and 8,6 to 16,6 and 8,12 to 16,12 and 20,4 to 20,14
#define    level4()    bar(4*25+19-9,4*25+14-9,4*25+19+9,14*25+14+9);\
		       bar(8*25+19-9,6*25+14-9,16*25+19+9,6*25+14+9);\
		       bar(8*25+19-9,12*25+14-9,16*25+19+9,12*25+14+9);\
		       bar(20*25+19-9,4*25+14-9,20*25+19+9,14*25+14+9);
// 14,15 to 21,15 and 21,3 to 21,15 and 12,6 to 12,12 and 8,9 to16,9
// 3,3 to 3,15 and 3,3 to 10,3 and 14,3 to 21,3 and 3,15 to 10,15
#define    level5()    bar(3*25+19-9,3*25+14-9,3*25+19+9,15*25+14+9);\
		       bar(3*25+19-9,3*25+14-9,10*25+19+9,3*25+14+9);\
		       bar(14*25+19-9,3*25+14-9,21*25+19+9,3*25+14+9);\
		       bar(3*25+19-9,15*25+14-9,10*25+19+9,15*25+14+9);\
		       bar(14*25+19-9,15*25+14-9,21*25+19+9,15*25+14+9);\
		       bar(21*25+19-9,3*25+14-9,21*25+19+9,15*25+14+9);\
		       bar(12*25+19-9,6*25+14-9,12*25+19+9,12*25+14+9);\
		       bar(8*25+19-9,9*25+14-9,16*25+19+9,9*25+14+9);

//bar(top left x y coordinates nd bottom right x y coordinates)
//cleardevice is analogous to clrscr
#define      fn()        cleardevice();\
			 settextstyle(4,0,8);\
			 setcolor(2);\
			 setfillstyle(1,0);\
			 bar3d(x+300,210+f,x-300,140+f,0,0);\
			 outtextxy(x-100,0,"Action");\
			 setcolor(12);\
			 settextstyle(7,0,4);\
			 outtextxy(x-100,150,"Load Game");\
			 outtextxy(x-100,220,"Delete Game");\
			 outtextxy(x-50,290,"Back");\
			 outtextxy(x-150,390,"Press \" ENTER \" to select");
//settextstyle(font style , direction, size) setcolor(color) setfillstyle(design,color)
//bar3d is given so that only the border gets colored not the entire box
//outtextxy(x,y,text)

#define     pause1()     cleardevice();\
			setcolor(12);\
			settextstyle(7,0,8);\
			setfillstyle(0,0);\
			bar3d(x+180,125,x-140,0,0,0);\
			bar3d(x+250,getmaxy(),x-200,getmaxy()-108,0,0);\
			outtextxy(x-120,0,"Paused");\
			settextstyle(7,0,3);\
			outtextxy(x-170,getmaxy()-108,"Press \"r\" to Resume");\
			outtextxy(x-170,getmaxy()-81,"Press \"m\" to goto Main Menu");\
			outtextxy(x-170,getmaxy()-54,"Press \"s\" to Save Game");\
			outtextxy(x-170,getmaxy()-27,"Press \"c\" to access Control Menu");\
			settextstyle(7,0,8);


#define     pause2()     cleardevice();\
			setcolor(12);\
			settextstyle(7,0,8);\
			setfillstyle(0,0);\
			bar3d(x+180,125,x-140,0,0,0);\
			bar3d(x+250,getmaxy(),x-200,getmaxy()-100,0,0);\
			outtextxy((getmaxx()/2)-120,0,"Paused");\
			settextstyle(7,0,3);\
			outtextxy(x-170,getmaxy()-90,"Press \"r\" to Resume");\
			outtextxy(x-170,getmaxy()-60,"Press \"m\" to goto Main Menu");\
			outtextxy(x-170,getmaxy()-30,"Press \"s\" to Save Game");\
			settextstyle(7,0,8);



#define   fnq()      cleardevice();\
		     settextstyle(7,0,8);\
		     bar3d(x+300,y+120,x-300,y-100,0,0);\
		     bar3d(x-230+(mf-1)*310,y+30,x-60+(mf-1)*310,y+100,0,0);\
		     outtextxy(x-250,y-120,"are u sure?");\
		     outtextxy(x-200,y,"yes");\
		     outtextxy(x+110,y,"no");



#define     fns()     cleardevice();\
		      setcolor(2);\
		      bar3d(x+300,160+fs,x-300,100+fs,0,0);\
		      settextstyle(4,0,8);\
		      outtextxy(100,0,"Snake Xenzia");\
		      setcolor(12);\
		      settextstyle(7,0,4);\
		      outtextxy(x-100,110,"New Game");\
		      outtextxy(x-100,160,"Saved Games");\
		      outtextxy(x-100,210,"Instructions");\
		      outtextxy(x-100,260,"High Score");\
		      outtextxy(x-100,310,"Quit Game");\
		      outtextxy(x-150,380,"Press \" ENTER \" to select");



#define     fn1()        cleardevice();\
			 settextstyle(4,0,8);\
			 setcolor(2);\
			 setfillstyle(1,0);\
			 bar3d(x+300,210+f,x-300,140+f,0,0);\
			 outtextxy(x-100,0,"Type");\
			 setcolor(12);\
			 settextstyle(7,0,4);\
			 outtextxy(x-100,150,"Singleplayer");\
			 outtextxy(x-100,220,"Multiplayer");\
			 outtextxy(x-50,290,"Back");\
			 outtextxy(x-150,390,"Press \" ENTER \" to select");



clrscr();
cleardevice();
setbkcolor(0);
settextstyle(7,0,5);
setcolor(12);
setfillstyle(1,0);
bar3d(x+156,y+15,x-156,y-15,0,0);
outtextxy(x-100,y+20,"Loading .....");
setfillstyle(4,2);
for(i=x-150;i<=x+150;i++)
{bar(i,y+9,x-150,y-9);
delay(10);
}



//menu
tops:


c.a[0]='a';
c.a[1]='\0';
c.s[0]='s';
c.s[1]='\0';
c.d[0]='d';
c.d[1]='\0';
c.w[0]='w';
c.w[1]='\0';
c.p[0]='p';
c.p[1]='\0';
c.c[0]='c';
c.c[1]='\0';
c.r[0]='r';
c.r[1]='\0';
c.m[0]='m';
c.m[1]='\0';
c.l[0]='s';
c.l[1]='\0';




ch=1;
cht=1;
f=1;
int vs,vst; // vs nd fs is for controlling the movement of bar in menu
x=getmaxx()/2;
y=getmaxy()/2;

fs=0;
setfillstyle(1,0);

fns();


for(i=0;;i++)
{
if(kbhit())
{vs=getch();
if(vs==int('w')&&fs>0) //when the user wants to scroll the menu he does so by using w nd s
{                       // y 2 conitions? it is bcoz when the user is at the last option nd gives s it shud not go down any further but shoud go up
			// similarly wen user is at the top option giving w shud no go up any further it shud go down
fs-=50;
ch-=1;
fns();//printing the menu screen
}
else
if(vs==('w')&&fs==0)
{
fs=200;
ch=5;
fns();
}
else
if(vs==('s')&&fs==200)
{
fs=0;
ch=1;
fns();
}
else
if(vs==('s')&&fs<200)
{
fs+=50;
ch+=1;
fns();
}
else
if(vs==13) //ascii value of enter is 13
{break;}
}
}


setcolor(12);

// new game starts
//when new game is selected
if(ch==1)

{
//(saved games load games)
goback:



f=0;
cht=1;

fn1();

for(;;)
{if(kbhit())
{vst=getch();
if(vst==int('w')&&cht>1)
{cht-=1;
f-=70;
fn1();
}
else
if(vst==int('s')&&cht<3)
{cht+=1;
f+=70;
fn1();
}
else
if(vst==int('w')&&cht==1)
{cht=3;
f=140;
fn1();
}
else
if(vst==int('s')&&cht==3)
{cht=1;
f=0;
fn1();
}
else
if(vst==13)
{
break;
}
}
}

 //in new game single player is selected
if(cht==1)      // singleplayer new games starts

{

char temp[50];
int o;

ifstream fin("spnames.txt");
//ifstream bin("highscore.dat",ios::binary);

do
{
clrscr();
cleardevice();
cout<<"\n\n\n\n\n\n\t\t\t\t\t  ";
outtextxy(x-300,80,"Player\'s Name :");
outtextxy(x-300,y-50,"Type \" Back \" to go back");
gets(play.name);

if(strcmpi(play.name,"back")==0)
goto goback;// go back goes to previous(save load) screen


while(fin.getline(temp,80,'\n'))// to check if any other player exists wid same name
{
if(strcmpi(temp,play.name)==0)
{
play.name[0]='\0';
outtextxy(x-300,y+50,"Player already exists!");
outtextxy(x-300,y+150,"Press any key to continue");
getch();
break;
}

}



fin.seekg(0,ios::beg);




}while(play.name[0]=='\0');


fin.close();






setfillstyle(1,0);

play.score=snake(1);    //score in single player mode

if(play.score==14)
{
play.score=-1;
mc=0;
mf=0;
goto tops;
}

// the score must be put into highscore file  if the score is greater than existing scores


fin.open("highscore.dat",ios::binary);

if(fin)
{

ofstream fout("temp.dat",ios::binary);
char temp[50];
int t,count=1,i=0;


while(fin.getline(temp,80,'\n')&&i<3)
{

fin.read((char*)&t,2);

if(play.score>=t)
{
if(count!=0)
{
fout.write(play.name,strlen(play.name));
fout<<"\n";
fout.write((char*)&play.score,2);
count=0;
}

fout.write(temp,strlen(temp));
fout<<"\n";
fout.write((char*)&t,2);
}
else
{
fout.write(temp,strlen(temp));
fout<<"\n";
fout.write((char*)&t,2);
}

i++;

}

if(count!=0&&i<3)
{
fout.write(play.name,strlen(play.name));
fout<<"\n";
fout.write((char*)&play.score,2);
count=0;
}



fin.close();
fout.close();

remove("highscore.dat");
rename("temp.dat","highscore.dat");

}
else
{
ofstream fout("highscore.dat",ios::binary);
fout.write(play.name,strlen(play.name));
fout<<"\n";
fout.write((char*)&play.score,sizeof(play.score));
fout.close();
}



goto tops;

		      // singleplayer new game ends
}

else if(cht==2)       // multiplayer new game starts

{



char temp[80];

ifstream fin("mpnames.txt");

do
{
clrscr();
cleardevice();
cout<<"\n\n\n\n\n\n\t\t\t\t\t  ";
outtextxy(x-300,80,"Pair\'s Name :");
outtextxy(x-300,y-50,"Type \" Back \" to go back");
gets(play.name);

if(strcmpi(play.name,"back")==0)
goto goback;


while(fin.getline(temp,80,'\n'))
if(strcmpi(temp,play.name)==0)
{
play.name[0]='\0';
outtextxy(x-300,y+50,"Pair already exists!");
outtextxy(x-300,y+150,"Press any key to continue");
getch();
}

fin.close();
fin.open("mpnames.txt");

}while(play.name[0]=='\0');


fin.close();




setfillstyle(1,0);


if(snake(2)==14)
{mc=0;mf=0;
goto tops;}



goto tops;


}      // multiplayer new game ends

else
if(cht==3)
{goto tops;}

}

// new games ends

else

// saved games starts

if(ch==2)

{

load:

f=0;
cht=1;

fn();

for(;;)// main loop
{if(kbhit())
{vst=getch();
if(vst==int('w')&&cht>1)
{cht-=1;
f-=70;
fn();
}
else
if(vst==int('s')&&cht<3)
{cht+=1;
f+=70;
fn();
}
else
if(vst==int('w')&&cht==1)
{cht=3;
f=140;
fn();
}
else
if(vst==int('s')&&cht==3)
{cht=1;
f=0;
fn();
}
else
if(vst==13)
{
break;
}
}
}

// loading saved games starts

if(cht==1)

{

back:


f=0;
cht=1;

fn1();

for(;;)
{if(kbhit())
{vst=getch();
if(vst==int('w')&&cht>1)
{cht-=1;
f-=70;
fn1();
}
else
if(vst==int('s')&&cht<3)
{cht+=1;
f+=70;
fn1();
}
else
if(vst==int('w')&&cht==1)
{cht=3;
f=140;
fn1();
}
else
if(vst==int('s')&&cht==3)
{cht=1;
f=0;
fn1();
}
else
if(vst==13)
{
break;
}
}
}


if(cht==1)               // loading singleplayer game starts

{

int exist=0;

char temp[80];

ifstream fin("spnames.txt");

fin.seekg(0,ios::end);

if(fin.tellg()==0||!fin)
{
clrscr();
cleardevice();
outtextxy(x-300,y-50,"No Singleplayer Saved Games");
outtextxy(x-300,y+50,"Press any key to go back");
getch();
goto back;
}

fin.close();
fin.open("spnames.txt");

do
{

clrscr();
cleardevice();
cout<<"\n\n\n\n\n\n\t\t\t\t\t  ";
outtextxy(x-300,80,"Player\'s Name :");
outtextxy(x-300,y-50,"Type \" Back \" to go back");
gets(play.name);


if(strcmpi(play.name,"back")==0)
goto back;


if(play.name[0]!='\0')
{
while(fin.getline(temp,80,'\n'))
if(strcmpi(temp,play.name)==0)
exist=1;


if(exist==0)
{play.name[0]='\0';
outtextxy(x-300,y+50,"Name doesn\'t match!");
outtextxy(x-300,y+150,"Press any key to go back");
getch();}

fin.close();
fin.open("spnames.txt");


}

}while(play.name[0]=='\0');


fin.close();



setfillstyle(1,0);



score=snake(3);

if(score==14)
{
play.score=-1;
mc=0;
mf=0;
goto tops;
}
else
play.score=score;


// if the player has continued saved game and got out his record will be deleted from the file

//now i have the name of rec to be deleted from the file in play.name

//deletion logic starts

int recpos=1,org;

fin.open("spnames.txt");

while(fin.getline(temp,80,'\n'))
{
if(strcmpi(play.name,temp)==0)
break;
else
recpos++;
}

org=recpos;

fin.close();
fin.open("spnames.txt");

ofstream fout("temp.txt");

while(fin.getline(temp,80,'\n'))
{
if(recpos!=1)
{fout.write(temp,strlen(temp));
fout<<"\n";}

recpos--;
}

recpos=org;

fin.close();
fout.close();

remove("spnames.txt");
rename("temp.txt","spnames.txt");


fin.open("spgame.dat",ios::binary);
fout.open("temp.dat",ios::binary);


int t;
snake1 s;


while(fin.read((char*)&t,2))
{
if(recpos!=1)
{
fout.write((char*)&t,2);
fin.read((char*)&t,2);
fout.write((char*)&t,2);
fin.read((char*)&t,2);
fout.write((char*)&t,2);
fin.read((char*)&t,2);
fout.write((char*)&t,2);
fin.read((char*)&t,2);
fout.write((char*)&t,2);
fin.read((char*)&t,2);
fout.write((char*)&t,2);
fin.read((char*)&t,2);
fout.write((char*)&t,2);
fin.read((char*)&t,2);
fout.write((char*)&t,2);
fin.read((char*)&t,2);
fout.write((char*)&t,2);
fin.read((char*)&t,2);
fout.write((char*)&t,2);
fin.read((char*)&t,2);
fout.write((char*)&t,2);
fin.read((char*)&t,2);
fout.write((char*)&t,2);
fin.read((char*)&t,2);
fout.write((char*)&t,2);

for(int q=0;q<t;q++)
{fin.read((char*)&s,sizeof(snake1));
fout.write((char*)&s,sizeof(snake1));}

}
else
{
fin.read((char*)&t,2);

fin.read((char*)&t,2);
fin.read((char*)&t,2);
fin.read((char*)&t,2);
fin.read((char*)&t,2);
fin.read((char*)&t,2);
fin.read((char*)&t,2);
fin.read((char*)&t,2);
fin.read((char*)&t,2);
fin.read((char*)&t,2);
fin.read((char*)&t,2);


fin.read((char*)&t,2);

for(int q=0;q<t;q++)
fin.read((char*)&s,sizeof(snake1));

}

recpos--;

}

fin.close();
fout.close();

remove("spgame.dat");
rename("temp.dat","spgame.dat");

// deletion logic ends

// the score is put into highscore file if the score is greater than existing score


fin.open("highscore.dat",ios::binary);

if(fin)
{

ofstream fout("temp.dat",ios::binary);
char temp[50];
int t,count=1,i=0;


while(fin.getline(temp,80,'\n')&&i<3)
{

fin.read((char*)&t,2);

if(play.score>=t)
{
if(count!=0)
{
fout.write(play.name,strlen(play.name));
fout<<"\n";
fout.write((char*)&play.score,2);
count=0;
}

fout.write(temp,strlen(temp));
fout<<"\n";
fout.write((char*)&t,2);
}
else
{
fout.write(temp,strlen(temp));
fout<<"\n";
fout.write((char*)&t,2);
}

i++;

}

if(count!=0&&i<3)
{
fout.write(play.name,strlen(play.name));
fout<<"\n";
fout.write((char*)&play.score,2);
count=0;
}


fin.close();
fout.close();

remove("highscore.dat");
rename("temp.dat","highscore.dat");

}
else
{
ofstream fout("highscore.dat",ios::binary);
fout.write(play.name,strlen(play.name));
fout<<"\n";
fout.write((char*)&play.score,2);
fout.close();
}



goto tops;

}                    // loading singleplayer game ends

else if(cht==2)      // loading multiplayerplayer game starts

{


int exist=0;

char temp[80];

ifstream fin("mpnames.txt");

fin.seekg(0,ios::end);

if(fin.tellg()==0||!fin)
{
clrscr();
cleardevice();
outtextxy(x-300,y-50,"No Multiplayer Saved Games");
outtextxy(x-300,y+50,"Press any key to go back");
getch();
goto back;
}

fin.close();
fin.open("mpnames.txt");

do
{

clrscr();
cleardevice();
cout<<"\n\n\n\n\n\n\t\t\t\t\t  ";
outtextxy(x-300,80,"Pair\'s Name :");
outtextxy(x-300,y-50,"Type \" Back \" to go back");
gets(play.name);

if(strcmpi(play.name,"back")==0)
goto back;


if(play.name[0]!='\0')
{
while(fin.getline(temp,80,'\n'))
if(strcmpi(temp,play.name)==0)
exist=1;


if(exist==0)
{play.name[0]='\0';
outtextxy(x-300,y+50,"Name doesn\'t match!");
outtextxy(x-300,y+150,"Press any key to go back");
getch();}

fin.close();
fin.open("mpnames.txt");


}

}while(play.name[0]=='\0');


fin.close();


setfillstyle(1,0);


if(snake(4)==14)
{mc=0;mf=0;}

goto tops;


}             // loading multiplayerplayer game ends

else
if(cht==3)
{goto load;}

}

// loading saved games ends

else

// deleting saved games starts

if(cht==2)

{

back1:


f=0;
cht=1;

fn1();

for(;;)
{if(kbhit())
{vst=getch();
if(vst==int('w')&&cht>1)
{cht-=1;
f-=70;
fn1();
}
else
if(vst==int('s')&&cht<3)
{cht+=1;
f+=70;
fn1();
}
else
if(vst==int('w')&&cht==1)
{cht=3;
f=140;
fn1();
}
else
if(vst==int('s')&&cht==3)
{cht=1;
f=0;
fn1();
}
else
if(vst==13)
{
break;
}
}
}


if(cht==1)              // deleting singleplayer file starts

{

int exist=0;

char temp[80];

ifstream fin("spnames.txt");

fin.seekg(0,ios::end);

if(fin.tellg()==0||!fin)
{
clrscr();
cleardevice();
outtextxy(x-300,y-50,"No Singleplayer Saved Games");
outtextxy(x-300,y+50,"Press any key to go back");
getch();
goto back1;
}

fin.close();
fin.open("spnames.txt");

do
{

clrscr();
cleardevice();
cout<<"\n\n\n\n\n\n\t\t\t\t\t  ";
outtextxy(x-300,80,"Player\'s Name :");
outtextxy(x-300,y-50,"Type \" Back \" to go back");
gets(play.name);


if(strcmpi(play.name,"back")==0)
goto back1;


if(play.name[0]!='\0')
{
while(fin.getline(temp,80,'\n'))
if(strcmpi(temp,play.name)==0)
exist=1;


if(exist==0)
{play.name[0]='\0';
outtextxy(x-300,y+50,"Name doesn\'t match!");
outtextxy(x-300,y+150,"Press any key to go back");
getch();}

fin.close();
fin.open("spnames.txt");


}

}while(play.name[0]=='\0');


fin.close();

//now i have the name of rec to be deleted from the file in play.name

//deletion logic starts

int recpos=1,org;

fin.open("spnames.txt");

while(fin.getline(temp,80,'\n'))
{
if(strcmpi(play.name,temp)==0)
break;
else
recpos++;
}

org=recpos;

fin.close();
fin.open("spnames.txt");

ofstream fout("temp.txt");

while(fin.getline(temp,80,'\n'))
{
if(recpos!=1)
{fout.write(temp,strlen(temp));
fout<<"\n";}

recpos--;
}

recpos=org;

fin.close();
fout.close();

remove("spnames.txt");
rename("temp.txt","spnames.txt");


fin.open("spgame.dat",ios::binary);
fout.open("temp.dat",ios::binary);


int t;
snake1 s;


while(fin.read((char*)&t,2))
{
if(recpos!=1)
{
fout.write((char*)&t,2);
fin.read((char*)&t,2);
fout.write((char*)&t,2);

fin.read((char*)&t,2);
fout.write((char*)&t,2);
fin.read((char*)&t,2);
fout.write((char*)&t,2);
fin.read((char*)&t,2);
fout.write((char*)&t,2);
fin.read((char*)&t,2);
fout.write((char*)&t,2);
fin.read((char*)&t,2);
fout.write((char*)&t,2);
fin.read((char*)&t,2);
fout.write((char*)&t,2);
fin.read((char*)&t,2);
fout.write((char*)&t,2);
fin.read((char*)&t,2);
fout.write((char*)&t,2);
fin.read((char*)&t,2);
fout.write((char*)&t,2);
fin.read((char*)&t,2);
fout.write((char*)&t,2);


fin.read((char*)&t,2);
fout.write((char*)&t,2);

for(int q=0;q<t;q++)
{fin.read((char*)&s,sizeof(snake1));
fout.write((char*)&s,sizeof(snake1));}

}
else
{
fin.read((char*)&t,2);

fin.read((char*)&t,2);
fin.read((char*)&t,2);
fin.read((char*)&t,2);
fin.read((char*)&t,2);
fin.read((char*)&t,2);
fin.read((char*)&t,2);
fin.read((char*)&t,2);
fin.read((char*)&t,2);
fin.read((char*)&t,2);
fin.read((char*)&t,2);


fin.read((char*)&t,2);

for(int q=0;q<t;q++)
fin.read((char*)&s,sizeof(snake1));

}

recpos--;

}

fin.close();
fout.close();

remove("spgame.dat");
rename("temp.dat","spgame.dat");

cleardevice();
outtextxy(x-250,y-100,"Deletion successful !!!");
outtextxy(x-250,y+100,"Press any key to continue");

getch();

// deletion logic ends

goto tops;

}                    // deleting singlelayer file ends

else if(cht==2)      // deleting multiplayer file starts

{


int exist=0;

char temp[80];

ifstream fin("mpnames.txt");

fin.seekg(0,ios::end);

if(fin.tellg()==0||!fin)
{

clrscr();
cleardevice();
outtextxy(x-300,y-50,"No Multiplayer Saved Games");
outtextxy(x-300,y+50,"Press any key to go back");
getch();
goto back1;
}

fin.close();
fin.open("mpnames.txt");

do
{

clrscr();
cleardevice();
cout<<"\n\n\n\n\n\n\t\t\t\t\t  ";
outtextxy(x-300,80,"Pair\'s Name :");
outtextxy(x-300,y-50,"Type \" Back \" to go back");
gets(play.name);

if(strcmpi(play.name,"back")==0)
goto back1;


if(play.name[0]!='\0')
{
while(fin.getline(temp,80,'\n'))
if(strcmpi(temp,play.name)==0)
exist=1;


if(exist==0)
{play.name[0]='\0';
outtextxy(x-300,y+50,"Name doesn\'t match!");
outtextxy(x-300,y+150,"Press any key to go back");
getch();}

fin.close();
fin.open("mpnames.txt");


}

}while(play.name[0]=='\0');


fin.close();



// deletion logic starts


int recpos=1,org;


fin.open("mpnames.txt");

while(fin.getline(temp,80,'\n'))
{
if(strcmpi(play.name,temp)==0)
break;
else
recpos++;
}

org=recpos;

fin.close();
fin.open("mpnames.txt");

ofstream fout("temp.txt");

while(fin.getline(temp,80,'\n'))
{
if(recpos!=1)
{fout.write(temp,strlen(temp));
fout<<"\n";}

recpos--;
}

recpos=org;

fin.close();
fout.close();

remove("mpnames.txt");
rename("temp.txt","mpnames.txt");


fin.open("mpgame.dat",ios::binary);
fout.open("temp.dat",ios::binary);


int t;
snake1 s;
snake2 e;


while(fin.read((char*)&t,2))
{
if(recpos!=1)
{
fout.write((char*)&t,2);
fin.read((char*)&t,2);
fout.write((char*)&t,2);
fin.read((char*)&t,2);
fout.write((char*)&t,2);

for(int q=0;q<t;q++)
{fin.read((char*)&s,sizeof(snake1));
fout.write((char*)&s,sizeof(snake1));}

fin.read((char*)&t,2);
fout.write((char*)&t,2);


for(q=0;q<t;q++)
{fin.read((char*)&e,sizeof(snake2));
fout.write((char*)&e,sizeof(snake2));}


}
else
{
fin.read((char*)&t,2);
fin.read((char*)&t,2);

for(int q=0;q<t;q++)
fin.read((char*)&s,sizeof(snake1));

fin.read((char*)&t,2);

for(q=0;q<t;q++)
fin.read((char*)&e,sizeof(snake2));

}

recpos--;

}

fin.close();
fout.close();

remove("mpgame.dat");
rename("temp.dat","mpgame.dat");

cleardevice();
outtextxy(x-250,y-100,"Deletion successful !!!");
outtextxy(x-250,y+100,"Press any key to continue");

getch();

// deletion logic ends

goto tops;





}          // deleting multiplayer file ends

else
if(cht==3)
{goto load;}

}

// deleting saved games ends

else

if(cht==3)
{goto tops;}


}


else

if(ch==3)

{
clrscr();
cleardevice();
settextstyle(4,0,5);
setcolor(2);
outtextxy(x-250,0,"Instructions (Default Controls)");
setcolor(12);
settextstyle(7,0,3);
outtextxy(x-300,60,"(1) Use \"w\",\"s\",\"d\",\"a\" to navigate");
outtextxy(x-300,100,"(2) Use \"w\",\"s\",\"d\",\"a\" for single player");
outtextxy(x-300,140,"(3) Use \"w\",\"s\",\"d\",\"a\" and \"i\",\"k\",\"l\",\"j\"");
outtextxy(x-300,180,"   for multiplayer.");
outtextxy(x-300,220,"(4) Press \"p\" to pause the game while playing");
outtextxy(x-300,260,"(5) Press \"r\" to resume game when paused");
outtextxy(x-300,300,"(6) Press \"m\" to quit to main menu when paused");
outtextxy(x-300,340,"(7) Press \"s\" to save the game when paused");
outtextxy(x-300,380,"(8) Press \"c\" to access the control menu when paused");
outtextxy(x-300,420,"(9) Press \"ENTER\" select choice");
b2s:
vs=getch();
if(vs==13)
{clrscr();
cleardevice();
goto tops;}
else{goto b2s;}

}

else

if(ch==4)

{

clrscr();
cleardevice();

ifstream fin("highscore.dat",ios::binary);

if(fin)
{
char temp[5][40];
int t,i=0;

while(fin.getline(temp[i],80,'\n')&&i<3)
{fin.read((char*)&t,2);
cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t    "<<t;
i++;
}

for(int j=0;j<i;j++)
{
outtextxy(120,125+j*120,temp[j]);
}

settextstyle(7,0,4);
outtextxy(50,50,"Player\'s Name");
outtextxy(380,50,"Player\'s Score");

fin.close();

}
else
{
settextstyle(7,0,4);
outtextxy(x-150,y-20,"No highscores yet");
}


for(;;)
if(kbhit())
if(getch()==13)
goto tops;



}




else



if(ch==5)

{mf=1;
fnq();
for(;;)
{
if(kbhit())
{mc=getch();
if(mc==13&&mf==1)
{
k=getmaxy();

settextstyle(7,0,4);

for(;k+120>-100;)
{
delay(70);
cleardevice();
k-=10;

setcolor(2);
outtextxy(x-170,k,"CREDITS");
setcolor(12);
outtextxy(x-170,60+k,"T.Ezhil Maran");
outtextxy(x-170,90+k,"R.Derick");
outtextxy(x-170,120+k,"A.Kamil Mohamed");

}

cleardevice();
outtextxy(x-100,y,"THANK YOU!");
delay(1500);


exit(0);
}
else
if(mc=='d'&&mf==1)
{
mf=2;
fnq();
}
else
if(mc=='a'&&mf==2)
{
mf=1;
fnq();
}
else
if(mc==13&&mf==2)
{goto tops;}
}//if block
}//for block
}


closegraph() ;


}



int snake(int arg)

{

int d1=0,d2=0,l,k,n1=4,n2=4,level=1,power=0,powercount=0;
int point=0,px,py,gate=0,control=0,gatecount=-1,entry=1;
char chc,z,resume=0;


nextlevel:


/*
level
px //spl food
py
control//0 wen entering the gate since the snake moves automatically or 1
gate
gatecount // while exit
power
powercount
entry // while entering
point //score
*/


n1=4,n2=4,power=0,powercount=0,gate=0,control=0,entry=1,gatecount=-1;


if(level!=1)
{
float angle[10];

angle[0]=0;

for(i=1;i<10;i++)
angle[i]=angle[i-1]-25;



do   // to make the snake follow a curvy path
{

setfillstyle(1,0);
bar(0,0,x-21,2*y);
bar(x+21,0,2*x,2*y);


for(i=0;i<10;i++)
{
if(angle[i]<x-10)
{setcolor(13-level+1);
setfillstyle(1,13-level+1);}
else
{setcolor(13-level);
setfillstyle(1,13-level);}

fillellipse(angle[i],20*sin(angle[i]/50)+y,15,15);
angle[i]+=10;}

setfillstyle(1,13-level);
bar(x-20,0,x+20,2*y);


delay(50);

}while(angle[9]<=2*x+30);


}


 /* data members of snake
    x,y are the coordinates
    tn is the number of turns one piece must make
    d keeps track of its direction
    t[] keeps track of all the turns it shud make in order
    p is its present path */




 /*s[0] is an invisible piece which influences all other
   pieces. for the purpose of displaying and changing the
   coordinates perfectly i have used it. if i display the
   piece s[0] it would be moving somewhere.*/




if(arg==1||arg==2)//arg is 1 single player,2 multiplayer,3 sp loaded,4 mp loaded
{
s1[0].x=1*25+19-200;
s1[0].y=2*25+14;

s1[0].tn=0;
s1[0].d=2;
s1[0].t[0]='\0';
s1[0].p='d';

if(arg==2)
{
s1[0].x=x;

s1[0].y=y-100;

s2[0].x=x;
s2[0].y=y+100;
s2[0].tn=0;
s2[0].d=2;
s2[0].t[0]='\0';
s2[0].p='d';
}


for(i=1;i<n1;i++)
{s1[i].x=s1[i-1].x-25;       //x radius=15
s1[i].y=s1[i-1].y;           //y radius=15
s1[i].tn=0;
s1[i].d=2;
s1[i].t[0]='\0';
s1[i].p='d';}

if(arg==2)
for(i=1;i<n2;i++)
{s2[i].x=s2[i-1].x-25;       //x radius=15
s2[i].y=s2[i-1].y;           //y radius=15
s2[i].tn=0;
s2[i].d=2;
s2[i].t[0]='\0';
s2[i].p='d';}


randomize();
k=random(23)+1;  //generates from 0 to 22 can hold from 1 to 23
l=random(17)+1; //generates from 0 to 16 and can hold from 1 to 17


if(level==2)// food not in block
{
if(k==6)
{if(l==1||l==2||l==3||l==4||l==5||l==6||l==7||l==8||l==9||l==10)
k++;}
else
if(k==18)
{if(l==8||l==9||l==10||l==11||l==12||l==13||l==14||l==15||l==16||l==17)
k++;}
}
else
if(level==3)
{
if(k==12)
{if(l==4||l==5||l==6||l==7||l==8||l==10||l==11||l==12||l==13||l==14)
k++;}
else
if(l==9)
{if(k==5||k==6||k==7||k==8||k==9||k==10||k==11||k==13||k==14||k==15||k==16||k==17||k==18||k==19)
l++;}
else
if(k==12&&l==9)
{k++;l++;}
}
else
if(level==4)
{
if(k==4||k==20)
{if(l==4||l==5||l==6||l==7||l==8||l==9||l==10||l==11||l==12||l==13||l==14)
k++;}
else
if(l==6||l==12)
{if(k==8||k==9||k==10||k==11||k==12||k==13||k==14||k==15||k==16)
l++;}
}
else
if(level==5)
{
if(k==3||k==21)
{if(l==4||l==5||l==6||l==7||l==8||l==9||l==10||l==11||l==12||l==13||l==14)
k++;}
else
if(l==3||l==15)
{if(k==4||k==5||k==6||k==7||k==8||k==9||k==10||k==14||k==15||k==16||k==17||k==18||k==19||k==20)
l++;}
else
if((k==3&&l==3)||(k==3&&l==15)||(k==21&&l==3)||(k==21&&l==15))
{k++;l++;}
else
if(k==12)
{if(l==6||l==7||l==8||l==10||l==11||l==12)
k++;}
else
if(l==9)
{if(k==8||k==9||k==10||k==11||k==13||k==14||k==15||k==16)
l--;}
else
if(k==12&&l==9)
{k++;l++;}
}




}



// here only i shud read from file and initialize objects and put resume=1


if(arg==3)

{
char temp[80];
int recpos=1;

ifstream fin("spnames.txt");

while(fin.getline(temp,80,'\n'))
{
if(strcmpi(play.name,temp)!=0)  // checking if any saved game exists with entered name
recpos++;
else
break;
}

fin.close();



/*
level
px
py
control
gate
gatecount// for printing =>   =>    =>
power
powercount
entry
*/



ifstream bin("spgame.dat",ios::binary);

while(bin.read((char*)&k,2))
{

bin.read((char*)&l,2);

bin.read((char*)&level,2);
bin.read((char*)&px,2);
bin.read((char*)&py,2);
bin.read((char*)&control,2);
bin.read((char*)&gate,2);
bin.read((char*)&gatecount,2);
bin.read((char*)&power,2);
bin.read((char*)&powercount,2);
bin.read((char*)&entry,2);
bin.read((char*)&point,2);

bin.read((char*)&n1,2);

for(int q=0;q<n1;q++)
{bin.read((char*)&s1[q],sizeof(snake1));}

if(recpos==1)
{break;}


recpos--;
}



bin.close();

resume=1;
}
else
if(arg==4)

{
char temp[80];
int recpos=1;

ifstream fin("mpnames.txt");

while(fin.getline(temp,80,'\n'))
{
if(strcmpi(play.name,temp)!=0)
recpos++;
else
break;
}

fin.close();

ifstream bin("mpgame.dat",ios::binary);

while(bin.read((char*)&k,2))
{

bin.read((char*)&l,2);
bin.read((char*)&n1,2);

for(int q=0;q<n1;q++)
{bin.read((char*)&s1[q],sizeof(snake1));}

bin.read((char*)&n2,2);

for(q=0;q<n2;q++)
{bin.read((char*)&s2[q],sizeof(snake2));}


if(recpos==1)
{break;}


recpos--;
}



bin.close();

resume=1;
}








if(arg==3)// when the saved game is being loaded then the loaded sp bcomes sp nd vice versa
arg=1;
else
if(arg==4)
arg=2;




for(;;)//game block starting
{



// if last element crosses the wall which is only possible when gate is
// open , level is cleared
if(s1[n1-1].x>=(2*x+50)&&s1[n1-1].y<=y+20&&s1[n1-1].y>=y-20)
{cleardevice();
setcolor(12);
settextstyle(7,0,3);
if(level!=5)
{outtextxy(x-150,y-20,"Congrats! Level Cleared!");
delay(4000);
level++;
goto nextlevel;}
else
{outtextxy(x-150,y-20,"YOU HAVE MASTERED THE GAME!!!");
delay(4000);
goto bottom;}
}







if(s1[1].x==(k*25+19)&&s1[1].y==(l*25+14))
{

if(gate==1)
{k=-1;l=-1;}

if(gate==0)
{

// k -->1 to 23

// l -->1 to 17

if(n1%5==0)     // these conditions ensure that the foods are separated by significant distances
{randomize();
k=random(6)+1;
l=random(5)+1;}
else
if(n1%3==0)
{randomize();
k=random(6)+7;
l=random(5)+6;}
else
if(n1%2==0)
{randomize();
k=random(6)+13;
l=random(4)+11;}
else
{randomize();
k=random(5)+19;
l=random(3)+15;}



if(level==2)//k(x),l(y) are food coordintes
{
if(k==6)
{if(l==1||l==2||l==3||l==4||l==5||l==6||l==7||l==8||l==9||l==10)
k++;}
else
if(k==18)
{if(l==8||l==9||l==10||l==11||l==12||l==13||l==14||l==15||l==16||l==17)
k++;}
}
else
if(level==3)
{
if(k==12)
{if(l==4||l==5||l==6||l==7||l==8||l==10||l==11||l==12||l==13||l==14)
k++;}
else
if(l==9)
{if(k==5||k==6||k==7||k==8||k==9||k==10||k==11||k==13||k==14||k==15||k==16||k==17||k==18||k==19)
l++;}
else
if(k==12&&l==9)
{k++;l++;}
}
else
if(level==4)
{
if(k==4||k==20)
{if(l==4||l==5||l==6||l==7||l==8||l==9||l==10||l==11||l==12||l==13||l==14)
k++;}
else
if(l==6||l==12)
{if(k==8||k==9||k==10||k==11||k==12||k==13||k==14||k==15||k==16)
l++;}
}
else
if(level==5)
{
if(k==3||k==21)
{if(l==4||l==5||l==6||l==7||l==8||l==9||l==10||l==11||l==12||l==13||l==14)
k++;}
else
if(l==3||l==15)
{if(k==4||k==5||k==6||k==7||k==8||k==9||k==10||k==14||k==15||k==16||k==17||k==18||k==19||k==20)
l++;}
else
if((k==3&&l==3)||(k==3&&l==15)||(k==21&&l==3)||(k==21&&l==15))
{k++;l++;}
else
if(k==12)
{if(l==6||l==7||l==8||l==10||l==11||l==12)
k++;}
else
if(l==9)
{if(k==8||k==9||k==10||k==11||k==13||k==14||k==15||k==16)
l--;}
else
if(k==12&&l==9)
{k++;l++;}
}





}


if(n1==12)
{gate=1;
gatecount=0;}



if(s1[n1-1].d==-1)// whenever the snake eats a new food it grows
{
s1[n1].x=s1[n1-1].x;  // the directions of last element of snake is passed to new element
s1[n1].y=s1[n1-1].y+25;
s1[n1].tn=s1[n1-1].tn;
s1[n1].d=s1[n1-1].d;
strcpy(s1[n1].t,s1[n1-1].t);
s1[n1].p=s1[n1-1].p;
n1++;
point+=10;
}
else
if(s1[n1-1].d==-2)
{
s1[n1].x=s1[n1-1].x+25;
s1[n1].y=s1[n1-1].y;
s1[n1].tn=s1[n1-1].tn;
s1[n1].d=s1[n1-1].d;
strcpy(s1[n1].t,s1[n1-1].t);
s1[n1].p=s1[n1-1].p;
n1++;
point+=10;
}
else
if(s1[n1-1].d==1)
{
s1[n1].x=s1[n1-1].x;
s1[n1].y=s1[n1-1].y-25;
s1[n1].tn=s1[n1-1].tn;
s1[n1].d=s1[n1-1].d;
strcpy(s1[n1].t,s1[n1-1].t);
s1[n1].p=s1[n1-1].p;
n1++;
point+=10;// points altered
}
else
if(s1[n1-1].d==2)
{
s1[n1].x=s1[n1-1].x-25;
s1[n1].y=s1[n1-1].y;
s1[n1].tn=s1[n1-1].tn;
s1[n1].d=s1[n1-1].d;
strcpy(s1[n1].t,s1[n1-1].t);
s1[n1].p=s1[n1-1].p;
n1++;
point+=10;
}


if(arg==1)// special food is created thrice
if(n1==7||n1==10||n1==13)    // for creating special food  only till 12
{
power=1;

powercount=150;// to check on the timelimit for which the special food is available


if(n1%7==0)
{randomize();
px=random(7)+17;
py=random(5)+13;}
else
if(n1%10==0)
{randomize();
px=random(8)+1;
py=random(6)+1;}
else
if(n1%13==0)
{randomize();
px=random(8)+9;
py=random(6)+7;}


if(level==2)  // spl food not in block
{
if(px==6)
{if(py==1||py==2||py==3||py==4||py==5||py==6||py==7||py==8||py==9||py==10)
px--;}
else
if(px==18)
{if(py==8||py==9||py==10||py==11||py==12||py==13||py==14||py==15||py==16||py==17)
px--;}
}
else
if(level==3)
{
if(px==12)
{if(py==4||py==5||py==6||py==7||py==8||py==10||py==11||py==12||py==13||py==14)
px--;}
else
if(py==9)
{if(px==5||px==6||px==7||px==8||px==9||px==10||px==11||px==13||px==14||px==15||px==16||px==17||px==18||px==19)
py--;}
else
if(px==12&&py==9)
{px--;py--;}
}
if(level==4)
{
if(px==4||px==20)
{if(py==4||py==5||py==6||py==7||py==8||py==9||py==10||py==11||py==12||py==13||py==14)
px--;}
else
if(py==6||py==12)
{if(px==8||px==9||px==10||px==11||px==12||px==13||px==14||px==15||px==16)
py--;}
}
else
if(level==5)
{
if(px==3||px==21)
{if(py==4||py==5||py==6||py==7||py==8||py==9||py==10||py==11||py==12||py==13||py==14)
px--;}
else
if(py==3||py==15)
{if(px==4||px==5||px==6||px==7||px==8||px==9||px==10||px==14||px==15||px==16||px==17||px==18||px==19||px==20)
py--;}
else
if((px==3&&py==3)||(px==3&&py==15)||(px==21&&py==3)||(px==21&&py==15))
{px--;py--;}
else
if(px==12)
{if(py==6||py==7||py==8||py==10||py==11||py==12)
px--;}
else
if(py==9)
{if(px==8||px==9||px==10||px==11||px==13||px==14||px==15||px==16)
py++;}
else
if(px==12&&py==9)
{k--;l--;}
}



}



}


if(arg==2)
if(s2[1].x==(k*25+19)&&s2[1].y==(l*25+14))
{


if(n2%5==0)
{randomize();
k=random(6)+1;
l=random(5)+1;}
else
if(n2%3==0)
{randomize();
k=random(6)+7;
l=random(5)+6;}
else
if(n2%2==0)
{randomize();
k=random(6)+13;
l=random(4)+11;}
else
{randomize();
k=random(5)+19;
l=random(3)+15;}



if(arg==2)
if(s2[n2-1].d==-1)
{
s2[n2].x=s2[n2-1].x;
s2[n2].y=s2[n2-1].y+25;
s2[n2].tn=s2[n2-1].tn;
s2[n2].d=s2[n2-1].d;
strcpy(s2[n2].t,s2[n2-1].t);
s2[n2].p=s2[n2-1].p;
n2++;
}
else
if(s2[n2-1].d==-2)
{
s2[n2].x=s2[n2-1].x+25;
s2[n2].y=s2[n2-1].y;
s2[n2].tn=s2[n2-1].tn;
s2[n2].d=s2[n2-1].d;
strcpy(s2[n2].t,s2[n2-1].t);
s2[n2].p=s2[n2-1].p;
n2++;
}
else
if(s2[n2-1].d==1)
{
s2[n2].x=s2[n2-1].x;
s2[n2].y=s2[n2-1].y-25;
s2[n2].tn=s2[n2-1].tn;
s2[n2].d=s2[n2-1].d;
strcpy(s2[n2].t,s2[n2-1].t);
s2[n2].p=s2[n2-1].p;
n2++;
}
else
if(s2[n2-1].d==2)
{
s2[n2].x=s2[n2-1].x-25;
s2[n2].y=s2[n2-1].y;
s2
[n2].tn=s2[n2-1].tn;
s2[n2].d=s2[n2-1].d;
strcpy(s2[n2].t,s2[n2-1].t);
s2[n2].p=s2[n2-1].p;
n2++;
}

}


for(i=2;i<n1;i++) // when the snake bites itself
if(s1[1].x==s1[i].x&&s1[1].y==s1[i].y)
{
setcolor(10);
circle(s1[i].x,s1[i].y,20);
setcolor(12);
d1++;



if(arg==2)  // snake 2 bites itself
for(j=2;j<n2;j++)
if(s2[1].x==s2[j].x&&s2[1].y==s2[j].y)
{ d2++;
setcolor(12);
circle(s2[j].x,s2[j].y,20);
}


delay(2000);

goto bottom;}


if(arg==2)
for(i=2;i<n2;i++)  // in mp to check if snake bites itself
if(s2[1].x==s2[i].x&&s2[1].y==s2[i].y)
{
setcolor(12);
circle(s2[i].x,s2[i].y,20);

d2++;


for(j=2;j<n1;j++)
if(s1[1].x==s1[j].x&&s1[1].y==s1[j].y)
{ d1++;
setcolor(10);
circle(s1[j].x,s1[j].y,20);
setcolor(12);
}

delay(2000);

goto bottom;}



for(i=n1-1;i>=1;i--)//the block altering the phase of each piece starts
{

if(s1[i].t[0]==s1[i-1].p) //the block checking for turn of the piece==position of the preceeding piece starts
{
if(s1[i].t[0]=='w')
{
s1[i].y-=25;
s1[i].d=-1;
s1[i].p=s1[i].t[0];
for(j=0;j<s1[i].tn;j++)
{s1[i].t[j]=s1[i].t[j+1];}
s1[i].tn--;
}
else
if(s1[i].t[0]=='s')
{
s1[i].y+=25;
s1[i].d=1;
s1[i].p=s1[i].t[0];
for(j=0;j<s1[i].tn;j++)
{s1[i].t[j]=s1[i].t[j+1];}
s1[i].tn--;
}
else
if(s1[i].t[0]=='d')
{
s1[i].x+=25;
s1[i].d=2;
s1[i].p=s1[i].t[0];
for(j=0;j<s1[i].tn;j++)
{s1[i].t[j]=s1[i].t[j+1];}
s1[i].tn--;
}
else
if(s1[i].t[0]=='a')
{
s1[i].x-=25;
s1[i].d=-2;
s1[i].p=s1[i].t[0];
for(j=0;j<s1[i].tn;j++)
{s1[i].t[j]=s1[i].t[j+1];}
s1[i].tn--;
}

}//the block checking for turn of the piece==position of the preceeding piece ends

else

if(s1[i].d==2)   //2 +x axis -2 -x axis 1 +y zxis -1 -y axis
s1[i].x+=25;

else

if(s1[i].d==-2)

s1[i].x-=25;

else

if(s1[i].d==1)
s1[i].y+=25;

else

if(s1[i].d==-1)
s1[i].y-=25;

}//the block altering phase of each piece ends


if(arg==2)
for(i=n2-1;i>=1;i--)//the block alteriwng the phase of each piece starts
{

if(s2[i].t[0]==s2[i-1].p) //the block checking for turn of the piece==position of the preceeding piece starts
{
if(s2[i].t[0]=='i')
{
s2[i].y-=25;
s2[i].d=-1;
s2[i].p=s2[i].t[0];
for(j=0;j<s2[i].tn;j++)
{s2[i].t[j]=s2[i].t[j+1];}
s2[i].tn--;
}
else
if(s2[i].t[0]=='k')
{
s2[i].y+=25;
s2[i].d=1;
s2[i].p=s2[i].t[0];
for(j=0;j<s2[i].tn;j++)
{s2[i].t[j]=s2[i].t[j+1];}
s2[i].tn--;
}
else
if(s2[i].t[0]=='l')
{
s2[i].x+=25;
s2[i].d=2;
s2[i].p=s2[i].t[0];
for(j=0;j<s2[i].tn;j++)
{s2[i].t[j]=s2[i].t[j+1];}
s2[i].tn--;
}
else
if(s2[i].t[0]=='j')
{
s2[i].x-=25;
s2[i].d=-2;
s2[i].p=s2[i].t[0];
for(j=0;j<s2[i].tn;j++)
{s2[i].t[j]=s2[i].t[j+1];}
s2[i].tn--;
}

}//the block checking for turn of the piece==position of the preceeding piece ends

else

if(s2[i].d==2)
s2[i].x+=25;

else

if(s2[i].d==-2)
s2[i].x-=25;

else

if(s2[i].d==1)
s2[i].y+=25;

else

if(s2[i].d==-1)
s2[i].y-=25;

}//the block altering phase of each piece ends



if(arg==2) // when length of snake 1 is greater than that of snake 2
if(s1[1].x==s2[1].x&&s1[1].y==s2[1].y)// when snakes clash
{
if(n1>n2)
{
setcolor(3);
circle((s1[1].x+s2[1].x)/2,(s1[1].y+s2[1].y)/2,20);
setcolor(12);
delay(2000);
d2++;
goto bottom;
}
else  // when length of snake 2 is greater
if(n1<n2)
{
setcolor(3);
circle((s1[1].x+s2[1].x)/2,(s1[1].y+s2[1].y)/2,20);
setcolor(12);
delay(2000);
d1++;
goto bottom;
}
else// both are equal
{
setcolor(3);
circle((s1[1].x+s2[1].x)/2,(s1[1].y+s2[1].y)/2,20);//when snakes clash
setcolor(12);
delay(2000);
d1++;
d2++;
goto bottom;
}
}
else
{
for(i=2;i<n1;i++)
{
if(s1[i].x==s2[1].x&&s1[i].y==s2[1].y)
n1=i;
}
for(i=2;i<n2;i++)
{
if(s2[i].x==s1[1].x&&s2[i].y==s1[1].y)
n2=i;
}
}




if(gate==0&&entry==0)
if(!(s1[1].x+15<=2*x-4&&s1[1].x-15>=4&&s1[1].y+15<=2*y-14&&s1[1].y-15>=14))
{d1++;
if(arg==2)
if(!(s2[1].x+15<=2*x-4&&s2[1].x-15>=4&&s2[1].y+15<=2*y-14&&s2[1].y-15>=14))
{d2++;}
delay(2000);
goto bottom;}



if(arg==2) // snake is out when it hits the borders
if(!(s2[1].x+15<=2*x-4&&s2[1].x-15>=4&&s2[1].y+15<=2*y-14&&s2[1].y-15>=14))
{d2++;
if(!(s1[1].x+15<=2*x-4&&s1[1].x-15>=4&&s1[1].y+15<=2*y-14&&s1[1].y-15>=14))
{d1++;}
delay(2000);
goto bottom;}




if(level==2)
{ // when snake hits the block
if(s1[1].x==6*25+19)
{if(s1[1].y==1*25+14||s1[1].y==2*25+14||s1[1].y==3*25+14||s1[1].y==4*25+14||s1[1].y==5*25+14||s1[1].y==6*25+14||s1[1].y==7*25+14||s1[1].y==8*25+14||s1[1].y==9*25+14||s1[1].y==10*25+14)
{d1++;delay(2000);goto bottom;}
}
else
if(s1[1].x==18*25+19)
{if(s1[1].y==8*25+14||s1[1].y==9*25+14||s1[1].y==10*25+14||s1[1].y==11*25+14||s1[1].y==12*25+14||s1[1].y==13*25+14||s1[1].y==14*25+14||s1[1].y==15*25+14||s1[1].y==16*25+14||s1[1].y==17*25+14)
{d1++;delay(2000);goto bottom;}
}
}
else
if(level==3)
{
if(s1[1].x==12*25+19)
{if(s1[1].y==4*25+14||s1[1].y==5*25+14||s1[1].y==6*25+14||s1[1].y==7*25+14||s1[1].y==8*25+14||s1[1].y==9*25+14||s1[1].y==10*25+14||s1[1].y==11*25+14||s1[1].y==12*25+14||s1[1].y==13*25+14||s1[1].y==14*25+14)
{d1++;delay(2000);goto bottom;}
}
else
if(s1[1].y==9*25+14)
{if(s1[1].x==5*25+19||s1[1].x==6*25+19||s1[1].x==7*25+19||s1[1].x==8*25+19||s1[1].x==9*25+19||s1[1].x==10*25+19||s1[1].x==11*25+19||s1[1].x==12*25+19||s1[1].x==13*25+19||s1[1].x==14*25+19||s1[1].x==15*25+19||s1[1].x==16*25+19|s1[1].x==17*25+19|s1[1].x==18*25+19||s1[1].x==19*25+19)
{d1++;delay(2000);goto bottom;}
}
}
else
if(level==4)
{
if(s1[1].x==4*25+19||s1[1].x==20*25+19)
{if(s1[1].y==4*25+14||s1[1].y==5*25+14||s1[1].y==6*25+14||s1[1].y==7*25+14||s1[1].y==8*25+14||s1[1].y==9*25+14||s1[1].y==10*25+14||s1[1].y==11*25+14||s1[1].y==12*25+14||s1[1].y==13*25+14||s1[1].y==14*25+14)
{d1++;delay(2000);goto bottom;}
}
else
if(s1[1].y==6*25+14||s1[1].y==12*25+14)
{if(s1[1].x==8*25+19||s1[1].x==9*25+19||s1[1].x==10*25+19||s1[1].x==11*25+19||s1[1].x==12*25+19||s1[1].x==13*25+19||s1[1].x==14*25+19||s1[1].x==15*25+19||s1[1].x==16*25+19)
{d1++;delay(2000);goto bottom;}
}
}
else
if(level==5)
{
if(s1[1].x==3*25+19||s1[1].x==21*25+19)
{if(s1[1].y==3*25+14||s1[1].y==4*25+14||s1[1].y==5*25+14||s1[1].y==6*25+14||s1[1].y==7*25+14||s1[1].y==8*25+14||s1[1].y==9*25+14||s1[1].y==10*25+14||s1[1].y==11*25+14||s1[1].y==12*25+14||s1[1].y==13*25+14||s1[1].y==14*25+14||s1[1].y==15*25+14)
{d1++;delay(2000);goto bottom;}
}
else
if(s1[1].x==12*25+19)
{if(s1[1].y==6*25+14||s1[1].y==7*25+14||s1[1].y==8*25+14||s1[1].y==9*25+14||s1[1].y==10*25+14||s1[1].y==11*25+14||s1[1].y==12*25+14)
{d1++;delay(2000);goto bottom;}
}
else
if(s1[1].y==3*25+14||s1[1].y==15*25+14)
{if(s1[1].x==3*25+19||s1[1].x==4*25+19||s1[1].x==5*25+19||s1[1].x==6*25+19||s1[1].x==7*25+19||s1[1].x==8*25+19||s1[1].x==9*25+19||s1[1].x==10*25+19||s1[1].x==14*25+19||s1[1].x==15*25+19||s1[1].x==16*25+19||s1[1].x==17*25+19||s1[1].x==18*25+19||s1[1].x==19*25+19||s1[1].x==20*25+19||s1[1].x==21*25+19)
{d1++;delay(2000);goto bottom;}
}
else
if(s1[1].y==9*25+14)
{if(s1[1].x==8*25+19||s1[1].x==9*25+19||s1[1].x==10*25+19||s1[1].x==11*25+19||s1[1].x==12*25+19||s1[1].x==13*25+19||s1[1].x==14*25+19||s1[1].x==15*25+19||s1[1].x==16*25+19)
{d1++;delay(2000);goto bottom;}
}
}






if(control==1&&gate==1)
if(s1[1].x>2*x-19&&s1[1].y<=y+20&&s1[1].y>=y-20)
control=0;
else
if(!(s1[1].x+15<=2*x-4&&s1[1].x-15>=4&&s1[1].y+15<=2*y-14&&s1[1].y-15>=14))
{d1++;
delay(2000);
goto bottom;}



cleardevice();

setfillstyle(0,0);
setcolor(6);
bar3d(2*x-3,2*y-23,2,22,0,0);

if(entry==1)
{
setfillstyle(1,0);
bar(2,46,5,84);
setcolor(6);
line(2,46,10,46);
line(2,84,10,84);


if(s1[1].x-15>=2)
control=1;
if(s1[n1-1].x-15>=2)
entry=0;
}


setfillstyle(1,14);
setcolor(14);
fillellipse(k*25+19,l*25+14,7,7);




if(gate==1)
{

setcolor(0);

line(2*x-3,y-25,2*x-3,y+25);
setcolor(6);
line(2*x-3,y-25,2*x-6,y-25);
line(2*x-3,y+25,2*x-6,y+25);



setcolor(6);

settextstyle(7,0,3);

if(gatecount%5==0)
{outtextxy(2*x-80,y-17,"=>");}
else
if(gatecount%5==1)
{outtextxy(2*x-80,y-17," =>");}
else
if(gatecount%5==2)
{outtextxy(2*x-80,y-17,"  =>");}
else
if(gatecount%5==3)
{outtextxy(2*x-80,y-17,"   =>");}
else
if(gatecount%5==4)
{outtextxy(2*x-80,y-17,"    =>");}


gatecount++;


if(gatecount==5)
gatecount=0;


}




if(power==1&&powercount>0)
{
setcolor(powercount%15+1);
setfillstyle(1,powercount%15+1);
fillellipse(px*25+19,py*25+14,powercount/10+1,powercount/10+1);
powercount-=4;
}
else // point altered
if(power==1&&powercount<=0)
{power=0;
powercount=0;}



if(s1[1].x==(px*25+19)&&s1[1].y==(py*25+14)&&arg==1)
{point+=powercount/3;
power=0;powercount=0;
px=-1;py=-1;}




setfillstyle(1,13-level);
setcolor(13-level);

for(i=1;i<n1;i++)
fillellipse(s1[i].x,s1[i].y,15,15);//ellipse can only be filled


setfillstyle(1,10);
setcolor(10);

if(arg==2)
for(i=1;i<n2;i++)
fillellipse(s2[i].x,s2[i].y,15,15);



setcolor(6);
setfillstyle(1,6);


if(level==2)
{level2();}
else
if(level==3)
{level3();}
else
if(level==4)
{level4();}
else
if(level==5)
{level5();}




if(arg==2)
delay(90);
else
delay(90-(level-2)-(n1-1));




if(resume==1)
{

if(chc!=c.r[0])
{
settextstyle(7,0,3);
setfillstyle(1,0);
setcolor(12);
bar3d(x-300,y+80,x+310,y-60,0,0);
outtextxy(x-280,y-40,"This dialogue box will disappear in 4 seconds");
outtextxy(x-280,y,"Press any navigation key to start");
outtextxy(x-280,y+40,"Snake(s) start moving towards respective side(s)");
delay(4000);


cleardevice();
setfillstyle(0,0);
setcolor(6);
bar3d(2*x-3,2*y-23,2,22,0,0);  // main border

if(entry==1)
{
setfillstyle(1,0);
bar(2,46,5,84);
setcolor(6);
line(2,46,10,46);
line(2,84,10,84);//x1,y1,x2,y2
}

setfillstyle(1,14);
setcolor(14);
fillellipse(k*25+19,l*25+14,7,7);



setfillstyle(1,13-level);
setcolor(13-level);

for(i=1;i<n1;i++)
fillellipse(s1[i].x,s1[i].y,15,15);


setfillstyle(1,10);
setcolor(10);

if(arg==2)
for(i=1;i<n2;i++)
fillellipse(s2[i].x,s2[i].y,15,15);


if(power==1&&powercount>0)
{
powercount+=4;
setcolor(powercount%15+1);
setfillstyle(1,powercount%15+1);
fillellipse(px*25+19,py*25+14,powercount/10+1,powercount/10+1);
}


if(gate==1)//exit
{setcolor(0);
line(2*x-3,y-25,2*x-3,y+25);
setcolor(6);
line(2*x-3,y-25,2*x-6,y-25);
line(2*x-3,y+25,2*x-6,y+25);
}

setcolor(6);
setfillstyle(1,6);


if(level==2)
{level2();}
else
if(level==3)
{level3();}
else
if(level==4)
{level4();}
else
if(level==5)
{level5();}


}


//resume
res:

chc=getch();

if(chc==c.a[0]||chc==c.s[0]||chc==c.d[0]||chc==c.w[0]||((chc=='i'||chc=='k'||chc=='j'||chc=='l')&&arg==2))
{resume=0;
goto kbhit;}
else
goto res;//anything except wasd wont resume
}




if(kbhit()&&control==1)
{

chc=getch();

kbhit:

if(s1[1].d!=1&&s1[1].d!=-1&&chc==c.w[0])//'w' block starting wen snake moves upward 's' doesnt work
{

for(i=1;i<n1;i++)
{
s1[i].tn++;                 //increasing tn of each piece and mentioning last turn
s1[i].t[s1[i].tn-1]='w';
s1[i].t[s1[i].tn]='\0';
}

s1[0].p='w';

}//'w' block ending

else

if(s1[1].d!=1&&s1[1].d!=-1&&chc==c.s[0])//'s' block starting
{

for(i=1;i<n1;i++)
{
s1[i].tn++;                 //increasing tn of each piece and mentioning last turn
s1[i].t[s1[i].tn-1]='s';
s1[i].t[s1[i].tn]='\0';
}

s1[0].p='s';

}//'s' block ending

else

if(s1[1].d!=2&&s1[1].d!=-2&&chc==c.d[0])//'d' block starting
{

for(i=1;i<n1;i++)
{
s1[i].tn++;                 //increasing tn of each piece and mentioning last turn
s1[i].t[s1[i].tn-1]='d';
s1[i].t[s1[i].tn]='\0';
}

s1[0].p='d';

}//'d' block ending

else

if(s1[1].d!=2&&s1[1].d!=-2&&chc==c.a[0])//'a' block starting
{

for(i=1;i<n1;i++)
{
s1[i].tn++;                 //increasing tn of each piece and mentioning last turn
s1[i].t[s1[i].tn-1]='a';
s1[i].t[s1[i].tn]='\0';
}

s1[0].p='a';

}//'a' block ending



if(arg==2)
if(s2[1].d!=1&&s2[1].d!=-1&&chc=='i')//'i' block starting
{

for(i=1;i<n2;i++)
{
s2[i].tn++;                 //increasing tn of each piece and mentioning last turn
s2[i].t[s2[i].tn-1]='i';
s2[i].t[s2[i].tn]='\0';
}

s2[0].p='i';

}//'i' block ending

else

if(s2[1].d!=1&&s2[1].d!=-1&&chc=='k')//'k' block starting
{

for(i=1;i<n2;i++)
{
s2[i].tn++;                 //increasing tn of each piece and mentioning last turn
s2[i].t[s2[i].tn-1]='k';
s2[i].t[s2[i].tn]='\0';
}

s2[0].p='k';

}//'k' block ending

else

if(s2[1].d!=2&&s2[1].d!=-2&&chc=='l')//'l' block starting
{

for(i=1;i<n2;i++)
{
s2[i].tn++;                 //increasing tn of each piece and mentioning last turn
s2[i].t[s2[i].tn-1]='l';
s2[i].t[s2[i].tn]='\0';
}

s2[0].p='l';

}//'l' block ending

else

if(s2[1].d!=2&&s2[1].d!=-2&&chc=='j')//'j' block starting
{

for(i=1;i<n2;i++)
{
s2[i].tn++;                 //increasing tn of each piece and mentioning last turn
s2[i].t[s2[i].tn-1]='j';
s2[i].t[s2[i].tn]='\0';
}

s2[0].p='j';

}//'j' block ending





if(chc==c.p[0])//if the entered character is p its pausing
{
p:
mf=1;
qf=1;


if(arg==1)
{pause1();}
else
{pause2();}


do{
z=getch();











if(z==c.c[0])
{

int y1=1;
char t='a';

topc:

cleardevice();
settextstyle(7,0,5);

setfillstyle(1,0);

//y1 from -4 to 5

bar3d(x-250,y+y1*40-10,x+250,y+y1*40+30,0,0);

outtextxy(x-150,y-230,"Customize Control");

settextstyle(7,0,3);

outtextxy(x-100,y-170,"Move Left");
outtextxy(x+100,y-170,":");
outtextxy(x+140,y-170,c.a);

outtextxy(x-100,y-130,"Move Down");
outtextxy(x+100,y-130,":");
outtextxy(x+140,y-130,c.s);

outtextxy(x-100,y-90,"Move Right");
outtextxy(x+100,y-90,":");
outtextxy(x+140,y-90,c.d);

outtextxy(x-100,y-50,"Move Up");
outtextxy(x+100,y-50,":");
outtextxy(x+140,y-50,c.w);

outtextxy(x-100,y-10,"Pause");
outtextxy(x+100,y-10,":");
outtextxy(x+140,y-10,c.p);

outtextxy(x-100,y+30,"Save Game");
outtextxy(x+100,y+30,":");
outtextxy(x+140,y+30,c.l);

outtextxy(x-100,y+70,"Control Menu");
outtextxy(x+100,y+70,":");
outtextxy(x+140,y+70,c.c);

outtextxy(x-100,y+110,"Main Menu");
outtextxy(x+100,y+110,":");
outtextxy(x+140,y+110,c.m);

outtextxy(x-100,y+150,"Resume");
outtextxy(x+100,y+150,":");
outtextxy(x+140,y+150,c.r);

outtextxy(x-50,y+190,"Back");

do
{

if(kbhit())
{

t=getch();
if(t=='s'&&y1!=5)
{y1++;
goto topc;}
else
if(t=='w'&&y1!=-4)
{y1--;
goto topc;}



if(t==13&&y1==-4)
{
setfillstyle(1,0);
bar3d(x-250,y+y1*40-10,x+250,y+y1*40+30,0,0);
outtextxy(x-100,y-170,"Move Left");
outtextxy(x+100,y-170,":");
t=getch();
if(t==13)
{goto topc;}
else
{c.a[0]=t;
goto topc;}//control menu top
}
else
if(t==13&&y1==-3)
{
setfillstyle(1,0);
bar3d(x-250,y+y1*40-10,x+250,y+y1*40+30,0,0);
outtextxy(x-100,y-130,"Move Down");
outtextxy(x+100,y-130,":");
t=getch();
if(t==13)
{goto topc;}
else
{c.s[0]=t;
goto topc;}
}
else
if(t==13&&y1==-2)
{
setfillstyle(1,0);
bar3d(x-250,y+y1*40-10,x+250,y+y1*40+30,0,0);
outtextxy(x-100,y-90,"Move Right");
outtextxy(x+100,y-90,":");
t=getch();
if(t==13)
{goto topc;}
else
{c.d[0]=t;
goto topc;}
}
else
if(t==13&&y1==-1)
{
setfillstyle(1,0);
bar3d(x-250,y+y1*40-10,x+250,y+y1*40+30,0,0);
outtextxy(x-100,y-50,"Move Up");
outtextxy(x+100,y-50,":");
t=getch();
if(t==13)
{goto topc;}
else
{c.w[0]=t;
goto topc;}
}
else
if(t==13&&y1==0)
{
setfillstyle(1,0);
bar3d(x-250,y+y1*40-10,x+250,y+y1*40+30,0,0);
outtextxy(x-100,y-10,"Pause");
outtextxy(x+100,y-10,":");
t=getch();
if(t==13)
{goto topc;}
else
{c.p[0]=t;
goto topc;}
}
else
if(t==13&&y1==1)
{
setfillstyle(1,0);
bar3d(x-250,y+y1*40-10,x+250,y+y1*40+30,0,0);
outtextxy(x-100,y+30,"Save Game");
outtextxy(x+100,y+30,":");
t=getch();
if(t==13)
{goto topc;}
else
{c.l[0]=t;
goto topc;}
}
else
if(t==13&&y1==2)
{
setfillstyle(1,0);
bar3d(x-250,y+y1*40-10,x+250,y+y1*40+30,0,0);
outtextxy(x-100,y+70,"Control Menu");
outtextxy(x+100,y+70,":");
t=getch();
if(t==13)
{goto topc;}
else
{c.c[0]=t;
goto topc;}
}
else
if(t==13&&y1==3)
{
setfillstyle(1,0);
bar3d(x-250,y+y1*40-10,x+250,y+y1*40+30,0,0);
outtextxy(x-100,y+110,"Main Menu");
outtextxy(x+100,y+110,":");
t=getch();
if(t==13)
{goto topc;}
else
{c.m[0]=t;
goto topc;}
}
else
if(t==13&&y1==4)
{
setfillstyle(1,0);
bar3d(x-250,y+y1*40-10,x+250,y+y1*40+30,0,0);
outtextxy(x-100,y+150,"Resume");
outtextxy(x+100,y+150,":");
t=getch();
if(t==13)
{goto topc;}
else
{c.r[0]=t;
goto topc;}
}


}

}while(!(t==13&&y1==5));

goto p;


}



















else
if(z==c.r[0]) //z while pausing
{resume=1;
continue;}
else
if(z==c.m[0])
{
bar3d(x+300,y+120,x-300,y-100,0,0);
bar3d(x-230,y+30,x-60,y+100,0,0);
outtextxy(x-250,y-120,"are u sure?");
outtextxy(x-200,y,"yes");
outtextxy(x+110,y,"no");
for(;;)
{
if(kbhit())
{mc=getch();
if(mc==13&&mf==1)
{play.score=n1-4;
return mc+mf;}   //if mc+mf==14 goto tops;
else
if(mc=='d'&&mf==1)
{

if(arg==1)
{pause1();}
else
{pause2();}


bar3d(x+300,y+120,x-300,y-100,0,0);
bar3d(x+80,y+30,x+250,y+100,0,0);
outtextxy(x-250,y-120,"are u sure?");
outtextxy(x-200,y,"yes");
outtextxy(x+110,y,"no");
mf=2;
}
else
if(mc=='a'&&mf==2)
{

if(arg==1)
{pause1();}
else
{pause2();}


bar3d(x+300,y+120,x-300,y-100,0,0);
bar3d(x-230,y+30,x-60,y+100,0,0);
outtextxy(x-250,y-120,"are u sure?");
outtextxy(x-200,y,"yes");
outtextxy(x+110,y,"no");
mf=1;}
else
if(mc==13&&mf==2)
{goto p;}
}//if block
}//for block
}
else

if(z==c.l[0])       // saving game
{

bar3d(x+300,y+120,x-300,y-100,0,0);
bar3d(x-230,y+30,x-60,y+100,0,0);
outtextxy(x-250,y-120,"are u sure?");
outtextxy(x-200,y,"yes");
outtextxy(x+110,y,"no");
for(;;)
{
if(kbhit())
{qc=getch();
if(qc==13&&qf==1)
{
setbkcolor(0);
bar(x+300,y+120,x-300,y-100);

setbkcolor(0);
settextstyle(7,0,5);
setcolor(12);
setfillstyle(1,0);
bar3d(x+156,y+15,x-156,y-15,0,0);
outtextxy(x-100,y+20,"Saving .....");
setfillstyle(4,2);
for(i=x-150;i<=x+150;i++)
{bar(i,y+9,x-150,y-9);
delay(10);
}

setfillstyle(1,0);
bar(x+300,y+120,x-300,y-100);
outtextxy(x-130,y,"Game saved!");


if(arg==1)
{

char temp[80];
int recpos=1,org;

ifstream fin("spnames.txt");
ofstream fout("temp.txt");

if(fin)
{
while(fin.getline(temp,80,'\n'))
{
if(strcmpi(play.name,temp)!=0)
recpos++;
else
break;
}

fin.close();
fin.open("spnames.txt");



org=recpos;



while(fin.getline(temp,80,'\n'))
{if(recpos!=1)
{fout.write(temp,strlen(temp));
fout<<"\n";}
recpos--;}

recpos=org;

fin.close();
fout.close();

remove("spnames.txt");
rename("temp.txt","spnames.txt");
}
else
{fin.close();
fout.close();}



fout.open("spnames.txt",ios::app);


fout.write(play.name,strlen(play.name));
fout<<"\n";

fout.close();


//saving game
ifstream bin("spgame.dat",ios::binary);
ofstream bout("temp.dat",ios::binary);


if(bin)
{

snake1 s;
int t;

while(bin.read((char*)&t,2))
{if(recpos!=1)
{
bout.write((char*)&t,2);
bin.read((char*)&t,2);
bout.write((char*)&t,2);
bin.read((char*)&t,2);
bout.write((char*)&t,2);
bin.read((char*)&t,2);
bout.write((char*)&t,2);
bin.read((char*)&t,2);
bout.write((char*)&t,2);
bin.read((char*)&t,2);
bout.write((char*)&t,2);
bin.read((char*)&t,2);
bout.write((char*)&t,2);
bin.read((char*)&t,2);
bout.write((char*)&t,2);
bin.read((char*)&t,2);
bout.write((char*)&t,2);
bin.read((char*)&t,2);
bout.write((char*)&t,2);
bin.read((char*)&t,2);
bout.write((char*)&t,2);
bin.read((char*)&t,2);
bout.write((char*)&t,2);

bin.read((char*)&t,2);
bout.write((char*)&t,2);


for(int q=0;q<t;q++)
{bin.read((char*)&s,sizeof(s));
bout.write((char*)&s,sizeof(s));}

}
else
{
bin.read((char*)&t,2);

bin.read((char*)&t,2);
bin.read((char*)&t,2);
bin.read((char*)&t,2);
bin.read((char*)&t,2);
bin.read((char*)&t,2);
bin.read((char*)&t,2);
bin.read((char*)&t,2);
bin.read((char*)&t,2);
bin.read((char*)&t,2);
bin.read((char*)&t,2);

bin.read((char*)&t,2);

for(int q=0;q<t;q++)
bin.read((char*)&s,sizeof(s));

}
recpos--;}


bin.close();
bout.close();

remove("spgame.dat");
rename("temp.dat","spgame.dat");
}
else
{bin.close();
bout.close();}



bout.open("spgame.dat",ios::binary|ios::app);

bout.write((char*)&k,2);
bout.write((char*)&l,2);

bout.write((char*)&level,2);
bout.write((char*)&px,2);
bout.write((char*)&py,2);
bout.write((char*)&control,2);
bout.write((char*)&gate,2);
bout.write((char*)&gatecount,2);
bout.write((char*)&power,2);
bout.write((char*)&powercount,2);
bout.write((char*)&entry,2);
bout.write((char*)&point,2);

bout.write((char*)&n1,2);


for(int q=0;q<n1;q++)
bout.write((char*)&s1[q],sizeof(s1[q]));


bout.close();

}

else

if(arg==2)
{

char temp[80];
int recpos=1,org;

ifstream fin("mpnames.txt");
ofstream fout("temp.txt");

if(fin)
{
while(fin.getline(temp,80,'\n'))
{
if(strcmpi(play.name,temp)!=0)
recpos++;
else
break;
}

fin.close();
fin.open("mpnames.txt");




org=recpos;



while(fin.getline(temp,80,'\n'))
{if(recpos!=1)
{fout.write(temp,strlen(temp));
fout<<"\n";}
recpos--;}

recpos=org;

fin.close();
fout.close();

remove("mpnames.txt");
rename("temp.txt","mpnames.txt");
}
else
{fin.close();
fout.close();}



fout.open("mpnames.txt",ios::app);


fout.write(play.name,strlen(play.name));
fout<<"\n";

fout.close();



ifstream bin("mpgame.dat",ios::binary);
ofstream bout("temp.dat",ios::binary);


if(bin)
{

snake1 s;
snake2 e;

int t;

while(bin.read((char*)&t,2))
{if(recpos!=1)
{
bout.write((char*)&t,2);
bin.read((char*)&t,2);
bout.write((char*)&t,2);
bin.read((char*)&t,2);
bout.write((char*)&t,2);


for(int q=0;q<t;q++)
{bin.read((char*)&s,sizeof(s));
bout.write((char*)&s,sizeof(s));}

bin.read((char*)&t,2);
bout.write((char*)&t,2);

for(q=0;q<t;q++)
{bin.read((char*)&e,sizeof(e));
bout.write((char*)&e,sizeof(e));}


}
else
{
bin.read((char*)&t,2);
bin.read((char*)&t,2);

for(int q=0;q<t;q++)
bin.read((char*)&s,sizeof(s));

bin.read((char*)&t,2);

for(q=0;q<t;q++)
bin.read((char*)&e,sizeof(e));


}
recpos--;}


bin.close();
bout.close();

remove("mpgame.dat");
rename("temp.dat","mpgame.dat");
}
else
{bin.close();
bout.close();}



bout.open("mpgame.dat",ios::binary|ios::app);

bout.write((char*)&k,2);
bout.write((char*)&l,2);
bout.write((char*)&n1,2);

for(int q=0;q<n1;q++)
bout.write((char*)&s1[q],sizeof(s1[q]));

bout.write((char*)&n2,2);

for(q=0;q<n2;q++)
bout.write((char*)&s2[q],sizeof(s2[q]));



bout.close();

}




delay(1500);

goto p;
}
else
if(qc=='d'&&qf==1)
{

if(arg==1)
{pause1();}
else
{pause2();}


bar3d(x+300,y+120,x-300,y-100,0,0);
bar3d(x+80,y+30,x+250,y+100,0,0);
outtextxy(x-250,y-120,"are u sure?");
outtextxy(x-200,y,"yes");
outtextxy(x+110,y,"no");
qf=2;
}
else
if(qc=='a'&&qf==2)
{

if(arg==1)
{pause1();}
else
{pause2();}


bar3d(x+300,y+120,x-300,y-100,0,0);
bar3d(x-230,y+30,x-60,y+100,0,0);
outtextxy(x-250,y-120,"are u sure?");
outtextxy(x-200,y,"yes");
outtextxy(x+110,y,"no");
qf=1;}
else
if(qc==13&&qf==2)
{goto p;}
}//if block
}//for block




}

}while(z!=c.r[0]&&z!=c.m[0]&&z!=c.l[0]&&z!=c.c[0]);
}

}

}//game block ending


bottom:


if(arg==2)
{
if(d2==1&&d1==0)
{
clrscr();
cleardevice();
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tRed Snake Wins!!!";
}
else
if(d1==1&&d2==0)
{
clrscr();
cleardevice();
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tGreen Snake Wins!!!";
}
else
if(d1==1&&d2==1)
{
clrscr();
cleardevice();
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tIts a DRAW!!!";
}

delay(3000);

}
else
{
clrscr();
cleardevice();


cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t       Your score is "<<point;
delay(3000);

return point;

}


}
//spgames-saved game


