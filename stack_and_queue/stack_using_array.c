#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int stack[MAX];
int top=-1; 
//push element on the stack------------
void push(int data)
{
	if(top==MAX-1)
	{
		printf("overflow\n");
		return;
	}
	stack[++top]=data;

}

//pop element from the stack-------------

int pop()
{
	if(top==-1)
	{
		printf("underflow\n");
		return -1;
	}
	int temp=stack[top--];
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

//time complexity --orderof(1)