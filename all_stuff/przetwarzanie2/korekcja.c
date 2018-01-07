#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


/*##########     Zdefiniowanie stałych symbolicznych     ##########*/

#define END 8                /* Wyłącznik menu */
#define MAX 1024            /* Maksymalny rozmiar wczytywanego obrazu */
#define DL_LINII 1024      /* Dlugosc buforow pomocniczych */


/*##########     3) FUNKCJA DO KOREKCJI GAMMA     ##########*/

void korekcja(int obraz_pgm[][MAX], int *wymx, int *wymy, int *szarosci, float g, float skala)
{
  int i,j;
  skala=*szarosci;
  for(i=0;i<*wymy;i++)
  {
    for(j=0;j<*wymx;j++)
    {
      obraz_pgm[i][j]=skala*pow((obraz_pgm[i][j]/skala), 1/g);
    }
  }
}