#include<stdio.h>
#include<stdlib.h>


int main(int argc, char const *argv[])
{
	int n;
	printf("enter the number of elements is entered in array\n");
	scanf("%d",&n);
	int a[n];
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);


	int i,j;

	printf("Left Childrens\n");
	for(j=1;j<=n/2;j++)
		printf("%d\n",a[j*2]);


	printf("Right Childrens\n");
	for(i=1;i<=n/2;i++)
		printf("%d\n",a[i*2+1]);
	

	return 0;
}