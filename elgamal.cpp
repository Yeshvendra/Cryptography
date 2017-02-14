#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
void elg()
{
	long long int i,t,p,e1,e2,P,P1,d,r,c1,c2;
	cout<<"\nEnter a large prime number : ";
	cin>>p;
	d=rand()%(p-2);
	cout<<"d : "<<d;
	if(d<=2)
		d=3;
	cout<<"\nEnter a generator : ";
	cin>>e1;
	e2=((long long int)pow(e1,d)%p);
	cout<<"e2 : "<<e2;
	cout<<"\nEnter r :";
	cin>>r;
	cout<<"\nEnter plain text : ";
	cin>>P;
	c1=(long long int)pow(e1,r)%p;
	if(c1<=0)
		c1=p+c1;
	//cout<<"c1 : "<<c1;
	c2=(long long int)(P*pow(e2,r))%p;
	if(c2<=0)
		c2=p+c2;
	//cout<<"c2 : "<<c2;
	cout<<"\nEncrypted text : "<<c1<<" "<<c2;
	t=(long long int)pow(c2,d);
	cout<<"t:"<<t;
	for(i=1;i<t;i++)
	{
		if(t*i%p==1)
		{
			t=i;
			break;
		}
	}
	cout<<"tdash:"<<t;
	P1=(c1*t)%p;
	cout<<"\nDecryption : "<<P;
}
int main()
{
	elg();
	return 0;
}
