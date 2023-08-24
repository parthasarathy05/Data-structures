#include<stdio.h>
int a[10][10],v[10],n,k1=1,sum=0;
int tra(int b){
	int i,j,k=0,min,fl,nod=0,v1=0;
	k=k1;
	for(i=1;i<=n;i++){
		if(i!=b){
		min=a[b][i];
		nod=i;
		break;
	}
	}
	for(i=1;i<=n;i++)
	{
		fl=0;
		if(a[b][i]<min & i!=b)
		{
			min=a[b][i];
			nod=i;
		}
			for(j=0;j<k;j++)
			{
				if(v[j]==nod)
				{
					fl=1;
						
				}
			}
			if(fl!=1)
			{
				v[k]=nod;
			}
			else {
			min=a[b][i+1];
			nod=i+1;
			v1++;
		}
	}
	if(v1==n)
	{
		v[k]=1;
		min=a[b][1];
	}
	k++;
	k1=k;
	sum+=min;
	if(v[k-1]==1 ){
	return v[k-1];
}
	else 
	{
		return tra(v[k-1]);
		
}
}
int main()
{
	int i,j,t;
	printf("\nenter the  no of cities : ");
	scanf("%d",&n);
	v[0]=1;
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("\nenter the cost from %d to %d : ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	t=tra(1);
	for(i=0;i<k1;i++)
	printf("%d-> ",v[i]);
	printf("\ntotal cost : %d",sum);
}

