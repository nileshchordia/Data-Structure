//operations like extract,increase and insert into the heap----------------
#include<stdio.h>

int minHeapify(int *a,int i,int len)
{
	int l,r,smallest,temp;
	l=2*i;
	r=2*i+1;
	if(l>len)
		return 1;
	if(l<=len && a[l]<a[i])
		smallest=l;
	else
		smallest=i;
	if(r<=len && a[r]<a[smallest])
		smallest=r;
	if(smallest!=i)
	{
		temp=a[i];
		a[i]=a[smallest];
		a[smallest]=temp;
		minHeapify(a,smallest,len);
	}
}


int extractMin(int *a,int len)
{
	int temp;
	temp=a[1];
	a[1]=a[len--];
	// printf("Len=%d\n",len );
	minHeapify(a,1,len);
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
		printf("Minimum element of heap is %d\n",extractMin(a,n));

	return 0;
}

//Time complexity----------orderof(logn)
//space complexity---------orderof(logn)