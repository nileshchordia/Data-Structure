#include<stdio.h>

void merge(int *a,int p,int q,int r)
{
	int n1=q-p+1;
	int n2=r-q;
	int L[n1+1];
	int R[n2+1];

	for(int i=1;i<=n1;i++)
	{
		L[i]=a[p+i-1];
		// printf("L[i]=%d\n",L[i] );
		// R[i]=a[i+q];
	}
	for(int j=1;j<=n2;j++)
	{
		R[j]=a[j+q];
		// printf("R[j]=%d\n",R[j] );
	}


	L[n1+1]=60000;  ///infinty value----------
	R[n2+1]=60000;	///infinty value----------


	int i=1,j=1;
	for(int k=p;k<=r;k++)
	{
		if(L[i]<=R[j])
		{
			// printf("%d\n",L[i] );
			a[k]=L[i];
			i++;
		}
		else
		{
			a[k]=R[j];
			// printf("%d\n",R[j] );
			j++;
		}
	}
	// for(int k=p;k<=r;k++)
		// printf("a[%d]=%d\n",k,a[k] );


}
void mergeSort(int *a,int p,int r)
{
	if(p<r)
	{
		int q=(p+r)/2;
		// printf("%d\t%d\t%d\n",p,q,r);
		mergeSort(a,p,q);
		mergeSort(a,q+1,r);
		merge(a,p,q,r);
	}
}


int main(int argc, char const *argv[])
{
	int n;
	printf("Enter the length of array\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter the element\n");
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);


	mergeSort(a,1,n);
	printf("After sorting\n");
	for(int i=1;i<=n;i++)
		printf("%d\n",a[i]);
	return 0;
}

// Time Complexity---------------------orderof(nlogn)
// Space Complexity---------------------orderof(n)