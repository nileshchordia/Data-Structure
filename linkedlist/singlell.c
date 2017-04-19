#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	
}*head=NULL;

//create node----------------
void create()
{
		int n;
	printf("enter the length of linkedlist");
	scanf("%d",&n);
	while(n)
	{
		struct node *current_node;
		struct node *new_node=(struct node *)malloc(sizeof(struct node));
		printf("enter the data\n");
		scanf("%d",&new_node->data);
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
		n--;
	}
}

//traversse-------------------
void traverse()
{
	struct node *new=head;
	while(new!=NULL)
	{
		printf("%d\n",new->data );
		new=new->next;
	}
}

//Insert node at beginning-------------
void insert()
{
	struct node* new_node=(struct node *)malloc(sizeof(struct node));
	printf("enter the value of node \n");
	scanf("%d",&new_node->data);
	new_node->next=head;
	head=new_node;
	printf("new traverse node\n");
	traverse();

}
void newTraverse(struct node *ptr)
{
	while(ptr)
	{
		printf("%d\n",ptr->data);
		ptr=ptr->next;
	}
}
//insert node at any point-----------------
void insert_mid()
{
	int n;
	printf("enter the level \n");
	scanf("%d",&n);
	struct node *new_node=head;
	struct node *new=(struct node *)malloc(sizeof(struct node));
	while(new_node->data!=n)
	{
		new_node=new_node->next;
	}
	printf("enter the value of data\n");
	scanf("%d",&new->data);
	new->next=new_node->next;
	new_node=new;
		printf("new traverse node\n");
	newTraverse(head);

}
//insert at the end---------------
void insert_end()
{
	struct node *new_node=(struct node *)malloc(sizeof(struct node ));
	printf("enter the value of data\n");
	scanf("%d",&new_node->data);
	new_node->next=NULL;
	struct node *new=head;
	while(new->next)
	{
		new=new->next;
	}
	new->next=new_node;
	printf("new traverse node\n");
	newTraverse(head);

}
int main(int argc, char const *argv[])
{
	char ch;
	printf("do you want create node\n");
	scanf("%c",&ch);
	if(ch=='y' ||ch=='Y')
	{
		create();
		printf("traversing the data\n");
		traverse();
		printf("Insert node at beginning\n");
		insert();
		printf("insert node at mid\n");
		insert_mid();
		printf("insert node at end\n");
		insert_end();
	}
	else
		return 0;
}