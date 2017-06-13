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

//function of finding the height of tree---------

int height(struct node* p)
{
	if(p)
	{
		if(!p->left && !p->right)
			return 0;

		int l=height(p->left);
		int r=height(p->right);
		int x=(l>r)?l:r;
		return 1+x;
	}
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
	printf("height of tree--\n");
	int value=height(root);
	printf("height = %d\n",value);

	return 0;
}


//time complexity-----orderof(n)---
//space complexity----orderof(n)---