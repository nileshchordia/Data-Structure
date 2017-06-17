#include<stdio.h>
#define MAX 10
int n=1;

int a[MAX];

void heap(int parentnode,int n)
{
	int temp;
	if(parentnode>0)
	{
		if(a[parentnode]>a[n])
		{
			temp=a[parentnode];
			a[parentnode]=a[n];
			a[n]=temp;
			heap(parentnode/2,parentnode);
		}
	}
}

void insert(int key)
{
	int parentnode,temp;
	a[n]=key;
	parentnode=n/2;
	printf("n=%d\n",n );
	heap(parentnode,n);
	n+=1;
}




int main(int argc, char const *argv[])
{
	int ch=7;
	int count=1,key;
	while(ch)
	{
		printf("Insert the key\n");
		printf("enter the value\n");
		scanf("%d",&key);
		insert(key);
		count++;
		ch--;
	}


	for(int i=1;i<count;i++)
		printf("%d\t",a[i]);


	printf("\n");
	return 0;
}


//Time complexity----------orderof(logn)
//space complexity---------orderof(logn)