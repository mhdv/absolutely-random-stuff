/*##########     PRZETWARZANIE OBRAZÓW     ##########*/
/*##########     Michał Filipowicz nr 226393     ##########*/     
/*##########     SPRAWOZDANIE ZNAJUDJE SIĘ NA KOŃCU KODU     ##########*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

/*##########     Zdefiniowanie stałych symbolicznych     ##########*/

#define END 8                /* Wyłącznik menu */
#define MAX 1024            /* Maksymalny rozmiar wczytywanego obrazu */
#define DL_LINII 1024      /* Dlugosc buforow pomocniczych */

/*##########     1) FUNKCJA WCZYTANIA OBRAZKA (SKOPIOWANA Z odczyt.c)     ##########*/

int czytaj(FILE *plik_we,int obraz_pgm[][MAX],int *wymx,int *wymy, int *szarosci) {
  char buf[DL_LINII];      /* bufor pomocniczy do czytania naglowka i komentarzy */
  int znak;                /* zmienna pomocnicza do czytania komentarzy */
  int koniec=0;            /* czy napotkano koniec danych w pliku */
  int i,j;

  /*Sprawdzenie czy podano prawid³owy uchwyt pliku */
  if (plik_we==NULL) {
    fprintf(stderr,"Blad: Nie podano uchwytu do pliku\n");
    return(0);
  }

  /* Sprawdzenie "numeru magicznego" - powinien byæ P2 */
  if (fgets(buf,DL_LINII,plik_we)==NULL)   /* Wczytanie pierwszej linii pliku do bufora */
    koniec=1;                              /* Nie udalo sie? Koniec danych! */

  if ( (buf[0]!='P') || (buf[1]!='2') || koniec) {  /* Czy jest magiczne "P2"? */
    fprintf(stderr,"Blad: To nie jest plik PGM\n");
    return(0);
  }

  /* Pominiecie komentarzy */
  do {
    if ((znak=fgetc(plik_we))=='#') {         /* Czy linia rozpoczyna sie od znaku '#'? */
      if (fgets(buf,DL_LINII,plik_we)==NULL)  /* Przeczytaj ja do bufora                */
  koniec=1;                   /* Zapamietaj ewentualny koniec danych */
    }  else {
      ungetc(znak,plik_we);                   /* Gdy przeczytany znak z poczatku linii */
    }                                         /* nie jest '#' zwroc go                 */
  } while (!koniec && znak=='#');   /* Powtarzaj dopoki sa linie komentarza */
                                    /* i nie nastapil koniec danych         */

  /* Pobranie wymiarow obrazu i liczby szarosci szarosci */
  if (fscanf(plik_we,"%d %d %d",wymx,wymy,szarosci)!=3) {
    fprintf(stderr,"Blad: Brak wymiarow obrazu lub liczby stopni szarosci\n");
    return(0);
  }
  /* Pobranie obrazu i zapisanie w tablicy obraz_pgm*/
  for (i=0;i<*wymy;i++) {
    for (j=0;j<*wymx;j++) {
      if (fscanf(plik_we,"%d",&(obraz_pgm[i][j]))!=1) {
  fprintf(stderr,"Blad: Niewlasciwe wymiary obrazu\n");
  return(0);
      }
    }
  }
  return *wymx**wymy;   /* Czytanie zakonczone sukcesem    */
  printf("Stopnie szarosci szarości pliku %s: %5d", plik_we, szarosci);
}                       /* Zwroc liczbe wczytanych pikseli */

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
    }
  }
}
    
/*##########     5) FUNKCJA DO WYŚWIETLANIA OBRAZKA PROGRAMEM 'display' (SKOPIOWANA Z odczyt.c)     ##########*/

void wyswietl(char *n_pliku) {
  char polecenie[DL_LINII];      /* bufor pomocniczy do zestawienia polecenia */

  strcpy(polecenie,"display ");  /* konstrukcja polecenia postaci */
  strcat(polecenie,n_pliku);     /* display "nazwa_pliku" &       */
  strcat(polecenie," &");
  printf("%s\n",polecenie);      /* wydruk kontrolny polecenia */
  system(polecenie);             /* wykonanie polecenia        */
}

/*##########     6) FUNKCJA DO ZAPISYWANIA OBRAZKA     ##########*/

void zapisz(int obraz_pgm[][MAX], int *wymx, int *wymy, int *szarosci, FILE *zapis)
{
int i,j;
 fprintf(zapis, "P2\n%d %d\n%d",*wymx, *wymy, *szarosci);
     for(i=0;i<*wymy;i++) 
     {
      fprintf(zapis, "\n");
      for(j=0;j<*wymx;j++) 
      { 
    fprintf(zapis,"%d  ",obraz_pgm[i][j]);
    }
  }
}

/*##########     7) WAŻNE INFORMACJE O PROGRAMIE     ##########*/

void informacje()
{
  printf("Uwaga!\n Do poprawnego działania programu, po każdym zapisie obrazka,\n żeby kontynuować pracę na obrazku zapisanym,\n zaleca się ponowne uruchomienie programu.\n");
  printf(" W przeciwnym razie program może błędnie odczytać wymiary obrazka,\n lub w najgorszym przypadku błędnie zapisać obrazek.\n\n");
  printf("Żeby kontynuować naciśnij dowolny klawisz\n");
  getchar();getchar();
  system("clear");
}

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


