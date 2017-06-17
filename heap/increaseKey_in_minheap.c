#include<stdio.h>



int minheapify(int *a,int i,int len)
{
	int l,r,temp,smallest;
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
		minheapify(a,smallest,len);
	}
}
void heapDecreaseKey(int *a,int i,int key,int len)
{
	a[i]=key;
	printf("a[i]=%d\n",a[i] );
	minheapify(a,i,len);
}


int main(int argc, char const *argv[])
{
	int n,j,key;
	printf("enter the number of elements has to be enterd in heap\n");
	scanf("%d",&n);

	int a[n];
	for (int i = 1; i <=n; ++i)//index start with 1----------
		scanf("%d",&a[i]);


	printf("enter index of node which has to be changed and decremented value\n ");
	scanf("%d%d",&j,&key);			//like node(index)=1 and value is 300

	heapDecreaseKey(a,j,key,n);
	for (int i = 1; i <=n; ++i)//index start with 1----------
		printf("%d\t",a[i]);


	printf("\n");
	return 0;
}




//Time complexity----------orderof(logn)
//space complexity---------orderof(1)