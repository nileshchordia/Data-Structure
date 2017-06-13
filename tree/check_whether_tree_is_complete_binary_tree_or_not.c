//Assumption----------complete binary tree ->node have either 0 or 2 children
//					  Full binary tree ->level must be same,only last level has leaf node
//					  node is NULL then it is also complete binary tree.

#include<stdio.h>
#include<stdlib.h>



struct node 
{
	int data;
	struct node *left,*right;
};

struct node * newnode(int data)
{
	struct node *p=(struct node *)malloc(sizeof(struct node));
	p->data=data;
	p->left=NULL;
	p->right=NULL;
	return p;
}


struct node *insert(struct node *p,int data)
{
	if(!p)
		return newnode(data);
	else if(data<p->data)
		p->left=insert(p->left,data);
	else
		p->right=insert(p->right,data);
	return p;
}

int iscomplete(struct node *p)
{
	if(!p)
		return 1;
	if(!p->left && !p->right)
		return 1;
	if(p->left && p->right)
		return iscomplete(p->left) && iscomplete(p->right);
	else
		return 0;

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
	// insert(root, 90);
	if(iscomplete(root))
		printf("Yes! It is complete binary tree\n");
	else
		printf("Nope! It is not complete binary tree\n");

	return 0;
}