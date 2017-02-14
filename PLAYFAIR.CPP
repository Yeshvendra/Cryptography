//Playfair Cipher By Yeshvendra Kumar Singh
#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
char p[100],c[100];
void shift(int k)
{
	int i;
	for(i=strlen(p)-1;i>k;i--)
	{
		p[i+1]=p[i];
	}
	p[strlen(p)+1]='\0';
}
void playfair()
{
	char k[5][5]={{'l','g','d','b','a'},{'q','m','h','e','c'},{'u','r','n','i','f'},{'x','v','s','o','k'},{'z','y','w','t','p'}};
	int len,i,j;
	cout<<"\nEnter the plain text:";
	cin>>p;
	//cout<<"\nEnter the 5*5 key:";
	//for(i=0;i<5;i++)
	//	for(j=0;j>5;j++)
	//		cin>>k[i][j];
	len=strlen(p);
	for(i=0;i<len;i++)
	{
		if(p[i]==p[i+1])
		{
			shift(i);
			if(p[i+1]!='x')
				p[i+1]='x';
			else
				p[i+1]='q';
		}
	}
	len=strlen(p);
	if(len%2==1)
	{
		p[len]='x';
		p[++len]='\0';
	}
	cout<<"\nPlain Text Now : "<<p;
	for(i=0;i<len;i+=2)
	{
		int lx1,ly1,lx2,ly2;
		for(int l=0;l<5;l++)
		{
			for(j=0;j<5;j++)
			{
				if(p[i]==k[l][j])
				{
					lx1=l;
					ly1=j;
				}
				if(p[i+1]==k[l][j])
				{
					lx2=l;
					ly2=j;
				}
			}
		}
		//cout<<lx1<<" "<<ly1<<" "<<lx2<<" "<<ly2<<"\n";
		if(ly1==ly2)
		{
			c[i]=k[(lx1+1)%5][ly1];
			c[i+1]=k[(lx2+1)%5][ly2];
		}
		else if(lx1==lx2)
		{
			c[i]=k[lx1][(ly1+1)%5];
			c[i+1]=k[lx2][(ly2+1)%5];
		}
		else
		{
			c[i]=k[lx1][ly2];
			c[i+1]=k[lx2][ly1];
		}
	}
	c[len]='\0';
	cout<<"\nCryptext : "<<c;
}
void decrypt()
{
	int i,j,len;
	char c1[100];
	char k[5][5]={{'l','g','d','b','a'},{'q','m','h','e','c'},{'u','r','n','i','f'},{'x','v','s','o','k'},{'z','y','w','t','p'}};
	len=strlen(c);
	for(i=0;i<len;i+=2)
	{
		int lx1,ly1,lx2,ly2;
		for(int l=0;l<5;l++)
		{
			for(j=0;j<5;j++)
			{
				if(c[i]==k[l][j])
				{
					lx1=l;
					ly1=j;
				}
				if(c[i+1]==k[l][j])
				{
					lx2=l;
					ly2=j;
				}
			}
		}
		//cout<<lx1<<" "<<ly1<<" "<<lx2<<" "<<ly2<<"\n";
		if(ly1==ly2)
		{
			c1[i]=k[(lx1-1)%5][ly1];
			c1[i+1]=k[(lx2-1)%5][ly2];
		}
		else if(lx1==lx2)
		{
			c1[i]=k[lx1][(ly1-1)%5];
			c1[i+1]=k[lx2][(ly2-1)%5];
		}
		else
		{
			c1[i+1]=k[lx2][ly1];
			c1[i]=k[lx1][ly2];
		}
	}
	c1[len]='\0';
	cout<<"\nPlain text : "<<c1;
}
void main()
{
	clrscr();
	playfair();
	decrypt();
	getch();
}