#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

/*##########     Zdefiniowanie stałych symbolicznych     ##########*/

#define END 8                /* Wyłącznik menu */
#define MAX 1024            /* Maksymalny rozmiar wczytywanego obrazu */
#define DL_LINII 1024      /* Dlugosc buforow pomocniczych */

/*##########     1) FUNKCJA WCZYTANIA OBRAZKA (SKOPIOWANA Z odczyt.c)     ##########*/

int czytaj(FILE *plik_we,int obraz_pgm[][MAX],int *wymx,int *wymy, int *szarosci) ;

/*##########     2) FUNKCJA DO ZMIANY POZIOMÓW     ##########*/

void progowanie(int obraz_pgm[][MAX], int *wymx, int *wymy, int *szarosci, int prog);

/*##########     3) FUNKCJA DO KOREKCJI GAMMA     ##########*/

void korekcja(int obraz_pgm[][MAX], int *wymx, int *wymy, int *szarosci, float g, float skala);

/*##########     4) FUNKCJA DO KONTUROWANIA     ##########*/

void konturowanie(int obraz_pgm[][MAX], int *wymx, int *wymy, int *szarosci);
  
/*##########     5) FUNKCJA DO WYŚWIETLANIA OBRAZKA PROGRAMEM 'display' (SKOPIOWANA Z odczyt.c)     ##########*/

void wyswietl(char *n_pliku) ;

/*##########     6) FUNKCJA DO ZAPISYWANIA OBRAZKA     ##########*/

void zapisz(int obraz_pgm[][MAX], int *wymx, int *wymy, int *szarosci, FILE *zapis);

/*##########     7) WAŻNE INFORMACJE O PROGRAMIE     ##########*/

void informacje();

/*##########     FUNKCJA MAIN - MENU     ##########*/
/* Dodatkowo każda opcja w menu została wzbogacona o opcjonalny zapis po użyciu dowolnego
przetwarzania obrazu, opcja dodana wyłącznie dla wygody użytkowania */

