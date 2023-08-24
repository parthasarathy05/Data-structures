#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start1, *start2;
int main()
{
	int n=2,i,j,val;
	struct node*tmp1 ,*tmp2,*fnnode1,*fnnode2 ,*tmp3,*tmp4,*malloc;
	start1=(struct node*)malloc(sizeof(struct node*));
	start2=(struct node* )malloc(sizeof(struct node*));
	printf("\nenter the value of start 1: ");
	scanf("%d",&val);
	start1->data=val;
	start1->next=NULL;
	tmp1=start1;
	for(i=0;i<n;i++)
	{
		fnnode1=(struct node* )malloc(sizeof(struct node*));
		printf("\nenter the data of ll1 : ");
		scanf("%d",&val);
		fnnode1->data=val;
		fnnode1->next=NULL;
		tmp1->next=fnnode1;
		tmp1=fnnode1;
	}
	printf("\nenter the value of start 2: ");
	scanf("%d",&val);
	start2->data=val;
	start2->next=NULL;
	tmp2=start2;
	for(i=0;i<n;i++)
	{
		fnnode2=(struct node* )malloc(sizeof(struct node*));
		printf("\nenter the data of ll2 : ");
		scanf("%d",&val);
		fnnode2->data=val;
		fnnode2->next=NULL;
		tmp2->next=fnnode2;
		tmp2=fnnode2;
	}
	tmp1=start1;
	tmp2=start2;
	i=0;
	while(tmp1!=NULL)
	{
		tmp3=tmp1->next;
		tmp4=tmp2->next;
		tmp1->next=tmp2;
		tmp2->next=tmp3;
		tmp2=tmp4;
		tmp1=tmp3;
		i++;
	}
	tmp1=start1;
	while(tmp1!=NULL)
	{
		printf("\n%d",tmp1->data);
		tmp1=tmp1->next;
	}
	
}

