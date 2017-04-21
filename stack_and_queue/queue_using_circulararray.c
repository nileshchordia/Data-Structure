#include<stdio.h>
#define MAX 4

int array[MAX];
int front=-1,rear=-1;

//enqueue-----insert the element to the queue----------
void enqueue(int data)
{
	rear=(rear+1)%MAX;
	if(rear==front)
	{
		printf("overflow\n");
		if(rear==0)
		{
			rear=MAX-1;
		}
		else
		{
			rear=rear-1;
		}
		return;

	}
	array[rear]=data;

}


//dequeue -----delete element from the queue------------
int dequeue()
{
	if(front==rear)
	{
		printf("underflow\n");
		return -1;
	}
	

	front=(front+1)%MAX;


	int item=array[front];
	return item;

}

int main(int argc, char const *argv[])
{
	enqueue(4);
	enqueue(7);
	enqueue(9);
	printf("%d\n",dequeue());  	//output is 4
	printf("%d\n",dequeue());	//output is 7
	enqueue(12);
	printf("%d\n",dequeue());	//output is 9
	enqueue(5);
	printf("%d\n",dequeue());	//output is 12
	printf("%d\n",dequeue());	//output is 5
	return 0;
}