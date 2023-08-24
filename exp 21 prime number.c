#include<stdio.h>
int main()
{
	int i,n,p=0;
	printf("\nenter the num : ");
	scanf("%d",&n);
	for(i=2;i<=n;i++)
	{
		if(n%i==0)
		p++;
	}
	if(p==1)
	printf("\nit is prime %d");
	else
	printf("\nit is not ");
}


