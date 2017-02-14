#include<stdio.h>
#include<string.h>
int l,p1[20],key1[20],c[20];
void enc()
{
	int i,j;
	for(i=0;i<l;i++)
	{
		c[i]=(p1[i]+key1[i])%26+97;
	}
	printf("\nCipher text : ");
	for(i=0;i<l;i++)
		printf("%c",(char)c[i]);
}
void dec()
{
	int i,j,pl[20];
	for(i=0;i<l;i++)
	{
		pl[i]=(c[i]-97-key1[i]);
		if(pl[i]<0)
			pl[i]+=26;
		pl[i]%=26;
		pl[i]+=97;
	}
	printf("\nPlain text : ");
	for(i=0;i<l;i++)
		printf("%c",(char)pl[i]);
}
int main()
{
	int i,j,k;
	char p[20],key[20],cho;
	printf("\nEnter the plain text : ");
	gets(p);
	l=strlen(p);
	for(i=0;i<l;i++)
	{
		p1[i]=p[i]-97;
	}
	printf("\nEnter the key : ");
	gets(key);
	k=strlen(key);
	for(i=0;i<l;i++)
	{
		key1[i]=key[i%k]-97;
	}
	enc();
	printf("\nDo you want to decrypt it ? (y/n)\n");
	scanf("%c",&cho);
	if(cho=='y')
		dec();
	return 0;
}
