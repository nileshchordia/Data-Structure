#include <stdio.h>


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
		printf("NIlesh\n");
		maxheapify(a,largest,len);
	}
}



void heap_increase_key(int *a,int i,int key,int len)
{
	a[i]=key;
	// printf("%d\n",a[i] );
	while(i>=1)
	{
		i/=2;
	maxheapify(a,i,len);

	}
	
}

int main(int argc, char const *argv[])
{
	int n,j,key;
	printf("enter the number of elements has to be enterd in heap\n");
	scanf("%d",&n);
	int a[n];
	for (int i = 1; i <=n; ++i)//index start with 1----------
		scanf("%d",&a[i]);


	printf("enter index of node which has to be changed and incremented value\n ");
	scanf("%d%d",&j,&key);			//like node(index)=1 and value is 300
	// a[j]=key;
	heap_increase_key(a,j,key,n);

	for (int i = 1; i <=n; ++i)//index start with 1----------
		printf("%d\t",a[i]);

	printf("\n");
	return 0;
}

//Time complexity----------orderof(logn)
//space complexity---------orderof(1)