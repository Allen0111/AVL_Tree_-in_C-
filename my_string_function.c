#include <stdio.h>
#include <string.h>
#include <ctype.h>

void my_string_function(char *str, char *name);
void reverse(char *str);

int main()
{
char string[29] = "ABCDEFG:HIJKLMNO:PQRSTUVQXYZ";
char name[28] = "\0";
my_string_function(string, name);
printf("%s", name);
return 0;
}

void my_string_function(char *str, char *name)
{
	char first[25] = "\0", last[25]= "\0", middle[25]= "\0";
	char *end = str + strlen(str) - 1;		//length of the string
	int position = 0;
	
	while (isalpha((int)*end))
	{
		last[position] = *end;
		position++;
		end--;
	}

	end--;
	position = 0;
	while (isalpha((int)*end))
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

void reverse(char *str)
{
	char temp;
	int i = 0;
	int j = strlen(str) - 1;
 
   while (i < j) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}