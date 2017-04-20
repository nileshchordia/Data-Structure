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

//reverse---------------

struct node * reverse(struct node *current_node)
{
	struct node *prev=NULL;
	struct node *next=NULL;
	while(current_node)
	{
		next=current_node->next;
		current_node->next=prev;
		prev=current_node;
		current_node=next;
	}
	return prev;

}

int main(int argc, char const *argv[])
{
	create();
	printf("traverse----------\n");
	traverse(head);
	head=reverse(head);
	printf("reverse is------------\n");
	traverse(head);
	return 0;
}