int main()
{
  int szarosci, prog, opcja, obraz[MAX][MAX], wymx, wymy, tn;
  float g, skala, skalamax, x, y;
  FILE *plik, *zapis;
  char nazwa[100],nazwa_zapis[100];
        system("clear");
          printf("Aby korzystać z funkcji programu, należy pierw wczytać obrazek.\n");
          printf("Przed pracą z programem warto zapoznać się z zakładką 'Ważne informacje'.\n");
  do
    {
    printf("###########################################");
  printf("\n### Wybierz opcje przetwarzania obrazu: ###\n");
    printf("### 1 - Wczytaj obrazek                 ###\n");
    printf("### 2 - Zmiana poziomów                 ###\n");
    printf("### 3 - Korekcja gamma                  ###\n");
    printf("### 4 - Konturowanie                    ###\n");
    printf("### 5 - Wyświetl obrazek                ###\n");
    printf("### 6 - Zapisz obrazek                  ###\n");
    printf("### 7 - Ważne informacje                ###\n");
    printf("### 8 - Zakończ                         ###\n");
    printf("###########################################\n\n");
    printf("Twój wybór: ");
  scanf("%d", &opcja);
  switch(opcja)
    {
    case 1:
      system("clear");
      printf("Wybrano wczytanie obrazka\n");
      printf("Podaj nazwę obrazka w formacie 'nazwa.pgm'\n");
      scanf("%s", nazwa);
      plik=fopen(nazwa,"r");
      if(plik!=NULL){
        printf("Poprawnie odczytano plik.\n");
        }else
        {
          printf("Nie udało się odczytać pliku.\n\a");
        }
      czytaj(plik, obraz, &wymx, &wymy, &szarosci);
      break;
    case 2:
      system("clear");
      if(plik==NULL)
      {
        printf("Nie możesz tego wykonać dopóki nie wczytasz obrazka.\a\n");
      }else{
      printf("Wybrano zmianę poziomów\n");
      printf("Podaj wartosc progu od 0 do 255.\n");
      scanf("%d",&prog);
      if(prog>=0 && prog<=255)
      {
        progowanie(obraz,&wymx,&wymy,&szarosci,prog);
          system("clear");
          printf("Czy chcesz zapisać zmiany do osobnego obrazka?\n");
          printf("1 - Tak\n");
          printf("2 - Nie\n");
          scanf("%d", &tn);
          system("clear");
          if(tn==1){
          printf("Podaj nazwę do zapisu obrazka w formacie 'nazwa.pgm'.\n");
          scanf("%s", nazwa_zapis);
          zapis=fopen(nazwa_zapis, "w");
          zapisz(obraz, &wymx, &wymy, &szarosci, zapis);
          system("clear");
          printf("Pomyślnie zapisano plik o nazwie '%s'.\n", nazwa_zapis);
          }else{
            system("clear");
            printf("Okej, zawsze możesz zapisać obrazek ręcznie w menu :).\n");
          }
      }else{
        printf("Podałeś błędną wartość progu... :).\n");
      }
      }
      break;
    case 3:
      system("clear");
      if(plik==NULL)
      {
        printf("Nie możesz tego wykonać dopóki nie wczytasz obrazka.\a\n");
      }else{
      printf("Wybrano korekcję gamma\n");
      printf("Podaj współczynnik gamma\nDla współczynnika 0<x<1 nastąpi przyciemnienie.\nDla współczynnika x>1 nastąpi rozjaśnienie.\n");
      scanf("%f",&g);
      if(g>=0 && g<=255)
      {
        korekcja(obraz,&wymx,&wymy,&szarosci,g,skala);
          system("clear");
          printf("Czy chcesz zapisać zmiany do osobnego obrazka?\n");
          printf("1 - Tak\n");
          printf("2 - Nie\n");
          scanf("%d", &tn);
          system("clear");
          if(tn==1){
          printf("Podaj nazwę do zapisu obrazka w formacie 'nazwa.pgm'.\n");
          scanf("%s", nazwa_zapis);
          zapis=fopen(nazwa_zapis, "w");
          zapisz(obraz, &wymx, &wymy, &szarosci, zapis);
          system("clear");
          printf("Pomyślnie zapisano plik o nazwie '%s'.\n", nazwa_zapis);
          }else{
            system("clear");
            printf("Okej, zawsze możesz zapisać obrazek ręcznie w menu :).\n");
          }
        }else{
        printf("Podałeś błędną wartość współczynnika gamma :).\n");
      }
      }
      break;
    case 4:
      system("clear");
      if(plik==NULL)
      {
        printf("Nie możesz tego wykonać dopóki nie wczytasz obrazka.\a\n");
      }else{
      printf("Wybrano konturowanie\n");
      konturowanie(obraz,&wymx,&wymy,&szarosci);
        system("clear");
        printf("Czy chcesz zapisać zmiany do osobnego obrazka?\n");
        printf("1 - Tak\n");
        printf("2 - Nie\n");
        scanf("%d", &tn);
        system("clear");
        if(tn==1){
        printf("Podaj nazwę do zapisu obrazka w formacie 'nazwa.pgm'.\n");
        scanf("%s", nazwa_zapis);
        zapis=fopen(nazwa_zapis, "w");
        zapisz(obraz, &wymx, &wymy, &szarosci, zapis);
        system("clear");
        printf("Pomyślnie zapisano plik o nazwie '%s'.\n", nazwa_zapis);
        }else{
          system("clear");
          printf("Okej, zawsze możesz zapisać obrazek ręcznie w menu :).\n");
        }
        }
      break;
    case 5:
      system("clear");
      if(plik==NULL)
      {
        printf("Nie możesz tego wykonać dopóki nie wczytasz obrazka.\a\n");
      }else{
      printf("Wybrano wyświetlenie obrazka\n");
      wyswietl(nazwa);
      }
      break;
    case 6:
      system("clear");
      if(plik==NULL)
      {
        printf("Nie możesz zapisać obrazka, ponieważ jeszcze go nie wczytałeś.\a\n");
      }else{
      printf("Wybrano zapisanie obrazka\n");
      printf("Podaj nazwę do zapisu obrazka w formacie 'nazwa.pgm'.\n");
      scanf("%s", nazwa_zapis);
      zapis=fopen(nazwa_zapis, "w");
      zapisz(obraz, &wymx, &wymy, &szarosci, zapis);
      system("clear");
      printf("Pomyślnie zapisano plik o nazwie '%s'.\n", nazwa_zapis);
      }
      break;
    case 7:
      system("clear");
      printf("Ważne informacje o programie.\n");
      informacje();
      break;
    case 8:
      system("clear");
      break;
    default:
      system("clear");
      printf("Wybrano błędną pozycję\n\a");
      break;
    }
    }while (opcja!=END);
    system("clear");
    if(plik!=NULL){
        printf("Czy chcesz zapisać zmiany przed wyjściem z programu?\n");
        printf("1 - Tak\n");
        printf("2 - Nie\n");
        scanf("%d", &tn);
        system("clear");
        if(tn==1){
        printf("Podaj nazwę do zapisu obrazka w formacie 'nazwa.pgm'.\n");
        scanf("%s", nazwa_zapis);
        zapis=fopen(nazwa_zapis, "w");
        zapisz(obraz, &wymx, &wymy, &szarosci, zapis);
        system("clear");
        printf("Pomyślnie zapisano plik o nazwie '%s'.\n", nazwa_zapis);
      }
    }else{
      system("clear");
    }
  printf("\nKoniec działania programu\n\n\a");
  return 0;
}