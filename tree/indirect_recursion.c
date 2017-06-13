#include<stdio.h>
#include<stdlib.h>



struct node{
	int data;
	struct node *left,*right;
};


void B(struct node *p);
void A(struct node *p);

struct node* newnode(int data)
{
	struct node *p=(struct node*)malloc(sizeof(struct node));
	p->data=data;
	p->left=NULL;
	p->right=NULL;
}

struct node* insert(struct node* node,int data)
{
	if(node==NULL)	
		return newnode(data);


	if(data<node->data)
		node->left=insert(node->left,data);
	else if(data>node->data)
		node->right=insert(node->right,data);

	return node;
}

void A(struct node *p)
{
	if(p)
	{
		printf("%d\n",p->data );
		B(p->left);
		B(p->right);
	}
}

void B(struct node *p)
{
	if(p)
	{
		A(p->left);
		printf("%d\n",p->data);
		A(p->right);
	}
}

int main(int argc, char const *argv[])
{
	struct node *root=NULL;
	root=insert(root,50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);
	printf("indirect recursion----A->B->A\n");
	A(root);
	return 0;
}