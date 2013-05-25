CC=gcc
RM= rm -f
CFLAGS=-ansi -Wall -O2 -pedantic

josephus: main.o list.o
	$(CC) $(CFLAGS) $^ -o $@
	@ $(RM) *.o

main.o: main.c
	$(CC) $(CFLAGS) -c $<

list.o: list.c
	$(CC) $(CFLAGS) -c $<
