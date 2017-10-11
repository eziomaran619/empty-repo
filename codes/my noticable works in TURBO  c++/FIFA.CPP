#include<iostream.h>
#include<ctype.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void main()
{
int gdriver = DETECT, gmode;
initgraph(&gdriver, &gmode, "C:\\turboc3\\bgi");
float ti;
int sub,a1,b1,i,j,x=getmaxx()/2,y=getmaxy()/2,ct=1,g1,g2,mf,qf,ax,by;  // ct tells which team has control of the ball
char o,chc,mc,qc,z,pc;                                    // g1 and g2 are the goals scored
int a,b;  // co ordinates of the ball

struct team1         // co ordinates of center of body
{                    // b is the count which tells whether a player has ball or not
int x,y,b,c,p;
char d;              // d is the direction in which the player is moving
}t1[3];              // p tells u whether the players ar ready to position or not
		     // c tells the player which ur controlling when you dont possess the ball


struct control1
{
char a[2],s[2],d[2],w[2];
char e[2],f[2],c[2];
}c1;

c1.a[0]='a';
c1.a[1]='\0';
c1.s[0]='s';
c1.s[1]='\0';
c1.d[0]='d';
c1.d[1]='\0';
c1.w[0]='w';
c1.w[1]='\0';
c1.f[0]='f';
c1.f[1]='\0';
c1.e[0]='e';
c1.e[1]='\0';
c1.c[0]='c';
c1.c[1]='\0';


struct team2         // co ordinates of center of body
{                    // b is the count which tells whether a player has ball or not
int x,y,b,c,p;
char d;              // p tells u whether the players ar ready to position or not
}t2[3];              // d is the direction in which the player is moving
		     // c tells the player which ur controlling when you dont possess the ball


struct control2
{
char j[2],k[2],l[2],i[2];
char u[2],h[2],n[2];
}c2;


c2.j[0]='j';
c2.j[1]='\0';
c2.k[0]='k';
c2.k[1]='\0';
c2.l[0]='l';
c2.l[1]='\0';
c2.i[0]='i';
c2.i[1]='\0';
c2.u[0]='u';
c2.u[1]='\0';
c2.h[0]='h';
c2.h[1]='\0';
c2.n[0]='n';
c2.n[1]='\0';

cleardevice();
setcolor(12);
settextstyle(7,0,2);
outtextxy(x-150,30,"TEAM 1 (RED COLOR)");
outtextxy(x-320,60,"(1)use \"w\",\"a\",\"s\",\"d\" to move");
outtextxy(x-320,90,"(2)use \"f\" to pass the ball and also change to");
outtextxy(x-320,120,"   the player near the ball when not in possession");
outtextxy(x-320,150,"(3)when u near the ball and cover it press\"c\" to tackle");
outtextxy(x-320,180,"(4)use \"e\" to position your teammates");


setcolor(5);
settextstyle(7,0,2);
outtextxy(x-150,2*y-180,"TEAM 2 (PURPLE COLOR)");
outtextxy(x-320,2*y-150,"(1)use \"i\",\"j\",\"k\",\"l\" to move");
outtextxy(x-320,2*y-120,"(2)use \"h\" to pass the ball and also change to");
outtextxy(x-320,2*y-90,"   the player near the ball when not in possession");
outtextxy(x-320,2*y-60,"(3)when u near the ball and cover it press\"n\" to tackle");
outtextxy(x-320,2*y-30,"(4)use \"u\" to position your teammates");

getch();

start:

if(ct==1)
{
t1[0].x=x-15;
t1[0].y=y-15;
t1[0].c=1;
t1[0].b=1;
t1[0].p=0;
t1[0].d='\0';

a=t1[0].x+13;
b=t1[0].y+14;


t1[1].x=x+40;
t1[1].y=y-15;
t1[1].d='\0';
t1[1].p=1;
t1[1].c=0;
t1[1].b=0;


t1[2].x=x;
t1[2].y=y+100;
t1[2].d='\0';
t1[2].p=1;
t1[2].c=0;
t1[2].b=0;

t2[0].x=x-100;
t2[0].y=y-50;
t2[0].c=1;
t2[0].b=0;
t2[0].d='\0';
t2[0].p=0;

t2[1].x=x+100;
t2[1].y=y-50;
t2[1].b=0;
t2[1].d='\0';
t2[1].p=1;
t2[1].c=0;


t2[2].x=x;
t2[2].y=y-100;
t2[2].b=0;
t2[2].d='\0';
t2[2].p=1;
t2[2].c=0;
}
else
if(ct==2)
{
t1[0].x=x-100;
t1[0].y=y+50;
t1[0].c=1;
t1[0].b=0;
t1[0].p=0;
t1[0].d='\0';

t1[1].x=x+100;
t1[1].y=y+50;
t1[1].d='\0';
t1[1].p=1;
t1[1].c=0;
t1[1].b=0;


t1[2].x=x;
t1[2].y=y+100;
t1[2].d='\0';
t1[2].p=1;
t1[2].c=0;
t1[2].b=0;


t2[0].x=x-15;
t2[0].y=y-15;
t2[0].c=1;
t2[0].b=1;
t2[0].d='\0';
t2[0].p=0;

a=t2[0].x+13;
b=t2[0].y+14;

t2[1].x=x+40;
t2[1].y=y-15;
t2[1].b=0;
t2[1].d='\0';
t2[1].p=1;
t2[1].c=0;


t2[2].x=x;
t2[2].y=y-100;
t2[2].b=0;
t2[2].d='\0';
t2[2].p=1;
t2[2].c=0;

}



cleardevice();
setfillstyle(0,0);
setcolor(12);
bar3d(2*x-1,2*y-11,1,11,0,0);             // border
line(1,y,2*x-1,y);                        // center line
circle(x,y,80);                           // center circle
bar3d(x+60,11,x-60,1,0,0);                // top goal
bar3d(x+120,50,x-120,11,0,0);             // top d box
sector(x,50,180,360,45,30);               // top semicircle
bar3d(x+60,2*y-1,x-60,2*y-11,0,0);        // bottom goal
bar3d(x+120,2*y-11,x-120,2*y-50,0,0);     // bottom d box
sector(x,2*y-50,0,180,45,30);             // bottom semicircle
setcolor(3);



for(i=0;i<3;i++)                                          // 1st team
{
setcolor(12);
setfillstyle(1,12);
bar3d(t1[i].x+10,t1[i].y+10,t1[i].x-10,t1[i].y-10,0,0);   // body
fillellipse(t1[i].x,t1[i].y-14,6,6);                      // head
bar3d(t1[i].x-7,t1[i].y,t1[i].x-2,t1[i].y+20,0,0);        // 1st leg
bar3d(t1[i].x+2,t1[i].y,t1[i].x+7,t1[i].y+20,0,0);        // 2nd leg
bar3d(t1[i].x,t1[i].y-7,t1[i].x-20,t1[i].y-10,0,0);       // 1st hand
bar3d(t1[i].x+20,t1[i].y-7,t1[i].x,t1[i].y-10,0,0);       // 2nd hand
}


for(i=0;i<3;i++)                                          // second team
{
setcolor(5);
setfillstyle(1,5);
bar3d(t2[i].x+10,t2[i].y+10,t2[i].x-10,t2[i].y-10,0,0);   // body
fillellipse(t2[i].x,t2[i].y-14,6,6);                      // head
bar3d(t2[i].x-7,t2[i].y,t2[i].x-2,t2[i].y+20,0,0);        // 1st leg
bar3d(t2[i].x+2,t2[i].y,t2[i].x+7,t2[i].y+20,0,0);        // 2nd leg
bar3d(t2[i].x,t2[i].y-7,t2[i].x-20,t2[i].y-10,0,0);       // 1st hand
bar3d(t2[i].x+20,t2[i].y-7,t2[i].x,t2[i].y-10,0,0);       // 2nd hand
}


settextstyle(4,0,4);
setcolor(12);
setfillstyle(0,0);
bar3d(x+250,55,x-210,15,0,0);
outtextxy(x-190,10,"press \"enter\" to start the match");


top:
o=getch();

if(o==13)
{
for(;;)      // game for block starts
{
cleardevice();
setfillstyle(0,0);
setcolor(12);
bar3d(2*x-1,2*y-11,1,11,0,0);             // border
line(1,y,2*x-1,y);                        // center line
circle(x,y,80);                           // center circle
bar3d(x+60,11,x-60,1,0,0);                // top goal
bar3d(x+120,50,x-120,11,0,0);             // top d box
sector(x,50,180,360,45,30);               // top semicircle
bar3d(x+60,2*y-1,x-60,2*y-11,0,0);        // bottom goal
bar3d(x+120,2*y-11,x-120,2*y-50,0,0);     // bottom d box
sector(x,2*y-50,0,180,45,30);	          // bottom semicircle
setcolor(3);
setfillstyle(1,3);
fillellipse(a,b,6,6);		          // football

for(i=0;i<3;i++)                                          // 1st team
if(t1[i].c==1)
{
setcolor(12);
circle(t1[i].x,t1[i].y,25);
setfillstyle(1,12);
bar3d(t1[i].x+10,t1[i].y+10,t1[i].x-10,t1[i].y-10,0,0);   // body
fillellipse(t1[i].x,t1[i].y-14,6,6);                      // head
bar3d(t1[i].x-7,t1[i].y,t1[i].x-2,t1[i].y+20,0,0);        // 1st leg
bar3d(t1[i].x+2,t1[i].y,t1[i].x+7,t1[i].y+20,0,0);        // 2nd leg
bar3d(t1[i].x,t1[i].y-7,t1[i].x-20,t1[i].y-10,0,0);       // 1st hand
bar3d(t1[i].x+20,t1[i].y-7,t1[i].x,t1[i].y-10,0,0);       // 2nd hand
}
else
{
setcolor(12);
setfillstyle(1,12);
bar3d(t1[i].x+10,t1[i].y+10,t1[i].x-10,t1[i].y-10,0,0);   // body
fillellipse(t1[i].x,t1[i].y-14,6,6);                      // head
bar3d(t1[i].x-7,t1[i].y,t1[i].x-2,t1[i].y+20,0,0);        // 1st leg
bar3d(t1[i].x+2,t1[i].y,t1[i].x+7,t1[i].y+20,0,0);        // 2nd leg
bar3d(t1[i].x,t1[i].y-7,t1[i].x-20,t1[i].y-10,0,0);       // 1st hand
bar3d(t1[i].x+20,t1[i].y-7,t1[i].x,t1[i].y-10,0,0);       // 2nd hand
}
for(i=0;i<3;i++)                                          // second team
if(t2[i].c==1)
{
setcolor(5);
circle(t2[i].x,t2[i].y,25);
setfillstyle(1,5);
bar3d(t2[i].x+10,t2[i].y+10,t2[i].x-10,t2[i].y-10,0,0);   // body
fillellipse(t2[i].x,t2[i].y-14,6,6);                      // head
bar3d(t2[i].x-7,t2[i].y,t2[i].x-2,t2[i].y+20,0,0);        // 1st leg
bar3d(t2[i].x+2,t2[i].y,t2[i].x+7,t2[i].y+20,0,0);        // 2nd leg
bar3d(t2[i].x,t2[i].y-7,t2[i].x-20,t2[i].y-10,0,0);       // 1st hand
bar3d(t2[i].x+20,t2[i].y-7,t2[i].x,t2[i].y-10,0,0);       // 2nd hand
}
else
{
setcolor(5);
setfillstyle(1,5);
bar3d(t2[i].x+10,t2[i].y+10,t2[i].x-10,t2[i].y-10,0,0);   // body
fillellipse(t2[i].x,t2[i].y-14,6,6);                      // head
bar3d(t2[i].x-7,t2[i].y,t2[i].x-2,t2[i].y+20,0,0);        // 1st leg
bar3d(t2[i].x+2,t2[i].y,t2[i].x+7,t2[i].y+20,0,0);        // 2nd leg
bar3d(t2[i].x,t2[i].y-7,t2[i].x-20,t2[i].y-10,0,0);       // 1st hand
bar3d(t2[i].x+20,t2[i].y-7,t2[i].x,t2[i].y-10,0,0);       // 2nd hand
}

delay(70);


if(ct==2)
{
if(a>x-60&&a<x+60&&b>2*y-11)
{
g2++;
cleardevice();
setcolor(12);
settextstyle(4,0,6);
outtextxy(x-100,y-50,"goalllll!!!!!");
ct=1;
getch();
goto start;
}

else

if(a>x-60&&a<x+60&&b<11)
{
g1++;
cleardevice();
setcolor(12);
settextstyle(4,0,6);
outtextxy(x-100,y-50,"own goalll!!!");
ct=2;
getch();
goto start;
}

else

if(a<=2*x-1&&a>=1&&(a>=x+60||a<=x-60)&&b>=2*y-11)
{
t2[2].d='\0';
t2[2].x=x;
t2[2].y=y;
t2[2].c=1;
t2[2].b=0;
ct=1;
t2[2].p=0;

t2[0].c=0;
t2[0].x=x-150;
t2[0].y=y+100;
t2[0].p=0;
t2[0].b=0;
t2[0].d='\0';

t2[1].x=x+150;
t2[1].y=y+100;
t2[1].c=0;
t2[1].p=0;
t2[1].b=0;
t2[1].d='\0';



t1[0].x=x-150;
t1[0].y=y-100;
t1[0].c=0;
t1[0].p=0;
t1[0].b=0;
t1[0].d='\0';

t1[1].x=x+150;
t1[1].y=y-100;
t1[1].c=0;
t1[1].p=0;
t1[1].b=0;
t1[1].d='\0';

t1[2].x=x;
t1[2].y=2*y-50;
t1[2].c=1;
t1[2].b=1;
t1[2].p=0;
t1[2].d='\0';

a=t1[2].x+13;
b=t1[2].y+14;

cleardevice();
setcolor(12);
settextstyle(4,0,6);
outtextxy(x-100,y-50,"away!!!!");
getch();
}

else

if(a<=2*x-1&&a>=1&&a>=x+60&&b<=11)
{
t2[2].d='\0';
t2[2].x=x;
t2[2].y=50;
t2[2].c=1;
t2[2].b=0;
ct=1;
t2[2].p=0;

t2[0].c=0;
t2[0].x=x-150;
t2[0].y=y+100;
t2[0].p=0;
t2[0].b=0;
t2[0].d='\0';

t2[1].x=x+150;
t2[1].y=y+100;
t2[1].c=0;
t2[1].p=0;
t2[1].b=0;
t2[1].d='\0';


t1[0].x=x-150;
t1[0].y=y-100;
t1[0].c=0;
t1[0].p=0;
t1[0].b=0;
t1[0].d='\0';

t1[1].x=x+150;
t1[1].y=y-100;
t1[1].c=0;
t1[1].p=0;
t1[1].b=0;
t1[1].d='\0';


t1[2].x=2*x-20;
t1[2].y=31;
t1[2].c=1;
t1[2].b=1;
t1[2].p=0;
t1[2].d='\0';

a=t1[2].x+13;
b=t1[2].y+14;


cleardevice();
settextstyle(4,0,6);
setcolor(12);
outtextxy(x-100,y-50,"corner!!!!");
getch();
}

else

if(a<=2*x-1&&a>=1&&a<=x-60&&b<=11)
{
t2[2].d='\0';
t2[2].x=x;
t2[2].y=50;
t2[2].c=1;
t2[2].b=0;
ct=1;
t2[2].p=0;

t2[0].x=x-150;
t2[0].y=y+100;
t2[0].c=0;
t2[0].p=0;
t2[0].b=0;
t2[0].d='\0';


t2[1].x=x+150;
t2[1].y=+100;
t2[1].c=0;
t2[1].p=0;
t2[1].b=0;
t2[1].d='\0';


t1[0].x=x-150;
t1[0].y=y-100;
t1[0].c=0;
t1[0].p=0;
t1[0].b=0;
t1[0].d='\0';

t1[1].x=x+150;
t1[1].y=y-100;
t1[1].c=0;
t1[1].p=0;
t1[1].b=0;
t1[1].d='\0';


t1[2].x=20;
t1[2].y=31;
t1[2].c=1;
t1[2].b=1;
t1[2].p=0;
t1[2].d='\0';

a=t1[2].x+13;
b=t1[2].y+14;


cleardevice();
settextstyle(4,0,6);
setcolor(12);
outtextxy(x-100,y-50,"corner!!!!");
getch();
}
else
if(a<=1&&b>=11&&b<=2*y-11)
{
t2[2].d='\0';
t2[2].x=x;
t2[2].y=y;
t2[2].c=1;
t2[2].b=0;
ct=1;
t2[2].p=0;

t2[0].x=x-150;
t2[0].y=y+100;
t2[0].c=0;
t2[0].p=0;
t2[0].b=0;
t2[0].d='\0';

t2[1].x=x+150;
t2[1].y=y+100;
t2[1].c=0;
t2[1].p=0;
t2[1].b=0;
t2[1].d='\0';


t1[0].y=y-100;
t1[0].x=x-150;
t1[0].c=0;
t1[0].p=0;
t1[0].b=0;
t1[0].d='\0';


t1[1].x=x+150;
t1[1].y=y-100;
t1[1].c=0;
t1[1].p=0;
t1[1].b=0;
t1[1].d='\0';


t1[2].x=21;
t1[2].y=b-14;
t1[2].c=1;
t1[2].b=1;
t1[2].p=0;
t1[2].d='\0';

a=t1[2].x+13;
b=t1[2].y+14;


cleardevice();
settextstyle(4,0,6);
setcolor(12);
outtextxy(x-100,y-50,"away!!!!");
getch();
}
else
if(a>=2*x-1&&b>=11&&b<=2*y-11)
{
t2[2].d='\0';
t2[2].x=x;
t2[2].y=y;
t2[2].c=1;
t2[2].b=0;
ct=1;
t2[2].p=0;

t2[0].x=x-150;
t2[0].y=y+100;
t2[0].c=0;
t2[0].p=0;
t2[0].b=0;
t2[0].d='\0';

t2[1].x=x+150;
t2[1].y=y+100;
t2[1].c=0;
t2[1].p=0;
t2[1].b=0;
t2[1].d='\0';


t1[0].y=y-100;
t1[0].x=x-150;
t1[0].c=0;
t1[0].p=0;
t1[0].b=0;
t1[0].d='\0';
t1[1].c=0;

t1[1].x=x+150;
t1[1].y=y-100;
t1[1].p=0;
t1[1].b=0;
t1[1].d='\0';


t1[2].x=2*x-1-20;
t1[2].y=b-14;
t1[2].c=1;
t1[2].b=1;
t1[2].p=0;
t1[2].d='\0';

a=t1[2].x+13;
b=t1[2].y+14;


cleardevice();
settextstyle(4,0,6);
setcolor(12);
outtextxy(x-100,y-50,"away!!!!");
getch();
}
else{;}


}
else
{;}

if(ct==1)
{
if(a>x-60&&a<x+60&&b<11)
{

g1++;
cleardevice();
setcolor(12);
settextstyle(4,0,6);
outtextxy(x-100,y-50,"goalllll!!!!!");
ct=2;
getch();
goto start;
}

else

if(a>x-60&&a<x+60&&b>2*y-11)
{
g2++;
cleardevice();
setcolor(12);
settextstyle(4,0,6);
outtextxy(x-100,y-50,"own goalll!!!");
ct=1;
getch();
goto start;
}

else


if(a<=2*x-1&&a>=1&&(a>=x+60||a<=x-60)&&b<=11)
{
t1[2].d='\0';
t1[2].x=x;
t1[2].y=y;
t1[2].b=0;
t1[2].c=1;
ct=2;
t1[2].p=0;


t1[0].x=x-150;
t1[0].y=y-100;
t1[0].c=0;
t1[0].p=0;
t1[0].b=0;
t1[0].d='\0';

t1[1].x=x+150;
t1[1].y=y-100;
t1[1].c=0;
t1[1].p=0;
t1[1].b=0;
t1[1].d='\0';


t2[0].y=y+100;
t2[0].x=x-150;
t2[0].c=0;
t2[0].p=0;
t2[0].b=0;
t2[0].d='\0';

t2[1].x=x+150;
t2[1].y=y+100;
t2[1].c=0;
t2[1].p=0;
t2[1].b=0;
t2[1].d='\0';


t2[2].x=x;
t2[2].y=50;
t2[2].c=1;
t2[2].b=1;
t2[2].p=0;
t2[2].d='\0';

a=t2[2].x+13;
b=t2[2].y+14;


cleardevice();
settextstyle(4,0,6);
setcolor(12);
outtextxy(x-100,y-50,"away!!!!");
getch();
}

else


if(a<=2*x-1&&a>=1&&a>=x+60&&b>=2*y-11)
{
t1[2].d='\0';
t1[2].x=x;
t1[2].y=2*y-50;
t1[2].b=0;
t1[2].c=1;
ct=2;
t1[2].p=0;

t1[0].x=x-150;
t1[0].y=y-100;
t1[0].c=0;
t1[0].p=0;
t1[0].b=0;
t1[0].d='\0';

t1[1].x=x+150;
t1[1].y=y-100;
t1[1].c=0;
t1[1].p=0;
t1[1].b=0;
t1[1].d='\0';

t2[0].y=y+100;
t2[0].x=x-150;
t2[0].c=0;
t2[0].p=0;
t2[0].b=0;
t2[0].d='\0';

t2[1].x=x+150;
t2[1].y=y+100;
t2[1].c=0;
t2[1].p=0;
t2[1].b=0;
t2[1].d='\0';

t2[2].x=2*x-20;
t2[2].y=2*y-31;
t2[2].c=1;
t2[2].b=1;
t2[2].p=0;
t2[2].d='\0';

a=t2[2].x+13;
b=t2[2].y+14;

cleardevice();
setcolor(12);
settextstyle(4,0,6);
outtextxy(x-100,y-50,"corner!!!!");
getch();
}

else

if(a<=2*x-1&&a>=1&&a<=x-60&&b>=2*y-11)
{
t1[2].d='\0';
t1[2].x=x;
t1[2].y=2*y-50;
t1[2].b=0;
t1[2].c=1;
ct=2;
t1[2].p=0;

t1[0].x=x-150;
t1[0].y=y-100;
t1[0].c=0;
t1[0].p=0;
t1[0].b=0;
t1[0].d='\0';

t1[1].x=x+150;
t1[1].y=y-100;
t1[1].c=0;
t1[1].p=0;
t1[1].b=0;
t1[1].d='\0';

t2[0].y=y+100;
t2[0].x=x-150;
t2[0].c=0;
t2[0].p=0;
t2[0].b=0;
t2[0].d='\0';


t2[1].c=0;
t2[1].p=0;
t2[1].b=0;
t2[1].d='\0';
t2[1].x=x+150;
t2[1].y=y+100;


t2[2].x=20;
t2[2].y=2*y-31;
t2[2].c=1;
t2[2].b=1;
t2[2].p=0;
t2[2].d='\0';

a=t2[2].x+13;
b=t2[2].y+14;


cleardevice();
setcolor(12);
settextstyle(4,0,6);
outtextxy(x-100,y-50,"corner!!!!");
getch();
}
else
if(a>=2*x-1&&b>=11&&b<=2*y-11)
{
t1[2].d='\0';
t1[2].x=x;
t1[2].y=y;
t1[2].b=0;
t1[2].c=1;
ct=2;
t1[2].p=0;

t1[0].x=x-150;
t1[0].y=y-100;
t1[0].c=0;
t1[0].p=0;
t1[0].b=0;
t1[0].d='\0';

t1[1].x=x+150;
t1[1].y=y-100;
t1[1].c=0;
t1[1].p=0;
t1[1].b=0;
t1[1].d='\0';


t2[0].y=y+100;
t2[0].x=x-150;
t2[0].c=0;
t2[0].p=0;
t2[0].b=0;
t2[0].d='\0';


t2[1].c=0;
t2[1].p=0;
t2[1].b=0;
t2[1].d='\0';
t2[1].x=x+150;
t2[1].y=y+100;


t2[2].x=2*x-1-20;
t2[2].y=b-14;
t2[2].c=1;
t2[2].b=1;
t2[2].p=0;
t2[2].d='\0';

a=t2[2].x+13;
b=t2[2].y+14;

cleardevice();
settextstyle(4,0,6);
setcolor(12);
outtextxy(x-100,y-50,"away!!!!");
getch();
}

else
if(a<=1&&b>=11&&b<=2*y-11)
{
t1[2].d='\0';
t1[2].x=x;
t1[2].y=y;
t1[2].b=0;
t1[2].c=1;
ct=2;
t1[2].p=0;

t1[0].x=x-150;
t1[0].y=y-100;
t1[0].c=0;
t1[0].p=0;
t1[0].b=0;
t1[0].d='\0';

t1[1].x=x+150;
t1[1].y=y-100;
t1[1].c=0;
t1[1].p=0;
t1[1].b=0;
t1[1].d='\0';


t2[0].y=y+100;
t2[0].x=x-150;
t2[0].c=0;
t2[0].p=0;
t2[0].b=0;
t2[0].d='\0';


t2[1].c=0;
t2[1].p=0;
t2[1].b=0;
t2[1].d='\0';
t2[1].x=x+150;
t2[1].y=y+100;


t2[2].x=21;
t2[2].y=b-14;
t2[2].c=1;
t2[2].b=1;
t2[2].p=0;
t2[2].d='\0';

a=t2[2].x+13;
b=t2[2].y+14;


cleardevice();
settextstyle(4,0,6);
setcolor(12);
outtextxy(x-100,y-50,"away!!!!");
getch();
}
else{;}

}
else{;}



for(i=0;i<3;i++)     //the block changing the coordinates of the player being controlled starts
{
if(ct==1)
{
if(t1[i].b!=1)
{
if(t1[i].d=='w')
t1[i].y-=12;
else
if(t1[i].d=='a')
t1[i].x-=12;
else
if(t1[i].d=='s')
t1[i].y+=12;
else
if(t1[i].d=='d')
t1[i].x+=12;
}
else
if(t1[i].b==1)
{
if(t1[i].d=='w')
{t1[i].y-=12;b-=12;}
else
if(t1[i].d=='a')
{t1[i].x-=12;a-=12;}
else
if(t1[i].d=='s')
{t1[i].y+=12;b+=12;}
else
if(t1[i].d=='d')
{t1[i].x+=12;a+=12;}
}
}
else
{
if(t1[i].d=='w')
t1[i].y-=16;
else
if(t1[i].d=='a')
t1[i].x-=16;
else
if(t1[i].d=='s')
t1[i].y+=16;
else
if(t1[i].d=='d')
t1[i].x+=16;
}



if(ct==2)
{
if(t2[i].b!=1)
{
if(t2[i].d=='i')
t2[i].y-=12;
else
if(t2[i].d=='j')
t2[i].x-=12;
else
if(t2[i].d=='k')
t2[i].y+=12;
else
if(t2[i].d=='l')
t2[i].x+=12;
}
else
if(t2[i].b==1)
{
if(t2[i].d=='i')
{t2[i].y-=12;b-=12;}
else
if(t2[i].d=='j')
{t2[i].x-=12;a-=12;}
else
if(t2[i].d=='k')
{t2[i].y+=12;b+=12;}
else
if(t2[i].d=='l')
{t2[i].x+=12;a+=12;}
}
}
else
{
if(t2[i].d=='i')
t2[i].y-=16;
else
if(t2[i].d=='j')
t2[i].x-=16;
else
if(t2[i].d=='k')
t2[i].y+=16;
else
if(t2[i].d=='l')
t2[i].x+=16;
}


} //the block changing the coordinates of the player being controlled ends





// the part resetting the position of the players starts


if((!(t1[0].x+10>x-150&&t1[0].x-10<x-150)||!(t1[0].y+10>y-100&&t1[0].y-10<y-100))&&t1[0].c!=1&&t1[0].p==1)
{
if(t1[0].x+10>x-150&&!(t1[0].x-10<x-150)&&t1[0].y+10>y-100&&!(t1[0].y-10<y-100))
{
t1[0].x-=12;
t1[0].y-=12;
}
else
if(t1[0].x-10<x-150&&!(t1[0].x+10>x-150)&&t1[0].y+10>y-100&&!(t1[0].y-10<y-100))
{
t1[0].x+=12;
t1[0].y-=12;
}
else
if(t1[0].x+10>x-150&&!(t1[0].x-10<x-150)&&t1[0].y-10<y-100&&!(t1[0].y+10>y-100))
{
t1[0].x-=12;
t1[0].y+=12;
}
else
if(t1[0].x-10<x-150&&!(t1[0].x+10>x-150)&&t1[0].y-10<y-100&&!(t1[0].y+10>y-100))
{
t1[0].x+=12;
t1[0].y+=12;
}
else

if(t1[0].x-10<x-150&&t1[0].x+10>x-150&&!(t1[0].y+10>y-100&&t1[0].y-10<y-100))
{if(t1[0].y>y-100)
t1[0].y-=12;
else
if(t1[0].y<y-100)
t1[0].y+=12;
}
else
if(!(t1[0].x-10<x-150&&t1[0].x+10>x-150)&&t1[0].y+10>y-100&&t1[0].y-10<y-100)
{if(t1[0].x>x-150)
t1[0].x-=12;
else
if(t1[0].x<x-150)
t1[0].x+=12;
}
}
else
t1[0].p=0;



if((!(t1[1].x+10>x+150&&t1[1].x-10<x+150)||!(t1[1].y+10>y-100&&t1[1].y-10<y-100))&&t1[1].c!=1&&t1[1].p==1)
{
if(t1[1].x+10>x+150&&!(t1[1].x-10<x+150)&&t1[1].y+10>y-100&&!(t1[1].y-10<y-100))
{
t1[1].x-=12;
t1[1].y-=12;
}
else
if(t1[1].x-10<x+150&&!(t1[1].x+10>x+150)&&t1[1].y+10>y-100&&!(t1[1].y-10<y-100))
{
t1[1].x+=12;
t1[1].y-=12;
}
else
if(t1[1].x+10>x+150&&!(t1[1].x-10<x+150)&&t1[1].y-10<y-100&&!(t1[1].y+10>y-100))
{
t1[1].x-=12;
t1[1].y+=12;
}
else
if(t1[1].x-10<x+150&&!(t1[1].x+10>x+150)&&t1[1].y-10<y-100&&!(t1[1].y+10>y-100))
{
t1[1].x+=12;
t1[1].y+=12;
}
else

if(t1[1].x-10<x+150&&t1[1].x+10>x+150&&!(t1[1].y+10>y-100&&t1[1].y-10<y-100))
{if(t1[1].y>y-100)
t1[1].y-=12;
else
if(t1[1].y<y-100)
t1[1].y+=12;
}
else
if(!(t1[1].x-10<x+150&&t1[1].x+10>x+150)&&t1[1].y+10>y-100&&t1[1].y-10<y-100)
{if(t1[1].x>x+150)
t1[1].x-=12;
else
if(t1[1].x<x+150)
t1[1].x+=12;
}
}
else
t1[1].p=0;


if((!(t1[2].x+10>x&&t1[2].x-10<x)||!(t1[2].y+10>y+125&&t1[2].y-10<y+125))&&t1[2].c!=1&&t1[2].p==1)
{
if(t1[2].x+10>x&&!(t1[2].x-10<x)&&t1[2].y+10>y+125&&!(t1[2].y-10<y+125))
{
t1[2].x-=12;
t1[2].y-=12;
}
else
if(t1[2].x-10<x&&!(t1[2].x+10>x)&&t1[2].y+10>y+125&&!(t1[2].y-10<y+125))
{
t1[2].x+=12;
t1[2].y-=12;
}
else
if(t1[2].x+10>x&&!(t1[2].x-10<x)&&t1[2].y-10<y+125&&!(t1[2].y+10>y+125))
{
t1[2].x-=12;
t1[2].y+=12;
}
else
if(t1[2].x-10<x&&!(t1[2].x+10>x)&&t1[2].y-10<y+125&&!(t1[2].y+10>y+125))
{
t1[2].x+=12;
t1[2].y+=12;
}
else

if(t1[2].x-10<x&&t1[2].x+10>x&&!(t1[2].y+10>y+125&&t1[2].y-10<y+125))
{if(t1[2].y>y+125)
t1[2].y-=12;
else
if(t1[2].y<y+125)
t1[2].y+=12;
}
else
if(!(t1[2].x-10<x&&t1[2].x+10>x)&&t1[2].y+10>y+125&&t1[2].y-10<y+125)
{if(t1[2].x>x)
t1[1].x-=12;
else
if(t1[2].x<x)
t1[2].x+=12;
}
}
else
t1[2].p=0;



if((!(t2[0].x+10>x-150&&t2[0].x-10<x-150)||!(t2[0].y+10>y+100&&t2[0].y-10<y+100))&&t2[0].c!=1&&t2[0].p==1)
{
if(t2[0].x+10>x-150&&!(t2[0].x-10<x-150)&&t2[0].y+10>y+100&&!(t2[0].y-10<y+100))
{
t2[0].x-=12;
t2[0].y-=12;
}
else
if(t2[0].x-10<x-150&&!(t2[0].x+10>x-150)&&t2[0].y+10>y+100&&!(t2[0].y-10<y+100))
{
t2[0].x+=12;
t2[0].y-=12;
}
else
if(t2[0].x+10>x-150&&!(t2[0].x-10<x-150)&&t2[0].y-10<y+100&&!(t2[0].y+10>y+100))
{
t2[0].x-=12;
t2[0].y+=12;
}
else
if(t2[0].x-10<x-150&&!(t2[0].x+10>x-150)&&t2[0].y-10<y+100&&!(t2[0].y+10>y+100))
{
t2[0].x+=12;
t2[0].y+=12;
}
else

if(t2[0].x-10<x-150&&t2[0].x+10>x-150&&!(t2[0].y+10>y+100&&t2[0].y-10<y+100))
{if(t2[0].y>y+100)
t2[0].y-=12;
else
if(t2[0].y<y+100)
t2[0].y+=12;
}
else
if(!(t2[0].x-10<x-150&&t2[0].x+10>x-150)&&t2[0].y+10>y+100&&t2[0].y-10<y+100)
{if(t2[0].x>x-150)
t2[0].x-=12;
else
if(t2[0].x<x-150)
t2[0].x+=12;
}
}
else
t2[0].p=0;



if((!(t2[1].x+10>x+150&&t2[1].x-10<x+150)||!(t2[1].y+10>y+100&&t2[1].y-10<y+100))&&t2[1].c!=1&&t2[1].p==1)
{
if(t2[1].x+10>x+150&&!(t2[1].x-10<x+150)&&t2[1].y+10>y+100&&!(t2[1].y-10<y+100))
{
t2[1].x-=12;
t2[1].y-=12;
}
else
if(t2[1].x-10<x+150&&!(t2[1].x+10>x+150)&&t2[1].y+10>y+100&&!(t2[1].y-10<y+100))
{
t2[1].x+=12;
t2[1].y-=12;
}
else
if(t2[1].x+10>x+150&&!(t2[1].x-10<x+150)&&t2[1].y-10<y+100&&!(t2[1].y+10>y+100))
{
t2[1].x-=12;
t2[1].y+=12;
}
else
if(t2[1].x-10<x+150&&!(t2[1].x+10>x+150)&&t2[1].y-10<y+100&&!(t2[1].y+10>y+100))
{
t2[1].x+=12;
t2[1].y+=12;
}
else

if(t2[1].x-10<x+150&&t2[1].x+10>x+150&&!(t2[1].y+10>y+100&&t2[1].y-10<y+100))
{if(t2[1].y>y+100)
t2[1].y-=12;
else
if(t2[1].y<y+100)
t2[1].y+=12;
}
else
if(!(t2[1].x-10<x+150&&t2[1].x+10>x+150)&&t2[1].y+10>y+100&&t2[1].y-10<y+100)
{if(t2[1].x>x+150)
t2[1].x-=12;
else
if(t2[1].x<x+150)
t2[1].x+=12;
}
}
else
t2[1].p=0;


if((!(t2[2].x+10>x&&t2[2].x-10<x)||!(t2[2].y+10>y-125&&t2[2].y-10<y-125))&&t2[2].c!=1&&t2[2].p==1)
{
if(t2[2].x+10>x&&!(t2[2].x-10<x)&&t2[2].y+10>y-125&&!(t2[2].y-10<y-125))
{
t2[2].x-=12;
t2[2].y-=12;
}
else
if(t2[2].x-10<x&&!(t2[2].x+10>x)&&t2[2].y+10>y-125&&!(t2[2].y-10<y-125))
{
t2[2].x+=12;
t2[2].y-=12;
}
else
if(t2[2].x+10>x&&!(t2[2].x-10<x)&&t2[2].y-10<y-125&&!(t2[2].y+10>y-125))
{
t1[2].x-=12;
t1[2].y+=12;
}
else
if(t2[2].x-10<x&&!(t2[2].x+10>x)&&t2[2].y-10<y-125&&!(t2[2].y+10>y-125))
{
t2[2].x+=12;
t2[2].y+=12;
}
else

if(t2[2].x-10<x&&t2[2].x+10>x&&!(t2[2].y+10>y-125&&t2[2].y-10<y-125))
{if(t2[2].y>y-125)
t2[2].y-=12;
else
if(t2[2].y<y-125)
t2[2].y+=12;
}
else
if(!(t2[2].x-10<x&&t2[2].x+10>x)&&t2[2].y+10>y-125&&t2[2].y-10<y-125)
{if(t2[2].x>x)
t2[1].x-=12;
else
if(t2[2].x<x)
t2[2].x+=12;
}
}
else
t2[2].p=0;


// the part resetting the position of the players ends










if(t1[0].b!=1&&t1[1].b!=1&&t1[2].b!=1&&t2[0].b!=1&&t2[1].b!=1&&t2[2].b!=1)
{


if(ax>=a1&&by<=b1)
{
a+=20*cos(ti);
b-=20*sin(ti);
}
else
if(ax>=a1&&by>=b1)
{
a+=20*cos(ti);
b+=20*sin(ti);
}
else
if(ax<=a1&&by<=b1)
{
a-=20*cos(ti);
b-=20*sin(ti);
}
else
if(ax<=a1&&by>=b1)
{
a-=20*cos(ti);
b+=20*sin(ti);
}


if(ct==1)
for(i=0;i<3;i++)
{
if(a>t1[i].x-15&&a<t1[i].x+15&&b>t1[i].y-15&&b<t1[i].y+25&&i!=sub)
{
ct=1;
t1[i].b=1;
t1[i].c=1;
t1[i].p=0;
for(j=0;j<3;j++)
{
if(j!=i)
{t1[j].b=0;
t1[j].c=0;}
}
a=t1[i].x+13;
b=t1[i].y+14;

}
if(a>t2[i].x-15&&a<t2[i].x+15&&b>t2[i].y-15&&b<t2[i].y+25)
{
ct=2;
t2[i].b=1;
t2[i].c=1;
t2[i].p=0;
for(j=0;j<3;j++)
{
if(j!=i)
{t2[j].b=0;
t2[j].c=0;}
}
a=t2[i].x+13;
b=t2[i].y+14;

}
}

if(ct==2)
for(i=0;i<3;i++)
{
if(a>t1[i].x-15&&a<t1[i].x+15&&b>t1[i].y-15&&b<t1[i].y+25)
{
ct=1;
t1[i].b=1;
t1[i].c=1;
t1[i].p=0;
for(j=0;j<3;j++)
{
if(j!=i)
{t1[j].b=0;
t1[j].c=0;}
}

a=t1[i].x+13;
b=t1[i].y+14;

}
if(a>t2[i].x-15&&a<t2[i].x+15&&b>t2[i].y-15&&b<t2[i].y+25&&i!=sub)
{
ct=2;
t2[i].b=1;
t2[i].c=1;
t2[i].p=0;
for(j=0;j<3;j++)
{
if(j!=i)
{t2[j].b=0;
t2[j].c=0;}
}
a=t2[i].x+13;
b=t2[i].y+14;

}
}

}










if(kbhit())              // kbhit() block starts
{
chc =getch();

if(chc==c1.e[0])
for(i=0;i<3;i++)
if(t1[i].c!=1)                 // reset button for team 1
t1[i].p=1;


if(chc==c2.u[0])
for(i=0;i<3;i++)             // reset button for team 2
if(t2[i].c!=1)
t2[i].p=1;

if(chc==c1.f[0]&&ct==1&&(t1[0].b==1||t1[1].b==1||t1[2].b==1))            // team1 passing the ball
{
if(t1[0].b==1)
{
if(sqrt(pow(x-t1[1].x,2)+pow(11-t1[1].y,2))<=sqrt(pow(x-t1[2].x,2)+pow(11-t1[2].y,2)))
{
t1[1].c=1;
t1[1].d='\0';
t1[1].b=0;      ax=t1[1].x;by=t1[1].y;
t1[1].p=0;      a1=a;b1=b;
t1[0].p=0;      ti=atan(fabs(b1-by)/fabs(a1-ax));
t1[0].c=0;      sub=0;
t1[0].b=0;
t1[0].d='\0';
}
else
{
t1[2].c=1;
t1[2].d='\0';
t1[2].b=0;
t1[2].p=0;
t1[0].p=0;      ax=t1[2].x;by=t1[2].y;
t1[0].c=0;      a1=a;b1=b;
t1[0].b=0;      ti=atan(fabs(b1-by)/fabs(a1-ax));
t1[0].d='\0';
sub=0;
}
}
else
if(t1[1].b==1)
{
if(sqrt(pow(t1[0].x-x,2)+pow(t1[0].y-11,2))<=sqrt(pow(x-t1[2].x,2)+pow(t1[2].y-11,2)))
{
t1[0].c=1;
t1[0].d='\0';
t1[0].b=0;
t1[0].p=0;         ax=t1[0].x;by=t1[0].y;
t1[1].p=0;         a1=a;b1=b;
t1[1].c=0;        ti=atan(fabs(b1-by)/fabs(a1-ax));
t1[1].b=0;
t1[1].d='\0';
sub=1;
}
else
{
t1[2].c=1;
t1[2].d='\0';
t1[2].b=0;
t1[2].p=0;         ax=t1[2].x;by=t1[2].y;
t1[1].p=0;         a1=a;b1=b;
t1[1].c=0;          ti=atan(fabs(b1-by)/fabs(a1-ax));
t1[1].b=0;
t1[1].d='\0';
sub=1;
}
}
else
if(t1[2].b==1)
{
if(sqrt(pow(t1[0].x-x,2)+pow(t1[0].y-11,2))<=sqrt(pow(t1[1].x-x,2)+pow(t1[1].y-11,2)))
{
t1[0].c=1;
t1[0].d='\0';
t1[0].b=0;         ax=t1[0].x;by=t1[0].y;
t1[0].p=0;         a1=a;b1=b;
t1[2].p=0;          ti=atan(fabs(b1-by)/fabs(a1-ax));
t1[2].c=0;
t1[2].b=0;
t1[2].d='\0';
sub=2;
}
else
{
t1[1].c=1;
t1[1].d='\0';
t1[1].b=0;
t1[1].p=0;          ax=t1[1].x;by=t1[1].y;
t1[2].p=0;           a1=a;b1=b;
t1[2].c=0;
t1[2].b=0;          ti=atan(fabs(b1-by)/fabs(a1-ax));
t1[2].d='\0';
sub=2;
}
}
} // team 1 passing the ball


if(chc==c2.h[0]&&ct==2&&(t2[0].b==1||t2[1].b==1||t2[2].b==1))             // team 2 passing the ball
{
if(t2[0].b==1)
{
if(sqrt(pow(x-t2[1].x,2)+pow(2*y-11-t2[1].y,2))<=sqrt(pow(x-t2[2].x,2)+pow(2*y-11-t2[2].y,2)))
{
t2[1].c=1;
t2[1].d='\0';
t2[1].b=0;          ax=t2[1].x;by=t2[1].y;
t2[1].p=0;          a1=a;b1=b;
t2[0].p=0;          ti=atan(fabs(b1-by)/fabs(a1-ax));
t2[0].c=0;
t2[0].b=0;
t2[0].d='\0';
sub=0;
}
else
{
t2[2].c=1;
t2[2].d='\0';
t2[2].b=0;           ax=t2[2].x;by=t2[2].y;
t2[2].p=0;          a1=a;b1=b;
t2[0].p=0;          ti=atan(fabs(b1-by)/fabs(a1-ax));
t2[0].c=0;
t2[0].b=0;
t2[0].d='\0';
sub=0;
}
}
else
if(t2[1].b==1)
{
if(sqrt(pow(t2[0].x-x,2)+pow(t2[0].y-2*y-11,2))<=sqrt(pow(t2[2].x-x,2)+pow(t2[2].y-2*y-11,2)))
{
t2[0].c=1;
t2[0].d='\0';
t2[0].b=0;            ax=t2[0].x;by=t2[0].y;
t2[0].p=0;          a1=a;b1=b;
t2[1].p=0;           ti=atan(fabs(b1-by)/fabs(a1-ax));
t2[1].c=0;
t2[1].b=0;
t2[1].d='\0';
sub=1;
}
else
{
t2[2].c=1;
t2[2].d='\0';
t2[2].b=0;          ax=t2[2].x;by=t2[2].y;
t2[2].p=0;          a1=a;b1=b;
t2[1].p=0;           ti=atan(fabs(b1-by)/fabs(a1-ax));
t2[1].c=0;
t2[1].b=0;
t2[1].d='\0';
sub=1;
}
}
else
if(t2[2].b==1)
{
if(sqrt(pow(t2[0].x-x,2)+pow(t2[0].y-2*y-11,2))<=sqrt(pow(t2[1].x-x,2)+pow(t2[1].y-2*y-11,2)))
{
t2[0].c=1;
t2[0].d='\0';
t2[0].b=0;
t2[0].p=0;            ax=t2[0].x;by=t2[0].y;
t2[2].p=0;          a1=a;b1=b;
t2[2].c=0;           ti=atan(fabs(b1-by)/fabs(a1-ax));
t2[2].b=0;
t2[2].d='\0';
sub=2;
}
else
{
t2[1].c=1;
t2[1].d='\0';
t2[1].b=0;            ax=t2[1].x;by=t2[1].y;
t2[1].p=0;          a1=a;b1=b;
t2[2].p=0;           ti=atan(fabs(b1-by)/fabs(a1-ax));
t2[2].c=0;
t2[2].b=0;
t2[2].d='\0';
sub=2;
}
}
} // team 2 passing the ball


if(chc==c1.f[0]&&ct!=1)             // team 1 player change starts
{

int O;

for(i=0;i<3;i++)
if(t2[i].c==1)
O=i;


int d1,d2;

if(t1[0].c==1)
{d1=sqrt(pow(t1[1].x-t2[O].x+13,2)+pow(t2[O].y+14-t1[1].y,2));
d2=sqrt(pow(t2[O].x+13-t1[2].x,2)+pow(t2[O].y+14-t1[2].y,2));
if(d1<=d2)
{
t1[1].c=1;
t1[1].d='\0';
t1[1].b=0;
t1[1].p=0;
t1[0].p=0;
t1[0].c=0;
t1[0].b=0;
t1[0].d='\0';
}
else
{
t1[2].c=1;
t1[2].d='\0';
t1[2].b=0;
t1[2].p=0;
t1[0].p=0;
t1[0].c=0;
t1[0].b=0;
t1[0].d='\0';
}
}
else
if(t1[1].c==1)
{d1=sqrt(pow(t1[0].x- t2[O].x+13,2)+pow(t2[O].y+14-t1[0].y,2));
d2=sqrt(pow( t2[O].x+13-t1[2].x,2)+pow(t2[O].y+14-t1[2].y,2));
if(d1<=d2)
{
t1[0].c=1;
t1[0].d='\0';
t1[0].b=0;
t1[0].p=0;
t1[1].p=0;
t1[1].c=0;
t1[1].b=0;
t1[1].d='\0';
}
else
{
t1[2].c=1;
t1[2].d='\0';
t1[2].b=0;
t1[2].p=0;
t1[1].p=0;
t1[1].c=0;
t1[1].b=0;
t1[1].d='\0';
}
}
else
if(t1[2].c==1)
{d1=sqrt(pow(t1[0].x-t2[O].x+13,2)+pow(t1[0].y-t2[O].y+14,2));
d2=sqrt(pow(t1[1].x-t2[O].x+13,2)+pow(t1[1].y-t2[O].y+14,2));
if(d1<=d2)
{
t1[0].c=1;
t1[0].d='\0';
t1[0].b=0;
t1[0].p=0;
t1[2].p=0;
t1[2].c=0;
t1[2].b=0;
t1[2].d='\0';
}
else
{
t1[1].c=1;
t1[1].d='\0';
t1[1].b=0;
t1[1].p=0;
t1[2].p=0;
t1[2].c=0;
t1[2].b=0;
t1[2].d='\0';
}
}
} // team 1 player change ends



if(chc==c2.h[0]&&ct!=2)             // team 2 player change starts
{

int O;

for(i=0;i<3;i++)
if(t1[i].c==1)
O=i;

int d1,d2;

if(t2[0].c==1)
{d1=sqrt(pow(t1[O].y+13-t2[1].x,2)+pow(t1[O].y+14-t2[1].y,2));
d2=sqrt(pow(t1[O].x+13-t2[2].x,2)+pow(t1[O].y+14-t2[2].y,2));
if(d1<=d2)
{
t2[1].c=1;
t2[1].d='\0';
t2[1].b=0;
t2[1].p=0;
t2[0].p=0;
t2[0].c=0;
t2[0].b=0;
t2[0].d='\0';
}
else
{
t2[2].c=1;
t2[2].d='\0';
t2[2].b=0;
t2[2].p=0;
t2[0].p=0;
t2[0].c=0;
t2[0].b=0;
t2[0].d='\0';
}
}
else
if(t2[1].c==1)
{d1=sqrt(pow(t2[0].x-t1[O].x+13,2)+pow(t2[0].y-t1[O].y+14,2));
d2=sqrt(pow(t1[O].x+13-t2[2].x,2)+pow(t2[2].y-t1[O].y+14,2));
if(d1<=d2)
{
t2[0].c=1;
t2[0].d='\0';
t2[0].b=0;
t2[0].p=0;
t2[1].p=0;
t2[1].c=0;
t2[1].b=0;
t2[1].d='\0';
}
else
{
t2[2].c=1;
t2[2].d='\0';
t2[2].b=0;
t2[2].p=0;
t2[1].p=0;
t2[1].c=0;
t2[1].b=0;
t2[1].d='\0';
}
}
else
if(t2[2].c==1)
{d1=sqrt(pow(t2[0].x- t1[O].x+13,2)+pow(t2[0].y-t1[O].y+14,2));
d2=sqrt(pow(t2[1].x- t1[O].x+13,2)+pow(t2[1].y-t1[O].y+14,2));
if(d1<=d2)
{
t2[0].c=1;
t2[0].d='\0';
t2[0].b=0;
t2[0].p=0;
t2[2].p=0;
t2[2].c=0;
t2[2].b=0;
t2[2].d='\0';
}
else
{
t2[1].c=1;
t2[1].d='\0';
t2[1].b=0;
t2[1].p=0;
t2[2].p=0;
t2[2].c=0;
t2[2].b=0;
t2[2].d='\0';
}
}
} // team 2 player change ends






if(chc==c1.w[0])
for(i=0;i<3;i++)
if(t1[i].c==1)
t1[i].d='w';

if(chc==c1.a[0])
for(i=0;i<3;i++)
if(t1[i].c==1)
t1[i].d='a';

if(chc==c1.s[0])
for(i=0;i<3;i++)
if(t1[i].c==1)
t1[i].d='s';

if(chc==c1.d[0])
for(i=0;i<3;i++)
if(t1[i].c==1)
t1[i].d='d';

if(chc==c2.i[0])
for(i=0;i<3;i++)
if(t2[i].c==1)
t2[i].d='i';

if(chc==c2.j[0])
for(i=0;i<3;i++)
if(t2[i].c==1)
t2[i].d='j';

if(chc==c2.k[0])
for(i=0;i<3;i++)
if(t2[i].c==1)
t2[i].d='k';

if(chc==c2.l[0])
for(i=0;i<3;i++)
if(t2[i].c==1)
t2[i].d='l';


if(chc==c1.c[0])
if(ct==2)
{
for(i=0;i<3;i++)   // player going to tackle the ball
if(t1[i].c==1)
break;

for(j=0;j<3;j++)
if(t2[j].c==1)     //player having ball
break;

if(a>t1[i].x-15&&a<t1[i].x+15&&b>t1[i].y-15&&b<t1[i].y+25)
{
ct=1;
t1[i].b=1;
t1[i].c=1;
t1[i].p=0;
t1[i].d='w';
a=t1[i].x+13;
b=t1[i].y+14;
t2[j].b=0;
t2[j].d='\0';
t2[j].p=0;
}

}


if(chc==c2.n[0])
if(ct==1)
{
for(i=0;i<3;i++)   // player going to tackle the ball
if(t2[i].c==1)
break;

for(j=0;j<3;j++)
if(t1[j].c==1)     //player having ball
break;

if(a>t2[i].x-15&&a<t2[i].x+15&&b>t2[i].y-15&&b<t2[i].y+25)
{
ct=2;
t2[i].b=1;
t2[i].c=1;
t2[i].p=0;
t2[i].d='k';
a=t2[i].x+13;
b=t2[i].y+14;
t1[j].b=0;
t1[j].d='\0';
t1[j].p=0;
}

}


if(chc=='p')
{
p:
mf=1;
qf=1;


cleardevice();
setfillstyle(0,0);
setcolor(12);
bar3d(2*x-1,2*y-11,1,11,0,0);             // border
line(1,y,2*x-1,y);                        // center line
circle(x,y,80);                           // center circle
bar3d(x+60,11,x-60,1,0,0);                // top goal
bar3d(x+120,50,x-120,11,0,0);             // top d box
sector(x,50,180,360,45,30);               // top semicircle
bar3d(x+60,2*y-1,x-60,2*y-11,0,0);        // bottom goal
bar3d(x+120,2*y-11,x-120,2*y-50,0,0);     // bottom d box
sector(x,2*y-50,0,180,45,30);	          // bottom semicircle
setcolor(3);
setfillstyle(1,3);
fillellipse(a,b,6,6);		   // football

for(i=0;i<3;i++)                                          // 1st team
if(t1[i].c==1&&t1[i].b!=1)
{
setcolor(12);
circle(t1[i].x,t1[i].y,25);
setfillstyle(1,12);
bar3d(t1[i].x+10,t1[i].y+10,t1[i].x-10,t1[i].y-10,0,0);   // body
fillellipse(t1[i].x,t1[i].y-14,6,6);                      // head
bar3d(t1[i].x-7,t1[i].y,t1[i].x-2,t1[i].y+20,0,0);        // 1st leg
bar3d(t1[i].x+2,t1[i].y,t1[i].x+7,t1[i].y+20,0,0);        // 2nd leg
bar3d(t1[i].x,t1[i].y-7,t1[i].x-20,t1[i].y-10,0,0);       // 1st hand
bar3d(t1[i].x+20,t1[i].y-7,t1[i].x,t1[i].y-10,0,0);       // 2nd hand
}
else
{setcolor(12);
setfillstyle(1,12);
bar3d(t1[i].x+10,t1[i].y+10,t1[i].x-10,t1[i].y-10,0,0);   // body
fillellipse(t1[i].x,t1[i].y-14,6,6);                      // head
bar3d(t1[i].x-7,t1[i].y,t1[i].x-2,t1[i].y+20,0,0);        // 1st leg
bar3d(t1[i].x+2,t1[i].y,t1[i].x+7,t1[i].y+20,0,0);        // 2nd leg
bar3d(t1[i].x,t1[i].y-7,t1[i].x-20,t1[i].y-10,0,0);       // 1st hand
bar3d(t1[i].x+20,t1[i].y-7,t1[i].x,t1[i].y-10,0,0);       // 2nd hand
}
for(i=0;i<3;i++)                                          // second team
if(t2[i].c==1&&t2[i].b!=1)
{
setcolor(5);
circle(t2[i].x,t2[i].y,25);
setfillstyle(1,5);
bar3d(t2[i].x+10,t2[i].y+10,t2[i].x-10,t2[i].y-10,0,0);   // body
fillellipse(t2[i].x,t2[i].y-14,6,6);                      // head
bar3d(t2[i].x-7,t2[i].y,t2[i].x-2,t2[i].y+20,0,0);        // 1st leg
bar3d(t2[i].x+2,t2[i].y,t2[i].x+7,t2[i].y+20,0,0);        // 2nd leg
bar3d(t2[i].x,t2[i].y-7,t2[i].x-20,t2[i].y-10,0,0);       // 1st hand
bar3d(t2[i].x+20,t2[i].y-7,t2[i].x,t2[i].y-10,0,0);       // 2nd hand
}
else
{setcolor(5);
setfillstyle(1,5);
bar3d(t2[i].x+10,t2[i].y+10,t2[i].x-10,t2[i].y-10,0,0);   // body
fillellipse(t2[i].x,t2[i].y-14,6,6);                      // head
bar3d(t2[i].x-7,t2[i].y,t2[i].x-2,t2[i].y+20,0,0);        // 1st leg
bar3d(t2[i].x+2,t2[i].y,t2[i].x+7,t2[i].y+20,0,0);        // 2nd leg
bar3d(t2[i].x,t2[i].y-7,t2[i].x-20,t2[i].y-10,0,0);       // 1st hand
bar3d(t2[i].x+20,t2[i].y-7,t2[i].x,t2[i].y-10,0,0);       // 2nd hand
}




setcolor(12);
settextstyle(7,0,8);
setfillstyle(0,0);
bar3d(x+180,125,x-140,0,0,0);
bar3d(x+220,getmaxy(),x-200,getmaxy()-100,0,0);
outtextxy((getmaxx()/2)-120,0,"paused");
settextstyle(7,0,2);
outtextxy(x-170,getmaxy()-100,"press \"r\" to resume");
outtextxy(x-170,getmaxy()-75,"press \"m\" to goto main menu");
outtextxy(x-170,getmaxy()-50,"press \"q\" to quit out of game");
outtextxy(x-170,getmaxy()-25,"press enter to access control menu");
settextstyle(7,0,8);
do{z=getch();

if(z==13)
{
int x1=0;
int y1=-3;
char t='a';
topc:
cleardevice();
/*cout<<"\n\n\n\n\n\t\t here ==> "<<t;   */
settextstyle(7,0,5);
setfillstyle(EMPTY_FILL,0);
bar3d(x-310+x1,y+y1*50,x-30+x1,y+y1*50+40,0,0);  //y1 from -3 to 3 && x1 = 0 or 340
outtextxy(x+90,y-200,"team 2");
outtextxy(x-250,y-200,"team 1");
settextstyle(7,0,3);
outtextxy(x-300,y-150,"move left");
outtextxy(x-100,y-150,":");
outtextxy(x-60,y-150,c1.a);
outtextxy(x-300,y-100,"move down");
outtextxy(x-100,y-100,":");
outtextxy(x-60,y-100,c1.s);
outtextxy(x-300,y-50,"move right");
outtextxy(x-100,y-50,":");
outtextxy(x-60,y-50,c1.d);
outtextxy(x-300,y,"move up");
outtextxy(x-100,y,":");
outtextxy(x-60,y,c1.w);
outtextxy(x-300,y+50,"position reset");
outtextxy(x-100,y+50,":");
outtextxy(x-60,y+50,c1.e);
outtextxy(x-300,y+100,"pass or change");
outtextxy(x-100,y+100,":");
outtextxy(x-60,y+100,c1.f);
outtextxy(x-300,y+150,"tackle");
outtextxy(x-100,y+150,":");
outtextxy(x-60,y+150,c1.c);

outtextxy(x+40,y-150,"move left");
outtextxy(x+220,y-150,":");
outtextxy(x+280,y-150,c2.j);
outtextxy(x+40,y-100,"move down");
outtextxy(x+220,y-100,":");
outtextxy(x+280,y-100,c2.k);
outtextxy(x+40,y-50,"move right");
outtextxy(x+220,y-50,":");
outtextxy(x+280,y-50,c2.l);
outtextxy(x+40,y,"move up");
outtextxy(x+220,y,":");
outtextxy(x+280,y,c2.i);
outtextxy(x+40,y+50,"position reset");
outtextxy(x+220,y+50,":");
outtextxy(x+280,y+50,c2.u);
outtextxy(x+40,y+100,"pass or change");
outtextxy(x+220,y+100,":");
outtextxy(x+280,y+100,c2.h);
outtextxy(x+40,y+150,"tackle");
outtextxy(x+220,y+150,":");
outtextxy(x+280,y+150,c2.n);

outtextxy(x-100,y+200,"press \"b\" to go back");
do{
if (kbhit())
{
t=getch();
if(t=='s'&&y1!=3)
{y1++;
goto topc;}
else
if(t=='w'&&y1!=-3)
{y1--;
goto topc;}
else
if(t=='d'&&x1==0)
{x1=340;
goto topc;}
else
if(t=='a'&&x1==340)
{x1=0;
goto topc;}

if(x1==0)
{

if(t==13&&y1==-3)
{
setfillstyle(SOLID_FILL,0);
bar3d(x-310+x1,y+y1*50,x-30+x1,y+y1*50+40,0,0);
outtextxy(x-300,y-150,"move left");
outtextxy(x-100,y-150,":");
t=getch();
if(t==13)
{goto topc;}
else
{c1.a[0]=t;
goto topc;}
}
else
if(t==13&&y1==-2)
{
setfillstyle(SOLID_FILL,0);
bar3d(x-310+x1,y+y1*50,x-30+x1,y+y1*50+40,0,0);
outtextxy(x-300,y-100,"move down");
outtextxy(x-100,y-100,":");
t=getch();
if(t==13)
{goto topc;}
else
{c1.s[0]=t;
goto topc;}
}
else
if(t==13&&y1==-1)
{
setfillstyle(SOLID_FILL,0);
bar3d(x-310+x1,y+y1*50,x-30+x1,y+y1*50+40,0,0);
outtextxy(x-300,y-50,"move right");
outtextxy(x-100,y-50,":");
t=getch();
if(t==13)
{goto topc;}
else
{c1.d[0]=t;
goto topc;}
}
else
if(t==13&&y1==0)
{
setfillstyle(SOLID_FILL,0);
bar3d(x-310+x1,y+y1*50,x-30+x1,y+y1*50+40,0,0);
outtextxy(x-300,y,"move up");
outtextxy(x-100,y,":");
t=getch();
if(t==13)
{goto topc;}
else
{c1.w[0]=t;
goto topc;}
}
else
if(t==13&&y1==1)
{
setfillstyle(SOLID_FILL,0);
bar3d(x-310+x1,y+y1*50,x-30+x1,y+y1*50+40,0,0);
outtextxy(x-300,y+50,"position reset");
outtextxy(x-100,y+50,":");
t=getch();
if(t==13)
{goto topc;}
else
{c1.e[0]=t;
goto topc;}
}
else
if(t==13&&y1==2)
{
setfillstyle(SOLID_FILL,0);
bar3d(x-310+x1,y+y1*50,x-30+x1,y+y1*50+40,0,0);
outtextxy(x-300,y+100,"pass or change");
outtextxy(x-100,y+100,":");
t=getch();
if(t==13)
{goto topc;}
else
{c1.f[0]=t;
goto topc;}
}
else
if(t==13&&y1==3)
{
setfillstyle(SOLID_FILL,0);
bar3d(x-310+x1,y+y1*50,x-30+x1,y+y1*50+40,0,0);
outtextxy(x-300,y+150,"tackle");
outtextxy(x-100,y+150,":");
t=getch();
if(t==13)
{goto topc;}
else
{c1.c[0]=t;
goto topc;}
}

}
else
{

if(t==13&&y1==-3)
{
setfillstyle(SOLID_FILL,0);
bar3d(x-310+x1,y+y1*50,x-30+x1,y+y1*50+40,0,0);
outtextxy(x+40,y-150,"move left");
outtextxy(x+220,y-150,":");
t=getch();
if(t==13)
{goto topc;}
else
{c2.j[0]=t;
goto topc;}
}
else
if(t==13&&y1==-2)
{
setfillstyle(SOLID_FILL,0);
bar3d(x-310+x1,y+y1*50,x-30+x1,y+y1*50+40,0,0);
outtextxy(x+40,y-100,"move down");
outtextxy(x+220,y-100,":");
t=getch();
if(t==13)
{goto topc;}
else
{c2.k[0]=t;
goto topc;}
}
else
if(t==13&&y1==-1)
{
setfillstyle(SOLID_FILL,0);
bar3d(x-310+x1,y+y1*50,x-30+x1,y+y1*50+40,0,0);
outtextxy(x+40,y-50,"move right");
outtextxy(x+220,y-50,":");
t=getch();
if(t==13)
{goto topc;}
else
{c2.l[0]=t;
goto topc;}
}
else
if(t==13&&y1==0)
{
setfillstyle(SOLID_FILL,0);
bar3d(x-310+x1,y+y1*50,x-30+x1,y+y1*50+40,0,0);
outtextxy(x+40,y,"move up");
outtextxy(x+220,y,":");
t=getch();
if(t==13)
{goto topc;}
else
{c2.i[0]=t;
goto topc;}
}
else
if(t==13&&y1==1)
{
setfillstyle(SOLID_FILL,0);
bar3d(x-310+x1,y+y1*50,x-30+x1,y+y1*50+40,0,0);
outtextxy(x+40,y+50,"position reset");
outtextxy(x+220,y+50,":");
t=getch();
if(t==13)
{goto topc;}
else
{c2.u[0]=t;
goto topc;}
}
else
if(t==13&&y1==2)
{
setfillstyle(SOLID_FILL,0);
bar3d(x-310+x1,y+y1*50,x-30+x1,y+y1*50+40,0,0);
outtextxy(x+40,y+100,"pass or change");
outtextxy(x+220,y+100,":");
t=getch();
if(t==13)
{goto topc;}
else
{c2.h[0]=t;
goto topc;}
}
else
if(t==13&&y1==3)
{
setfillstyle(SOLID_FILL,0);
bar3d(x-310+x1,y+y1*50,x-30+x1,y+y1*50+40,0,0);
outtextxy(x+40,y+150,"tackle");
outtextxy(x+220,y+150,":");t=getch();
if(t==13)
{goto topc;}
else
{c2.n[0]=t;
goto topc;}
}

}

}
}while(t!='b');

goto p;
}
else
if(z=='r')
{continue;}
else
if(z=='m')
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
{/*return mc+mf;*/}   //if mc+mf==14 goto topf;
else
if(mc=='d'&&mf==1)
{
cleardevice();
setfillstyle(0,0);
setcolor(12);
bar3d(2*x-1,2*y-11,1,11,0,0);             // border
line(1,y,2*x-1,y);                        // center line
circle(x,y,80);                           // center circle
bar3d(x+60,11,x-60,1,0,0);                // top goal
bar3d(x+120,50,x-120,11,0,0);             // top d box
sector(x,50,180,360,45,30);               // top semicircle
bar3d(x+60,2*y-1,x-60,2*y-11,0,0);        // bottom goal
bar3d(x+120,2*y-11,x-120,2*y-50,0,0);     // bottom d box
sector(x,2*y-50,0,180,45,30);	          // bottom semicircle
setcolor(3);
setfillstyle(1,3);
fillellipse(a,b,6,6);		   // football

for(i=0;i<3;i++)                                          // 1st team
if(t1[i].c==1&&t1[i].b!=1)
{
setcolor(12);
circle(t1[i].x,t1[i].y,25);
setfillstyle(1,12);
bar3d(t1[i].x+10,t1[i].y+10,t1[i].x-10,t1[i].y-10,0,0);   // body
fillellipse(t1[i].x,t1[i].y-14,6,6);                      // head
bar3d(t1[i].x-7,t1[i].y,t1[i].x-2,t1[i].y+20,0,0);        // 1st leg
bar3d(t1[i].x+2,t1[i].y,t1[i].x+7,t1[i].y+20,0,0);        // 2nd leg
bar3d(t1[i].x,t1[i].y-7,t1[i].x-20,t1[i].y-10,0,0);       // 1st hand
bar3d(t1[i].x+20,t1[i].y-7,t1[i].x,t1[i].y-10,0,0);       // 2nd hand
}
else
{setcolor(12);
setfillstyle(1,12);
bar3d(t1[i].x+10,t1[i].y+10,t1[i].x-10,t1[i].y-10,0,0);   // body
fillellipse(t1[i].x,t1[i].y-14,6,6);                      // head
bar3d(t1[i].x-7,t1[i].y,t1[i].x-2,t1[i].y+20,0,0);        // 1st leg
bar3d(t1[i].x+2,t1[i].y,t1[i].x+7,t1[i].y+20,0,0);        // 2nd leg
bar3d(t1[i].x,t1[i].y-7,t1[i].x-20,t1[i].y-10,0,0);       // 1st hand
bar3d(t1[i].x+20,t1[i].y-7,t1[i].x,t1[i].y-10,0,0);       // 2nd hand
}
for(i=0;i<3;i++)                                          // second team
if(t2[i].c==1&&t2[i].b!=1)
{
setcolor(5);
circle(t2[i].x,t2[i].y,25);
setfillstyle(1,5);
bar3d(t2[i].x+10,t2[i].y+10,t2[i].x-10,t2[i].y-10,0,0);   // body
fillellipse(t2[i].x,t2[i].y-14,6,6);                      // head
bar3d(t2[i].x-7,t2[i].y,t2[i].x-2,t2[i].y+20,0,0);        // 1st leg
bar3d(t2[i].x+2,t2[i].y,t2[i].x+7,t2[i].y+20,0,0);        // 2nd leg
bar3d(t2[i].x,t2[i].y-7,t2[i].x-20,t2[i].y-10,0,0);       // 1st hand
bar3d(t2[i].x+20,t2[i].y-7,t2[i].x,t2[i].y-10,0,0);       // 2nd hand
}
else
{setcolor(5);
setfillstyle(1,5);
bar3d(t2[i].x+10,t2[i].y+10,t2[i].x-10,t2[i].y-10,0,0);   // body
fillellipse(t2[i].x,t2[i].y-14,6,6);                      // head
bar3d(t2[i].x-7,t2[i].y,t2[i].x-2,t2[i].y+20,0,0);        // 1st leg
bar3d(t2[i].x+2,t2[i].y,t2[i].x+7,t2[i].y+20,0,0);        // 2nd leg
bar3d(t2[i].x,t2[i].y-7,t2[i].x-20,t2[i].y-10,0,0);       // 1st hand
bar3d(t2[i].x+20,t2[i].y-7,t2[i].x,t2[i].y-10,0,0);       // 2nd hand
}

setcolor(12);


settextstyle(7,0,8);
setfillstyle(0,0);
bar3d(x+180,125,x-140,0,0,0);
bar3d(x+220,getmaxy(),x-200,getmaxy()-100,0,0);
outtextxy((getmaxx()/2)-120,0,"paused");
settextstyle(7,0,2);
outtextxy(x-170,getmaxy()-100,"press \"r\" to resume");
outtextxy(x-170,getmaxy()-75,"press \"m\" to goto main menu");
outtextxy(x-170,getmaxy()-50,"press \"q\" to quit out of game");
outtextxy(x-170,getmaxy()-25,"press enter to access control menu");
settextstyle(7,0,8);
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

cleardevice();
setfillstyle(0,0);
setcolor(12);
bar3d(2*x-1,2*y-11,1,11,0,0);             // border
line(1,y,2*x-1,y);                        // center line
circle(x,y,80);                           // center circle
bar3d(x+60,11,x-60,1,0,0);                // top goal
bar3d(x+120,50,x-120,11,0,0);             // top d box
sector(x,50,180,360,45,30);               // top semicircle
bar3d(x+60,2*y-1,x-60,2*y-11,0,0);        // bottom goal
bar3d(x+120,2*y-11,x-120,2*y-50,0,0);     // bottom d box
sector(x,2*y-50,0,180,45,30);	          // bottom semicircle
setcolor(3);
setfillstyle(1,3);
fillellipse(a,b,6,6);		   // football

for(i=0;i<3;i++)                                          // 1st team
if(t1[i].c==1&&t1[i].b!=1)
{
setcolor(12);
circle(t1[i].x,t1[i].y,25);
setfillstyle(1,12);
bar3d(t1[i].x+10,t1[i].y+10,t1[i].x-10,t1[i].y-10,0,0);   // body
fillellipse(t1[i].x,t1[i].y-14,6,6);                      // head
bar3d(t1[i].x-7,t1[i].y,t1[i].x-2,t1[i].y+20,0,0);        // 1st leg
bar3d(t1[i].x+2,t1[i].y,t1[i].x+7,t1[i].y+20,0,0);        // 2nd leg
bar3d(t1[i].x,t1[i].y-7,t1[i].x-20,t1[i].y-10,0,0);       // 1st hand
bar3d(t1[i].x+20,t1[i].y-7,t1[i].x,t1[i].y-10,0,0);       // 2nd hand
}
else
{setcolor(12);
setfillstyle(1,12);
bar3d(t1[i].x+10,t1[i].y+10,t1[i].x-10,t1[i].y-10,0,0);   // body
fillellipse(t1[i].x,t1[i].y-14,6,6);                      // head
bar3d(t1[i].x-7,t1[i].y,t1[i].x-2,t1[i].y+20,0,0);        // 1st leg
bar3d(t1[i].x+2,t1[i].y,t1[i].x+7,t1[i].y+20,0,0);        // 2nd leg
bar3d(t1[i].x,t1[i].y-7,t1[i].x-20,t1[i].y-10,0,0);       // 1st hand
bar3d(t1[i].x+20,t1[i].y-7,t1[i].x,t1[i].y-10,0,0);       // 2nd hand
}
for(i=0;i<3;i++)                                          // second team
if(t2[i].c==1&&t2[i].b!=1)
{
setcolor(5);
circle(t2[i].x,t2[i].y,25);
setfillstyle(1,5);
bar3d(t2[i].x+10,t2[i].y+10,t2[i].x-10,t2[i].y-10,0,0);   // body
fillellipse(t2[i].x,t2[i].y-14,6,6);                      // head
bar3d(t2[i].x-7,t2[i].y,t2[i].x-2,t2[i].y+20,0,0);        // 1st leg
bar3d(t2[i].x+2,t2[i].y,t2[i].x+7,t2[i].y+20,0,0);        // 2nd leg
bar3d(t2[i].x,t2[i].y-7,t2[i].x-20,t2[i].y-10,0,0);       // 1st hand
bar3d(t2[i].x+20,t2[i].y-7,t2[i].x,t2[i].y-10,0,0);       // 2nd hand
}
else
{setcolor(5);
setfillstyle(1,5);
bar3d(t2[i].x+10,t2[i].y+10,t2[i].x-10,t2[i].y-10,0,0);   // body
fillellipse(t2[i].x,t2[i].y-14,6,6);                      // head
bar3d(t2[i].x-7,t2[i].y,t2[i].x-2,t2[i].y+20,0,0);        // 1st leg
bar3d(t2[i].x+2,t2[i].y,t2[i].x+7,t2[i].y+20,0,0);        // 2nd leg
bar3d(t2[i].x,t2[i].y-7,t2[i].x-20,t2[i].y-10,0,0);       // 1st hand
bar3d(t2[i].x+20,t2[i].y-7,t2[i].x,t2[i].y-10,0,0);       // 2nd hand
}


setcolor(12);

setfillstyle(0,0);
bar3d(x+180,125,x-140,0,0,0);
bar3d(x+220,getmaxy(),x-200,getmaxy()-100,0,0);
outtextxy((getmaxx()/2)-120,0,"paused");
settextstyle(7,0,2);
outtextxy(x-170,getmaxy()-100,"press \"r\" to resume");
outtextxy(x-170,getmaxy()-75,"press \"m\" to goto main menu");
outtextxy(x-170,getmaxy()-50,"press \"q\" to quit out of game");
outtextxy(x-170,getmaxy()-25,"press enter to access control menu");
settextstyle(7,0,8);
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

if(z=='q')
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
{exit(0);}
else
if(qc=='d'&&qf==1)
{

cleardevice();
setfillstyle(0,0);
setcolor(12);
bar3d(2*x-1,2*y-11,1,11,0,0);             // border
line(1,y,2*x-1,y);                        // center line
circle(x,y,80);                           // center circle
bar3d(x+60,11,x-60,1,0,0);                // top goal
bar3d(x+120,50,x-120,11,0,0);             // top d box
sector(x,50,180,360,45,30);               // top semicircle
bar3d(x+60,2*y-1,x-60,2*y-11,0,0);        // bottom goal
bar3d(x+120,2*y-11,x-120,2*y-50,0,0);     // bottom d box
sector(x,2*y-50,0,180,45,30);	          // bottom semicircle
setcolor(3);
setfillstyle(1,3);
fillellipse(a,b,6,6);		   // football

for(i=0;i<3;i++)                                          // 1st team
if(t1[i].c==1&&t1[i].b!=1)
{
setcolor(12);
circle(t1[i].x,t1[i].y,25);
setfillstyle(1,12);
bar3d(t1[i].x+10,t1[i].y+10,t1[i].x-10,t1[i].y-10,0,0);   // body
fillellipse(t1[i].x,t1[i].y-14,6,6);                      // head
bar3d(t1[i].x-7,t1[i].y,t1[i].x-2,t1[i].y+20,0,0);        // 1st leg
bar3d(t1[i].x+2,t1[i].y,t1[i].x+7,t1[i].y+20,0,0);        // 2nd leg
bar3d(t1[i].x,t1[i].y-7,t1[i].x-20,t1[i].y-10,0,0);       // 1st hand
bar3d(t1[i].x+20,t1[i].y-7,t1[i].x,t1[i].y-10,0,0);       // 2nd hand
}
else
{setcolor(12);
setfillstyle(1,12);
bar3d(t1[i].x+10,t1[i].y+10,t1[i].x-10,t1[i].y-10,0,0);   // body
fillellipse(t1[i].x,t1[i].y-14,6,6);                      // head
bar3d(t1[i].x-7,t1[i].y,t1[i].x-2,t1[i].y+20,0,0);        // 1st leg
bar3d(t1[i].x+2,t1[i].y,t1[i].x+7,t1[i].y+20,0,0);        // 2nd leg
bar3d(t1[i].x,t1[i].y-7,t1[i].x-20,t1[i].y-10,0,0);       // 1st hand
bar3d(t1[i].x+20,t1[i].y-7,t1[i].x,t1[i].y-10,0,0);       // 2nd hand
}
for(i=0;i<3;i++)                                          // second team
if(t2[i].c==1&&t2[i].b!=1)
{
setcolor(5);
circle(t2[i].x,t2[i].y,25);
setfillstyle(1,5);
bar3d(t2[i].x+10,t2[i].y+10,t2[i].x-10,t2[i].y-10,0,0);   // body
fillellipse(t2[i].x,t2[i].y-14,6,6);                      // head
bar3d(t2[i].x-7,t2[i].y,t2[i].x-2,t2[i].y+20,0,0);        // 1st leg
bar3d(t2[i].x+2,t2[i].y,t2[i].x+7,t2[i].y+20,0,0);        // 2nd leg
bar3d(t2[i].x,t2[i].y-7,t2[i].x-20,t2[i].y-10,0,0);       // 1st hand
bar3d(t2[i].x+20,t2[i].y-7,t2[i].x,t2[i].y-10,0,0);       // 2nd hand
}
else
{setcolor(5);
setfillstyle(1,5);
bar3d(t2[i].x+10,t2[i].y+10,t2[i].x-10,t2[i].y-10,0,0);   // body
fillellipse(t2[i].x,t2[i].y-14,6,6);                      // head
bar3d(t2[i].x-7,t2[i].y,t2[i].x-2,t2[i].y+20,0,0);        // 1st leg
bar3d(t2[i].x+2,t2[i].y,t2[i].x+7,t2[i].y+20,0,0);        // 2nd leg
bar3d(t2[i].x,t2[i].y-7,t2[i].x-20,t2[i].y-10,0,0);       // 1st hand
bar3d(t2[i].x+20,t2[i].y-7,t2[i].x,t2[i].y-10,0,0);       // 2nd hand
}



setcolor(12);


settextstyle(7,0,8);
setfillstyle(0,0);
bar3d(x+180,125,x-140,0,0,0);
bar3d(x+220,getmaxy(),x-200,getmaxy()-100,0,0);
outtextxy((getmaxx()/2)-120,0,"paused");
settextstyle(7,0,2);
outtextxy(x-170,getmaxy()-100,"press \"r\" to resume");
outtextxy(x-170,getmaxy()-75,"press \"m\" to goto main menu");
outtextxy(x-170,getmaxy()-50,"press \"q\" to quit out of game");
outtextxy(x-170,getmaxy()-25,"press enter to access control menu");
settextstyle(7,0,8);
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

cleardevice();
setfillstyle(0,0);
setcolor(12);
bar3d(2*x-1,2*y-11,1,11,0,0);             // border
line(1,y,2*x-1,y);                        // center line
circle(x,y,80);                           // center circle
bar3d(x+60,11,x-60,1,0,0);                // top goal
bar3d(x+120,50,x-120,11,0,0);             // top d box
sector(x,50,180,360,45,30);               // top semicircle
bar3d(x+60,2*y-1,x-60,2*y-11,0,0);        // bottom goal
bar3d(x+120,2*y-11,x-120,2*y-50,0,0);     // bottom d box
sector(x,2*y-50,0,180,45,30);	          // bottom semicircle
setcolor(3);
setfillstyle(1,3);
fillellipse(a,b,6,6);		   // football

for(i=0;i<3;i++)                                          // 1st team
if(t1[i].c==1&&t1[i].b!=1)
{
setcolor(12);
circle(t1[i].x,t1[i].y,25);
setfillstyle(1,12);
bar3d(t1[i].x+10,t1[i].y+10,t1[i].x-10,t1[i].y-10,0,0);   // body
fillellipse(t1[i].x,t1[i].y-14,6,6);                      // head
bar3d(t1[i].x-7,t1[i].y,t1[i].x-2,t1[i].y+20,0,0);        // 1st leg
bar3d(t1[i].x+2,t1[i].y,t1[i].x+7,t1[i].y+20,0,0);        // 2nd leg
bar3d(t1[i].x,t1[i].y-7,t1[i].x-20,t1[i].y-10,0,0);       // 1st hand
bar3d(t1[i].x+20,t1[i].y-7,t1[i].x,t1[i].y-10,0,0);       // 2nd hand
}
else
{setcolor(12);
setfillstyle(1,12);
bar3d(t1[i].x+10,t1[i].y+10,t1[i].x-10,t1[i].y-10,0,0);   // body
fillellipse(t1[i].x,t1[i].y-14,6,6);                      // head
bar3d(t1[i].x-7,t1[i].y,t1[i].x-2,t1[i].y+20,0,0);        // 1st leg
bar3d(t1[i].x+2,t1[i].y,t1[i].x+7,t1[i].y+20,0,0);        // 2nd leg
bar3d(t1[i].x,t1[i].y-7,t1[i].x-20,t1[i].y-10,0,0);       // 1st hand
bar3d(t1[i].x+20,t1[i].y-7,t1[i].x,t1[i].y-10,0,0);       // 2nd hand
}
for(i=0;i<3;i++)                                          // second team
if(t2[i].c==1&&t2[i].b!=1)
{
setcolor(5);
circle(t2[i].x,t2[i].y,25);
setfillstyle(1,5);
bar3d(t2[i].x+10,t2[i].y+10,t2[i].x-10,t2[i].y-10,0,0);   // body
fillellipse(t2[i].x,t2[i].y-14,6,6);                      // head
bar3d(t2[i].x-7,t2[i].y,t2[i].x-2,t2[i].y+20,0,0);        // 1st leg
bar3d(t2[i].x+2,t2[i].y,t2[i].x+7,t2[i].y+20,0,0);        // 2nd leg
bar3d(t2[i].x,t2[i].y-7,t2[i].x-20,t2[i].y-10,0,0);       // 1st hand
bar3d(t2[i].x+20,t2[i].y-7,t2[i].x,t2[i].y-10,0,0);       // 2nd hand
}
else
{setcolor(5);
setfillstyle(1,5);
bar3d(t2[i].x+10,t2[i].y+10,t2[i].x-10,t2[i].y-10,0,0);   // body
fillellipse(t2[i].x,t2[i].y-14,6,6);                      // head
bar3d(t2[i].x-7,t2[i].y,t2[i].x-2,t2[i].y+20,0,0);        // 1st leg
bar3d(t2[i].x+2,t2[i].y,t2[i].x+7,t2[i].y+20,0,0);        // 2nd leg
bar3d(t2[i].x,t2[i].y-7,t2[i].x-20,t2[i].y-10,0,0);       // 1st hand
bar3d(t2[i].x+20,t2[i].y-7,t2[i].x,t2[i].y-10,0,0);       // 2nd hand
}


setcolor(12);



settextstyle(7,0,8);
setfillstyle(0,0);
bar3d(x+180,125,x-140,0,0,0);
bar3d(x+220,getmaxy(),x-200,getmaxy()-100,0,0);
outtextxy((getmaxx()/2)-120,0,"paused");
settextstyle(7,0,2);
outtextxy(x-170,getmaxy()-100,"press \"r\" to resume");
outtextxy(x-170,getmaxy()-75,"press \"m\" to goto main menu");
outtextxy(x-170,getmaxy()-50,"press \"q\" to quit out of game");
outtextxy(x-170,getmaxy()-25,"press enter to access control menu");
settextstyle(7,0,8);
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

}while(z!='r'&&z!='m'&&z!='q');
}




}  // kbhit() block  ends


} // game for block ends




}
else
goto top;


closegraph();
}