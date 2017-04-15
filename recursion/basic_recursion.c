#include<stdio.h>

void recursion(int n)
{
	if(n>=1)
	{
		recursion(n-1);
		printf("%d",n );
		recursion(n-1);
	}
}
int main(int argc, char const *argv[])
{
	int n=4;
	recursion(n);
	return 0;
}