#include<stdio.h>
#include<math.h>
char key[16],plaintext[16],criptext[16];
int sb1={1,1,0,0,0,1,1,0},c[8],pb[16][8],kb[16][8],sb[8][8]={{1,0,0,0,1,1,1,1},{1,1,0,0,0,1,1,1},{1,1,1,0,0,0,1,1},{1,1,1,1,0,0,0,1},{1,1,1,1,1,0,0,0},{0,1,1,1,1,1,0,0},{0,0,1,1,1,1,1,0},{0,0,0,1,1,1,1,1}};
void BS()
{
	int i,j,k,l;
	for(i=0;i<16;i++)
	{
		for(j=0;j<8;j++)
		{
			for(k=0;k<8;k++)
			{
				c[j]+=sb[j][k]*pb[i][k];	
			}	
		}	
		for(j=0;j<8;j++)
			pb[i][j]=c[j];
	}	
}
void bintodec()
{
	int i,j;
	for(i=0;i<16;i++)
	{
		(int)plaintext[i]=0;
		for(j=0;j<8;j++)
		{
			plaintext[i]+=(pow(2,j)*pb[i][j]);
		}
	}
}
void SR()
{
	int i,j,k,l;
	int t[8];
	for(i=0;i<4;i++)
	{
		for(k=0;k<i;k++)
		{
			for(l=0;l<8;l++)
				t[l]=pb[2*i][l];
			for(j=0;j<3;j++)
			{
				for(l=0;l<8;l++)
					pb[2*i+j][l]=pb[2*i+j+1][l];
			}
			for(l=0;l<8;l++)
				pb[2*i+3][l]=t[l];
		}
	}
}
void MC()
{
	
}
void ARK()
{
	int i,j;
	for(i=0;i<16;i++)
	{
		for(j=0;j<8;j++)
		{
			if((pb[i][j]==1&&kb[i][j]==0)||(pb[i][j]==0&&kb[i][j]==1))
				pb[i][j]=1;
			else
				pb[i][j]=0;
		}
	}
}
void changekey()
{
	
}
int main()
{
	int i,j;
	printf("\nEnter 16 char plain text : \n");
	for(i=0;i<16;i++)
		scanf("%c",&plaintext[i]);
	printf("\nEnter 16 char key : \n");
	for(i=0;i<16;i++)
		scanf("%c",&key[i]);
	for(i=0;i<16;i++)
	{
		for(j=7;j>=0;j--)
		{
			if((int)plaintext[i]>pow(2,j))
			{
				(int)plaintext[i]-=pow(2,j);
				pb[i][7-j]=1;		
			}
			else
			{
				pb[i][7-j]=0;
			}
		}
	}
	for(i=0;i<16;i++)
	{
		for(j=7;j>=0;j--)
		{
			if((int)key[i]>pow(2,j))
			{
				(int)key[i]-=pow(2,j);
				kb[i][7-j]=1;		
			}
			else
			{
				kb[i][7-j]=0;
			}
		}
	}
	return 0;
}
