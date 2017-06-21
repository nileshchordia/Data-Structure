#include <stdio.h>


void bubbleSort(int *a,int n)
{
	int swapped,i,j,temp;
	for(i=0;i<n;i++)
	{
		swapped=0;
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				swapped=1;
			}

		}
		if(swapped==0)
			break;
	}

}
int main(int argc, char const *argv[])
{
	int n;
	printf("enter the length of array\n");
	scanf("%d",&n);
	int a[n];
	printf("enter the value of element\n");
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
	}
	bubbleSort(a,n);
	printf("After sorting\n");

	for (int i = 0; i < n; ++i)
	{
		printf("%d\t",a[i] );
	}
	printf("\n");
	return 0;
}

// Time Complexity---------------------orderof(n*n)(worst case)----orderof(n)(best case)----
// Space Complexity---------------------orderof(1)