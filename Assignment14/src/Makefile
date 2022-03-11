CC=gcc
CFLAGS=-I.

ArrayDataStore: ArrayDataStore.o main.o
	$(CC) $(CFLAGS) -o $@ $^
main.o: main.c ArrayDataStore.h
	$(CC) $(CFLAGS) -c main.c
ArrayDataStore.o: ArrayDataStore.c ArrayDataStore.h
	$(CC) $(CFLAGS) -c ArrayDataStore.c