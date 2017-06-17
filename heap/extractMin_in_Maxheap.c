#include<stdio.h>



int maxHeapify(int *a,int i,int len)
{
	int l=2*i;
	int r=2*i+1;
	// printf("%d\n",i );
	int largest,temp;
	if(l>len)
		return 0;

	if(l<=len && a[l]>a[i])
		largest=l;
	else
		largest=i;

	if(l<=len && a[r]>a[largest])
		largest=r;

	if(largest!=i)
	{	
		temp=a[largest];
		a[largest]=a[i];
		a[i]=temp;
		maxHeapify(a,largest,len);
	}


}
void buildMaxHeap(int *a,int len)
{
	// int i=len/2+1;
	for(int i=len/2+1;i>=1;i--)
	{
		// printf("len=%d\n",len );
		maxHeapify(a,i,len);
	}


}

int extractMin(int *a,int len)
{
	int i=len/2+1;
	// printf("i=%d\n",i );
	int min=60000;  //any maximum  value------------------
	for(i;i<=len;i++)
	{
		if(min>a[i])
			min=a[i];
	}
	return min;

}

int main(int argc, char const *argv[])
{
	int n;
	printf("enter the size of heap\n");
	scanf("%d",&n);
	// printf("%d\n",n);

	int a[n];
	printf("Enter the element\n");
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		// printf("%d\n",i );
	}
	
	buildMaxHeap(a,n);


	for(int i=1;i<=n;i++)
		printf("%d\t",a[i]);

	printf("\n");

	printf("minimum element in max heap= %d\n",extractMin(a,n));

	


	return 0;
}



// Time complexity -----------------orderof(n)
//space complexity------------------orderof(1)