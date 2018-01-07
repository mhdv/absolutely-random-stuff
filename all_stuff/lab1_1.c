#include <stdio.h>
int main()
{
  int a; 
    printf("Podaj temperature we Wroclawiu: ");
    scanf("%d", &a);
    if (a<=20){
      printf("Nie jest zbyt cieplo!");
    }   else {
      printf("Ladna dzis pogoda!");
  }
    printf("\n");
  return 0;
  }
