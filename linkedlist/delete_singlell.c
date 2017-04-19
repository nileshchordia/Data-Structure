#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	
}*head=NULL;

//create node--------------

void create()
{

	int i=8;
	while(i)
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
		i--;
	}

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


//delete node from beginning------------
void delete_Beg()
{
	struct node *p=head;
	head=head->next;
	free(p);
	printf("delete node from beginnig & new traverse is---------\n");
	traverse();
}

//delete node at any level----------
void delete_Mid()
{
	//struct node *head;
	int n;
	printf("enter node which u have deleted\n");
	scanf("%d",&n);
	struct node *p=head;
	// printf("before= %d\n",head->next->data);
	while(p->next->data!=n)
	{
		// printf("data=%d",head->data);
		p=p->next;
	}
	// printf("\n");
	// struct node *p=head->next;
	p->next=p->next->next;
	// printf("after= %d\n",p->next->data);
	// free(p);
	printf("delete node from midlevel & new traverse is---------\n");
	traverse();
}

//delete node at the end level-----------
void delete_End()
{
	struct node *p=head;
	while(p->next->next)
	{
		p=p->next;
	}
	p->next=NULL;
	printf("delete node from end & new traverse is---------\n");	
	traverse();
}

int main(int argc, char const *argv[])
{
	char ch;
	create();
	traverse();
	delete_Beg();
	delete_Mid();
	delete_End();
	return 0;
}