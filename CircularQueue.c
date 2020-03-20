#include<stdio.h>
#include<stdlib.h>
#define MAX 5
void insert();
void delet();
void display();
int queue[MAX];
int front=-1;
int rear=-1;
int main()
{
	int choice,n,i;
	printf("\n1.Insert\n2.Delete\n3.Display\n4.exit");
	do
	{
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter the MAXIMUM 5 element: ");
				scanf("%d",&n);
				for(i=0;i<n;i++)
				{
				insert();
			    }
				break;
			case 2:
				delet();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
		}
	}while(choice!=4);
}
void insert()
{
	int item;
	printf("\nEnter the data: ");
	scanf("%d",&item);
	if((rear+1)%MAX==front)
	{
		printf("\nOverflow the condition: ");
		return;
	}
	else if(front==-1 && rear==-1)
	{
		front=rear=0;
	}
	else if(rear==MAX-1&&front!=0)
	{
		rear=0;
	}
	else
	{
		rear=(rear+1)%MAX;
	}
	queue[rear]=item;	
}
void delet()
{
	if(front==-1&&rear==-1)
	{
		printf("\nOverflow: ");
		return;
	}
	else if(front==rear)
	{
		rear=front=-1;	
	}
	else if(front==MAX-1)
	    front=0;
	else 
	{
	  printf("\n%d item is delete: ",queue[front]);
	  front=front+1;
    }
}
void display()
{
	int i=front;
	if(front==-1&&rear==-1)
	{
		printf("\nqueue is empty: ");
	}
	else
	{
		printf("\nThe circular queue element is \n");
		while(i!=rear)
		{
			printf("  %d ",queue[i]);
			i=(i+1)%MAX;
		}
		printf("  %d",queue[rear]);
	}
}
