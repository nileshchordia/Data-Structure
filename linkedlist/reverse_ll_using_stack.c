#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	
}*head=NULL;

//dynamic array----



//create node--------------

void create()
{

	int i=1;
	while(i<=8)
	{
		struct node *new_node,*current_node;
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

//reverse using stack----------

void reverse()
{
	int * array;
	array=(int*)malloc(sizeof(int)*10);
	int top=-1;
	struct node *new=head;
	while(new)
	{
		array[++top]=new->data;
		new=new->next;
	}
	while(top!=-1)
		printf("%d\n",array[top--] );
}



//traverse----------

void traverse()
{
	struct node *new=head;
	while(new)
	{
		printf("%d\n",new->data);
		new=new->next;
	}
}



int main(int argc, char const *argv[])
{
	create();
	printf("tarverse is --\n");
	traverse();
	printf("reverse traverse using stack is ---\n");
	reverse();
	// rTraverse();

	return 0;
}