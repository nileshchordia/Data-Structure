#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left,*right;
};

struct node* newNode(int data)
{
	struct node *p=(struct node*)malloc(sizeof(struct node));
	p->data=data;
	p->left=NULL;
	p->right=NULL;

	return p;
}

struct node* insert(struct node* node,int data)
{
	if(node==NULL)
	{
		return newNode(data);
	}

	if(data<node->data)
		node->left=insert(node->left,data);
	else if(data>node->data)
		node->right=insert(node->right,data);


	return node;
}


//fuction of count the no. of full node from above tree----
int fullNode(struct node* t)
{	if(!t)
		return 0;

	if(!t->left && !t->right) //t->left==NULL && t->right==NULL
		return 0;

	int l=fullNode(t->left);
	int r=fullNode(t->right);
	int x=(t->left && t->right)?1:0;  //backbone of this code----remember
	return l+r+x;
}



int main(int argc, char const *argv[])
{
	struct node* root=NULL;
	root=insert(root,50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);
	printf("counting the number of full-node---\n");
	int value=fullNode(root);
	printf("no. of full-node=%d\n", value);

	return 0;
}

//time complexity-----orderof(n)---
//space complexity----orderof(n)---