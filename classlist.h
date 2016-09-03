//Allen Bui
//X339Y958
//CS300 Fall Semester
//October 22, 2014
//classlist.h
//prototypes and typedefs for a classlist.c


#ifndef classlist_h

#define classlist_h

	/* * * * * * * * * * * * *
	 *    TYPE DEFINITIONS   *
	 * * * * * * * * * * * * */
	 #define MAX_LINE 100
	 
	/* * * * * * * * * * * * *
	 *  FUNCTION PROTOTYPES  *
	 * * * * * * * * * * * * */
	void empty_array(char *str, int length);		//The function empty_array will set all characters of a string to the null character.
	void remove_spaces(char *str);			//this trim function removes white spaces, tabs, and new lines from a string
	void my_string_function(char *str, char *name);		//my_string_function reads a string backwards
	void reverse(char *str);	//this function reverses the string
	 
#endif