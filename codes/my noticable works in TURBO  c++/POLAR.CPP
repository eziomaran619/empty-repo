#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>

void main()
{
int gdriver = DETECT, gmode;
initgraph(&gdriver, &gmode,"C:\\turboc3\\bgi");

// x maximum=639  y maximum=479

int x=getmaxx()/2,y=getmaxy()/2;

float a,b,c,d,e,f,g,h,r,q,i;

char ch;

// x=319        y=239

do{

clrscr();
cleardevice();

cout<<"\n\n\t\t\tmath functions in polar form :";
cout<<"\n\n\n\t\t\t\texplanation\n\t\t\t\t===========";
cout<<"\n\n(1)\"q\" is the angle between a ray originating from \"o\" and the horizontal";
cout<<"\n\n(2)\"r\" is the length of that ray and \"r\"is a function of \"q\"";
cout<<"\n\n(3)the locus of head of all such rays possible is the required curve";

cout<<"\n\npress any key to continue";
getch();

clrscr();
cleardevice();

cout<<"\n\n(1)the math function is of the form r=(a+bsinq)(c+dcosq)+(e+fsinq)(g+hcosq)";
cout<<"\n\n(2)where a,b,c,d,e,f,g,h are constants and q and r are angle and radius ";
cout<<"\n   respectively";
cout<<"\n\n(3)give values such that the max value of \"r\" does not exceed 200 ";
cout<<"\n   and is not below 50 or else the curve won't be visible properly";
cout<<"\n\n(4)for example give 100,0,1,1,0,0,0,0 to see a cordioid";

cout<<"\n\nenter the value of a ==> ";
cin>>a;
cout<<"\nenter the value of b ==> ";
cin>>b;
cout<<"\nenter the value of c ==> ";
cin>>c;
cout<<"\nenter the value of d ==> ";
cin>>d;
cout<<"\nenter the value of e ==> ";
cin>>e;
cout<<"\nenter the value of f ==> ";
cin>>f;
cout<<"\nenter the value of g ==> ";
cin>>g;
cout<<"\nenter the value of h ==> ";
cin>>h;

cout<<"\npress any key to draw the function";
getch();

clrscr();
cleardevice();

setcolor(12);
setfillstyle(1,12);
settextstyle(2,0,6);

line(0,y,2*x,y);  // horizontal line
circle(x,y,1);    // the origin point
circle(x+9,y,5);  // the origin's name "o"


for(q=0;q<=6.28;q+=0.02)
{
delay(50);

cleardevice();

outtextxy(5,20," \"o\" is the point form where ray used to measure angle originates");

line(0,y,2*x,y);  // horizontal line
circle(x,y,1);    // the origin point
circle(x+9,y,5);  // the origin's name "o"

r=(a+b*sin(q))*(c+d*cos(q))+(e+f*sin(q))*(g+h*cos(q));
line(x,y,r*cos(q)+x,y-r*sin(q));
circle(r*cos(q)+x,y-r*sin(q),5);
circle(r*cos(q)+x,y-r*sin(q),1);

for(i=0;i<q;i+=0.02)
{
r=(a+b*sin(i))*(c+d*cos(i))+(e+f*sin(i))*(g+h*cos(i));
circle(r*cos(i)+x,y-r*sin(i),1);
}

}

cout<<"\n\n\n\n   do u want to continue with another set of values (y/other keys) ==> ";
cin>>ch;

}while(ch=='y'||ch=='Y');

closegraph() ;

}

