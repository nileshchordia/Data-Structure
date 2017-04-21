#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * next;
}*head=NULL;

//push element on the stack-------
void push(int i)
{
	struct node *p=(struct node *)malloc(sizeof(struct node));
	p->data=i;
	p->next=head;
	head=p;


}

//pop element from stack----------

int pop()
{
	int temp;
	struct node *p;
	if(head==NULL)
	{
		printf("underflow\n");
		return -1;
	}
	temp=head->data;
	p=head;
	head=head->next;
	free(p);
	return temp;

}


int main(int argc, char const *argv[])
{
	push(1);
	push(3);
	printf("pop is %d\n",pop());  //output is 3
	push(5);
	printf("pop is %d\n",pop());	//output is 5
	push(7);
	push(9);
	printf("pop is %d\n",pop());	//output is 9
	printf("pop is %d\n",pop());	//output is 7
	printf("pop is %d\n",pop());	//output is 1
	return 0;
}

//time complexity ----orderof(1)