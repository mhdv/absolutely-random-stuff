#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


/*##########     Zdefiniowanie stałych symbolicznych     ##########*/

#define END 8                /* Wyłącznik menu */
#define MAX 1024            /* Maksymalny rozmiar wczytywanego obrazu */
#define DL_LINII 1024      /* Dlugosc buforow pomocniczych */


/*##########     7) WAŻNE INFORMACJE O PROGRAMIE     ##########*/

void informacje()
{
  printf("Uwaga!\n Do poprawnego działania programu, po każdym zapisie obrazka,\n żeby kontynuować pracę na obrazku zapisanym,\n zaleca się ponowne uruchomienie programu.\n");
  printf(" W przeciwnym razie program może błędnie odczytać wymiary obrazka,\n lub w najgorszym przypadku błędnie zapisać obrazek.\n\n");
  printf("Żeby kontynuować naciśnij dowolny klawisz\n");
  getchar();getchar();
  system("clear");
}