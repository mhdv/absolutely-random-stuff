#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
  int a=0,b=0,c;   /*a-licznik, b-czestotliwosc*/
  FILE *f=fopen("przeciecie1.txt","r"); /*wczytuje wartosci z pliku*/
  if(f==NULL) {
    perror("Nie udalo sie wczytac pliku tekstowego 'przeciecie1.txt'");
    return 1;
  }
  puts("Poprawnie odczytano plik tekstowy.");
  fscanf(f, "%d", &c);
  printf("%d\n", c);
  fclose(f);
  return 0;
}
