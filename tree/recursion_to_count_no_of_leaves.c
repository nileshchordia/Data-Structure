#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left,*right;
};

struct node* newnode(int data)
{	
	struct node *p=(struct node*)malloc(sizeof(struct node));
	p->data=data;
	p->left=NULL;
	p->right=NULL;

	return p;
}



struct node* insert(struct node *node,int data)
{
	if(node==NULL)
		return newnode(data);


	if(data<node->data)
		node->left=insert(node->left,data);
	else if(data>node->data)
		node->right=insert(node->right,data);


	return node;

}

//function of count the no. of leaf from given tree----

int leaf(struct node *p)
{
	if(p)
	{
		if(!p->left && !p->right)
			return 1;
		else
			return leaf(p->left)+leaf(p->right);
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
	printf("counting the leaf node of above tree---\n");
	int value=leaf(root);
	printf("leaf node=%d\n",value );
	return 0;
}

//time complexity-----orderof(n)---
//space complexity----orderof(n)---