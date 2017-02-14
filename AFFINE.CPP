//Afine cipher decryption and encryption
#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int c[100],k1,k2,len;
char plain[100];
void encrypt()
{
	char p[100];
	int t[100],flag=0;
	cout<<"Enter the plain text:";
	cin>>p;
	strcpy(plain,p);
	cout<<"Enter the key k1 and k2 :";
	cin>>k1>>k2;
	len=strlen(p);
	cout<<"\nEncryption : ";
	for(int i=0;i<strlen(p);i++)
	{
		if(p[i]>=97&&p[i]<=122)
		{
			t[i]=((((int)p[i]-97)*k1)%26)+97;
			//cout<<(char)t[i]<<"\n";
			flag=1;
		}
		if(p[i]>=65&&p[i]<=91)
		{
			t[i]=((((int)p[i]-65)*k1)%26)+65;
			//cout<<(char)t[i]<<"\n";
			flag=2;
		}
	}
	for(i=0;i<strlen(p);i++)
	{
		if(flag==1)
		{
			c[i]=((t[i]-97+k2)%26)+97;
			cout<<(char)c[i];
		}
		if(flag==2)
		{
			c[i]=((t[i]-65+k2)%26)+65;
			cout<<(char)c[i];
		}
	}
}
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
/*void brutef()
{
	char ch,p[100];
	int flag=0;
	cout<<"\nDo you want to apply brute force ? (y/n)";
	cin>>ch;
	if(ch=='y')
	{
		for(k1=1;k1<=25;k1+=2)
		{
			if(k1!=13)
			for(k2=0;k2<26;k2++)
			{
				//cout<<"\nFor k1:"<<k1<<" and k2:"<<k2;
				strcpy(p,decrypt());
				//cout<<"    "<<p<<"    "<<plain;
				if(strcmp(p,plain)==0)
				{
					cout<<"\nMatch Found !!\nFor key k1 : "<<k1<<" k2 : "<<k2;
					flag=1;
				}
				if(flag==1)
					break;
			}
			if(flag==1)
				break;
		}
	}
	else
	cout<<"\nThank You !!";
	getch();
}*/
int main()
{
	char choice;
	clrscr();
	encrypt();
	cout<<"\nDo you want to decrypt it ? (y/n) :";
	cin>>choice;
	if(choice=='y')
		cout<<"\nDecryption : "<<decrypt();
	//brutef();
	getch();
	return 0;
}
