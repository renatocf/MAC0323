CC=gcc
LDFLAGS=-lm
CFLAGS=-Wall -O2
RM=rm -f

desafio: desafio.o Point.o quicksort.o
	$(CC) $^ -o $@ $(LDFLAGS)
	@ $(RM) *.o

desafio.o: desafio.c
	$(CC) $(CFLAGS) -c $^

Point.o: Point.c
	$(CC) $(CFLAGS) -c $^ $(LDFLAGS)

quicksort.o: quicksort.c
	$(CC) $(CFLAGS) -c $^

clean:
	$(RM) *.o
