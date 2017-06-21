// This type of sorting is applied for given range like (1 to 5)

#include <stdio.h>
void countingSort(int *a,int *b,int k,int n)
{
	int c[k];
	for(int i=1;i<=k;i++)
		c[i]=0;
	for(int i=1;i<=n;i++)
	{
		c[a[i]]=c[a[i]]+1;
	}
	for(int j=2;j<=k;j++)
		c[j]=c[j-1]+c[j];
	for(int i=n;i>0;i--)
	{
		b[c[a[i]]]=a[i];
		c[a[i]]=c[a[i]]-1;
	}
	// for(int )
}

int main(int argc, char const *argv[])
{
	int n,range;
	printf("Enter the end value of range starting from 1\n");
	scanf("%d",&range);
	printf("Enter the size of array\n");
	scanf("%d",&n);
	int a[n],b[n];
	printf("Enter the value\n");
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);

	countingSort(a,b,range,n);
	printf("After sorting\n");
	for(int i=1;i<=n;i++)
		printf("%d\t",b[i] );

	printf("\n");
	return 0;


// time complexity----------orderof(n+k)------
// space complexity------------orderof(k)-------------
//It is also called stable sorting algorithm--------it preserve order of keys------