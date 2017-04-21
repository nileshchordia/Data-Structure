#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20

//stack for operator----------
int stack[MAX];
int top=-1;



//priority of operators-------------
int priority(char ch)
{
	if(ch=='+'||ch=='-')
		return 1;
	else if(ch=='*'||ch=='/')
		return 2;
	else
		return -1;
}


//infixToPostfix-------------------
void infixToPostfix(char *a)
{
	for(int i=0;i<strlen(a);i++)
	{
		if((a[i]>='1' &&a[i]<='9')||(a[i]>='A' && a[i]<='Z')||a[i]>='a' &&a[i]<='z')
			printf("%c",a[i]);
		else if(a[i]=='(')
			stack[++top]=a[i];
		else if(a[i]==')')
		{
			while(stack[top]!='(')
			{
				printf("%c",stack[top--]);
			}
			top--;
		}
		else
		{
			while(priority(a[i])<=priority(stack[top]))
			{
				printf("%c",stack[top--]);
			}
			stack[++top]=a[i];
		}
	}
	while(top!=-1)
	{
		printf("%c",stack[top--] );
	}
}


//main-----------
int main(int argc, char const *argv[])
{
	char a[]="6*5+2";
	infixToPostfix(a);
	return 0;
}



//stack is used for pushing operators---------it is called stack operator.
//time complexity -----------orderof(n)
//space complexity---------------orderof(n)