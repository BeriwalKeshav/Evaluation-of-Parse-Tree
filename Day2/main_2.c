/*
Group no.: A41
Anuj Kharbanda 2017B4A71508H
Kshitij Verma 2017B1A71145H
Keshav Beriwal 2017B4A71301H
*/
#include<stdio.h>
#include "day2.h"

// main program to convert infix expression to postfix.
// author: Rashi Jain, 11/10/19

int main()
{
	char infix_exp[100];
	//scan the infix expression 
	scanf("%s", infix_exp);
	infixToPostfix(infix_exp); //The function will print the postFix expression. 
	return 0;
}
