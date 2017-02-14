#include<stdio.h>
#include<string.h>
int al[20]={0},mati[20]={0},matd[20][20]={0};
char temp,a[20]={'*'},nc[20][50],c[50],key[50],matc[20][20];
void test()
{
	int t,b,i1,col,sgcd,max=0,gcd[20],i,j,l,count1,count=0,flag=0;
	l=strlen(c);
	for(i=0;i<l-2;i++)
	{
		count1=0;
		for(j=i+3;j<l-2;j++)
		{
			if(c[i]==c[j]&&c[i+1]==c[j+1]&&c[i+2]==c[j+2])
			{
				matd[count][count1++]=j-i;
				mati[count]++;
				matc[count][0]=c[i];
				matc[count][1]=c[i+1];
				matc[count++][2]=c[i+2];
			}
		}
	}
	printf("\nMatch\tInst\tDist");
	printf("\n--------------------------------------");
	for(i=0;i<count;i++)
	{
		printf("\n%c%c%c",matc[i][0],matc[i][1],matc[i][2]);
		printf("\t%d",mati[i]);
		for(j=0;j<mati[i];j++)
			printf("\t%d",matd[i][j]);
	}
	printf("\n\n");
	for(i=0;i<count;i++)
	{
		if(max<matd[i][0])
			max=matd[i][0];
	}
	count1=0;
	for(i=1;i<max;i++)
	{
		for(j=0;j<count;j++)
		{
			if(matd[j][0]%i==0)
				flag=1;
			else
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
			gcd[count1++]=i;
	}
	printf("\nThe GCD :-\n");
	for(i=0;i<count1;i++)
		printf("\n%d",gcd[i]);
	printf("\nEnter a GCD to start our operation : ");
	scanf("%d",&sgcd);
	col=l/sgcd;
	for(i=0;i<l;i++)
	{
		nc[i/sgcd][i%sgcd]=c[i];
		//printf("%c,%d,%d  ",c[i],i/sgcd,i%sgcd);
	}
	//for(i=0;i<l;i++)
	//printf("%c    ",nc[i/sgcd][i%sgcd]);
	for(i=0;i<sgcd;i++)
	{
		for(l=0;l<=count1;l++)
		{
			al[l]=0;
			a[l]='*';
		}
		count1=0;
		l=0;
		printf("\nFor Column No. %d",i+1);
		for(j=0;j<col;j++)
		{
			flag=0;
			for(b=0;b<=count1;b++)
				if(nc[j][i]==a[b])
				{
					al[b]++;
					flag=1;
					break;
				}
			if(flag==0)
			{
				count1++;
				a[l]=nc[j][i];
				al[l++]++;	
			}					
		}
		for(l=0;l<count1;l++)
			printf("\n%c -> %d",a[l],al[l]);
		for(i1=0;i1<count1;i1++)
		{	
			for(j=0;j<col-i1-1;j++)
			{
				if(al[j]<al[j+1])
				{
					l=al[j];
					al[j]=al[j+1];
					al[j+1]=l;
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;		
				}	
			}	
		}
		printf("\nMost Occuring in column %d is %c having %d instance.",i+1,a[0],al[0]);
		printf("\nAssuming (e) as the most occuring character.");
		t=a[0]-'e';
		if(t<0)
			t+=26;
		t+=97;
		printf("\nAccordingly the key for column %d is %c.\n\n",i+1,(char)t);	
	}	
}
int main()
{
	int i,j;
	printf("\nEnter a cipher text : ");
	gets(c);
	test();
	return 0;
}
