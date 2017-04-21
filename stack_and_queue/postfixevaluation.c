//postfix evaluation for 1 digit (1 to 9) and binary operator--------
#include<stdio.h>
#include<string.h>
#define MAX 20


//stack for storing operand--------------
int stack[MAX];
int top=-1;

//evaluate for operator-------------
int evaluate(int a,int b,char ch)
{
	printf("a=%d\tb=%d\n",a,b);
	switch(ch)
	{
		case '+':return a+b;
		case '-':return a-b;
		case '*':return a*b;
		case '/':return a/b;
	}
	
}

//postfix evalution-------------
int postfixEvaluation(char *exp)
{
	for(int i=0;i<strlen(exp);i++)
	{
		if(exp[i]>='1' && exp[i]<='9')
		{
			stack[++top]=exp[i];
		}
		else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='*')
		{
			char temp2=stack[top--];
			char temp1=stack[top--];
			temp2=temp2-'0';
			temp1=temp1-'0';
			
			int  new=evaluate(temp1,temp2,exp[i]);
			new=new+'0';
			stack[++top]=new;
		}
	}
	int final=stack[top--];
	return final-'0';
}



//main-------------------
int main(int argc, char const *argv[])
{
	char exp[]="312*+";		//evaluate from infix_to_postfix.c---3+1*2
	int value=postfixEvaluation(exp);
	printf("%d\n",value);
	return 0;
}