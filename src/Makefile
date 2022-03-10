CC=gcc
CFLAGS=-I.
stringlist: stringlist.o main.o
	$(CC) $(CFLAGS) -o $@ $^
main.o: main.c stringlist.h
	$(CC) $(CFLAGS) -c main.c
stringlist.o: stringlist.c stringlist.h
	$(CC) $(CFLAGS) -c stringlist.c