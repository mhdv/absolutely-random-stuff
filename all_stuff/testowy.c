#include<stdio.h>
#include<stdlib.h>

int main()
{
  int a;
  system("clear");
  do
    {
  printf("\n Proste menu:\n");
  printf("1 - Pozycja pierwsza\n");
  printf("2 - Pozycja druga\n");
  printf("3 - Pozycja trzecia\n");
  printf("4 - Zakończ działanie\n");
  printf("Twój wybór: ");
  scanf("%d", &a);
  switch(a)
    {
    case 1:
      system("clear");
      printf("Wybrano pozycję pierwszą\n");
      break;
    case 2:
      system("clear");
      printf("Wybrano pozycję drugą\n");
      break;
    case 3:
      system("clear");
      printf("Wybrano pozycję trzecią\n");
      break;
    case 4:
      system("clear");
      break;
    default:
      system("clear");
      printf("Wybrano błędną pozycję\n");
      break;
    }
    }while (a!=4);
  printf("\nKoniec działania programu\n");
  return 0;
}
  
