CC?=gcc
CFLAGS?=-g -Wall -Wextra

myapp: problemHWE.o
	$(CC) $(CFLAGS) -o $@ $^ -lm

problemHWE.o: problemHWE.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm myapp *.o *.gch