#include<stdio.h>

void insertsort(int *p,int n)
{
	// for(int j=1;j<=n;j++)
	// {
	// 	printf("%d\t",p[j]);
	// }
	for(int j=2;j<=n;j++)
	{
		int i=j-1;
		int key=p[j];
		while(i>0 && p[i]>key)
		{
			p[i+1]=p[i];
			i--;
		}
		p[i+1]=key;
	}
	for(int j=1;j<=n;j++)
	{
		printf("%d\t",p[j]);
	}
}

int main(int argc, char const *argv[])
{
	int n,i=1;
	printf("enter the no. of element \n");
	scanf("%d",&n);
	int num=n;
	int a[num];
	while(num)
	{
		scanf("%d",&a[i]);
		i++;
		num--;
	}
	insertsort(a,n);
	return 0;
}

//time complexity====n**2
//space complexity====constant