OBJS=rc4.o test.o
CC=gcc
CFLAGS=-O -g -Wall

test:$(OBJS)
	$(CC) $(OBJS) -o test

rc_4.o:rc4.c rc4.h
	$(CC) $(CFLAGS) -c rc4.c -o rc4.o

test.o:test.c rc4.h
	$(CC) $(CFLAGS) -c test.c -o test.o

clean:
	rm -rf *.o test