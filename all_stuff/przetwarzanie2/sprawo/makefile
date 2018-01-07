CC=gcc -lm

all: lab3.c czytaj.o informacje.o konturowanie.o korekcja.o progowanie.o wyswietl.o zapisz.o
	$(CC) lab3.c czytaj.o informacje.o konturowanie.o korekcja.o progowanie.o wyswietl.o zapisz.o -o prog

czytaj.o: czytaj.c
	$(CC) czytaj.c -c -o czytaj.o

informacje.o: informacje.c
	$(CC) informacje.c -c -o informacje.o

konturowanie.o: konturowanie.c
	$(CC) konturowanie.c -c -o konturowanie.o

korekcja.o: korekcja.c
	$(CC) korekcja.c -c -o korekcja.o

progowanie.o: progowanie.c
	$(CC) progowanie.c -c -o progowanie.o

wyswietl.o: wyswietl.c
	$(CC) wyswietl.c -c -o wyswietl.o

zapisz.o: zapisz.c
	$(CC) zapisz.c -c -o zapisz.o

clean:
	rm *.o