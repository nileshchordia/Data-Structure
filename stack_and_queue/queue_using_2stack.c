#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int stack1[MAX];
int stack2[MAX];



int top=-1; //ptr for stack1--------
int up=-1;  //ptr for stack2-----------

//push ---push element to the stack------
void push(int data)
{
	if(top==MAX-1)
	{
		printf("overflow\n");
		return;
	}
	stack1[++top]=data;
	// printf("top=%d\n",top);
}


//pop---- pop element from stack--------
int pop()
{
	int data;
	data=stack2[up--];
	return data;
}




//enqueue------- insert the element to the queue----------
void enqueue(int data)
{
	push(data);

}

//dequeue---- delete the element from the queue-----------
int dequeue()
{
	if(up==-1)
	{	
		if(top==-1)
		{
			printf("underflow\n");
			return -1;
		}
		else
		{
			while(top!=-1)
			{
				// printf("while top=%d\n",top);
				stack2[++up]=stack1[top--];

			}
		}

	}
	int x=pop();
	return x;
}

int main(int argc, char const *argv[])
{
	enqueue(5);
	enqueue(7);
	enqueue(9);
	printf("%d\n",dequeue());  //output is 5
	printf("%d\n",dequeue());	//output is 7
	enqueue(2);
	enqueue(12);
	printf("%d\n",dequeue());	//output is 9
	printf("%d\n",dequeue());	//output is 2
	printf("%d\n",dequeue());	//output is 12
	return 0;
}


//NOTE:-keep practising.You will success.Nothing will get with out hardwork.Be patience-------------