#include<stdio.h>




int maxheapify(int *a,int i,int len)
{
	int l,r,temp,largest;
	l=2*i;
	r=2*i+1;
	if(l>len)
		return 0;
	if(l<=len &&a[l]>a[i])
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
		// printf("NIlesh\n");
		maxheapify(a,largest,len);
	}
}

void heapSort(int *a,int len)
{
	if(len>0)
	{
		int temp;
		temp=a[len];
		a[len--]=a[1];
		a[1]=temp;
		maxheapify(a,1,len);
		heapSort(a,len);
	}
}


int main(int argc, char const *argv[])
{
	int n,j,key;
	printf("enter the number of elements to insert in heap\n");
	scanf("%d",&n);

	int a[n];

	printf("enter the element in order of maxheap\n");
	for (int i = 1; i <=n; ++i)//index start with 1----------
		scanf("%d",&a[i]);

	heapSort(a,n);

	printf("Sorting here in ascending order\n");
	for(int i=1;i<=n;i++)
		printf("%d\t",a[i] );
	printf("\n");


	return 0;
}

// Time complexity---------orderof(log(n))
///space complexity----------orderof(n)