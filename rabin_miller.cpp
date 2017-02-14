#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int t,n,k,m,i;
	cout<<"\nEnter a number : ";
	cin>>n;
	for(i=0;(int)pow(2,i)<n;i++)
	{
		if((n-1)%(int)pow(2,i)==0){
			m=i;
		}
	}
	k=(n-1)/(int)pow(2,m);
	cout<<"m = "<<m<<"k = "<<k<<"\n";
	t=pow(2,k);
	if(t%n==1){
		cout<<"prime";
		return 0;
	}	
	for(i=0;i<m;i++){
		t=(int)pow(2,(int)pow(2,i)*k)%n;
		if(t<0)
			t=n+t;
		if(t==1||t==n-1){
			cout<<"prime";
			return 0;
		}
	}
	cout<<"composite";
	return 0;
}
