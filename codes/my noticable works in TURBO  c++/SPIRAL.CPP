#include<iostream.h>
#include<conio.h>
#include<stdio.h>

void main()
{

clrscr();

int a[9][9]={0},n,i,j,d=1,r=0,c=0;

cout<<"\n\n\t\t\tSPIRAL!!!!!!";

cout<<"\n\nenter the length of the spiral ==> ";


cin>>n;

cout<<"\n\nSPIRAL ====> \n\n";

for(i=0;i<n;i++)
for(j=1;j<=n;j++)
{
if(d==1)
{
a[r][c]=j;
if(a[r][c+1]!=0||c==n-1)
{d=2;r++;}
else
c++;
}
else
if(d==2)
{
a[r][c]=j;
if(a[r+1][c]!=0||r==n-1)
{d=3;c--;}
else
r++;
}
else
if(d==3)
{
a[r][c]=j;
if(a[r][c-1]!=0||c==0)
{d=4;r--;}
else
c--;
}
else
if(d==4)
{
a[r][c]=j;
if(a[r-1][c]!=0)
{d=1;c++;}
else
r--;
}
}


for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
cout<<a[i][j]<<"  ";

cout<<"\n\n";
}


getch();

}


