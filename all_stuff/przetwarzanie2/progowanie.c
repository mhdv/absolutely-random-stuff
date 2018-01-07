#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


/*##########     Zdefiniowanie stałych symbolicznych     ##########*/

#define END 8                /* Wyłącznik menu */
#define MAX 1024            /* Maksymalny rozmiar wczytywanego obrazu */
#define DL_LINII 1024      /* Dlugosc buforow pomocniczych */


/*##########     2) FUNKCJA DO ZMIANY POZIOMÓW     ##########*/

void progowanie(int obraz_pgm[][MAX], int *wymx, int *wymy, int *szarosci, int prog)
{
  int i,j;
  for(i=0;i<*wymy;i++)
  {
    for(j=0;j<*wymx;j++)
    {
      if(obraz_pgm[i][j]<=prog) obraz_pgm[i][j]=0;
      else if(obraz_pgm[i][j]>prog) obraz_pgm[i][j]=*szarosci;
    }
  }
}