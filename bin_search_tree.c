//Allen Bui
//X339Y958
//CS300 Fall Semester
//October 6, 2014
//bin_search_tree.c is where the prototypes listed in bin_search_tree.h are defined

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bin_search_tree.h"

void key_set_equal(Key a, Key b) // Sets the key a to the value of the key b.
{
	strcpy(a,b);
}

int key_is_equal(Key a, Key b) // Returns true (1) if the two keys are equal, or false (0) otherwise.
{
	int is_equal;		//variable used to return truth value
	
	if(strcmp(a,b) ==0)
	{
		is_equal = 1;
	}
	else
	{
		is_equal = 0;
	}
	
	return (is_equal);
}

int key_less_than(Key a, Key b) // Returns true (1) if a comes before b in the order used for sorting
{
	int is_less;		//variable used to return truth value
	
	if (strcmp(b,a) > 0)
	{
		is_less = 1;
	}
	else
	{
		is_less = 0;
	}
	
	return (is_less);
}

void tree_init(Tree *t) // initialize the tree *t. 
{
	(*t) =NULL;
}

Node *tree_make_node(Key k, Node *parent) 	//makes a new node (with malloc), sets its key to k, 
{											//its parent to parent, and its left and right children to NULL.

	Node *new_node;		//used to allocate memory to add to tree
	
	if ((new_node = (malloc(sizeof(Node)))))
	{
		key_set_equal(new_node->key, k);
		new_node->parent = parent;
		new_node->leftchild = NULL;
		new_node->rightchild = NULL;
	}
	
	return new_node;
}

Node *tree_root(Tree t)	// returns the root of t. (This is an identity function, included for complete- ness.) 
{
	return t;
}

Node *tree_parent(Node *n) //Returns the parent of n. 
{
	return n->parent;
}

Node *tree_leftchild(Node *n) //Returns the left child of n. 
{
	return n->leftchild;
}

Node *tree_rightchild(Node *n) //Returns the right child of n. 
{
	return n->rightchild;
}

//Returns the node in tree t whose key is k if it exists, or NULL if it doesn’t exist. 
Node *tree_search(Key k, Tree t)
{
        if((t) == NULL)
        {
			return NULL;
        }
        if(key_less_than(k, t->key))
        {
			tree_search(k,t->rightchild);
        }
        else if(!key_less_than(k, t->key))
			{
				tree_search(k,t->leftchild);
			}
	return t;
			
}

//Returns the number of children (0, 1 or 2) of node n. 
int tree_num_children(Node *n)
{
	if((!(n->leftchild && n->rightchild)) && (n->leftchild || n->rightchild)) //XOR
	{
		return 1;
	}
	if(n->leftchild && n->rightchild)
	{
		return 2;
	}
	else
	{
		return 0;
	}
}

//Adds a new node whose key is k to the tree t. 
void tree_insert(Tree *t, Key k)
{
	if((*t) == NULL)
	{
		(*t) = (tree_make_node (k, (*t)));
	}
	else if (key_is_equal(k, (*t)->key))
		{
			return;
		}
		else if (key_less_than(k, (*t)->key))
			{
				if ((*t)->leftchild == NULL)
				{	
					(*t)->leftchild = tree_make_node(k, (*t));
				}
				else
				{
					tree_insert((&(*t)->leftchild), k);
				}
			}
			else /*greater than*/
			{
				if((*t)->rightchild == NULL)
				{
					(*t)->rightchild = tree_make_node(k, (*t));
				}
				else
				{
					tree_insert((&(*t)->rightchild), k);
				}
			}
}


//helper function used to get the successor of a node
Node *get_successor(Tree t)
{
	if (t!=NULL)
	{
		while(t->leftchild !=NULL)
		{
			t=t->leftchild;
		}
	}
	return t;
}

//Removes the node whose key is k from the tree t if it is contained in the tree. 
void tree_delete(Tree t, Key k)
{
	Node *parent, *successor;
	
	if (t == NULL)
	{
		return;
	}
	if (key_less_than(k, t->key))
	{
		tree_delete(t->leftchild, k);
	}
	else if (key_less_than(t->key, k))
		{
			tree_delete(t->rightchild, k);
		}
			else // found node to remove 
			{
				parent = t;
				successor = t->rightchild;
				
				if (tree_num_children(t) == 0)
				{
					if (t->parent->leftchild == t)
					{
						t->parent->leftchild = NULL;
					}
					else
					{
						t->parent->rightchild = NULL;
					}
					free(t);
				}
				if (tree_num_children(t) == 1)
				{
					if(tree_rightchild(t) == NULL)
					{
						if(parent->leftchild == t)
						{
							t->parent->leftchild = t->leftchild;
							t->leftchild->parent = t->parent;
						}
						else
						{
							t->parent->rightchild = t->leftchild;
							t->leftchild->parent = t->parent;
						}
					}
					if (tree_leftchild(t) == NULL)
					{
						if(t->parent->leftchild == t)
						{
							t->parent->leftchild = t->rightchild;
							t->rightchild->parent = t->parent;
						}
						else
						{
							t->parent->rightchild = t->rightchild;
							t->rightchild->parent = t->parent;
						}
					}
					free(t);
				}
				
				if (tree_num_children(t) == 2)	 // node has two children 
					{
						if(successor != NULL)
						{
						successor = get_successor(successor);
						}
						key_set_equal(t->key,successor->key);
						tree_delete(t->rightchild, t->key);
					}
			}
}

//Writes out the key for each node of tree n, one key per line, in preorder, to the ﬁle fp. 
void tree_preorder(Node *n, FILE *fp)
{
	if (n != NULL)
	{
		fprintf(fp,"%s\n", n->key);
		tree_preorder(n->leftchild, fp);
		tree_preorder(n->rightchild, fp);
	}
}

//Writes out the key for each node of tree n, one key per line, in postorder, to the ﬁle fp. 
void tree_postorder(Node *n, FILE *fp)
{
	if (n !=NULL)
	{
		tree_postorder(n->leftchild, fp);
		tree_postorder(n->rightchild, fp);
		fprintf(fp,"%s\n", n->key);
	}
}

//Writes out the key for each node of tree n, one key per line, inorder, to the ﬁle fp. 
void tree_inorder(Node *n, FILE *fp)
{
	if(n != NULL)
	{
		tree_inorder(n->leftchild, fp);
		fprintf(fp,"%s\n", n->key);
		tree_inorder(n->rightchild, fp);
	}
}

//Returns true (1) if tree t is empty and false (0) otherwise. 
int tree_empty(Tree t)
{
	if(t)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

//Returns the height of the tree t.
int tree_height(Tree t) 
{
	int left_height, right_height;		//variables to keep track of left and right side of tree,
											//the function returns whichever is greater
 
	if (!t)
	{
		return -1;
	}
	
	left_height = tree_height(t->leftchild);
	right_height = tree_height(t->rightchild);
	
	if (left_height > right_height)
	{
		return (left_height + 1);
	}
	else 
	{
		return (right_height +1);
	}
}

void tree_make_null(Tree t) //Deletes all nodes of the tree t.
{
	if(!t)
	{
		tree_make_null(t->leftchild);
		tree_make_null(t->rightchild);
		free(t);
	}
}