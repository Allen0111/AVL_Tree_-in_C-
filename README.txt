
READ ME!

    Author....................Allen Bui | x339y958

    Last Revision Date........September 6, 2016

    Purpose...................This program takes a previous implementation of a binary
                              search tree ( written by me in CS300 ) and adds the AVL
                              property which will yield better runtimes in the average
                              and worst case.


/* * * * * * * * * * * SPECIAL NOTE FOR AVL HEIGHT PROPERTY * * * * * * * * * * * * *
 *																											   *
 *	  The height h of an AVL tree with n nodes lies in the interval:						*
 *																												*
 *	 			log2(n+1) ≤ h < c log2(n+2)+b															*
 *																												*
 *	  with the golden ratio φ := (1+√5) ⁄ 2 ≈ 1.618, 											*
 *	  c := 1⁄ log2 φ ≈ 1.44,  																			*
 *	  and  b := c⁄2 log2 5 – 2 ≈ –0.328. 															*
 *																												*
 *	  This is because an AVL tree of height h contains at least Fh+2 – 1 nodes 		*
 *	  where {Fh} is the Fibonacci sequence with the seed values F1 = 1, F2 = 1.		*
 *																												*
 *	  FOLLOW THIS LINK FOR MORE INFO:  https://en.wikipedia.org/wiki/AVL_tree			*
 *																												*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */

INCLUDED:
    Makefile
    All source code necessary for compilation (.c, .h)
    Output of preorder traversal and insert/delete/search stats
    Chart of the plotted runtimes of insert/delete/search stats

To COMPILE:
    (Linux) in a terminal, change directiry (via cd) to the destination of
    the source files and makefile. type "make". this should compile with
    compiler warnings set to max.

To RUN:
    (Linux) in a terminal, change directory (via cd command) to the destination
    of the executable. type "./avltree". The program will run for some time,
    please be patient. You will be notified once the program is complete.

OUTPUT:
    the output of the program will yield 8 text files:
        1-7) AVL_preorder_n_10.txt 
             AVL_preorder_n_100.txt
             AVL_preorder_n_1k.txt
             AVL_preorder_n_10k.txt
             AVL_preorder_n_100k.txt
             AVL_preorder_n_1_million.txt
             AVL_preorder_n_10_million.txt
                - will store the preorder traversal of
                the tree when n = 10, 100, 1000, ..., 10000000
                brace yourself, these output files are roughly 2 GB and will take
                a bit of time to open for the larger inputs of n. 
                Make sure you are using a stable text editor to open this
                ( i.e. gedit (NOTE: DO NOT USE ATOM ) )
        8) AVL_tree_test.txt - contains the stats for insert/delete/search for
                n = 10, 100, 1000, ..., 10000000
                at each instance, the program runs 10 samples and will display all 10
                as well as the average runtime. ( NOTE: this program does not eliminate
                outliers prior to calculating average and therefore may be skewed )
