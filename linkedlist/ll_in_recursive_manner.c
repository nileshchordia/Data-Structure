#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
}*head=NULL;

//create-------------

void create()
{
	int i=1;
	

	while(i<8)
	{
		struct node *current_node, *new_node;
		new_node=(struct node *)malloc(sizeof(struct node));
		new_node->data=i;
		new_node->next=NULL;
		if(head==NULL)
		{
			head=new_node;
			current_node=new_node;
		}
		else
		{
			current_node->next=new_node;
			current_node=new_node;
		}
		i++;
		
	}
}

 //traverse---------------------

void traverse(struct node *p)
{

	if(p)
	{
		
		printf("%d\n",p->data );
		traverse(p->next);
		
	}
}

//reverse------------------

void reverse(struct node *p)
{
	
	if(p)
	{
		reverse(p->next);
		printf("%d\n",p->data );
		
	}
}


//main---------------------

int main()
{
	create();
	printf("traverse----------\n");
	traverse(head);
	printf("reverse----\n");
	reverse(head);
	return 0;
}