# "makefile" for the final implementation of lab of the
# Summer 2019 term (SENG 265).
#

CC=gcc

# The line with -DDEBUG can be used for development. When
# building your code for evaluation, however, the line *without*
# the -DDEBUG will be used.
#
CFLAGS=-c -Wall -g -DDEBUG -std=c99
#CFLAGS=-c -Wall -g -std=c99


all: lab8

lab8: lab8.o listy.o emalloc.o
	$(CC) lab8.o listy.o emalloc.o -o lab8

lab8.o: lab8.c listy.h ics.h emalloc.h
	$(CC) $(CFLAGS) lab8.c

listy.o: listy.c listy.h ics.h emalloc.h
	$(CC) $(CFLAGS) listy.c

emalloc.o: emalloc.c emalloc.h
	$(CC) $(CFLAGS) emalloc.c

clean:
	rm -rf *.o lab8
