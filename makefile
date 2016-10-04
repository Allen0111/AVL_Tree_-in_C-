CC = gcc -g -lrt -Wall

all: avltree

avltree: bin_search_tree.o avltree.c
	$(CC) -o avltree avltree.c bin_search_tree.o

bin_search_tree.o: bin_search_tree.h bin_search_tree.c
	$(CC) -c bin_search_tree.c

tidy :
	rm -f bin_search_tree.o core

clean :
	rm -f avltree bin_search_tree.o core
