/*
Group no.: A41
Anuj Kharbanda 2017B4A71508H
Kshitij Verma 2017B1A71145H
Keshav Beriwal 2017B4A71301H
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "modifiedDay1.h"
#include "day3.h"
node* parseTree(char post_exp[])
{	
	node *t;							//declaring 't' as node*(structure containing value of node, pointer to left subtree, and pointer to right subtree)
	int max=  strlen(post_exp);			//maximum length of the input expression

	node* stack[100];					//declaring stack of type node*
	int stackPointer = -1;				//Initialize the pointer to point to -1 as it is empty.
	
	for(int i=0;i<max;i++)
	{
		if(post_exp[i]=='V'||post_exp[i]=='>'||post_exp[i]=='^')
		{
			node * a = (node* ) malloc(sizeof( node* ));    	/*to allocate block of memory for 'a'(of type node*(structure containing value of node, 																	pointer to left subtree, and pointer to right subtree))*/
			a->left = NULL;										//initializing pointer to left subtree as NULL
			a->right = NULL;									//initializing pointer to right subtree as NULL
			node *rightOperand= top(stack,max,stackPointer);	//storing top element of stack in rightOperand		
			
			pop(stack,max,&stackPointer);						//removing it from stack
			node * leftOperand = top(stack,max,stackPointer);	//storing next element of stack in leftOperand			
			
			pop(stack,max,&stackPointer);						//removing it from stack
			a->ch = post_exp[i];								//assigning the operator(i.e., post_exp[i]) as value of node for a
			a->left = leftOperand;								//assigning leftOperand as left child of a
			a->right= rightOperand;								//assigning rightOperand as right child of a
			push(stack,max,&stackPointer,a);					//pushing the current node again
		}
		else if(post_exp[i]!='V'&&post_exp[i]!='>'&&post_exp[i]!='^'&&post_exp[i]!='~')
		{
			node * a = (node* )malloc(sizeof( node* ));			/*to allocate block of memory for 'a'(of type node*(structure containing value of node, 																	pointer to left subtree, and pointer to right subtree))*/
			a->left = NULL;										//initializing pointer to left subtree as NULL
			a->right = NULL;									//initializing pointer to right subtree as NULL
			a->ch = post_exp[i];								//assigning the operand(i.e., post_exp[i]) as value of node for a
			push(stack,max,&stackPointer,a);					//pushing the current node again
		}	
		else if(post_exp[i]=='~')
		{
			node * a = (node* )malloc(sizeof( node* ));			/*to allocate block of memory for 'a'(of type node*(structure containing value of node, 																	pointer to left subtree, and pointer to right subtree))*/
			a->left = NULL;										//initializing pointer to left subtree as NULL
			a->right = NULL;									//initializing pointer to right subtree as NULL
			node *rightOperand= top(stack,max,stackPointer);	//storing top element of stack in rightOperand
			pop(stack,max,&stackPointer);						//removing it from stack
			node *leftOperand = NULL;							//storing NULL in leftOperand as ~ have only right subtree
			a->ch = post_exp[i];								//assigning '~'(i.e., post_exp[i]) as value of node for a
			a->left = NULL;
			a->right = rightOperand;							//assigning rightOperand as right child of a
			push(stack,max,&stackPointer,a);					//pushing the current node again
		}

	}
	
	t=top(stack,max,stackPointer);				//top of the stack, i.e., the root of the parse tree
	pop(stack,max,&stackPointer);
	return t;
}
void inorder(node * root)/*!< pointer to the root where where u want to start the traversal */
{
	/*This is how the function works-
	 Inorder traversal of the parse tree from root*/

    if (!(root->left== NULL && root->right==NULL))
        printf("(");								/*printing '(' at the start of the expression when either of the left or right subtree exists, i.e., it 														is not an atom*/
    if(root->left!=NULL)
         inorder(root->left);						//if the left subtree is not NULL, then making recursive calls to it
    printf("%c",root->ch);							//printing the value of the curreent node
    if(root->right!=NULL)
        inorder(root->right);						//if the right subtree is not NULL, then making recursive calls to it
    if (!(root->left== NULL && root->right==NULL))
        printf(")");

								/*printing ')' at the end of the expression when either of the left or right subtree exists, i.e., it 															is not an atom*/
}
