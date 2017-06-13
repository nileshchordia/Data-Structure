#include<stdio.h>
#include<stdlib.h>

struct node
{
	int item;
	struct node *left;
	struct node *right;
};

//newnode-------------
struct node* newnode(int item)
{
	struct node *p=(struct node *)malloc(sizeof(struct node));
	p->item=item;
	p->left=NULL;
	p->right=NULL;
	return p;
}


//insert newnode-----------
struct node* insert(struct node* node,int item)
{
	if(node==NULL)
		return newnode(item);


	if(item<node->item)
		node->left=insert(node->left,item);
	else if(item>node->item)
		node->right=insert(node->right,item);

	return node;


}
//Inorder------------left-->root->right
void inOrder(struct node *p)
{
	if(p!=NULL)
	{
		inOrder(p->left);
		printf("%d\t",p->item);
		inOrder(p->right);
	}
}


//preOrder-----------root-->left-->right
void preOrder(struct node *p)
{
	if(p)
	{
		printf("%d\t",p->item);
		preOrder(p->left);
		preOrder(p->right);
	}



}


//postOrder-------left-->right-->root
void postOrder(struct node *p)
{
	if(p)
	{
		postOrder(p->left);
		postOrder(p->right);
		printf("%d\t",p->item);
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
	printf("InOrder Traversal------\n");
	inOrder(root);
	printf("\n");
	printf("PreOrder Traversal------\n");
	preOrder(root);
	printf("\n");
	printf("PostOrder Traversal------\n");
	postOrder(root);
	printf("\n");
	return 0;
}

//space complexity------orderof(n)--for each traversal
//time complexity----------orderof(n)--for each traversal