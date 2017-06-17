#include <stdio.h>





int min_heapify(int *a,int i,int len)
{
	int l=2*i;
	int r=2*i+1;
	int smallest,temp;
	if(l>len)
		return 0;
	if(l<=len && a[l]<a[i])
		smallest=l;
	else
		smallest=i;
	if(r<=len && a[r]<a[smallest])
		smallest=r;
	if(smallest!=i)
	{
		temp=a[smallest];
		a[smallest]=a[i];
		a[i]=temp;
		min_heapify(a,smallest,len);
	}
}


void build_min_heap(int *a,int len)
{
	for (int i = len/2; i >0; --i)
		/* code */min_heapify(a,i,len);
}
int main(int argc, char const *argv[])
{
	int n;
	printf("enter the number of elements has to be enterd in heap\n");
	scanf("%d",&n);
	int a[n];
	for (int i = 1; i <=n; ++i)
		scanf("%d",&a[i]);
	build_min_heap(a,n);
	for (int i = 1; i <=n; ++i)
		printf("%d\t",a[i]);
	printf("\n");
	return 0;
}



//Time complexity----------orderof(n)---(build min heap)
//space complexity---------orderof(logn)


// NOTE --------time complexity----if only for minheapify is ---------orderof(logn)
//---------------space complexity-------------------------------------orderof(logn)