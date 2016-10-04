/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                   *
 * Allen Bui | X339Y958                                              *
 * Version 1.0 - October 22, 2014 (init)                             *
 * Version 2.0 - September 2, 2016 (Balance Property ( AVL ) )       *
 * bin_search_tree.h                                                 *
 * prototypes and typedefs for a binary search tree                  *
 *                                                                   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef bin_search_tree_h

#define bin_search_tree_h

    /* * * * * * * * * * * * *
     *    TYPE DEFINITIONS   *
     * * * * * * * * * * * * */

    typedef struct node
    {
        int key;
        int height;
        struct node *parent;
        struct node *leftchild;
        struct node *rightchild;
    } Node;

    typedef Node *Tree;

    /* * * * * * * * * * * * *
     *  FUNCTION PROTOTYPES  *
     * * * * * * * * * * * * */

    void key_set_equal( int a,  int b );

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * tree_make_node : makes a new node with malloc. sets its key to k, its parent to parent, and its
     *                  left and right children to NULL.
     *
     * Parameters : int a which is the key of interest
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    int key_is_equal( int a, int b );

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * key_less_than compares a & b. returns 1 if the
     * second parameter is greater than the first, 0 otherwise.
     *
     * Parameters : int a which is the first key value
     *              int b which is the second key value
     * Returns : int value : 1 if b is greater than a, 0 otherwise
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    int key_less_than( int a, int b );

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * tree_init : initializes the tree
     *
     * Parameters : Node *n which is the node of interest
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void tree_init( Tree *t );

    Node *tree_make_node( int k, Node *parent );

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * tree_root : returns the root of t. (This is an identity function, included for complete- ness.)
     *             returns NULL if tree has no root
     *
     * Parameters : Tree *t which is the tree of interest
     * Returns : Node * which is the pointer to the root
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    Node *tree_root( Tree t );

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * tree_parent : is a function that returns the parent of the node. returns NULL if the node
     *               is the root
     *
     * Parameters : Node *n which is the node of interest
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    Node *tree_parent( Node *n );

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * tree_leftchild : is a function that returns the leftchild of the node. returns NULL if the node
     *                   does not have a leftchild
     *
     * Parameters : Node *n which is the node of interest
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    Node *tree_leftchild( Node *n );

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * tree_rightchild : is a function that returns the rightchild of the node. returns NULL if the node
     *                   does not have a rightchild
     *
     * Parameters : Node *n which is the node of interest
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    Node *tree_rightchild( Node *n );

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * tree_search : Returns the node in tree t whose key is k if it exists, or NULL if it doesn’t exist.
     *
     * Parameters : int k which is the integer key value we are looking for.
     *              Tree *t which is the tree we are traversing to search
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    Node *tree_search( int k, Tree *t );

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * tree_num_children : Returns the number of children (0, 1 or 2) of node n.
     *
     * Parameters : Node *n which is the node of interest
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    int tree_num_children( Node *n );

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * tree_insert : Adds a node to the current tree. If the node exists, it returns 0.
     *               if the insertion succeeds, it returns 1.
     *
     * Parameters : Tree *t which is a pointer to the the tree
     *              int k which is the key we would like to delete
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    int tree_insert( Tree *t, int k );

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * tree_delete : Removes the node whose key is k from the tree t if it is contained in the tree.
     *               If the node does not exist, then it will return after hitting null.
     *
     * Parameters : Tree *t which is a pointer to the the tree
     *              int k which is the key we would like to delete
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void tree_delete( Tree *t, int k );

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Preorder traverses the tree in a print-left-right fashion. it prints each node's key, parent,
     * leftchild, rightchild and height to a file which is specified as the second input parameter
     *
     * Parameters : Node *n which is the pointer to the root of the tree
     *              File *fp which is the pointer to the output file
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void tree_preorder( Node *n, FILE *fp );

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Postorder traverses the tree in a left-right-print fashion. it prints each node's key, parent,
     * leftchild, rightchild and height to a file which is specified as the second input parameter
     *
     * Parameters : Node *n which is the pointer to the root of the tree
     *              File *fp which is the pointer to the output file
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void tree_postorder( Node *n, FILE *fp );

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * inorder traverses a tree in a left-print-right fashion. it prints each node's key, parent,
     * leftchild, rightchild and height to a file which is specified as the second input parameter
     *
     * Parameters : Node *n which is the pointer to the root of the tree
     *              File *fp which is the pointer to the output file
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void tree_inorder( Node *n, FILE *fp );

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * tree_empty : checks to see whether a tree is empty
     *
     * Parameters : Tree t which is the tree we evaluating
     * Returns : int value. 0 for tree is not empty, 1 for tree is empty
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    int tree_empty( Tree t );

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * tree_height is used to find the height of a tree
     *
     * Parameters : Tree t which is the tree we are trying to find the height for
     * Returns : int which is the height of the tree
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    int tree_height( Tree t );

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * tree_make_null : is a function call that is used for freeing an entire tree
     *
     * Parameters : Tree t which is the tree we are destroying
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void tree_make_null( Tree t );

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * get_successor : helper function used to get the successor of a node
     *
     * Parameters : Tree t which is the direct rightchild of the node we are getting the successor for
     * Returns : Node * which is the successor
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    Node *get_successor( Tree t );


    /* NEW FUNCTIONS FOR AVL IMPLEMENTATION ARE LOCATED BELOW THIS COMMENT */


    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * AVL_Check returns the difference between the left and right subtree. values greater than 1 mean
     * that there is an imbalance. values less than or equal 1 mean that the root is still balanced
     *
     * Parameters : Node* which is the node which we want to rotate (central)
     * Returns : int which left subtree - right subtree, negative values indicate the left subtree is heavy
     *           and positive values indicate that the right subtree is heavy. Zero indicates perfect balance
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    int AVL_Check( Node *root );

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * RotateRight is a function that takes a node (central) and rotates it (central) to the right,
     * making central's left node central's parent, and the new parent's right subtree is attached
     * to central's left subtree
     *
     * Parameters : Node* which is the node which we want to rotate (central)
     * Returns : Node* which is the new parent of input parameter (central)
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    Node *RotateRight( Node *central, int rotationScheme );

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * RotateLeft is a function that takes a node (central) and rotates it (central) to the left,
     * making central's right node central's parent, and the new parent's left subtree is attached
     * to central's right subtree
     *
     * Parameters : Node* which is the node which we want to rotate (central)
     * Returns : Node* which is the new parent of input parameter (central)
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    Node *RotateLeft( Node *central, int rotationScheme );

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Utility function used to find the max of two numbers
     *
     * Parameters : int height of left subtree and int height of right subtree
     * Returns : int which is the height of left or right subtree, whichever is greatest. in the
     *           event of a tie, it doesnt matter, so just return something
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    int findMax( int left, int right );

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Getter function that accesses and returns the height of a node (n)
     *
     * Parameters : Node *n, which is the node of interest
     * Returns : int which is the height of node n
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    int getHeight( Node *n );

#endif
