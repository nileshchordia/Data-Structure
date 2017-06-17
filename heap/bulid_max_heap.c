#include<stdio.h>



int  max_heapify(int *a,int i,int len)
{
	int l=2*i;
	int r=2*i+1;
	int largest;
	if(l>len)
		return 0;
	if(l<=len && a[l]>a[i])
		largest=l;
	else
		largest=i;
	if(r<=len && a[r]>a[largest])
		largest=r;
	
	if(largest!=i)
	{
		// printf("NIlesh jain\n");
		int temp=a[largest];
		a[largest]=a[i];
		a[i]=temp;
		max_heapify(a,largest,len);
	}


}


void buid_max_heap(int *a,int len)
{

	for(int j=len/2;j>0;j--)
	{
		max_heapify(a,j,len);
	}


}


int main()
{
	int n;
	printf("enter the number of elements has to be enterd in heap\n");
	scanf("%d",&n);

	int a[n];
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);

	buid_max_heap(a,n);

	for(int i=1;i<=n;i++)
		printf("%d\n",a[i]);
	// max_heapify(a,3,n);



	return 0;
}


//Time complexity----------orderof(n)---(build max heap)
//space complexity---------orderof(logn)


// NOTE --------time complexity----if only for maxheapify is ---------orderof(logn)
//---------------space complexity-------------------------------------orderof(logn)