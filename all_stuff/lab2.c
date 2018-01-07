/*############### PROGRAM PRZECIECIA ZERA ###############*/
/*############### MICHAŁ FILIPOWICZ, NR ALBUMU:226393 ###############*/
/*########## SPRAWOZDANIE ORAZ TESTY ZNAJDUJĄ SIĘ NA KOŃCU ##########*/

/*Aby uruchomić program po skompilowaniu: ./a.out <dane_wejściowe.txt*/

/*############### KOD ORAZ KOMENTARZE ###############*/
#include<stdio.h>
/* MAX-maksymalna wartość, MIN-minimalna, PACZKA-ilość wartości w jednej paczce, END-wartość która ma zakończyć program, FMAX-maksymalne tętno, FMIN-minimalne tętno*/
#define MAX 10
#define MIN -10
#define PACZKA 99
#define END 99
#define FMAX 14
#define FMIN 8

int main()
{
  int licznik=0, przeciecia=0; /*licznik-ilość wczytanych wartości, przecięcia-ilość przecięć*/
  float aktualna=0, poprzednia=0;/*aktualna to wartość, poprzednia to wartość przed nią*/
  do /*pętla do...while kończąca się w momencie osiągnięcia wartości "aktualna=99"*/
    {/*wczytywanie pierwszej wartości*/
      scanf("%f", &aktualna);
      if(aktualna>=MIN && aktualna<=MAX)
	{/*wzrost licznika po wczytaniu wartości*/
	  ++licznik;
	   /*zliczanie przecięć zera, dodanie +1 do przecięć*/
	  if(aktualna*poprzednia<0) ++przeciecia;
	}
      if(licznik==PACZKA)
	{/*jeśli licznik osiągnie 99, pokazywana jest informacja o tętnie, a następnie wczytywana jest kolejna paczka z pliku tekstowego*/
	  if(przeciecia>=FMIN && przeciecia<=FMAX)
	    {
	      printf("Tętno prawidłowe: %d\n", przeciecia);
	    }else{
	    printf("Uwaga! Tętno to: %d\n", przeciecia);
	  }
	  licznik=0; przeciecia=0; aktualna=0; poprzednia=0;
	}
      if(aktualna!=0)
      poprzednia=aktualna;
    }while(aktualna!=END);
  return 0;
}

/*
### SPRAWOZDANIE - PRZECIĘCIA ZERA ###

Michał Filipowicz,
nr Albumu: 226393,
Kierunek AiR, W4,
DATA: 23.11.2015.
>>Kod źródłowy powyżej.

>Testy programu:
 -->Dane wejściowe 1:
Program pokazuje poprawne wartości, porównane z wynikami znajomych, wszystkie są takie same.
 -->Dane wejściowe 2:
Program również pokazuje poprawne wartości...
 -->Dane wejściowe dodatkowe:
Użycie opublikowanych, innych danych wejściowych, wyniki takie same jak u innych, wyniki poprawne.
 -->Użycie specjalnie napisanego pliku tekstowego, mającego na celu sprawdzenie tętna powyżej 50:
Program poprawnie policzył oraz podał wynik dla tętna powyżej 50.
 -->Użycie pliku tekstowego, w którym przecięć zera nie ma:
Program poprawnie wskazuje na brak przecięć zera.

>Wnioski:
->Program radzi sobie z powierzonymi mu zadaniami, poprawnie oblicza przecięcia zera, wypisuje które tętno jest poprawne, które zaś nie.
->Program nadaje się do testowania na dowolnych plikach tekstowych z uporządkowanymi liczbami.
*/
