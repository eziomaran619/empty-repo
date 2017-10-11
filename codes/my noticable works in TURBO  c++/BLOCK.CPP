
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

void main()
{
int gdriver = DETECT, gmode;
initgraph(&gdriver, &gmode,"C:\\turboc3\\bgi");

// x maximum=639  y maximum=479

int x=getmaxx()/2,y=getmaxy()/2;

// x=319        y=239

char key;

//		  	 <=                o
//   <==>  =><=   ||     =>      ___      o o    .    o    *   <<<
// (large,short,bullet,reverse,shield)  (multi,small,big,fire,speed)
//    x     x     x       x       x        x     x    x   x     x

int z,j,gx,gd,i,reverse=0,bullet=0,shield=0,speed=0,small[3],blockcount=50,level=1;
int bulletcount=-1,reversecount=0,speedcount=0,shieldcount=0,smallcount[3];
int fire[3],resume=0;
// fast => speed=2   z is randomizer
// gx is left x co ordinate of gun  gd is length of gun
// if fire balltype=-5 , for the purpose of printing
// j is bullet time   k is fireball time

int mf,qf;
char mc,qc;

struct control
{
char a,d,w,j,k,l,i;
}c;

c.w='w';
c.a='a';
c.d='d';
c.l='l';
c.k='k';
c.j='j';
c.i='i';

struct player
{
int x,y,l,el;   // extra length = 5(long) & -5(short)
}p;

struct ball
{                   // c=control  a=angle
int x,y,r,c,q,er;     // quadrant     extra radius  = 2(big) & -2(small)
double a;
}b[3];


struct gun
{               // bullets start from y=430 and decrese till 30 at a rate of 40 units per tick
int x,y,d,el,er;        // there will be 10 such pair of bullets
}bullets[10];    // d is distance between 2  bullets

//line(2*x-14,2*y-5,14,2*y-5);  shield line


	// from 20 to 620 (600)units available in x axis for blocks
	// from 20 to 320 (300)units available in y axis for blocks
	// max block size is 60x60 square


struct bricks
{                          //  ice(makes fire ball normal)
int x,y,b,l,spike,e,powere;//  spike(common to all , makes the ball smaller)
int color,p,powery;        //  metal block only destroyable by fire ball
char type[10],power[15];
double crack;              //  thick block (easily breakable by speed ball or big ball or 4 shots with normal ball or fast small ball)
}block[5][10];             //  normal(light red)

// p is pattern  powere is existance of power powery is coordinate of moving power

// if spike is 1 bottom if -1 top


// (4) metal    (8) ice    (12)  thick   (rest all) normal



// (1) longpad        (9) reverse       (17) multiple balls
// (3) smallpad       (11) bigball      (19) speedball
// (5) bullets        (13) smallball    (even) normal
// (7) shield         (15) fire ball



#define   printb()    cleardevice();\
		      setcolor(6);\
		      setfillstyle(1,6);\
		      bar3d(8,6,14,2*y-5,0,0);\
		      bar3d(8,6,2*x-8,10,0,0);\
		      bar3d(2*x-14,10,2*x-8,2*y-5,0,0);\
		      bar3d(p.x-(p.l/2),p.y+4,p.x+(p.l/2),p.y-4,0,0);


#define     pause()     cleardevice();\
			settextstyle(7,0,8);\
			setfillstyle(0,0);\
			setcolor(12);\
			bar3d(x+180,125,x-140,0,0,0);\
			bar3d(x+220,getmaxy(),x-200,getmaxy()-100,0,0);\
			outtextxy((getmaxx()/2)-120,0,"paused");\
			settextstyle(7,0,3);\
			outtextxy(x-170,getmaxy()-90,"press \"r\" to resume");\
			outtextxy(x-170,getmaxy()-60,"press \"m\" to goto main menu");\
			outtextxy(x-170,getmaxy()-30,"press \"q\" to quit out of game");\
			settextstyle(7,0,8);





cleardevice();
settextstyle(4,0,6);
setcolor(2);
outtextxy(x-250,0,"Instructions  1");
setcolor(12);
settextstyle(7,0,3);
outtextxy(x-300,60,"(1)use \"d\",\"a\"to move pad");
outtextxy(x-300,105,"(2)use \"w\" to launch the ball");
outtextxy(x-300,150,"(3)use \"l\",\"j\" to move the gun to desired side");
outtextxy(x-300,195,"(4)use \"k\",\"i\" to decrease and increase the");
outtextxy(x-300,240,"seperation of gun respectively");
outtextxy(x-300,285,"(5)single bullet is capable of breaking only ice block");
outtextxy(x-300,330,"(6)double bullet is capable of breaking normal block");
outtextxy(x-300,375,"in 1 strike and thick block in 50 strikes.it is ");
outtextxy(x-300,420,"incapable of breaking a metal block");

getch();

cleardevice();
settextstyle(4,0,6);
setcolor(2);
outtextxy(x-250,0,"Instructions  2");
setcolor(12);
settextstyle(7,0,3);
outtextxy(x-300,60,"(7)exept slow small ball all other can crack thick ");
outtextxy(x-300,105,"block and break it in 3 cracks");
outtextxy(x-300,150,"(8)normal block and ice are the easily breakable ones");
outtextxy(x-300,195,"exept that ice block can change fire ball to normall ball");
outtextxy(x-300,240,"(9)spikes block deflates the ball");
outtextxy(x-300,285,"(10)only fire ball can melt metal block no other can");
outtextxy(x-300,330,"(11)all negative powers and some important powers have");
outtextxy(x-300,375,"time limit");

getch();




blocktop:

bulletcount=-1;reversecount=0;speedcount=0;shieldcount=0;
reverse=0;bullet=0;shield=0;speed=0;blockcount=50;resume=0;


fire[0]=0;
fire[1]=0;
fire[2]=0;

small[0]=0;
small[1]=0;
small[2]=0;

smallcount[0]=0;
smallcount[1]=0;
smallcount[2]=0;



randomize();

for(i=0;i<5;i++)
for(j=0;j<10;j++)
{

block[i][j].x=20+j*60;

block[i][j].b=random(11)+30;
block[i][j].l=random(11)+40;
block[i][j].y=random(61-block[i][j].b)+20+60*i;


z=random(20)+1;
if(z==1)
strcpy(block[i][j].power,"longpad");
else
if(z==3)
strcpy(block[i][j].power,"smallpad");
else
if(z==5||z==6)
strcpy(block[i][j].power,"bullets");
else
if(z==7)
strcpy(block[i][j].power,"shield");
else
if(z==9)
strcpy(block[i][j].power,"reverse");
else
if(z==11||z==12)
strcpy(block[i][j].power,"bigball");
else
if(z==13)
strcpy(block[i][j].power,"smallball");
else
if(z==15||z==16||z==14)
strcpy(block[i][j].power,"fireball");
else
if(z==17)
strcpy(block[i][j].power,"multipleballs");
else
if(z==19)
strcpy(block[i][j].power,"speedball");
else
strcpy(block[i][j].power,"nothing");

z=random(41);
if(z==10||z==30)
block[i][j].spike=-1;
else
if(z==20||z==40)
block[i][j].spike=1;


z=random(6)+1;
if(z==2)
{strcpy(block[i][j].type,"metal");
block[i][j].color=8;
block[i][j].p=4;}
else
if(z==4)
{strcpy(block[i][j].type,"ice");
block[i][j].color=15;
block[i][j].p=10;}
else
if(z==6)
{strcpy(block[i][j].type,"thick");
block[i][j].color=12;
block[i][j].p=1;}
else
{strcpy(block[i][j].type,"normal");
block[i][j].color=12;
block[i][j].p=10;}


block[i][j].e=1;
block[i][j].crack=0;
block[i][j].powere=0;
block[i][j].powery=-100;



// all blocks have crack=0 but only for thick blocks crack increases


}




for(i=0;i<10;i++)
{bullets[i].y=470;
bullets[i].er=1;
bullets[i].el=1;}



p.el=0;
p.x=x;               // pad center at x=320      thickness 8 units
p.y=2*y-12;          // pad jumps by 20 units
p.l=80+8*p.el;       // ball deflects in 4 angles 30,40,60,72


b[0].er=0;
b[0].c=1;
b[0].r=6+b[0].er;
b[0].x=p.x;          // ball is at x=320
b[0].y=p.y-9;
b[1].c=0;
b[2].c=0;



printb();
setcolor(9);
setfillstyle(1,9);
fillellipse(b[0].x,b[0].y,b[0].r,b[0].r); //ball


int d=-1;

for(;;)
{

printb();


for(i=0;i<5;i++)
for(j=0;j<10;j++)
if(block[i][j].e==1)
{

setcolor(block[i][j].color);
setfillstyle(block[i][j].p,block[i][j].color);
bar3d(block[i][j].x,block[i][j].y,block[i][j].x+block[i][j].l,block[i][j].y+block[i][j].b,0,0);

setfillstyle(1,block[i][j].color);

if(block[i][j].spike==1)        //  down spike
for(z=block[i][j].x+4;z<=block[i][j].x+block[i][j].l-2;z+=10)
line(z,block[i][j].y+block[i][j].b,z,block[i][j].y+block[i][j].b+3);
else
if(block[i][j].spike==-1)        //  up spike
for(z=block[i][j].x+4;z<=block[i][j].x+block[i][j].l-2;z+=10)
line(z,block[i][j].y,z,block[i][j].y-3);

}





setcolor(9);
setfillstyle(1,9);
fillellipse(b[0].x,b[0].y,b[0].r,b[0].r); //ball


delay(30);

if(d==-1&&b[0].x==p.x-(p.l/2))
d=1;
else
if(d==1&&b[0].x==p.x+(p.l/2))
d=-1;
else
if(d==-1&&b[0].x>=p.x-(p.l/2))
b[0].x-=1;
else
if(d==1&&b[0].x<=p.x+(p.l/2))
b[0].x+=1;

if(kbhit())     // kbhit block
{

key=getch();

if(key==c.w)
break;

if(key==c.a&&p.x-(p.l/2)>19)
{p.x-=20;
b[0].x-=20;
}
else
if(key==c.d&&p.x+(p.l/2)<2*x-19)
{p.x+=20;
b[0].x+=20;
}



} // kbhit block

}





for(;;)                 // game block

{

if(b[0].c==0&&b[1].c==0&&b[2].c==0)
{
break;
}

if(blockcount==0)
{cleardevice();
setcolor(12);
settextstyle(3,0,6);
outtextxy(x-150,y-50,"level cleared");
level++;
delay(5000);
goto blocktop;
}

printb();



for(i=0;i<5;i++)        // brick for block starts
for(j=0;j<10;j++)
{

if(block[i][j].e==1)    // brick existance block starts
{
setcolor(block[i][j].color);
setfillstyle(block[i][j].p,block[i][j].color);
bar3d(block[i][j].x,block[i][j].y,block[i][j].x+block[i][j].l,block[i][j].y+block[i][j].b,0,0);

setfillstyle(1,block[i][j].color);

if(block[i][j].spike==1)        //  down spike
for(z=block[i][j].x+4;z<=block[i][j].x+block[i][j].l-2;z+=10)
line(z,block[i][j].y+block[i][j].b,z,block[i][j].y+block[i][j].b+3);
else
if(block[i][j].spike==-1)        //  up spike
for(z=block[i][j].x+4;z<=block[i][j].x+block[i][j].l-2;z+=10)
line(z,block[i][j].y,z,block[i][j].y-3);



if(strcmpi(block[i][j].type,"thick")==0)
{setcolor(0);
if(block[i][j].crack==1)
{line(block[i][j].x,block[i][j].y,block[i][j].x+16,block[i][j].y+8);
line(block[i][j].x+8,block[i][j].y+4,block[i][j].x+20,block[i][j].y+5);
}
else
if(block[i][j].crack==2)
{
line(block[i][j].x,block[i][j].y,block[i][j].x+16,block[i][j].y+8);
line(block[i][j].x+8,block[i][j].y+4,block[i][j].x+20,block[i][j].y+5);
line(block[i][j].x+22,block[i][j].y+11,block[i][j].x+28,block[i][j].y+17);
line(block[i][j].x+25,block[i][j].y+9,block[i][j].x+19,block[i][j].y+14);
}
if(block[i][j].crack>=3)
{line(block[i][j].x,block[i][j].y,block[i][j].x+16,block[i][j].y+8);
line(block[i][j].x+8,block[i][j].y+4,block[i][j].x+20,block[i][j].y+5);
line(block[i][j].x+22,block[i][j].y+11,block[i][j].x+28,block[i][j].y+17);
line(block[i][j].x+25,block[i][j].y+9,block[i][j].x+19,block[i][j].y+14);
line(block[i][j].x+block[i][j].l,block[i][j].y+block[i][j].b,block[i][j].x+block[i][j].l-12,block[i][j].y+block[i][j].b-6);
line(block[i][j].x+block[i][j].l-4,block[i][j].y+block[i][j].b-2,block[i][j].x+block[i][j].l-7,block[i][j].y+block[i][j].b-7);
}


}


}    // brick existance block ends


setcolor(3);
settextstyle(1,0,1);


if(block[i][j].powere==1)  // power existance modifier starts
{

if(strcmpi(block[i][j].power,"longpad")==0)
{
outtextxy(block[i][j].x+(block[i][j].l/2),block[i][j].powery,"\"<==>\"");
block[i][j].powery+=3;
}
else
if(strcmpi(block[i][j].power,"smallpad")==0)
{
outtextxy(block[i][j].x+(block[i][j].l/2),block[i][j].powery,"\"=><=\"");
block[i][j].powery+=3;
}
else
if(strcmpi(block[i][j].power,"bullets")==0)
{
outtextxy(block[i][j].x+(block[i][j].l/2),block[i][j].powery,"\" : : \"");
block[i][j].powery+=3;
}
else
if(strcmpi(block[i][j].power,"shield")==0)
{
outtextxy(block[i][j].x+(block[i][j].l/2),block[i][j].powery,"\"___\"");
block[i][j].powery+=3;
}
else
if(strcmpi(block[i][j].power,"reverse")==0)
{
outtextxy(block[i][j].x+(block[i][j].l/2),block[i][j].powery-10,"\"=>\"");
outtextxy(block[i][j].x+(block[i][j].l/2),block[i][j].powery,"<=");
block[i][j].powery+=3;
}
else
if(strcmpi(block[i][j].power,"bigball")==0)
{
outtextxy(block[i][j].x+(block[i][j].l/2),block[i][j].powery,"\" o \"");
block[i][j].powery+=3;
}
else
if(strcmpi(block[i][j].power,"smallball")==0)
{
outtextxy(block[i][j].x+(block[i][j].l/2),block[i][j].powery,"\" . \"");
block[i][j].powery+=3;
}
else
if(strcmpi(block[i][j].power,"fireball")==0)
{
outtextxy(block[i][j].x+(block[i][j].l/2),block[i][j].powery,"\" * \"");
block[i][j].powery+=3;
}
else
if(strcmpi(block[i][j].power,"multipleballs")==0)
{
outtextxy(block[i][j].x+(block[i][j].l/2),block[i][j].powery-10,"\" o\"");
outtextxy(block[i][j].x+(block[i][j].l/2),block[i][j].powery,"o o");
block[i][j].powery+=3;
}
else
if(strcmpi(block[i][j].power,"speedball")==0)
{
outtextxy(block[i][j].x+(block[i][j].l/2),block[i][j].powery,"\"<<<\"");
block[i][j].powery+=3;
}


}  // power existance modifier ends



if(block[i][j].powere==1)
if(block[i][j].powery>=p.y+4&&((block[i][j].x+block[i][j].l/2+30>p.x-p.l/2&&block[i][j].x+block[i][j].l/2+30<p.x+p.l/2)||(block[i][j].x+block[i][j].l/2+10<p.x+p.l/2&&block[i][j].x+block[i][j].l/2+10>p.x-p.l/2)))
{

block[i][j].powere=0;

if(strcmpi(block[i][j].power,"multipleballs")==0)   // multipleballs
{
if(b[0].c==1&&b[1].c==0&&b[2].c==0)
{
b[1].x=b[0].x+1;
b[2].x=b[0].x-1;
b[1].y=b[0].y-1;
b[2].y=b[0].y+1;
b[1].c=b[2].c=1;
b[1].r=b[2].r=b[0].r;
b[1].er=b[2].er=b[0].er;
b[1].q=2;
b[2].q=1;
b[1].a=-22.0/7+22.0/(7*3.6);
b[2].a=-22.0/(7*4.3);
fire[1]=fire[2]=fire[0];
small[1]=small[2]=small[0];
smallcount[1]=smallcount[2]=smallcount[0];
}
else
if(b[0].c==0&&b[1].c==1&&b[2].c==0)
{
b[0].x=b[1].x+1;
b[2].x=b[1].x-1;
b[0].y=b[1].y-1;
b[2].y=b[1].y+1;
b[0].c=b[2].c=1;
b[0].r=b[2].r=b[1].r;
b[0].er=b[2].er=b[1].er;
b[0].q=2;
b[2].q=1;
b[0].a=-22.0/7+22.0/(7*3.6);
b[2].a=-22.0/(7*4.3);
fire[0]=fire[2]=fire[1];
small[0]=small[2]=small[1];
smallcount[0]=smallcount[2]=smallcount[1];
}
else
if(b[0].c==0&&b[1].c==0&&b[2].c==1)
{
b[1].x=b[2].x+1;
b[0].x=b[2].x-1;
b[1].y=b[2].y-1;
b[0].y=b[2].y+1;
b[1].c=b[0].c=1;
b[1].r=b[0].r=b[2].r;
b[1].er=b[0].er=b[2].er;
b[1].q=2;
b[0].q=1;
b[1].a=-22.0/7+22.0/(7*3.6);
b[0].a=-22.0/(7*4.3);
fire[1]=fire[0]=fire[2];
small[1]=small[0]=small[2];
smallcount[1]=smallcount[0]=smallcount[2];
}

}

else
if(strcmpi(block[i][j].power,"bigball")==0)       // bigball
{
for(z=0;z<=2;z++)
if(b[z].r!=8)
{b[z].er=2;
b[z].r+=b[z].er;}
}
else
if(strcmpi(block[i][j].power,"smallpad")==0&&p.l!=40)    // smallpad
{
p.el=-5;
p.l+=8*p.el;
if(bullet==1)
{

if(gx<p.x-p.l/2+8)
{

if(gd>p.l-16)
{gd=p.l-8;
gx=p.x-p.l/2+8;}
else
{gx=p.x-p.l/2+8;}

}

if((gx+gd)>p.x+(p.l/2)-8)

{

if(gd<=p.l-16)
{gx=p.x+(p.l/2)-8-gd;}
else
{gd=p.l-16;
gx=p.x+(p.l/2)-8-gd;}

}

}

}
else
if(strcmpi(block[i][j].power,"longpad")==0&&p.l!=120)    // longpad
{p.el=5;
p.l+=8*p.el;}
else
if(strcmpi(block[i][j].power,"shield")==0)    // shield
{shield=1;
shieldcount=0;}
else
if(strcmpi(block[i][j].power,"smallball")==0)   // smallball
{
for(z=0;z<=2;z++)
if(b[z].r!=4)
{b[z].er=-2;
b[z].r+=b[z].er;}
if(b[0].r==4)
{smallcount[0]=0;
smallcount[1]=0;
smallcount[2]=0;
small[0]=1;
small[1]=1;
small[2]=1;}
}
else
if(strcmpi(block[i][j].power,"reverse")==0)     // reverse
{reverse=1;
reversecount=0;}
else
if(strcmpi(block[i][j].power,"fireball")==0)     // fireball
{fire[0]=-5;fire[1]=-5;fire[2]=-5;}
else
if(strcmpi(block[i][j].power,"bullets")==0)    // bullets
{
if(bullet!=1)
{bulletcount=0;
bullet=1;
gx=p.x-(p.l/2)+8;
gd=p.l-16;}
else
if(bullet==1)
{bulletcount=0;
for(z=0;z<10;z++)
{bullets[z].y=470;
bullets[z].el=1;
bullets[z].er=1;}
}

}
else
if(strcmpi(block[i][j].power,"speedball")==0)    // speedball
{speed=3;
speedcount=0;}

}



if(block[i][j].powery>=2*y)
block[i][j].powere=0;




if(bullet==1&&block[i][j].e==1)
for(z=0;z<10;z++)
{

if(strcmpi(block[i][j].type,"ice")==0)    // ice block start
{

// left bullet
if(bullets[z].el==1&&bullets[z].x>=block[i][j].x&&bullets[z].x<=block[i][j].x+block[i][j].l&&bullets[z].y+5>block[i][j].y&&bullets[z].y-5<block[i][j].y+block[i][j].b)
{if(strcmpi(block[i][j].power,"nothing")!=0)
block[i][j].powere=1;
else
block[i][j].powere=0;

bullets[z].el=0;
block[i][j].e=0;
block[i][j].powery=block[i][j].y+block[i][j].b/2;
blockcount--;
break;
}
else       // right bullet
if(bullets[z].er==1&&bullets[z].x+bullets[z].d>=block[i][j].x&&bullets[z].x+bullets[z].d<=block[i][j].x+block[i][j].l&&bullets[z].y+5>block[i][j].y&&bullets[z].y-5<block[i][j].y+block[i][j].b)
{if(strcmpi(block[i][j].power,"nothing")!=0)
block[i][j].powere=1;
else
block[i][j].powere=0;

bullets[z].er=0;
block[i][j].e=0;
block[i][j].powery=block[i][j].y+block[i][j].b/2;
blockcount--;
break;
}



}   // ice block end

else

if(strcmpi(block[i][j].type,"metal")==0)    // metal block start
{

// both right and left bullet
if(bullets[z].el==1&&bullets[z].x>block[i][j].x&&bullets[z].x<block[i][j].x+block[i][j].l&&bullets[z].y-5<block[i][j].y+block[i][j].b)
if(bullets[z].er==1&&bullets[z].x+bullets[z].d>block[i][j].x&&bullets[z].x+bullets[z].d<block[i][j].x+block[i][j].l&&bullets[z].y-5<block[i][j].y+block[i][j].b)
{bullets[z].el=0;
bullets[z].er=0;}
else       // only left bullet
{bullets[z].el=0;}
else       // only right bullet
if(bullets[z].er==1&&bullets[z].x+bullets[z].d>block[i][j].x&&bullets[z].x+bullets[z].d<block[i][j].x+block[i][j].l&&bullets[z].y-5<block[i][j].y+block[i][j].b)
{bullets[z].er=0;}

}   // metal block end

else

if(strcmpi(block[i][j].type,"thick")==0)    // thick block start
{

// both right and left bullet
// both the bullet cracking the block
if(bullets[z].el==1&&bullets[z].x>=block[i][j].x&&bullets[z].x<=block[i][j].x+block[i][j].l&&bullets[z].y-5<block[i][j].y+block[i][j].b)
if(bullets[z].y+5>block[i][j].y)
if(bullets[z].er==1&&bullets[z].x+bullets[z].d>=block[i][j].x&&bullets[z].x+bullets[z].d<=block[i][j].x+block[i][j].l&&bullets[z].y+5>block[i][j].y&&bullets[z].y-5<block[i][j].y+block[i][j].b)
{
if(block[i][j].crack<50)
{block[i][j].crack++;
bullets[z].el=0;
bullets[z].er=0;}
else       // both bullet at the final stage of breaking the block
if(block[i][j].crack==50)
{
if(strcmpi(block[i][j].power,"nothing")!=0)
block[i][j].powere=1;
else
block[i][j].powere=0;

bullets[z].el=0;
bullets[z].er=0;
block[i][j].e=0;
block[i][j].powery=block[i][j].y+block[i][j].b/2;
blockcount--;
break;
}
}
else
{bullets[z].el=0;}
else       // only left bullet
{bullets[z].el=0;}
else       // only right bullet
if(bullets[z].er==1&&bullets[z].x+bullets[z].d>block[i][j].x&&bullets[z].x+bullets[z].d<block[i][j].x+block[i][j].l&&bullets[z].y-5<block[i][j].y+block[i][j].b)
{bullets[z].er=0;}


}   // thick block end


else

if(strcmpi(block[i][j].type,"normal")==0)    //normal block start
{

// both right and left bull
if(bullets[z].el==1&&bullets[z].x>=block[i][j].x&&bullets[z].x<=block[i][j].x+block[i][j].l&&bullets[z].y-5<block[i][j].y+block[i][j].b)
if(bullets[z].y+5>block[i][j].y)
if(bullets[z].er==1&&bullets[z].x+bullets[z].d>=block[i][j].x&&bullets[z].x+bullets[z].d<=block[i][j].x+block[i][j].l&&bullets[z].y+5>block[i][j].y&&bullets[z].y-5<block[i][j].y+block[i][j].b)
{
if(strcmpi(block[i][j].power,"nothing")!=0)
block[i][j].powere=1;
else
block[i][j].powere=0;

bullets[z].el=0;
bullets[z].er=0;
block[i][j].e=0;
block[i][j].powery=block[i][j].y+block[i][j].b/2;
blockcount--;
break;
}
else
{bullets[z].el=0;}
else       // only left bullet
{bullets[z].el=0;}
else       // only right bullet
if(bullets[z].er==1&&bullets[z].x+bullets[z].d>block[i][j].x&&bullets[z].x+bullets[z].d<block[i][j].x+block[i][j].l&&bullets[z].y-5<block[i][j].y+block[i][j].b)
{bullets[z].er=0;}


}   // normal block end




}  // bullet for block end






}   // brick for block ends


setcolor(6);
setfillstyle(1,6);

if(bullet==1)
{fillellipse(gx,p.y-5,2,5);
fillellipse(gx+gd,p.y-5,2,5);
bulletcount++;}




if(bulletcount==250)
{
for(i=0;i<10;i++)
{bullets[i].y=470;}


bulletcount=-1;
bullet=0;
}






setcolor(14);
setfillstyle(1,14);

if(bulletcount>=1)
{
if(bulletcount<=10)
for(i=0;i<bulletcount;i++)
{
bullets[i].y-=40;

if(bullets[i].y==430)
{bullets[i].x=gx;
bullets[i].d=gd;}

if(bullets[i].el==1)
{fillellipse(bullets[i].x,bullets[i].y,2,5);}
if(bullets[i].er==1)
{fillellipse(bullets[i].x+bullets[i].d,bullets[i].y,2,5);}
}
else
for(i=0;i<10;i++)
{                                            // shooting bullets
if(bullets[i].y==30)
{bullets[i].y=430;
bullets[i].x=gx;
bullets[i].d=gd;
bullets[i].el=1;
bullets[i].er=1;}
else
bullets[i].y-=40;

if(bullets[i].el==1)
{fillellipse(bullets[i].x,bullets[i].y,2,5);}
if(bullets[i].er==1)
{fillellipse(bullets[i].x+bullets[i].d,bullets[i].y,2,5);}


}

}








if(shieldcount==1500)
{shield=0;}
else
if(shield==1)
{setcolor(10);
line(2*x-14,2*y-5,14,2*y-5);
shieldcount++;}



if(speedcount==1000)
speed=0;
else
if(speed==5)
speedcount++;



for(i=0;i<=2;i++)
if(smallcount[i]==1000)
{if(b[i].er==-2)
{b[i].er=0;
b[i].r+=2;}
small[i]=0;
smallcount[i]=0;
}
else
if(small[i]==1)
smallcount[i]++;



if(reversecount==1000)
reverse=0;
else
if(reverse==1)
reversecount++;



for(i=0;i<=2;i++)
if(b[i].c==1)
{


if(b[i].y+b[i].r>=2*y-5)
{
if(shield==1)
{
if(b[i].q==3)
{
b[i].a=-b[i].a;
b[i].q=2;
}
else
if(b[i].q==4)
{
b[i].a=-b[i].a;
b[i].q=1;
}
shield=0;   // ball has struc the shield so '0'
}
else
{
b[i].c=0;
}

}

// ball deflection starts

if(b[i].x-b[i].r<=14&&b[i].q==2)
{
b[i].a=-((22.0/7)+b[i].a);
b[i].q=1;
}
else
if(b[i].x+b[i].r>=2*x-10&&b[i].q==1)
{
b[i].a=-((22.0/7)+b[i].a);
b[i].q=2;
}
else
if(b[i].x-b[i].r<=14&&b[i].q==3)
{
b[i].a=22.0/7-b[i].a;
b[i].q=4;
}
else
if(b[i].x+b[i].r>=2*x-10&&b[i].q==4)
{
b[i].a=22.0/7-b[i].a;
b[i].q=3;
}
else
if(b[i].y-b[i].r<=10&&b[i].q==1)
{
b[i].a=-b[i].a;                      // 4q=-1q
b[i].q=4;
}
else
if(b[i].y-b[i].r<=10&&b[i].q==2)
{
b[i].a=-b[i].a;                      // 3q=-2q
b[i].q=3;
}


if((b[i].y+b[i].r>=p.y-4)&&(b[i].y+b[i].r<=p.y+4))
{
// as y always decreases there is a -ve sign


if(b[i].x<=p.x&&b[i].x>=p.x-p.l/2)
{
if(b[i].x<=p.x&&b[i].x>=p.x-1*(10+p.el))
b[i].a=-(22.0/7)+(44.0/35); //pi-pi/2.5       72 degrees
else
if(b[i].x<p.x-1*(10+p.el)&&b[i].x>=p.x-2*(10+p.el))
b[i].a=-(22.0/7)+(22.0/21); //pi-pi/3     60 degrees
else
if(b[i].x<p.x-2*(10+p.el)&&b[i].x>=p.x-3*(10+p.el))
b[i].a=-(22.0/7)+(44.0/63);  //pi-pi/4.5    40 degrees
else
if(b[i].x<p.x-3*(10+p.el)&&b[i].x>=p.x-4*(10+p.el))
b[i].a=-(22.0/7)+(11.0/21);  //pi-pi/6    30 degrees

b[i].q=2;
}
else
if(b[i].x>=p.x&&b[i].x<=p.x+p.l/2)
{
if(b[i].x>p.x&&b[i].x<=p.x+1*(10+p.el))
b[i].a=-44.0/35;   //pi/2.5    72 degrees
else
if(b[i].x>p.x+1*(10+p.el)&&b[i].x<=p.x+2*(10+p.el))
b[i].a=-22.0/21;   //pi/3      60 degrees
else
if(b[i].x>p.x+2*(10+p.el)&&b[i].x<=p.x+3*(10+p.el))
b[i].a=-44.0/63;   //pi/4.5     40 degrees
else
if(b[i].x>p.x+3*(10+p.el)&&b[i].x<=p.x+4*(10+p.el))
b[i].a=-11.0/21;    //pi/6      30 degrees

b[i].q=1;
}
else
if(pow(b[i].x-(p.x-(p.l/2)),2)+pow(b[i].y-(p.y-4),2)<=pow(b[i].r,2))
{
b[i].a=-(22.0/7)+(11.0/21);  //pi-pi/6    30 degrees
b[i].q=2;
}
else
if(pow(b[i].x-(p.x+(p.l/2)),2)+pow(b[i].y-(p.y-4),2)<=pow(b[i].r,2))
{
b[i].a=-11.0/21;    //pi/6      30 degrees
b[i].q=1;
}

}
else
if(b[i].y>=2*y)
b[i].c=0;

// ball deflection ends



for(z=0;z<5;z++)
for(j=0;j<10;j++)
if(block[z][j].e==1)
{


if(b[i].x-b[i].r<=(block[z][j].x+block[z][j].l)&&b[i].x-b[i].r>block[z][j].x&&b[i].y<block[z][j].y+block[z][j].b&&b[i].y>block[z][j].y&&b[i].q==2)
{


if(strcmpi(block[z][j].type,"normal")==0)
{
blockcount--;
b[i].a=-((22.0/7)+b[i].a);
b[i].q=1;
block[z][j].e=0;
if(strcmpi(block[z][j].power,"nothing")!=0)
{block[z][j].powere=1;
block[z][j].powery=block[z][j].y+block[z][j].b/2;}
break;
}
else
if(strcmpi(block[z][j].type,"ice")==0)
{
if(fire[i]==-5)
{
b[i].a=-((22.0/7)+b[i].a);
b[i].q=1;
fire[i]=0;
break;
}
else
{
blockcount--;
b[i].a=-((22.0/7)+b[i].a);
b[i].q=1;
block[z][j].e=0;
if(strcmpi(block[z][j].power,"nothing")!=0)
{block[z][j].powere=1;
block[z][j].powery=block[z][j].y+block[z][j].b/2;}
break;
}
}
else
if(strcmpi(block[z][j].type,"metal")==0)
{
if(fire[i]==-5)
{
blockcount--;
b[i].a=-((22.0/7)+b[i].a);
b[i].q=1;
block[z][j].e=0;
if(strcmpi(block[z][j].power,"nothing")!=0)
{block[z][j].powere=1;
block[z][j].powery=block[z][j].y+block[z][j].b/2;}
break;
}
else
{
b[i].a=-((22.0/7)+b[i].a);
b[i].q=1;
break;
}
}
else
if(strcmpi(block[z][j].type,"thick")==0)
{
if((b[i].r==4&&speed==5)||b[i].r==6||b[i].r==8)
if(block[z][j].crack<3)
{
block[z][j].crack++;
b[i].a=-((22.0/7)+b[i].a);
b[i].q=1;
break;
}
else
{
blockcount--;
b[i].a=-((22.0/7)+b[i].a);
b[i].q=1;
block[z][j].e=0;
if(strcmpi(block[z][j].power,"nothing")!=0)
{block[z][j].powere=1;
block[z][j].powery=block[z][j].y+block[z][j].b/2;}
break;
}
else
{
b[i].a=-((22.0/7)+b[i].a);
b[i].q=1;
break;
}
}     // if block of thick



}     // if block of ball





if(b[i].x+b[i].r>=block[z][j].x&&b[i].x+b[i].r<block[z][j].x+block[z][j].l&&b[i].y<block[z][j].y+block[z][j].b&&b[i].y>block[z][j].y&&b[i].q==1)
{



if(strcmpi(block[z][j].type,"normal")==0)
{
blockcount--;
b[i].a=-((22.0/7)+b[i].a);
b[i].q=2;
block[z][j].e=0;
if(strcmpi(block[z][j].power,"nothing")!=0)
{block[z][j].powere=1;
block[z][j].powery=block[z][j].y+block[z][j].b/2;}
break;
}
else
if(strcmpi(block[z][j].type,"ice")==0)
{
if(fire[i]==-5)
{
b[i].a=-((22.0/7)+b[i].a);
b[i].q=2;
fire[i]=0;
break;
}
else
{
blockcount--;
b[i].a=-((22.0/7)+b[i].a);
b[i].q=2;
block[z][j].e=0;
if(strcmpi(block[z][j].power,"nothing")!=0)
{block[z][j].powere=1;
block[z][j].powery=block[z][j].y+block[z][j].b/2;}
break;
}
}
else
if(strcmpi(block[z][j].type,"metal")==0)
{
if(fire[i]==-5)
{
blockcount--;
b[i].a=-((22.0/7)+b[i].a);
b[i].q=2;
block[z][j].e=0;
if(strcmpi(block[z][j].power,"nothing")!=0)
{block[z][j].powere=1;
block[z][j].powery=block[z][j].y+block[z][j].b/2;}
break;
}
else
{
b[i].a=-((22.0/7)+b[i].a);
b[i].q=2;
break;
}
}
else
if(strcmpi(block[z][j].type,"thick")==0)
{
if((b[i].r==4&&speed==5)||b[i].r==6||b[i].r==8)
if(block[z][j].crack<3)
{
block[z][j].crack++;
b[i].a=-((22.0/7)+b[i].a);
b[i].q=2;
break;
}
else
{
blockcount--;
b[i].a=-((22.0/7)+b[i].a);
b[i].q=2;
block[z][j].e=0;
if(strcmpi(block[z][j].power,"nothing")!=0)
{block[z][j].powere=1;
block[z][j].powery=block[z][j].y+block[z][j].b/2;}
break;
}
else
{
b[i].a=-((22.0/7)+b[i].a);
b[i].q=2;
break;
}

}     // if block of thick

}





if(b[i].x-b[i].r<=block[z][j].x+block[z][j].l&&b[i].x-b[i].r>block[z][j].x&&b[i].y<block[z][j].y+block[z][j].b&&b[i].y>block[z][j].y&&b[i].q==3)
{

if(strcmpi(block[z][j].type,"normal")==0)
{
blockcount--;
b[i].a=(22.0/7)-b[i].a;
b[i].q=4;
block[z][j].e=0;
if(strcmpi(block[z][j].power,"nothing")!=0)
{block[z][j].powere=1;
block[z][j].powery=block[z][j].y+block[z][j].b/2;}
break;
}
else
if(strcmpi(block[z][j].type,"ice")==0)
{
if(fire[i]==-5)
{
b[i].a=(22.0/7)-b[i].a;
b[i].q=4;
fire[i]=0;
break;
}
else
{
blockcount--;
b[i].a=(22.0/7)-b[i].a;
b[i].q=4;
block[z][j].e=0;
if(strcmpi(block[z][j].power,"nothing")!=0)
{block[z][j].powere=1;
block[z][j].powery=block[z][j].y+block[z][j].b/2;}
break;
}
}
else
if(strcmpi(block[z][j].type,"metal")==0)
{
if(fire[i]==-5)
{
blockcount--;
b[i].a=(22.0/7)-b[i].a;
b[i].q=4;
block[z][j].e=0;
if(strcmpi(block[z][j].power,"nothing")!=0)
{block[z][j].powere=1;
block[z][j].powery=block[z][j].y+block[z][j].b/2;}
break;
}
else
{
b[i].a=(22.0/7)-b[i].a;
b[i].q=4;
break;
}
}
else
if(strcmpi(block[z][j].type,"thick")==0)
{
if((b[i].r==4&&speed==5)||b[i].r==6||b[i].r==8)
if(block[z][j].crack<3)
{
block[z][j].crack++;
b[i].a=(22.0/7)-b[i].a;
b[i].q=4;
break;
}
else
{
blockcount--;
b[i].a=(22.0/7)-b[i].a;
b[i].q=4;
block[z][j].e=0;
if(strcmpi(block[z][j].power,"nothing")!=0)
{block[z][j].powere=1;
block[z][j].powery=block[z][j].y+block[z][j].b/2;}
break;
}
else
{
b[i].a=(22.0/7)-b[i].a;
b[i].q=4;
break;
}

}     // if block of thick

}





if(b[i].x+b[i].r>=block[z][j].x&&b[i].x+b[i].r<block[z][j].x+block[z][j].l&&b[i].y<block[z][j].y+block[z][j].b&&b[i].y>block[z][j].y&&b[i].q==4)
{

if(strcmpi(block[z][j].type,"normal")==0)
{
blockcount--;
b[i].a=(22.0/7)-b[i].a;
b[i].q=3;
block[z][j].e=0;
if(strcmpi(block[z][j].power,"nothing")!=0)
{block[z][j].powere=1;
block[z][j].powery=block[z][j].y+block[z][j].b/2;}
break;
}
else
if(strcmpi(block[z][j].type,"ice")==0)
{
if(fire[i]==-5)
{
b[i].a=(22.0/7)-b[i].a;
b[i].q=3;
fire[i]=0;
break;
}
else
{
blockcount--;
b[i].a=(22.0/7)-b[i].a;
b[i].q=3;
block[z][j].e=0;
if(strcmpi(block[z][j].power,"nothing")!=0)
{block[z][j].powere=1;
block[z][j].powery=block[z][j].y+block[z][j].b/2;}
break;
}
}
else
if(strcmpi(block[z][j].type,"metal")==0)
{
if(fire[i]==-5)
{
blockcount--;
b[i].a=(22.0/7)-b[i].a;
b[i].q=3;
block[z][j].e=0;
if(strcmpi(block[z][j].power,"nothing")!=0)
{block[z][j].powere=1;
block[z][j].powery=block[z][j].y+block[z][j].b/2;}
break;
}
else
{
b[i].a=(22.0/7)-b[i].a;
b[i].q=3;
break;
}
}
else
if(strcmpi(block[z][j].type,"thick")==0)
{
if((b[i].r==4&&speed==5)||b[i].r==6||b[i].r==8)
if(block[z][j].crack<3)
{
block[z][j].crack++;
b[i].a=(22.0/7)-b[i].a;
b[i].q=3;
break;
}
else
{
blockcount--;
b[i].a=(22.0/7)-b[i].a;
b[i].q=3;
block[z][j].e=0;
if(strcmpi(block[z][j].power,"nothing")!=0)
{block[z][j].powere=1;
block[z][j].powery=block[z][j].y+block[z][j].b/2;}
break;
}
else
{
b[i].a=(22.0/7)-b[i].a;
b[i].q=3;
break;
}

}     // if block of thick

}






if(b[i].y-b[i].r<=block[z][j].y+block[z][j].b&&b[i].y-b[i].r>block[z][j].y&&b[i].x<block[z][j].x+block[z][j].l&&b[i].x>block[z][j].x&&b[i].q==1)
{

if(block[z][j].spike==1)
{
b[i].er=-2;
b[i].r=4;
b[i].a=-b[i].a;
b[i].q=4;
if(small[i]!=1)
{small[i]=1;
smallcount[i]=0;}
break;
}
else
{

if(strcmpi(block[z][j].type,"normal")==0)
{
blockcount--;
b[i].a=-b[i].a;
b[i].q=4;
block[z][j].e=0;
if(strcmpi(block[z][j].power,"nothing")!=0)
{block[z][j].powere=1;
block[z][j].powery=block[z][j].y+block[z][j].b/2;}
break;
}
else
if(strcmpi(block[z][j].type,"ice")==0)
{
if(fire[i]==-5)
{
b[i].a=-b[i].a;
b[i].q=4;
fire[i]=0;
break;
}
else
{
blockcount--;
b[i].a=-b[i].a;
b[i].q=4;
block[z][j].e=0;
if(strcmpi(block[z][j].power,"nothing")!=0)
{block[z][j].powere=1;
block[z][j].powery=block[z][j].y+block[z][j].b/2;}
break;
}
}
else
if(strcmpi(block[z][j].type,"metal")==0)
{
if(fire[i]==-5)
{
blockcount--;
b[i].a=-b[i].a;
b[i].q=4;
block[z][j].e=0;
if(strcmpi(block[z][j].power,"nothing")!=0)
{block[z][j].powere=1;
block[z][j].powery=block[z][j].y+block[z][j].b/2;}
break;
}
else
{
b[i].a=-b[i].a;
b[i].q=4;
break;
}
}
else
if(strcmpi(block[z][j].type,"thick")==0)
{
if((b[i].r==4&&speed==5)||b[i].r==6||b[i].r==8)
if(block[z][j].crack<3)
{
block[z][j].crack++;
b[i].a=-b[i].a;
b[i].q=4;
break;
}
else
{
blockcount--;
b[i].a=-b[i].a;
b[i].q=4;
block[z][j].e=0;
if(strcmpi(block[z][j].power,"nothing")!=0)
{block[z][j].powere=1;
block[z][j].powery=block[z][j].y+block[z][j].b/2;}
break;
}
else
{
b[i].a=-b[i].a;
b[i].q=4;
break;
}

}     // if block of thick


}


}






if(b[i].y-b[i].r<=block[z][j].y+block[z][j].b&&b[i].y-b[i].r>block[z][j].y&&b[i].x<block[z][j].x+block[z][j].l&&b[i].x>block[z][j].x&&b[i].q==2)
{

if(block[z][j].spike==1)
{
b[i].er=-2;
b[i].r=4;
b[i].a=-b[i].a;
b[i].q=3;
if(small[i]!=1)
{small[i]=1;
smallcount[i]=0;}
break;
}
else
{

if(strcmpi(block[z][j].type,"normal")==0)
{
blockcount--;
b[i].a=-b[i].a;
b[i].q=3;
block[z][j].e=0;
if(strcmpi(block[z][j].power,"nothing")!=0)
{block[z][j].powere=1;
block[z][j].powery=block[z][j].y+block[z][j].b/2;}
break;
}
else
if(strcmpi(block[z][j].type,"ice")==0)
{
if(fire[i]==-5)
{
b[i].a=-b[i].a;
b[i].q=3;
fire[i]=0;
break;
}
else
{
blockcount--;
b[i].a=-b[i].a;
b[i].q=3;
block[z][j].e=0;
if(strcmpi(block[z][j].power,"nothing")!=0)
{block[z][j].powere=1;
block[z][j].powery=block[z][j].y+block[z][j].b/2;}
break;
}
}
else
if(strcmpi(block[z][j].type,"metal")==0)
{
if(fire[i]==-5)
{
blockcount--;
b[i].a=-b[i].a;
b[i].q=3;
block[z][j].e=0;
if(strcmpi(block[z][j].power,"nothing")!=0)
{block[z][j].powere=1;
block[z][j].powery=block[z][j].y+block[z][j].b/2;}
break;
}
else
{
b[i].a=-b[i].a;
b[i].q=3;
break;
}
}
else
if(strcmpi(block[z][j].type,"thick")==0)
{
if((b[i].r==4&&speed==5)||b[i].r==6||b[i].r==8)
if(block[z][j].crack<3)
{
block[z][j].crack++;
b[i].a=-b[i].a;
b[i].q=3;
break;
}
else
{
blockcount--;
b[i].a=-b[i].a;
b[i].q=3;
block[z][j].e=0;
if(strcmpi(block[z][j].power,"nothing")!=0)
{block[z][j].powere=1;
block[z][j].powery=block[z][j].y+block[z][j].b/2;}
break;
}
else
{
b[i].a=-b[i].a;
b[i].q=3;
break;
}

}     // if block of thick


}


}






if(b[i].y+b[i].r>=block[z][j].y&&b[i].y+b[i].r<block[z][j].y+block[z][j].b&&b[i].x<block[z][j].x+block[z][j].l&&b[i].x>block[z][j].x&&b[i].q==3)
{
if(block[z][j].spike==-1)
{
b[i].er=-2;
b[i].r=4;
b[i].a=-b[i].a;
b[i].q=2;
if(small[i]!=1)
{small[i]=1;
smallcount[i]=0;}
break;
}
else
{

if(strcmpi(block[z][j].type,"normal")==0)
{
blockcount--;
b[i].a=-b[i].a;
b[i].q=2;
block[z][j].e=0;
if(strcmpi(block[z][j].power,"nothing")!=0)
{block[z][j].powere=1;
block[z][j].powery=block[z][j].y+block[z][j].b/2;}
break;
}
else
if(strcmpi(block[z][j].type,"ice")==0)
{
if(fire[i]==-5)
{
b[i].a=-b[i].a;
b[i].q=2;
fire[i]=0;
break;
}
else
{
blockcount--;
b[i].a=-b[i].a;
b[i].q=2;
block[z][j].e=0;
if(strcmpi(block[z][j].power,"nothing")!=0)
{block[z][j].powere=1;
block[z][j].powery=block[z][j].y+block[z][j].b/2;}
break;
}
}
else
if(strcmpi(block[z][j].type,"metal")==0)
{
if(fire[i]==-5)
{
blockcount--;
b[i].a=-b[i].a;
b[i].q=2;
block[z][j].e=0;
if(strcmpi(block[z][j].power,"nothing")!=0)
{block[z][j].powere=1;
block[z][j].powery=block[z][j].y+block[z][j].b/2;}
break;
}
else
{
b[i].a=-b[i].a;
b[i].q=2;
break;
}
}
else
if(strcmpi(block[z][j].type,"thick")==0)
{
if((b[i].r==4&&speed==5)||b[i].r==6||b[i].r==8)
if(block[z][j].crack<3)
{
block[z][j].crack++;
b[i].a=-b[i].a;
b[i].q=2;
break;
}
else
{
blockcount--;
b[i].a=-b[i].a;
b[i].q=2;
block[z][j].e=0;
if(strcmpi(block[z][j].power,"nothing")!=0)
{block[z][j].powere=1;
block[z][j].powery=block[z][j].y+block[z][j].b/2;}
break;
}
else
{
b[i].a=-b[i].a;
b[i].q=2;
break;
}

}     // if block of thick


}

}






if(b[i].y+b[i].r>=block[z][j].y&&b[i].y+b[i].r<block[z][j].y+block[z][j].b&&b[i].x<block[z][j].x+block[z][j].l&&b[i].x>block[z][j].x&&b[i].q==4)
{

if(block[z][j].spike==-1)
{
b[i].er=-2;
b[i].r=4;
b[i].a=-b[i].a;
b[i].q=1;
if(small[i]!=1)
{small[i]=1;
smallcount[i]=0;}
break;
}
else
{

if(strcmpi(block[z][j].type,"normal")==0)
{
blockcount--;
b[i].a=-b[i].a;
b[i].q=1;
block[z][j].e=0;
if(strcmpi(block[z][j].power,"nothing")!=0)
{block[z][j].powere=1;
block[z][j].powery=block[z][j].y+block[z][j].b/2;}
break;
}
else
if(strcmpi(block[z][j].type,"ice")==0)
{
if(fire[i]==-5)
{
b[i].a=-b[i].a;
b[i].q=1;
fire[i]=0;
break;
}
else
{
blockcount--;
b[i].a=-b[i].a;
b[i].q=1;
block[z][j].e=0;
if(strcmpi(block[z][j].power,"nothing")!=0)
{block[z][j].powere=1;
block[z][j].powery=block[z][j].y+block[z][j].b/2;}
break;
}
}
else
if(strcmpi(block[z][j].type,"metal")==0)
{
if(fire[i]==-5)
{
blockcount--;
b[i].a=-b[i].a;
b[i].q=1;
block[z][j].e=0;
if(strcmpi(block[z][j].power,"nothing")!=0)
{block[z][j].powere=1;
block[z][j].powery=block[z][j].y+block[z][j].b/2;}
break;
}
else
{
b[i].a=-b[i].a;
b[i].q=1;
break;
}
}
else
if(strcmpi(block[z][j].type,"thick")==0)
{
if((b[i].r==4&&speed==5)||b[i].r==6||b[i].r==8)
if(block[z][j].crack<3)
{
block[z][j].crack++;
b[i].a=-b[i].a;
b[i].q=1;
break;
}
else
{
blockcount--;
b[i].a=-b[i].a;
b[i].q=1;
block[z][j].e=0;
if(strcmpi(block[z][j].power,"nothing")!=0)
{block[z][j].powere=1;
block[z][j].powery=block[z][j].y+block[z][j].b/2;}
break;
}
else
{
b[i].a=-b[i].a;
b[i].q=1;
break;
}

}     // if block of thick


}


}





}






b[i].x+=(4.9+0.1*i+speed)*cos(b[i].a);
b[i].y+=(4.9+0.1*i+speed)*sin(b[i].a);
setcolor(9+fire[i]);
setfillstyle(1,9+fire[i]);
fillellipse(b[i].x,b[i].y,b[i].r,b[i].r); //ball

}





if(bullet==1)
{
if(blockcount>=25)
delay(7);
else
if(blockcount>=10)
delay(10);
else
if(blockcount>=0)
delay(13);
}
else
{
if(blockcount>=25)
delay(14);
else
if(blockcount>=10)
delay(17);
else
if(blockcount>=0)
delay(20);
}





if(resume==1)
{delay(1000);
resume=0;}






if(kbhit())
{

key=getch();

if(reverse!=1)
{
if(key==c.a&&p.x-(p.l/2)>19)
{p.x-=20;
gx-=20;
printb();}
else
if(key==c.d&&p.x+(p.l/2)<2*x-19)
{p.x+=20;
gx+=20;
printb();}
}
else
{
if(key==c.d&&p.x-(p.l/2)>19)
{p.x-=20;
gx-=20;
printb();}
else
if(key==c.a&&p.x+(p.l/2)<2*x-19)
{p.x+=20;
gx+=20;
printb();}
}


if(bullet==1)
if(key==c.k&&gd>8)
{gx+=4;
gd-=8;}
else
if(key==c.i&&gd<p.l-16)
{
if(gx==p.x-(p.l/2)+8)
{gd+=8;}
else
if(gx+gd==p.x+(p.l/2)-8)
{gx-=8;
gd+=8;}
else
{gx-=4;
gd+=8;}
}
else
if(key==c.j&&gx>p.x-(p.l/2)+8)
{gx-=4;}
else
if(key==c.l&&gx+gd<p.x+(p.l/2)-8)
{gx+=4;}


if(key=='p')
{
pb:
mf=1;
qf=1;


pause();

do{z=getch();
if(z=='r')
{resume=1;
continue;}
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
{;}//{return mc+mf;}   //if mc+mf==14 goto block;
else
if(mc=='d'&&mf==1)
{
pause();

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


pause();

bar3d(x+300,y+120,x-300,y-100,0,0);
bar3d(x-230,y+30,x-60,y+100,0,0);
outtextxy(x-250,y-120,"are u sure?");
outtextxy(x-200,y,"yes");
outtextxy(x+110,y,"no");
mf=1;}
else
if(mc==13&&mf==2)
{goto pb;}
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

pause();

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

pause();

bar3d(x+300,y+120,x-300,y-100,0,0);
bar3d(x-230,y+30,x-60,y+100,0,0);
outtextxy(x-250,y-120,"are u sure?");
outtextxy(x-200,y,"yes");
outtextxy(x+110,y,"no");
qf=1;}
else
if(qc==13&&qf==2)
{goto pb;}
}//if block
}//for block
}

}while(z!='r'&&z!='m'&&z!='q');
}





}  // kbhit block



}   // game block

clrscr();
cleardevice();

cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tyour score  "<<level;
delay(5000);
getch();

//return level;

closegraph() ;

}

