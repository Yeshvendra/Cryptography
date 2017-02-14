#include<stdio.h>
#include<math.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	long long int e,d,m,c,p,q,n,t,i,j,k=2,l,pri[50][50],prime[1000];
	for(i=0;i<50;i++){
		for(j=0;j<50;j++){
			pri[i][j]=k;
			k++;
			for(l=2;l<pri[i][j]/2;l++)
				if(pri[i][j]%l==0){
					pri[i][j]=0;
					break;
				}
		}
	}
	k=0;
	for(i=0;i<50;i++){
		for(j=0;j<50;j++){
			if(pri[i][j]!=0){
				prime[k]=pri[i][j];
				k++;
				cout<<pri[i][j]<<"\n";
			}
		}
	}
	p=prime[rand()%k];
	q=prime[rand()%k];
	n=p*q;
	t=(p-1)*(q-1);
	cout<<"\nEnter the public key : ";
	cin>>e;
	for(i=1;i<t;i++)
	{
		if(e*i%t==1)
		{
			d=i;
			break;
		}
	}
	cout<<"p="<<p<<" q="<<q<<" e="<<e<<" d="<<d<<"\n";
	cout<<"\nEnter the message : ";
	cin>>m;
	c=(long long int)pow(m,e);
	//cout<<"\npow(m,e) : "<<c;
	c=c%n;
	if(c<=0)
		c=n+c;
	cout<<"\nCriptext : "<<c<<" .\n";
	m=(long long int)pow(c,d);
	m=m%n;
	if(m<=0)
		m=n+m;
	cout<<"\nAfter decryption Plaintext : "<<m<<" .";
	return 0;
}
