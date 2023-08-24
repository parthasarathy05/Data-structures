#include<stdio.h>
int main()
{
	int n,rem,sum=0,i;
	printf("\nenter the num : ");
	scanf("%d",&n);
	while(n!=0)
	{
		rem=n%10;
		sum+=rem;
		n/=10;
	}
	printf("%d",sum);
}

