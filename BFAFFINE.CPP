//brute force attack on affine cipher
#include<iostream.h>
#include<conio.h>
#include<string.h>
int k1,k2,len;
char c[100];
/*void decrypt()
{
	int c1[100],p[100],k1dash,flag=0;
	cout<<" Decryption : ";
	for(int i=0;i<len;i++)
	{
		if(c[i]>=97&&c[i]<=122)
		{
			c1[i]=(((int)c[i]-97-k2)%26)+97;
			if(c1[i]<=96)
				c1[i]+=26;
			//cout<<c1[i];
			flag=1;
		}
		if(c[i]>=65&&c[i]<=91)
		{
			c1[i]=(((int)c[i]-65-k2)%26)+65;
			if(c1[i]<=64)
				c1[i]+=26;
			//cout<<c1[i];
			flag=2;
		}
	}
	for(i=0;i<len;i++)
	{
		for(int j=0;j<26;j++)
			if((j*k1)%26==1)
				k1dash=j;
		//cout<<(int)'a';
		if(flag==1)
		{
			p[i]=((c1[i]-97)*k1dash)%26+97;
			cout<<(char)p[i];
		}
		if(flag==2)
		{
			p[i]=((c1[i]-65)*k1dash)%26+65;
			cout<<(char)p[i];
		}
	}
	p[i]='\n';
}*/
char* decrypt()
{
	int c1[100],k1dash,flag=0;
	char p[100];
	//cout<<"\nDecryption : ";
	for(int i=0;i<len;i++)
	{
		if(c[i]>=97&&c[i]<=122)
		{
			c1[i]=(((int)c[i]-97-k2)%26)+97;
			if(c1[i]<=96)
				c1[i]+=26;
			//cout<<c1[i];
			flag=1;
		}
		if(c[i]>=65&&c[i]<=91)
		{
			c1[i]=(((int)c[i]-65-k2)%26)+65;
			if(c1[i]<=64)
				c1[i]+=26;
			//cout<<c1[i];
			flag=2;
		}
	}
	for(i=0;i<len;i++)
	{
		for(int j=0;j<26;j++)
			if((j*k1)%26==1)
				k1dash=j;
		//cout<<(int)'a';
		if(flag==1)
		{
			p[i]=((c1[i]-97)*k1dash)%26+97;
			//cout<<(char)p[i];
		}
		if(flag==2)
		{
			p[i]=((c1[i]-65)*k1dash)%26+65;
			//cout<<(char)p[i];
		}
	}
	//cout<<"test"<<p<<"\n";
	p[len]='\0';
	return p;
}
void main()
{
	char ch;
	clrscr();
	cout<<"\nEnter the cipher text : ";
	cin>>c;
	len=strlen(c);
	cout<<"\nDo you want to apply brute force ? (y/n)";
	cin>>ch;
	if(ch=='y')
	{
		for(k1=1;k1<=26;k1+=2)
		{
			if(k1!=13)
			for(k2=0;k2<26;k2++)
			{
				cout<<"\nFor k1:"<<k1<<" and k2:"<<k2;
				cout<<" Plain text: "<<decrypt();
			}
		}
	}
	cout<<"\nThank You !!";
	getch();
}