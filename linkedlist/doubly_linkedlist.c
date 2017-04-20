#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *prev;
	struct node *next;
}*head=NULL;


//create------------

void create()
{
	int i=1;
	while(i<=7)
	{
		struct node *new_node=(struct node *)malloc(sizeof(struct node));
		struct node *current_node;
		new_node->data=i;
		new_node->next=NULL;
		new_node->prev=NULL;
		if(head==NULL)
		{
			head=new_node;
			current_node=new_node;
		}
		else
		{
			current_node->next=new_node;
			new_node->prev=current_node;
			current_node=new_node;
		}
		i++;
	}
}

//traverse----
void traverse(struct node *p)
{
	if(p)
	{
		printf("%d\n",p->data);
		printf("previous node value=%d\n",p->prev->data );
		traverse(p->next);
	}
	
}



int main(int argc, char const *argv[])
{
	/* code */
	create();
	printf("traverse is----\n");
	traverse(head->next);
	return 0;
}