//Hill Cipher By Yeshvendra Kumar Singh
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
int col,c1[20][20]={0},k1[2][2];
void hill()
{
	int len;
	char p[20],c[20],k[2][2];
	int m[2][10],p1[20];
	cout<<"\nEnter plain text:";
	cin>>p;
	len=strlen(p);
	if(len%2==1)
	{
		p[len]='x';
		p[len+1]='\0';
	}
	cout<<"\n"<<p<<"\n";
	for(int j=0;j<len;j++)
	{
		if(p[j]>=97&&p[j]<=122)
			p1[j]=(int)p[j]-97;
		else if(p[j]>=65&&p[j]<=91)
			p1[j]=(int)p[j]-65;
		else
		{
			cout<<"\nInvalid Input!!";
			getch();
			exit(0);
		}
	}
	//for(int i=0;i<len;i++)
	//cout<<"\n"<<p1[i]<<"\n";
	col=len/2;
	for(int l=0;l<len;l++)
	{
		m[(int)l%2][l/2]=p1[l];
	}
	cout<<"\n";
	for(l=0;l<2;l++)
	{
		for(int k=0;k<col;k++)
		{
			cout<<m[l][k]<<"  ";
		}
		cout<<"\n";
	}
	cout<<"\nEnter the 2*2 key for hill cipher:\n";
	for(int i=0;i<2;i++)
		for(j=0;j<2;j++)
		{
			cin>>k[i][j];
			if(k[i][j]>=97&&k[i][j]<=122)
				k1[i][j]=k[i][j]-97;
			else if(k[i][j]>=65&&k[i][j]<=91)
				k1[i][j]=k[i][j]-65;
			else
			{
				cout<<"\nInvalid Input!!";
				getch();
				exit(0);
			}
		}
	cout<<"Key :-\n";
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
			cout<<k1[i][j]<<"  ";
		cout<<"\n";
	}
	cout<<"\nCipher text :";
	for(i=0;i<2;i++)
		for(j=0;j<col;j++)
			for(l=0;l<2;l++)
				 c1[i][j]+=k1[i][l]*m[l][j];
	for(i=0;i<col;i++)
		for(l=0;l<2;l++)
		{
			c1[l][i]%=26;
			if(c1[l][i]<0)
				c1[l][i]+=26;
			cout<<(char)(c1[l][i]+97);
		}
}
void decyphter()
{
	int t,i,j,l,p[2][20]={0};
	int k1dash[2][2]={0.0};
	char cho;
	t=k1[0][0]*k1[1][1]-k1[0][1]*k1[1][0];
	if(t<0)
		t+=26;
	for(i=0;i<26;i++)
		if(i*t%26==1)
			break;
	t=i;
	k1dash[0][0]=k1[1][1];
	k1dash[1][1]=k1[0][0];
	k1dash[0][1]=(-1)*k1[0][1];
	k1dash[1][0]=(-1)*k1[1][0];
	cout<<"\n\nDo you want to decrypt ? (y/n)\n";
	cin>>cho;
	if(cho=='y')
	{
	cout<<"\n\nInverse of key:-\n";
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			if(k1dash[i][j]<0)
				k1dash[i][j]+=26;
			k1dash[i][j]=(k1dash[i][j]*t)%26;
			cout<<k1dash[i][j]<<"  ";
		}
		cout<<"\n";
	}
	for(i=0;i<2;i++)
		for(j=0;j<col;j++)
			for(l=0;l<2;l++)
				 p[i][j]+=k1dash[i][l]*c1[l][j];
	cout<<"\nPlain text : ";
	for(i=0;i<col;i++)
		for(l=0;l<2;l++)
		{
			p[l][i]%=26;
			if(p[l][i]<0)
				p[l][i]+=26;
			cout<<(char)(p[l][i]+97);
		}
	}
}
void main()
{
	clrscr();
	hill();
	decyphter();
	getch();
}