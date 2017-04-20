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
		if(i==7)
		{
			new_node->data=i;
			new_node->next=head;
		}
		else
		{
			new_node->data=i;
			new_node->next=NULL;
		}
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


//circular likedlist---------

void circularLinkedList()
{
	struct node *p=head;
	while(p->next!=head)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
	printf("%d\n",p->data);
}


int main(int argc, char const *argv[])
{
	create();
	printf("circular Linked List----------\n");
	circularLinkedList();
	return 0;
}