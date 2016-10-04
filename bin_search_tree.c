/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Allen Bui | X339Y958														 *
 * Note: Original BST Data Structure implemented in CS300					 *
 * CS721 Homework 1 takes the original CS300 BST 							 *
 * data structure adds the AVL property										 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bin_search_tree.h"


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * tree_make_node : makes a new node with malloc. sets its key to k, its parent to parent, and its
 *                  left and right children to NULL.
 *
 * Parameters : int a which is the key of interest
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int key_is_equal( int a, int b ) // Returns true (1) if the two keys are equal, or false (0) otherwise.
{
    if ( a == b )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * key_less_than compares a & b. returns 1 if the
 * second parameter is greater than the first, 0 otherwise.
 *
 * Parameters : int a which is the first key value
 *              int b which is the second key value
 * Returns : int value : 1 if b is greater than a, 0 otherwise
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int key_less_than( int a, int b )
{
    if ( b > a )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * tree_init : initializes the tree
 *
 * Parameters : Node *n which is the node of interest
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void tree_init( Tree *t )
{
	( *t ) = NULL;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * tree_make_node : makes a new node with malloc. sets its key to k, its parent to parent, and its
 *                  left and right children to NULL.
 *
 * Parameters : Node *parent which is the parent node
 *              int k which is the key value of the new node
 * Returns : Node *n which is the pointer to the newly created node
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Node *tree_make_node( int k, Node *parent )
{
	Node *new_node;		//used to allocate memory to add to tree

	if ( ( new_node = ( malloc( sizeof( Node ) ) ) ) )
	{
		new_node->key = k; //key_set_equal( new_node->key, k );
		new_node->parent = parent;
		new_node->leftchild = NULL;
		new_node->rightchild = NULL;
        new_node->height = 1;
	}
	return new_node;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * tree_root : returns the root of t. (This is an identity function, included for complete- ness.)
 *             returns NULL if tree has no root
 *
 * Parameters : Tree *t which is the tree of interest
 * Returns : Node * which is the pointer to the root
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Node *tree_root( Tree t )
{
	return t;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * tree_parent : is a function that returns the parent of the node. returns NULL if the node
 *               is the root
 *
 * Parameters : Node *n which is the node of interest
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Node *tree_parent( Node *n ) //Returns the parent of n.
{
	return n->parent;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * tree_leftchild : is a function that returns the leftchild of the node. returns NULL if the node
 *                   does not have a leftchild
 *
 * Parameters : Node *n which is the node of interest
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Node *tree_leftchild( Node *n )
{
	return n->leftchild;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * tree_rightchild : is a function that returns the rightchild of the node. returns NULL if the node
 *                   does not have a rightchild
 *
 * Parameters : Node *n which is the node of interest
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Node *tree_rightchild( Node *n )
{
	return n->rightchild;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * tree_search : Returns the node in tree t whose key is k if it exists, or NULL if it doesn’t exist.
 *
 * Parameters : int k which is the integer key value we are looking for.
 *              Tree *t which is the tree we are traversing to search
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Node *tree_search( int k, Tree *t)
{
    Node * temp;

    if ( ( *t ) == NULL )
    {
		return NULL;
    }
    if ( key_is_equal( k, ( *t )->key ) )
    {
        return(*t);
    }
    else if ( key_less_than( k, ( *t )->key ) )
    {
		temp = tree_search( k, ( &( *t )->leftchild ) );
    }
    else
	{
		temp = tree_search( k, ( &( *t )->rightchild ) );
	}
    return temp;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * tree_num_children : Returns the number of children (0, 1 or 2) of node n.
 *
 * Parameters : Node *n which is the node of interest
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int tree_num_children( Node *n )
{
	if ( ( !( n->leftchild && n->rightchild ) ) && ( n->leftchild || n->rightchild ) ) //XOR
	{
		return 1;
	}
	if( n->leftchild && n->rightchild )
	{
		return 2;
	}
	else
	{
		return 0;
	}
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * tree_insert : Adds a node to the current tree. If the node exists, it returns 0.
 *               if the insertion succeeds, it returns 1.
 *
 * Parameters : Tree *t which is a pointer to the the tree
 *              int k which is the key we would like to delete
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int tree_insert( Tree *t, int k )
{
    int retVal;

	if ( ( *t ) == NULL )
	{
		( *t ) = ( tree_make_node( k, ( *t ) ) );
        retVal = 1;
	}
	else if ( key_is_equal( k, ( *t )->key ) )
	{
		return 0;
	}
	else if ( key_less_than( k, ( *t )->key ) )
	{
		if ( ( *t )->leftchild == NULL )
		{
			( *t )->leftchild = tree_make_node( k, ( *t ) );
            retVal = 1;
		}
		else
		{
			retVal = tree_insert( ( &( *t )->leftchild ), k );
		}
	}
	else /* key is greater than */
	{
		if ( ( *t )->rightchild == NULL )
		{
			( *t )->rightchild = tree_make_node( k, ( *t ) );
            retVal = 1;
		}
		else
		{
			retVal = tree_insert( ( &( *t )->rightchild ), k );
		}
	}

    ( *t )->height = 1 + findMax( getHeight( ( *t )->leftchild ), getHeight( ( *t )->rightchild ) );

    // check if the insertion caused an imbalance between subtrees
    int balance = AVL_Check( *t );

    if ( balance > 1 )  //left subtree is heavy
    {
        if ( k > ( *t )->leftchild->key )
        {
            ( *t )->leftchild = RotateLeft( ( *t )->leftchild, 1 );
            ( *t ) = RotateRight( *t, 2 );
        }
        else
        {
            ( *t ) = RotateRight( *t, 2 );
        }
    }
    else if ( balance < -1 )    // right subtree is heavy
    {
        if ( k < ( *t )->rightchild->key )
        {
            ( *t )->rightchild = RotateRight( ( *t )->rightchild, 1 );
            ( *t ) = RotateLeft( *t, 2 );
        }
        else
        {
            ( *t ) = RotateLeft( *t, 2 );
        }
    }
    return retVal;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * get_successor : helper function used to get the successor of a node
 *
 * Parameters : Tree t which is the direct rightchild of the node we are getting the successor for
 * Returns : Node * which is the successor
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Node *get_successor( Tree t )
{
	if ( t != NULL )
	{
		while( t->leftchild != NULL )
		{
			t=t->leftchild;
		}
	}
	return t;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * tree_delete : Removes the node whose key is k from the tree t if it is contained in the tree.
 *               If the node does not exist, then it will return after hitting null.
 *
 * Parameters : Tree *t which is a pointer to the the tree
 *              int k which is the key we would like to delete
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void tree_delete( Tree *t, int k )
{
	Node *parent, *successor;

	if ( ( *t ) == NULL )
	{
		return;
	}
	if ( key_less_than( k, (*t)->key ) )
	{
		tree_delete( ( &( *t )->leftchild ), k );
	}
	else if ( key_less_than( ( *t )->key, k ) )
	{
		tree_delete( ( &( *t )->rightchild), k );
	}
	else // found node to remove
	{
		parent = ( *t )->parent;
		successor = ( *t )->rightchild;
		if ( tree_num_children( *t ) == 0 )
		{
            if ( tree_parent( *t ) != NULL )
            {
    			if ( ( *t )->parent->leftchild == ( *t ) )
    			{
    				( *t )->parent->leftchild = NULL;
    			}
    			else
    			{
    				( *t )->parent->rightchild = NULL;
    			}
            }
            parent = ( *t );
            *t = NULL;
			free( parent );
		}
		else if ( tree_num_children( ( *t ) ) == 1 )
		{
            Node *temp = ( *t );
			if ( tree_rightchild( (*t) ) == NULL )
			{
                if ( ( *t )->parent != NULL )
                {
    				if ( parent->leftchild == ( *t ) )
    				{
    					( *t )->parent->leftchild = ( *t )->leftchild;
    					temp->leftchild->parent = temp->parent;
    				}
    				else
    				{
    					( *t )->parent->rightchild = ( *t )->leftchild;
    					temp->leftchild->parent = temp->parent;
    				}
                }
                else // if node has no parent, then node is root
                {
                    temp = ( *t );
                    *t = ( *t )->leftchild;
                    ( *t )->parent = NULL;
                }
			}
			else if ( tree_leftchild( *t ) == NULL )
			{
                if ( ( *t )->parent != NULL)
                {
    				if ( ( *t )->parent->leftchild == ( *t ) )
    				{
                        temp = ( *t );
    					(*t)->parent->leftchild = ( *t )->rightchild;
    					temp->rightchild->parent = temp->parent;
    				}
    				else
    				{
                        temp = ( *t );
    					( *t )->parent->rightchild = ( *t )->rightchild;
    					temp->rightchild->parent = temp->parent;
    				}
                }
                else // if node has no parent, then node is root
                {
                    temp = ( *t );
                    *t = ( *t )->rightchild;
                    ( *t )->parent = NULL;
                }
			}
			free( temp );
            ( temp ) = NULL;
		}
		else if ( tree_num_children( ( *t ) ) == 2 )	 // node has two children
		{
			if( successor != NULL )
			{
			    successor = get_successor( successor );
			}
			(*t)->key = successor->key;
			tree_delete( ( &( *t )->rightchild ), ( *t )->key );
		}
	}

    if ( ( *t ) == NULL )
    {
        return;
    }
    else
    {
        ( *t )->height = 1 + findMax( getHeight( ( *t )->leftchild ), getHeight( ( *t )->rightchild ) );

        int balance = AVL_Check( ( *t ) );

        // if balance is positive, then the left subtree is greater than the right
        if ( balance > 1 )
        {
            if ( AVL_Check( ( *t )->leftchild ) >= 0 )
            {
                ( *t ) = RotateRight( ( *t ), 2 );
            }
            else
            {
                ( *t )->leftchild = RotateLeft( ( *t )->leftchild, 1 );
                ( *t ) = RotateRight( ( *t ), 2 );
            }
        }
        else if ( balance < -1 ) // right subtree is heavier than left
        {
            if ( AVL_Check( ( *t )->rightchild ) <= 0 )
            {
                ( *t ) = RotateLeft( ( *t ), 2 );
            }
            else
            {
                ( *t )->rightchild =  RotateRight( ( *t )->rightchild, 1 );
                ( *t ) = RotateLeft( ( *t ), 2 );
            }
        }
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Preorder traverses the tree in a print-left-right fashion. it prints each node's key, parent,
 * leftchild, rightchild and height to a file which is specified as the second input parameter
 *
 * Parameters : Node *n which is the pointer to the root of the tree
 *              File *fp which is the pointer to the output file
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void tree_preorder( Node *n, FILE *fp )
{
	if ( n != NULL )
	{
		fprintf( fp,"\n\tNode : %d\t\t\t%d\n--------------------------------------------------------\n", n->key, n->height );

        if ( n->parent != NULL )
        {
            fprintf( fp,"\t\tParent ====> %d\n", n->parent->key );
        }
        else
        {
            fprintf( fp,"\t\tParent ====> NULL\n" );
        }
        if ( n->leftchild != NULL )
        {
            fprintf( fp,"\t\tLeft Child ====> %d\n", n->leftchild->key );
        }
        else
        {
            fprintf( fp,"\t\tLeft Child ====> NULL\n" );
        }
        if ( n->rightchild != NULL )
        {
            fprintf( fp,"\t\tRight Child ====> %d\n", n->rightchild->key  );
        }
        else
        {
            fprintf( fp,"\t\tRight Child ====> NULL\n" );
        }

		tree_preorder( n->leftchild, fp );
		tree_preorder( n->rightchild, fp );
	}
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Postorder traverses the tree in a left-right-print fashion. it prints each node's key, parent,
 * leftchild, rightchild and height to a file which is specified as the second input parameter
 *
 * Parameters : Node *n which is the pointer to the root of the tree
 *              File *fp which is the pointer to the output file
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void tree_postorder( Node *n, FILE *fp )
{
	if ( n !=NULL )
	{
		tree_postorder( n->leftchild, fp );
		tree_postorder( n->rightchild, fp );

        fprintf( fp,"\n\tNode : %d\t\t\t%d\n--------------------------------------------------------\n", n->key, n->height );

        if ( n->parent != NULL )
        {
            fprintf( fp,"\t\tParent ====> %d\n", n->parent->key );
        }
        else
        {
            fprintf( fp,"\t\tParent ====> NULL\n" );
        }
        if ( n->leftchild != NULL )
        {
            fprintf( fp,"\t\tLeft Child ====> %d\n", n->leftchild->key );
        }
        else
        {
            fprintf( fp,"\t\tLeft Child ====> NULL\n" );
        }
        if ( n->rightchild != NULL )
        {
            fprintf( fp,"\t\tRight Child ====> %d\n", n->rightchild->key  );
        }
        else
        {
            fprintf( fp,"\t\tRight Child ====> NULL\n" );
        }	}
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * inorder traverses a tree in a left-print-right fashion. it prints each node's key, parent,
 * leftchild, rightchild and height to a file which is specified as the second input parameter
 *
 * Parameters : Node *n which is the pointer to the root of the tree
 *              File *fp which is the pointer to the output file
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void tree_inorder( Node *n, FILE *fp )
{
	if( n != NULL )
	{
		tree_inorder( n->leftchild, fp );

        fprintf( fp,"\n\tNode : %d\t\t\t%d\n--------------------------------------------------------\n", n->key, n->height );

        if ( n->parent != NULL )
        {
            fprintf( fp,"\t\tParent ====> %d\n", n->parent->key );
        }
        else
        {
            fprintf( fp,"\t\tParent ====> NULL\n" );
        }
        if ( n->leftchild != NULL )
        {
            fprintf( fp,"\t\tLeft Child ====> %d\n", n->leftchild->key );
        }
        else
        {
            fprintf( fp,"\t\tLeft Child ====> NULL\n" );
        }
        if ( n->rightchild != NULL )
        {
            fprintf( fp,"\t\tRight Child ====> %d\n", n->rightchild->key  );
        }
        else
        {
            fprintf( fp,"\t\tRight Child ====> NULL\n" );
        }

        tree_inorder( n->rightchild, fp );
	}
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * tree_empty : checks to see whether a tree is empty
 *
 * Parameters : Tree t which is the tree we evaluating
 * Returns : int value. 0 for tree is not empty, 1 for tree is empty
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int tree_empty( Tree t )
{
	if( t )
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * tree_height is used to find the height of a tree
 *
 * Parameters : Tree t which is the tree we are trying to find the height for
 * Returns : height of the tree
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int tree_height( Tree t )
{
	int left_height, right_height;		//variables to keep track of left and right side of tree,
											//the function returns whichever is greater
	if ( !t )
	{
		return -1;
	}

	left_height = tree_height( t->leftchild );
	right_height = tree_height( t->rightchild );

	if ( left_height > right_height )
	{
		return ( left_height + 1 );
	}
	else
	{
		return ( right_height + 1 );
	}
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * tree_make_null : is a function call that is used for freeing an entire tree
 *
 * Parameters : Tree t which is the tree we are destroying
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void tree_make_null( Tree t ) //Deletes all nodes of the tree t.
{
	if( !t )
	{
		tree_make_null( t->leftchild );
		tree_make_null( t->rightchild );
		free( t );
	}
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * AVL_Check returns the difference between the left and right subtree. values greater than 1 mean
 * that there is an imbalance. values less than or equal 1 mean that the root is still balanced
 *
 * Parameters : Node* which is the node which we want to rotate (central)
 * Returns : int which left subtree - right subtree, negative values indicate the left subtree is heavy
 *           and positive values indicate that the right subtree is heavy. Zero indicates perfect balance
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int AVL_Check( Node *root )
{
    if ( root != NULL )
    {
        return ( getHeight( root->leftchild ) - getHeight( root->rightchild ) );
    }

    return 0;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * RotateRight is a function that takes a node (central) and rotates it (central) to the right,
 * making central's left node central's parent, and the new parent's right subtree is attached
 * to central's left subtree
 *
 * Parameters : Node* which is the node which we want to rotate (central)
 * Returns : Node* which is the new parent of input parameter (central)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Node *RotateRight( Node *central, int rotationScheme )
{
    // set pointers to prepare for data structure manipulation
    Node *leftNode = central->leftchild;
    Node *leftNode_RightSubTree = leftNode->rightchild;

    // manipulate the data structre as described in the function description
    leftNode->rightchild = central;
    central->leftchild = leftNode_RightSubTree;
    if ( leftNode_RightSubTree )
    {
        leftNode_RightSubTree->parent = central;
    }
    leftNode->parent = central->parent;
    if (central->parent)
    {
        // whether leftnode becomes left or right child
        // depends on its value, so check it
        if ( central->parent->key > leftNode->key )
        {
            central->parent->leftchild = leftNode;
        }
        else
        {
            central->parent->rightchild = leftNode;
        }
    }
    central->parent = leftNode;

    // redefine the height of the nodes
    central->height = 1 + findMax( getHeight( central->leftchild ), getHeight( central->rightchild ) );
    leftNode->height = 1 + findMax( getHeight( leftNode->leftchild ), getHeight( leftNode->rightchild ) );

    // return the new central node
    return leftNode;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * RotateLeft is a function that takes a node (central) and rotates it (central) to the left,
 * making central's right node central's parent, and the new parent's left subtree is attached
 * to central's right subtree
 *
 * Parameters : Node* which is the node which we want to rotate (central)
 * Returns : Node* which is the new parent of input parameter (central)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Node *RotateLeft( Node *central, int rotationScheme )
{
    // temp variables for pointer maniuplation
    Node *rightNode = central->rightchild;
    Node *rightNode_leftSubTree = rightNode->leftchild;

    // rotate nodes left according to lecture 2 notes
    rightNode->leftchild = central;
    central->rightchild = rightNode_leftSubTree;
    if ( rightNode_leftSubTree )
    {
        rightNode_leftSubTree->parent = central;
    }
    rightNode->parent = central->parent;
    if ( central->parent )
    {
        // whether rightNode will be left or right child
        // depends on its value, so check it
        if ( central->parent->key > rightNode->key )
        {
            central->parent->leftchild = rightNode;
        }
        else
        {
            central->parent->rightchild = rightNode;
        }
    }
    central->parent = rightNode;

    // adjust heights of the nodes that were moved
    central->height = 1 + findMax( getHeight( central->leftchild ), getHeight( central->rightchild ) );
    rightNode->height = 1 + findMax( getHeight( rightNode->leftchild ), getHeight( rightNode->rightchild ) );

    // return new central node
    return rightNode;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Utility function used to find the max of two numbers
 *
 * Parameters : int height of left subtree and int height of right subtree
 * Returns : int which is the height of left or right subtree, whichever is greatest. in the
 *           event of a tie, it doesnt matter, so just return something
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int findMax( int left, int right )
{
    if ( left > right )
    {
        return left;
    }
    return right;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Getter function that accesses and returns the height of a node (n)
 *
 * Parameters : Node *n, which is the node of interest
 * Returns : int which is the height of node n
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int getHeight( Node *n )
{
    if ( n == NULL )
    {
        return 0;
    }
    return n->height;
}
