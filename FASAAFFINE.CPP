//frequency analysis and statistical attack on affine cipher
#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
char c[100];
int k1,k2,len;
char* decrypt()
{
	int c1[100],k1dash,flag=0;
	char p[100];
	len=strlen(c);
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
void fa()
{
	int n[20]={0},n1=1,flag,t;
	char ch[20];
	ch[0]=c[0];
	n[0]=1;
	for(int i=1;c[i]!='\0';i++)
	{
		flag=0;
		for(int j=0;j<n1;j++)
		{
			if(c[i]==ch[j])
			{
				n[j]++;
				flag=1;
			}
		}
		if(flag==0)
		{
			ch[n1]=c[i];
			n[n1++]=1;
		}
	}
	for(int j=0;j<n1;j++)
		cout<<ch[j]<<"=="<<n[j]<<"\n";
	int large=0,pos=0,spos;
	for(i=0;i<n1;i++)
	{
		if(n[i]>large)
		{
			large=n[i];
			pos=i;
		}
	}
	large=0;
	for(i=0;i<n1;i++)
	{
		if(pos!=i)
		{
			if(n[i]>large)
			{
				large=n[i];
				spos=i;
			}
		}
	}
	//k1=(int)(ch[spos]-ch[pos])/(19-4);
	for(j=0;j<26;j++)
		if((j*(int)(ch[spos]-ch[pos]))%26==1)
			t=j;
	k1=t*(19-4);
	k1%=26;
	if(k1<0)
		k1=26+k1;
	k1+=1;
	cout<<"\nk1="<<k1;
	k2=(((int)ch[pos]-97)-k1*4);
	k2%=26;
	if(k2<0)
		k2=26+k2;
	cout<<"\nk2="<<k2;
	cout<<"\nDecryption : "<<decrypt();
	//cout<<"\nMax frequency is "<<n[pos]<<" and charater is "<<ch[pos]<<"\n";
	//cout<<"Second Max frequency is "<<n[spos]<<" and charater is "<<ch[spos]<<"\n";
}
void main()
{
	clrscr();
	cout<<"\nEnter the ciphertext: ";
	cin>>c;
	fa();
	getch();
}