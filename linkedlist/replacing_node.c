#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*head=NULL;

//create--------------------
void create()
{
	int i=8;
	

	while(i)
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
		i--;
		
	}
}

//traverse----------
void traverse()
{
	struct node *p=head;
	printf("traverse is \n");
	while(p)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}

//replace last node to first node-----------
void replace()
{
	printf("replace the node ---------\n");
	struct node *p=head;
	while(p->next->next)
	{
		p=p->next;

	}
	// printf("%d\n",p->data);
	p->next->next=head;
	head=p->next;
	p->next=NULL;
	traverse();


}



int main()
{
	create();
	traverse();
	replace();
	return 0;
}