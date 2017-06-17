#include<stdio.h>



int minHeapify(int *a,int i,int len)
{
	int l=2*i;
	int r=2*i+1;
	printf("%d\n",i );
	int smallest,temp;
	if(l>len)
		return 0;

	if(l<=len && a[l]<a[i])
		smallest=l;
	else
		smallest=i;

	if(l<=len && a[r]<a[smallest])
		smallest=r;

	if(smallest!=i)
	{	
		temp=a[smallest];
		a[smallest]=a[i];
		a[i]=temp;
		minHeapify(a,smallest,len);
	}


}
void buildMinHeap(int *a,int len)
{
	// int i=len/2+1;
	for(int i=len/2+1;i>=1;i--)
	{
		// printf("len=%d\n",len );
		minHeapify(a,i,len);
	}


}

int extractMax(int *a,int len)
{
	int i=len/2+1;
	// printf("i=%d\n",i );
	int max=0;
	for(i;i<=len;i++)
	{
		if(max<a[i])
			max=a[i];
	}
	return max;

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
	
	buildMinHeap(a,n);


	for(int i=1;i<=n;i++)
		printf("%d\t",a[i]);

	printf("\n");

	printf("maximum element in min heap= %d\n",extractMax(a,n));

	


	return 0;
}



// Time complexity -----------------orderof(n)
//space complexity------------------orderof(1)