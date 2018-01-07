#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>



/*##########     Zdefiniowanie stałych symbolicznych     ##########*/

#define END 8                /* Wyłącznik menu */
#define MAX 1024            /* Maksymalny rozmiar wczytywanego obrazu */
#define DL_LINII 1024      /* Dlugosc buforow pomocniczych */



/*##########     4) FUNKCJA DO KONTUROWANIA     ##########*/

void konturowanie(int obraz_pgm[][MAX], int *wymx, int *wymy, int *szarosci)
{
 int x, y, i, j;
  for(i=0;i<*wymy;i++)
  {
    for(j=0;j<*wymx;j++)
    {
      if(j+1 <= *wymx)
      {
   if(obraz_pgm[i][j+1]-obraz_pgm[i][j] >0) x=obraz_pgm[i][j+1]-obraz_pgm[i][j];
   else x=obraz_pgm[i][j]-obraz_pgm[i][j+1];
      }
      else x=obraz_pgm[i][j];   
      if (i+1 <= *wymy)
      {
   if(obraz_pgm[i+1][j]-obraz_pgm[i][j] >0) y=obraz_pgm[i+1][j]-obraz_pgm[i][j];
   else y=obraz_pgm[i][j]-obraz_pgm[i+1][j];
      }
      else y=obraz_pgm[i][j];
      if(x+y<=*szarosci) obraz_pgm[i][j]=x+y;
      else;
    }
  }
}