#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int stack[MAX];
int top=-1;


void push(int data)
{
	stack[++top]=data;
}

int pop()
{
	int item=stack[top--];
	return item;
}


void reverse()
{
	if(top>0)
	{
		int x=pop();
		reverse();
		push(x);
	}
	else
		printf("%d\n",stack[top--] );

}
int dequeue()
{
	reverse();
}
void enqueue(int data)
{
	push(data);
}


int main(int argc, char const *argv[])
{
	enqueue(1);
	enqueue(2);
	enqueue(3);
	dequeue();
	dequeue();
	enqueue(4);
	dequeue();
	dequeue();
	return 0;
}

