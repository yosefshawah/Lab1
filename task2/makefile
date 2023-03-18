all: base

base: base.o
	gcc -g -m32 -Wall -o base base.o

base.o: base.c
	gcc -g -Wall -m32 -c -o base.o base.c

.PHONY: clean

clean:
	rm -f *.o base

