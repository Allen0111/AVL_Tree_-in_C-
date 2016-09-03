CC = gcc -g -Wall

all: classlist

classlist: bin_search_tree.o set.o classlist.h classlist.c
	$(CC) -o classlist classlist.c bin_search_tree.o set.o

bin_search_tree.o: bin_search_tree.h bin_search_tree.c
	$(CC) -c bin_search_tree.c
	
set.o: set.h set.c
	$(CC) -c set.c
	
tidy :
	rm -f bin_search_tree.o set.o core

clean :
	rm -f classlist bin_search_tree.o set.o core