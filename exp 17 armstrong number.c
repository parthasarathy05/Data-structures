#include<stdio.h>
int main()
{
	int n,i,rem,sum=0,k;
	printf("\nenter the num : ");
	scanf("%d",&n);
	k=n;
	while(n!=0)
	{
		rem=n%10;
		sum+=(rem)*(rem)*(rem);
		n/=10;
	}
	if(sum==k)
	printf("\nit is armstrong ");
	else
	printf("\nit is not ");
}

