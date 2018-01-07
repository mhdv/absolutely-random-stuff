#include<stdio.h>

int main()
{
  int a;
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
      printf("Wybrano pozycję pierwszą\n");
      break;
    case 2:
      printf("Wybrano pozycję drugą\n");
      break;
    case 3:
      printf("Wybrano pozycję trzecią\n");
      break;
    case 4:
      break;
    default:
      printf("Wybrano błędną pozycję\n");
      break;
    }
    }while (a!=4);
  printf("\nKoniec działania programu\n");
  return 0;
}
  
