//Allen Bui
//X339Y958
//CS300 Fall Semester
//September 18, 2014
//classlist.c
//Assignment 6 - Sets/Binary Search Trees

	/* * * * * * * * * * * * *
	 *					     *
	 * EXTRA CREDIT VERSION! *
	 *						 *
	 * * * * * * * * * * * * */

	 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "set.h"
#include "classlist.h"

int main ()
{
	Set root;		//this is a variable of type set, which is a tree
	set_init(&root);		//initialization

	char enrollment_file[] = "enrollment_list.txt";		//name of enrolment file
	char drop_file[] = "drop_list.txt";						//name of drop file
	char out_file_name[] = "classlist.txt";			//name of output file
	Key read_string, name, delete_node;		//read_string is type key which will be used to initially read in lines from file,
									//then passed for string manipulation and finally stored as name, which is also of type key.
									// delete node does the same job as read_string
	
	empty_array(read_string, MAX_LINE);			//clears out variable

	
	FILE *read_in = fopen(enrollment_file, "r");		//opening enrollment_file for reading

	if (read_in == NULL)
	{
		printf("ERROR: COULD NOT OPEN %s\n", enrollment_file);
		exit(EXIT_FAILURE);
	}
	
	if(read_in != NULL && (!feof(read_in)))
	{	
		while (fgets(read_string, MAX_LINE ,read_in) != NULL)
		{
			empty_array(name, MAX_LINE);
			remove_spaces(read_string);
			my_string_function(read_string, name);
			remove_spaces(name);
			set_insert(&root, name);
		}
	}

	fclose(read_in);
	
	FILE *drop_list = fopen(drop_file, "r");		//opening drop_file for reading and deleting

	if (drop_list == NULL)
	{
		printf("ERROR: COULD NOT OPEN %s\n", drop_file);
		exit(EXIT_FAILURE);
	}
	
	if(drop_list != NULL && (!feof(drop_list)))
	{	
		while (fgets(read_string, MAX_LINE ,drop_list) != NULL)
		{
			empty_array(delete_node, MAX_LINE);
			remove_spaces(read_string);
			my_string_function(read_string, delete_node);
			remove_spaces(delete_node);
			set_delete(&root, delete_node);
			
		}
	}

	fclose(drop_list);		
	
	FILE *write_file = fopen(out_file_name, "w");		//opens file for writing
	if (write_file == NULL)
	{
		printf("ERROR: Could not open input file %s for reading.\n", out_file_name);
		exit (EXIT_FAILURE);
	}
	
	fprintf(write_file,"Class List for CS 300:\n\n");
	set_inorder(&root, write_file);
	
	printf("A current list of parts was saved in the file %s\n", out_file_name);
	printf("%d",set_member(delete_node, &root));
	fclose(write_file);
	set_make_null(&root);
	
	return 0;
}

//The function empty_array will set all characters of a string to the null character.
void empty_array(char *str, int length)
{
   int index;        /* index for string */

   for (index = 0; index < length; index++)
   {
      str[index] = '\0';
   }
}


//this trim function removes white spaces, tabs, and new lines from a string
void remove_spaces(char *str)
{
	char *end = str + strlen(str) - 1;		//length of the string to decrement
	
	while (isspace((int)*end) || *end == '\n' || *end == ' ' || *end == '\t')
	{
		*end = '\0';
		end--;
	}
	
	return;
}

//reads a string char by char and stores name last, first middle, as required
void my_string_function(char *str, char *name)
{																			//first last and middle will be used to store first last and middle name 
	char first[25] = "\0", last[25]= "\0", middle[25]= "\0";			//and then strcat to name
	char *end = str + strlen(str) - 1;		//length of the string
	int position = 0;		//variable to traverse array of characters
	
	while (isalpha((int)*end))
	{
		last[position] = *end;
		position++;
		end--;
	}

	end--;
	position = 0;
	while (isalpha((int)*end) || (isspace((int)*end)))
	{
		middle[position] = *end;
		position++;
		end--;
	}

	end--;
	position = 0;
	while (isalpha((int)*end))
	{
		first[position] = *end;
		position++;
		end--;
	}
	reverse(last);
	reverse(middle);
	reverse(first);
	strcat(name, last);
	strcat(name, ", ");
	strcat(name, first);
	strcat(name, " ");
	strcat(name, middle);
}

//my_string_function reads a string backwards
//this function reverses the string
void reverse(char *str)
{
	char temp;		//temporary character variable to store character that is to be reversed
	int beginning = 0;			//beginning is used to start from beginning of string
	int end = strlen(str) - 1;			//end is initialized as strlen so that it can start from end of string
 
	while (beginning < end) 
	{
		temp = str[beginning];
		str[beginning] = str[end];
		str[end] = temp;
		beginning++;
		end--;
	}
}
