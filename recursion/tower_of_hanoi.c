#include <stdio.h>
#include <stdlib.h>

void towerOfHanoi(int n,char firstrod,char secondrod, char thirdrod)
{
	if(n>=1)
	{
		towerOfHanoi(n-1,firstrod,thirdrod,secondrod);
		printf("disc %d is moving from %c to %c\n",n,firstrod,secondrod);
		towerOfHanoi(n-1,thirdrod,secondrod,firstrod);
	}
}
int main(int argc, char const *argv[])
{
	int n;
	printf("enter the no. of disc\n");
	scanf("%d",&n);
	towerOfHanoi(n,'A','B','C');//A,B,C are name of rods-----------

	return 0;
}


//2**n-1 moves------
//2**(n+1)-1 functions invocations-----------
//time complexity---2**n
//space complexity---n
//NOTE:-no. of invocation is too much.to reduce it.if disc is 1 then directly move it.instead of n is greater than and equal to 1 write n greater than 1