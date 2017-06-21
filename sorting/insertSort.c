#include<stdio.h>

void insertSort(int *a,int len)
{
	for(int j=1;j<len;j++)
	{
		int key=a[j];
		int i=j-1;
		while(i>-1 && a[i]>key)
		{
			a[i+1]=a[i];
			i-=1;
		}
		a[i+1]=key;
	}
}


int main(int argc, char const *argv[])
{
	int n;
	printf("Enter the length of array\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter the element\n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);

	insertSort(a,n);
	printf("After sorting\n");
	for(int i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
	return 0;
}

// Time Complexity---------------------orderof(n*n)
// Space Complexity---------------------orderof(1)