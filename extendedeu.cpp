#include<stdio.h>
#include<conio.h>
int main()
{
	int r1,r2,r;

	int q;
	printf("\t---program to find out multiplicative inverse ------\n");
	printf("\n Enter firsr coprime  no. :");
	scanf("%d",&r1);
	printf("\n Enter second coprime no. :");
	scanf("%d",&r2);
//	r1=26;
//	r2=3;
	int t1,t2,t;
	t1=0;t2=1;
	while(r2 !=0)
	{
		q=r1/r2;
		r=r1-q*r2;
		r1=r2;
		r2=r;
		t=t1-q*t2;
		t1=t2;
		t2=t;
		
	}
	//printf("gcd is : %d",r1);
	printf("\nmultiplicative inverse is : %d",t1);
	
}