/*##########     SPRAWOZDANIE     ##########*/

/*

Michał Filipowicz, nr 226393;
Przetwarzanie obrazów;
Środa 19.12.2015;

    Testy Programu:

  1) Test ma na celu sprawdzenie poprawności działania samego menu.
  
    Włączenie każdej opcji bez wczytanego obrazka skutkuje poprawnym
  uruchomieniem danej funkcji przetwarzania obrazów oraz zapytaniem
  o zapis pliku.

  2) Test ma na celu sprawdzenie poprawności działania funkcji
  wczytania obrazka i jego wyświetlenia (obu funkcji skopiowanych z
  pliku odczyt.c).

    Uruchomienie opcji nr 1 w programie skutkuje poprawnym zapytaniem
  o nazwę obrazka, wczytanie obrazka z rozszerzeniem .pgm skutkuje
  wyświetleniem komunikatu o poprawnym wczytaniu obrazka. Podanie
  błędnej nazwy pliku lub podanie nazwy pliku bez rozszerzenia, lub
  z błędnym rozszerzeniem skutkuje wypisaniem w programie informacji
  o błędzie.
  Po poprawnym wczytaniu obrazka, za pomocą opcji 6, program bez
  problemu otwiera wczytany przez użytkownika obrazek za pomocą
  programu 'display'.

  3) Test ma na celu sprawdzenie poprawności działania zmiany poziomów.

    Na przykładowym obrazku pobranym z serwera diablo testuję funkcję
  do zmiany poziomów. Po użyciu opcji 2 na wczytanym obrazku poprawnie
  pokazuje się komunikat z prośbą o podanie wartości progu, zaś po jej
  podaniu pojawia się zapytanie o chęć zapisu pliku. Po zapisaniu pliku,
  wczytaniu go w naszym programie oraz wyświetleniu, obrazek okazuje się
  być poprawnie zmodyfikowany.

  4) Test ma na celu sprawdzenie poprawności działania korekcji gamma.

    Podobnie jak w teście zmiany poziomów, program poprawnie wczytuje
  zapytanie o wartość współczynnika korekcji, następnie wyświetla zapytanie
  o zapis przetworzonego obrazka. Po ponownym uruchomieniu i wyświetleniu,
  obrazek jest poprawnie zmodyfikowany.

  5) Test ma na celu sprawdzenie poprawności działania konturowania.

    Znów podobnie jak w poprzednich funkcjach, program poprawnie
  wczytuje funkcję konturowania obrazka, zaś po ponownym jego uruchomieniu
  i wyświetleniu obrazka, można ujrzeć efekty poprawnego działania tej funkcji.

  6) Test ma na celu sprawdzenie poprawności działania wyświetlania obrazka.

    Test był przeprowadzany praktycznie każdorazowo wraz z poprzednimi testami,
  funkcja poprawnie uruchamia program 'display' i otwiera w nim wczytany przez
  nas obrazek w formacie .pgm.

  7) Test ma na celu sprawdzenie poprawności działania funkcji zapisu.

    Po wczytaniu przykładowego obrazka do programu, ewentualnej obróbce go
  za pomocą dostępnych funkcji, testuję działanie funkcji zapisu obrazka.
  Po wybraniu opcji 6 w naszym menu, program poprawnie wyświetla zapytanie
  o nazwę obrazka do zapisu. Ponad to, program poprawnie zapisuje pliki również
  bez rozszerzenia oraz w innych rozszerzeniach, po czym nie ma problemu z ich
  odczytaniem. W przypadku nie wczytania żadnego obrazka, program nie pozwoli na
  zapis.

  8) Test ma na celu użycie wielu funkcji przetwarzania obrazów na jednym
  obrazku.

    Po wczytaniu obrazka, używam pierw funkcji konturowania, następnie bez
  wcześniejszego zapisu używam funkcji korekcji gamma. Zapisuję obrazek za
  pomocą opcji 7 i wczytuję przetworzony plik. Po wyświetleniu go programem
  'display' doskonale widać przeprowadzone na nim operacje konturowania oraz
  korekcji gamma.

  9) Test ma na celu sprawdzenie utracenia danych po przeprowadzonych operacjach.

    Program okazuje się być na to w 100% odporny. Po użyciu każdej z funkcji, program
  sam pyta użytkownika o chęć zapisu. W przypadku odmowy, po wczytaniu jakiegokolwiek
  pliku, przy próbie wyłączenia programu użytkownik zostaje raz jeszcze zapytany o
  chęć zapisu.



    Podsumowanie:

  Podsumowując, program działa jak najbardziej poprawnie. Wszystkie jego funkcje wczytują
  się dobrze i poprawnie przetwarzają wczytany obrazek. Program jest też w dużej mierze
  zabezpieczony przed utratą przetworzonych lub wczytanych danych, gdyż po użyciu każdej
  funkcji program daje możliwość zapisu. Wyjście z programu 'przez przypadek' również nie
  jest problemem, ponieważ program przed wyjściem również pyta o to, czy użytkownik chce
  zapisać swój obrazek.

  */
