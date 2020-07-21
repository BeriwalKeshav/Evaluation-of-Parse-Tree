node *impl_free(node *root);
{

    if (!(root->left== NULL && root->right==NULL))								/*printing '(' at the start of the expression when either of the left or right subtree exists, i.e., it 														is not an atom*/
         impl_free(root->left);						//if the left subtree is not NULL, then making recursive calls to it
    if(root->ch=='>')
    {
    	root->ch=='V';
    	    node * a = (node* ) malloc(sizeof( node* ));    	/*to allocate block of memory for 'a'(of type node*(structure containing value of node, 																	pointer to left subtree, and pointer to right subtree))*/
			a->left =NULL;										//initializing pointer to left subtree as NULL
			a->right = root->left;
			a->ch='~';
		root->left=a;
    }							//printing the value of the curreent node
    if(root->right!=NULL)
        impl_free(root->right);
        ret					//if the right subtree is not NULL, then making recursive calls to i	
}