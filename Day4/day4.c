/*
Group no.: A41
Anuj Kharbanda 2017B4A71508H
Kshitij Verma 2017B1A71145H
Keshav Beriwal 2017B4A71301H
*/

#include<stdio.h>
#include"modifiedDay1.h"
#include"day4.h"

int evalParseTree(node *root, char var[], int value[], int n) // Recursive Function to Evaluate the Parse Tree
{
static int gg=1; // Variable to go to next line after printing inflix Expression.
if(gg==1)
{
printf("\n");
gg++;
}

	if( root == NULL ) // Checking if there is a root node.
        return -1;

	else if( root ->left == NULL && root->right == NULL) // Checking if the left child of a node is NULL and Right child of node is NULL
    {
        int i;
        for( i = 0;i<n;i++)
            if( var[i] == root->ch)  
                break;
        return value[i]; // The FUnction returns value of operand.
    }
    int a =  evalParseTree( root->left ,var, value,n);  // Recursive call to the function evalParseTree.
    int b = evalParseTree( root->right , var,value,n);  // Recursive call to the function evalParseTree.
    if( root->ch == 'V')
        return (a|b); 					// Returning "OR" of two operands.
    else if( root->ch == '^')
        return ( a&b); 					// Returns "AND" of two operands.			
    else if( root->ch == '>')				// Returning "Implication" of two operand.
    {
        if( a == 0 || b == 1)
            return 1;
        else if( a== 1 && b== 0)
            return 0;
    }
    else if( (root->ch == '~') && (a==-1))		// Returns Negation of the operand.
        return (!b);
    
 }
