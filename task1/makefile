all: addressess

addressess: addressess.o
	gcc -g -m32 -Wall -o addressess addressess.o

addressess.o: addressess.c
	gcc -g -Wall -m32 -c -o addressess.o addressess.c

.PHONY: clean

clean:
	rm -f *.o addressess

