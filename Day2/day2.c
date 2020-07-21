/*
Group no.: A41
Anuj Kharbanda 2017B4A71508H
Kshitij Verma 2017B1A71145H
Keshav Beriwal 2017B4A71301H
*/
#include<stdio.h>
#include<string.h>
#include"day2.h"
#include"day1.h"
void infixToPostfix(char infix_exp[])
{
	int max=strlen(infix_exp);//declare maximum number of characters in the stack.
	char stack[max];//declare a stack of max charaters.
	int stackPointer=-1;//Initialize the pointer to point to -1 as it is empty. 
	for(int i=0;infix_exp[i]!='\0';i++)//scanning the infix expression from left to right
	{
		if((infix_exp[i]!='~')&&(infix_exp[i]!='^')&&(infix_exp[i]!='>')&&(infix_exp[i]!='V')&&(infix_exp[i]!='(')&&(infix_exp[i]!=')'))
		{
			printf("%c",infix_exp[i]);				//printing operands
		}
		else if((infix_exp[i]=='~')||(infix_exp[i]=='^')||(infix_exp[i]=='>')||(infix_exp[i]=='V')||(infix_exp[i]=='('))
		{
			push(stack, max, &stackPointer, infix_exp[i]);			//pushing operators and '(' into the stack
		}
		else if(infix_exp[i]==')')
		{
			while(top(stack, max, stackPointer)!='(')
				{
					printf("%c", top(stack, max, stackPointer));	//printing the elements of stack
					pop(stack, max, &stackPointer);			//popping the elements of the stack
				}
			pop(stack, max, &stackPointer);			//popping the leftover element, i.e., '('
		}
	}
	printf("\n");  
}
