#include<stdio.h>
#include<stdlib.h>


struct node
{
	int data;
	struct node *left,*right;
};


struct node *newnode(int data)
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
	if(data>p->data)
		p->right=insert(p->right,data);
	else
		p->left=insert(p->left,data);

}


// finding minimmum element -----------
int findmin(struct node *p)
{
	while(p->left)
	{
		p=p->left;
	}
	return p->data;
}


//finding maximum element -------------
int findmax(struct node *p)
{
	while(p->right)
	{
		p=p->right;
	}
	return p->data;
}


int main(int argc, char const *argv[])
{
	struct node *root=NULL;
	root=insert(root,40);
	insert(root,15);
	insert(root,46);
	insert(root,42);
	insert(root,70);
	insert(root,60);
	insert(root,35);
	insert(root,80);
	printf("Minimum element is %d\n",findmin(root));
	printf("Maximum element is %d\n",findmax(root));
	return 0;
}


