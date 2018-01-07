#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


/*##########     Zdefiniowanie stałych symbolicznych     ##########*/

#define END 8                /* Wyłącznik menu */
#define MAX 1024            /* Maksymalny rozmiar wczytywanego obrazu */
#define DL_LINII 1024      /* Dlugosc buforow pomocniczych */


/*##########     6) FUNKCJA DO ZAPISYWANIA OBRAZKA     ##########*/

void zapisz(int obraz_pgm[][MAX], int *wymx, int *wymy, int *szarosci, FILE *zapis)
{
int i,j;
 fprintf(zapis, "P2\n%d %d\n%d",*wymx, *wymy, *szarosci);
     for(i=0;i<*wymy;i++) 
     {
      fprintf(zapis, "\n");
      for(j=0;j<*wymx;j++) 
      { 
    fprintf(zapis,"%d  ",obraz_pgm[i][j]);
    }
  }
}