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

//inorder traversal---------
void inorder(struct node *node)
{
	if(node)
	{
		inorder(node->left);
		printf("%d\n",node->data );
		inorder(node->right);
	}
}



//searching the element-----
void search(struct node* node,int data)
{
	if(node)
	{
		if(data==node->data)
		{
			printf("Yes, this element is present\n");
			return;
		}

		else if(data>node->data)
			search(node->right,data);
		else if(data<node->data)
			search(node->left,data);

	}
	else
 		printf("No, this elemnet is not present in tree\n");

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
	printf("inorder traversal ----\n");
	inorder(root);
	printf("searching the element------\n");
	search(root,40);
	return 0;
}
//time complexity ----orderof(n)--for inorder-traversal
//space complexity---orderof(n)--for inorder-tarversal

//time complexity ----orderof(log(n))--for searching the element(BST)