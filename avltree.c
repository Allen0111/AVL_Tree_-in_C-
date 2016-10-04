/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                   *
 *   Allen Bui | x339y958                                                            *
 *   CS300 Data Structures & Algorithms                                              *
 *   Version 1.0 - Basic implementation of a BST : September 18, 2014                *
 *   CS721 Advanced Algorithms & Analysis                                            *
 *   Version 2.0 - Added AVL property and performance logging : September 5, 2016    *
 *                                                                                   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdint.h>
#include <limits.h>
#include "bin_search_tree.h"

// used to calculate time
#define BILLION 1000000000L

// used to keep track of max n values
// make this value smaller for shorter program execution times.
#define MAX_N_VALUE 10000000

// number of tests to run on each n value
#define NUM_TESTS 10

// Iterations of each n value, used to calculate averages
// of inserting n nodes into an empty tree
#define ITERATIONS 1

// constants for code readabilty
#define TEN                  10
#define ONE_HUNDRED          100
#define ONE_THOUSAND         1000
#define TEN_THOUSAND         10000
#define ONE_HUNDRED_THOUSAND 100000
#define ONE_MILLION          1000000
#define TEN_MILLION          10000000


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                               *
 *  main() is the starting point for program execution. main will create an AVL  *
 *  tree, and at each instance where n = 10, 100, 1k, 10k ..., 10 million, it    *
 *  will run tests to calculate the average times for insert, search, and        *
 *  delete                                                                       *
 *                                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int main( )
{
    printf("\nProcessing. Please be patient, you will be notified when the evaluation is complete.\n");

	Tree root;
	tree_init( &root );      //initialization

    // name of output file
	char out_file_name[ ] = "AVL_tree_test.txt";
	char preorder_file_name1[ ] = "AVL_preorder_n_10.txt";
	char preorder_file_name2[ ] = "AVL_preorder_n_100.txt";
	char preorder_file_name3[ ] = "AVL_preorder_n_1k.txt";
	char preorder_file_name4[ ] = "AVL_preorder_n_10k.txt";
	char preorder_file_name5[ ] = "AVL_preorder_n_100k.txt";
	char preorder_file_name6[ ] = "AVL_preorder_n_1_million.txt";
	char preorder_file_name7[ ] = "AVL_preorder_n_10_million.txt";

    //opens file for writing
    FILE *write_file = fopen( out_file_name, "w" );
    if ( write_file == NULL )
    {
        printf( "ERROR: Could not open input file %s for reading.\n", out_file_name );
        exit ( EXIT_FAILURE );
    }

    //opens file for writing
    FILE *preorderOutput1 = fopen( preorder_file_name1, "w" );
    if ( preorderOutput1 == NULL )
    {
        printf( "ERROR: Could not open input file %s for reading.\n", preorder_file_name1 );
        exit ( EXIT_FAILURE );
    }

    //opens file for writing
    FILE *preorderOutput2 = fopen( preorder_file_name2, "w" );
    if ( preorderOutput2 == NULL )
    {
        printf( "ERROR: Could not open input file %s for reading.\n", preorder_file_name2 );
        exit ( EXIT_FAILURE );
    }
    //opens file for writing
    FILE *preorderOutput3 = fopen( preorder_file_name3, "w" );
    if ( preorderOutput3 == NULL )
    {
        printf( "ERROR: Could not open input file %s for reading.\n", preorder_file_name3 );
        exit ( EXIT_FAILURE );
    }
    //opens file for writing
    FILE *preorderOutput4 = fopen( preorder_file_name4, "w" );
    if ( preorderOutput4 == NULL )
    {
        printf( "ERROR: Could not open input file %s for reading.\n", preorder_file_name4 );
        exit ( EXIT_FAILURE );
    }
    //opens file for writing
    FILE *preorderOutput5 = fopen( preorder_file_name5, "w" );
    if ( preorderOutput5 == NULL )
    {
        printf( "ERROR: Could not open input file %s for reading.\n", preorder_file_name5 );
        exit ( EXIT_FAILURE );
    }
    //opens file for writing
    FILE *preorderOutput6 = fopen( preorder_file_name6, "w" );
    if ( preorderOutput6 == NULL )
    {
        printf( "ERROR: Could not open input file %s for reading.\n", preorder_file_name6 );
        exit ( EXIT_FAILURE );
    }
    //opens file for writing
    FILE *preorderOutput7 = fopen( preorder_file_name7, "w" );
    if ( preorderOutput7 == NULL )
    {
        printf( "ERROR: Could not open input file %s for reading.\n", preorder_file_name7 );
        exit ( EXIT_FAILURE );
    }

    // structures for calculating time
    struct timespec startTime, endTime;

    // uint64_t for calculating time elapsed
    uint64_t timeElapsed;

    // it to iterate through a loop, record to iterate and insert records
    int it = 0, record = 0;

    // array to log times for printing and calculating average
    uint64_t insertLog[ 10 ];
    uint64_t deleteLog[ 10 ];
    uint64_t searchLog[ 10 ];

    // proceed identical calculations ITERATIONS times
    for ( it = 0; it < ITERATIONS; it++ )
    {
        // counter variable
        record = 0;

        // begin inserting records
        while ( record <= MAX_N_VALUE )
        {
            // randomly generate a number
            int random = rand( ) % INT_MAX;

            // insert the record into the tree, we dont allow duplicates
            if ( tree_insert( &root, random ) == 0 )
            {
                // if the random number generator created a duplicate
                // inc until the number is unique
                int success = 0;
                while ( success == 0 )
                {
                    if ( tree_insert( &root, ++random % INT_MAX ) == 1 )
                    {
                        success++;
                    }
                }
            }
            record++;

            // if we are at an n-value of interest, perform the checks
            if ( record == TEN || record == ONE_HUNDRED || record == ONE_THOUSAND || record == TEN_THOUSAND
                || record == ONE_HUNDRED_THOUSAND || record == ONE_MILLION || record == TEN_MILLION )
            {
                int i;
                for ( i = 0; i < NUM_TESTS ; i++ )
                {
                    int insertVal = rand( ) % INT_MAX;

                    // get start time
                    clock_gettime( CLOCK_MONOTONIC, &startTime );
                    // insert a random node and record the time taken
                    tree_insert( &root, insertVal );
                    // get end time
                    clock_gettime( CLOCK_MONOTONIC, &endTime );

                    // calculate total time taken to insert n records
                    timeElapsed = BILLION * ( endTime.tv_sec - startTime.tv_sec ) + endTime.tv_nsec - startTime.tv_nsec;
                    // log the time
                    insertLog[ i ] = timeElapsed;

                    // get start time
                    clock_gettime( CLOCK_MONOTONIC, &startTime );
                    // insert a random node and record the time taken
                    tree_search( insertVal, &root );
                    // get end time
                    clock_gettime( CLOCK_MONOTONIC, &endTime );

                    // calculate total time taken to insert n records
                    timeElapsed = BILLION * ( endTime.tv_sec - startTime.tv_sec ) + endTime.tv_nsec - startTime.tv_nsec;

                    // log the time
                    searchLog[ i ] = timeElapsed;

                    // get start time
                    clock_gettime( CLOCK_MONOTONIC, &startTime );
                    // insert a random node and record the time taken
                    tree_delete( &root, insertVal );
                    // get end time
                    clock_gettime( CLOCK_MONOTONIC, &endTime );

                    // calculate total time taken to insert n records
                    timeElapsed = BILLION * ( endTime.tv_sec - startTime.tv_sec ) + endTime.tv_nsec - startTime.tv_nsec;
                    // log the time
                    deleteLog[ i ] = timeElapsed;
                }

                // Output results for insertion
                uint64_t sum = 0;
                for ( i = 0; i < NUM_TESTS; i++ )
                {
                    fprintf( write_file, "\n Runtime of insert on test number %d for n = %d: %llu nanoseconds", i + 1, record ,( long long unsigned int )insertLog[ i ] );
                    sum += insertLog[ i ];

                    // on final iteration, calculate the average and print it
                    if ( i == ( NUM_TESTS - 1 ) )
                    {
                        fprintf( write_file, "\nINSERT: AVERAGE RUNTIME FOR n = %d : %llu nanoseconds\n", record, ( long long unsigned int )( sum / ( long long unsigned int )NUM_TESTS ) );
                        fprintf( write_file, "\n\n\n" );
                        printf( "\nINSERT: AVERAGE RUNTIME FOR n = %d : %llu nanoseconds\n", record, ( long long unsigned int )( sum / ( long long unsigned int )NUM_TESTS ) );
                    }
                }

                // Output results for search
                sum = 0;
                for ( i = 0; i < NUM_TESTS; i++ )
                {
                    fprintf( write_file, "\n Runtime of insert on test number %d for n = %d: %llu nanoseconds", i + 1, record ,( long long unsigned int )searchLog[ i ] );
                    sum += searchLog[ i ];

                    // on final iteration, calculate the average and print it
                    if ( i == ( NUM_TESTS - 1 ) )
                    {
                        // CAUTION: This program does not take care of outliers, so for purposes of measuring times, we need to doublecheck the output and remove outliers
                        fprintf( write_file, "\nSEARCH: AVERAGE RUNTIME FOR n = %d : %llu nanoseconds\n", record, ( long long unsigned int )( sum / ( long long unsigned int )NUM_TESTS ) );
                        fprintf( write_file, "\n\n\n" );
                        printf( "\nSEARCH: AVERAGE RUNTIME FOR n = %d : %llu nanoseconds\n", record, ( long long unsigned int )( sum / ( long long unsigned int )NUM_TESTS ) );
                    }
                }

                // Ouput results for delete
                sum = 0;
                for ( i = 0; i < NUM_TESTS; i++ )
                {
                    fprintf( write_file, "\n Runtime of delete on test number %d for n = %d: %llu nanoseconds", i + 1, record ,( long long unsigned int )deleteLog[ i ] );
                    sum += deleteLog[ i ];

                    // on final iteration, calculate the average and print it
                    if ( i == ( NUM_TESTS - 1 ) )
                    {
                        fprintf( write_file, "\nDELETE: AVERAGE RUNTIME FOR n = %d : %llu nanoseconds\n", record, ( long long unsigned int )( sum / ( long long unsigned int )NUM_TESTS ) );
                        fprintf( write_file, "\n\n\n" );
                        printf( "\nDELETE: AVERAGE RUNTIME FOR n = %d : %llu nanoseconds\n", record, ( long long unsigned int )( sum / ( long long unsigned int )NUM_TESTS ) );
                    }
                }

                // print the tree in a preorder traversal
                if ( record == TEN )
                {
                    fprintf( preorderOutput1, "\nPREORDER TRAVERSAL OF TREE AT n = %d", record );
                    tree_preorder( root, preorderOutput1 );
                    fprintf( preorderOutput1, "\n\n" );
                    fclose( preorderOutput1 );
                }
                else if ( record == ONE_HUNDRED )
                {
                    fprintf( preorderOutput2, "\nPREORDER TRAVERSAL OF TREE AT n = %d", record );
                    tree_preorder( root, preorderOutput2 );
                    fprintf( preorderOutput2, "\n\n" );
                    fclose( preorderOutput2 );
                }
                else if ( record == ONE_THOUSAND )
                {
                    fprintf( preorderOutput3, "\nPREORDER TRAVERSAL OF TREE AT n = %d", record );
                    tree_preorder( root, preorderOutput3 );
                    fprintf( preorderOutput3, "\n\n" );
                    fclose( preorderOutput3 );
                }
                else if ( record == TEN_THOUSAND )
                {
                    fprintf( preorderOutput4, "\nPREORDER TRAVERSAL OF TREE AT n = %d", record );
                    tree_preorder( root, preorderOutput4 );
                    fprintf( preorderOutput4, "\n\n" );
                    fclose( preorderOutput4 );
                }
                else if ( record == ONE_HUNDRED_THOUSAND )
                {
                    fprintf( preorderOutput5, "\nPREORDER TRAVERSAL OF TREE AT n = %d", record );
                    tree_preorder( root, preorderOutput5 );
                    fprintf( preorderOutput5, "\n\n" );
                    fclose( preorderOutput5 );
                }
                else if ( record == ONE_MILLION )
                {
                    fprintf( preorderOutput6, "\nPREORDER TRAVERSAL OF TREE AT n = %d", record );
                    tree_preorder( root, preorderOutput6 );
                    fprintf( preorderOutput6, "\n\n" );
                    fclose( preorderOutput6 );
                }
                else if ( record == TEN_MILLION )
                {
                    fprintf( preorderOutput7, "\nPREORDER TRAVERSAL OF TREE AT n = %d", record );
                    tree_preorder( root, preorderOutput7 );
                    fprintf( preorderOutput7, "\n\n" );
                    fclose( preorderOutput7 );
                }
            }
        }

        // empty the tree and prepare for the next iteration
        if ( root )
        {
            tree_make_null( root );
        }
    }

    fclose( write_file );

    printf( "\n\nEvaluation complete.\n" );
    printf( "\nPlease check AVL_tree_test.txt for the output of insert, search, and delete stats.\n" );
    printf( "\nPlease check AVL_preorder_n_...txt files for the preorder output for the tree at n = 10, 100, ..., 10 million\n\n\n\t\tEXIT SUCCESS!\n\n\n");

    if ( root )
    {
        tree_make_null( root );
    }

	return 0;
}

