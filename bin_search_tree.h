//Allen Bui
//X339Y958
//CS300 Fall Semester
//October 22, 2014
//bin_search_tree.h
//prototypes and typedefs for a binary search tree

#ifndef bin_search_tree_h

#define bin_search_tree_h

	#define KEY_LENGTH 100
	
	/* * * * * * * * * * * * *
	 *    TYPE DEFINITIONS   *
	 * * * * * * * * * * * * */
		
	typedef char Key[KEY_LENGTH];
	
	typedef struct node 
	{ 
		Key key;
		struct node *parent; 
		struct node *leftchild;
		struct node *rightchild;
	} Node;
	
	typedef Node *Tree;
	 
	/* * * * * * * * * * * * *
	 *  FUNCTION PROTOTYPES  *
	 * * * * * * * * * * * * */

	void key_set_equal(Key a, Key b); // Sets the key a to the value of the key b.

	int key_is_equal(Key a, Key b); // Returns true (1) if the two keys are equal, or false (0) otherwise.

	int key_less_than(Key a, Key b); // Returns true (1) if a comes before b in the order used for sorting

	void tree_init(Tree *t); // initialize the tree *t. 

	Node *tree_make_node(Key k, Node *parent); 	//makes a new Node (with malloc), sets its key to k, its parent to parent, 
												//and its left and right children to NULL.

	Node *tree_root(Tree t);	// returns the root of t. (This is an identity function, included for complete- ness.) 

	Node *tree_parent(Node *n); //Returns the parent of n. 

	Node *tree_leftchild(Node *n); //Returns the left child of n. 

	Node *tree_rightchild(Node *n); //Returns the right child of n. 

	Node *tree_search(Key k, Tree t); //Returns the node in tree t whose key is k if it exists, or NULL if it doesn’t exist. 

	int tree_num_children(Node *n); //Returns the number of children (0, 1 or 2) of node n. 

	void tree_insert(Tree *t, Key k); //Adds a new node whose key is k to the tree t. 

	void tree_delete(Tree t, Key k); //Removes the node whose key is k from the tree t if it is contained in the tree. 

	void tree_preorder(Node *n, FILE *fp); 	//Writes out the key for each node of tree n, 
											//one key per line, in preorder, to the ﬁle fp. 

	void tree_postorder(Node *n, FILE *fp); //Writes out the key for each node of tree n, 
											//one key per line, in postorder, to the ﬁle fp. 

	void tree_inorder(Node *n, FILE *fp); 	//Writes out the key for each node of tree n, 
											//one key per line, inorder, to the ﬁle fp. 

	int tree_empty(Tree t); //Returns true (1) if tree t is empty and false (0) otherwise. 

	int tree_height(Tree t); //Returns the height of the tree t. 

	void tree_make_null(Tree t); //Deletes all nodes of the tree t.

	Node *get_successor(Tree t);

#endif