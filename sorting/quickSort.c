#include <stdio.h>

int partition(int *a,int p,int r)
{
	int temp;
	int key=a[r];
	int j=p;
	int i=j-1;
	for(j;j<r;j++)
	{
		if(a[j]<=key)
		{

			temp=a[++i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[++i];
	a[i]=key;
	a[r]=temp;
	return i;

}
void quickSort(int *a,int p,int r)
{
	if(p<r)
	{
		int q=partition(a,p,r);
		// printf("q=%d\n",q );
		quickSort(a,p,q-1);
		quickSort(a,q+1,r);
	}
}
int main(int argc, char const *argv[])
{
	int n;
	printf("enter the size of array\n");
	scanf("%d",&n);


	int a[n];
	printf("Enter the value of element\n");
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);

	quickSort(a,1,n);

	printf("After sorting\n");
	for(int i=1;i<=n;i++)
		printf("%d\t",a[i] );

	printf("\n");

	return 0;
}


// Time Complexity---------------------orderof(nlogn)(bestcase)--------orderof(n*n)(worst case(ascending order,descending order,all elements are same))
// Space Complexity---------------------orderof(logn)(best case(balanced))---------(unbalanced)orderof(n)(worst case)-----------