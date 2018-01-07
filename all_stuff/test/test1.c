#include <stdio.h>
int main()
{
  int a; 
    printf("Podaj temperature we Wroclawiu: ");
    scanf("%d", &a);
    if (a<=-20){
      printf("Mozna zamarznac! Nie wychodz z domu!");
    } else  
    if(a>-20, a<=-5){
      printf("Na dworze jest strasznie zimno!");
    } else
    if(a>-5, a<=5){
      printf("Zimno dzisiaj, lepiej wskoczyc pod koc!");
    } else
    if(a>5, a<=15){
      printf("Nie jest dzisiaj za cieplo!");
    } else
    if(a>15, a<=25){
      printf("Idealna pogoda :)!");
	} else
    if(a>25, a<=40){
      printf("Goraco jak w piekle!");
	} else
    if(a>40){
      printf("Gorecej niz w piekle!!");
    }
    printf("\n");
  return 0;
  }
