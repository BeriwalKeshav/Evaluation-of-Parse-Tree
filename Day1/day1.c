/*
Group no.: A41
Anuj Kharbanda 2017B4A71508H
Kshitij Verma 2017B1A71145H
Keshav Beriwal 2017B4A71301H
*/
#include<stdio.h>
#include"day1.h"
void push(char stack[], int max, int *stackPointer, char value)
{
		if(*stackPointer!=(max-1)) 
			stack[++(*stackPointer)]=value;
		// increment stackpointer by 1, value goes to new position of the stackpointer in the stack array
		else
			printf("Stack is full, given item cannot be added\n");
			
}

void pop(char stack[], int max, int *stackPointer)
{
	if((*stackPointer)!=-1)
		*stackPointer=*stackPointer-1;
	 // decrement stackpointer by 1, that is 	
    	else
    		printf("The stack is empty\n");
}

int isEmpty(char stack[], int max, int stackPointer)
{
	if(stackPointer==-1) //checks if there is no element in the stack, that is when the stack is empty stackpointer is -1 
		return 1;
	else
		return 0;
}

int isFull(char stack[], int max, int stackPointer)
{
	if(stackPointer==(max-1)) //checks if the stack is full, that is when the stack is full stackpointer is max-1 
		return 1;
	else
		return 0;
}

char top(char stack[], int max, int stackPointer)
{
		if(stackPointer==-1)
		{
			printf("Stack is empty");
			return 0;
		}
		return stack[stackPointer]; // return top element of the stack as stackPointer points to top element
}
