CC=gcc
LMATH=-lm
CFLAGS=-ansi -Wall -O2

distancia: main.o Point.o
	$(CC) main.o Point.o -o distancia $(LMATH)

main.o: main.c
	$(CC) -c main.c $(CFLAGS) 

Point.o: Point.c
	$(CC) -c Point.c $(CFLAGS) $(LMATH)

clean:
	rm -f *.o
