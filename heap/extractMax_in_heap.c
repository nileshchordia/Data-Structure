//operations like extract,increase and insert into the heap----------------
#include<stdio.h>

int maxHeapify(int *a,int i,int len)
{
	int l,r,largest,temp;
	l=2*i;
	r=2*i+1;
	if(l>len)
		return 1;
	if(l<=len && a[l]>a[i])
		largest=l;
	else
		largest=i;
	if(r<=len && a[r]>a[largest])
		largest=r;
	if(largest!=i)
	{
		temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		maxHeapify(a,largest,len);
	}
}


int extractMax(int *a,int len)
{
	int temp;
	temp=a[1];
	a[1]=a[len--];
	// printf("Len=%d\n",len );
	maxHeapify(a,1,len);
	return temp;
}


int main(int argc, char const *argv[])
{
	int n;
	printf("enter the number of elements has to be enterd in heap\n");
	scanf("%d",&n);
	int a[n];
	for (int i = 1; i <=n; ++i)
		scanf("%d",&a[i]);

	for (n;n>0;--n)
		printf("Maximum element of heap is %d\n",extractMax(a,n));

	return 0;
}

//Time complexity----------orderof(logn)
//space complexity---------orderof(logn)