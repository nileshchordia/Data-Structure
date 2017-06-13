#include<stdio.h>
#include<stdlib.h>


struct  node
{	
	int data;
	struct node *left,*right;;
	
};


struct node* newnode(int data)
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
		return newnode(data);
	if(data<node->data)
		node->left=insert(node->left,data);
	else if(data>node->data)
		node->right=insert(node->right,data);

	return node;
}


//find inorder successor--------
struct node * findmin(struct node *p)
{
	while(p->left)
		p=p->left;
	return p;
}



//deleting node--------------
struct node * delete(struct node *p,int value)
{
	if(p)
	{
		if(value<p->data)
			p->left=delete(p->left,value);
		else if(value>p->data)
			p->right=delete(p->right,value);
		else
		{
			if(p->left==NULL)
			{
						struct node *temp=p->right;
						free(p);
						return temp;
			}
			else if(p->right==NULL)
			{
						struct node *temp=p->left;
						free(p);
						return temp;
			}
			struct node *temp=findmin(p->right);
			p->data=temp->data;
			p->right=delete(p->right,temp->data);
		}
		return p;


	}
}



//traverse--------------

void inorder(struct node *p)
{
	if(p)
	{
		inorder(p->left);
		printf("%d\n",p->data );
		inorder(p->right);
	}
}
//main-----------
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
	// insert(root,90);
	printf("delete the leaf node\n");
	root=delete(root,80);
	inorder(root);
	printf("delete the node which have one child\n");
	root=delete(root,70);
	inorder(root); 
	printf("delete the node which have two child\n");
	root=delete(root,30);
	inorder(root); 
	return 0;
}