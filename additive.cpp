#include<stdio.h>
#include<conio.h>
int main()
{
	char a[30];	
	char cipher[30];
	int x=0,y=0,key;
	int c=0;
	
	printf("enter the key value :");
	scanf("%d",&key);
	printf("Enter the text here :");
	getchar();
	
	while((c=getchar()) !='\n')
	{
		a[x++]=(char)c;
		cipher[y++]=(char)((((c+key)-65)%26) +65);
		
		
	}
	cipher[y]=0;
	printf("%s",cipher);
	
	//decoding 
	c=0;
	while((c=getchar()) !='\n')
	{
	
		a[y++]=(char)((((c-key)-65)%26) +65);
		
		
	}
	a[y]=0;
	printf(" \nPlain Text  After Decoding is:%s",a );
	
}

