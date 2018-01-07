CC=gcc -lm

all: modul.o
	$(CC) main.c modul.o -o prog

modul.o: modul.c
	$(CC) modul.c -c -o modul.o

clean:
	rm *.o

