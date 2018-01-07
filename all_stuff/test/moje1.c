#include<stdio.h>
#include<time.h>
int main(){
  int a,b,c,g;
  float x;
 poczatek: printf("\n\n\n");
  printf("Witaj w moim pierwszym wielozadaniowym programie!\n");
  printf("Jesli chcesz:\n\n 1)Dodac a,b,c - wpisz 1\n 2)Wymnozyc a,b,c - wpisz 2\n 3)Porownac a,b,c - wpisz 3\n 4)Przeliczyc euro na zlotowki - wpisz 4\n 5)Przeliczyc zlotowki na euro - wpisz 5\n Oraz zatwierdz przyciskiem 'enter'\n ---------------------------------\n ABY WYJSC WPISZ 99 I ROWNIEZ ZATWIERDZ 'ENTER'\n");
  scanf("%d", &g);
  switch(g){
    case 3:
      printf("Wybrales porownanie liczb:\n");
  printf("Podaj wartosc a: ");
  scanf("%d", &a);
  printf("Podaj wartosc b: ");
  scanf("%d", &b);
  printf("Podaj wartosc c: ");
  scanf("%d", &c);
  if(a>b && b>c){
    printf("%d>%d>%d", a,b,c);
  }else if(a>c && c>b){
    printf("%d>%d>%d", a,c,b);
  }else if(b>a && a>c){
    printf("%d>%d>%d", b,a,c);
  }else if(b>c && c>a){
    printf("%d>%d>%d", b,c,a);
  }else if(c>a && a>b){
    printf("%d>%d>%d", c,a,b);
  }else if(c>b && b>a){
    printf("%d>%d>%d", c,b,a);
  }else if(a==b && a>c){
    printf("%d=%d>%d", a,b,c);
  }else if(a==c && a>b){
    printf("%d=%d>%d", a,c,b);
  }else if(b==c && b>a){
    printf("%d=%d>%a", b,c,a);
  }else if(a==b && b==c){
    printf("%d=%d=%d", a,b,c);
  }else if(a==b && a<c){
    printf("%d>%d=%d", c,a,b);
  }else if(a==c && a<b){
    printf("%d>%d=%d", b,a,c);
  }else if(b==c && b<a){
    printf("%d>%d=%d", a,b,c);
  } printf("\n\n ^^ OTO TWOJ WYNIK ^^\n ###########################################\n URUCHAMIAM 'MENU' PONOWNIE\n"); 
  goto poczatek;  break;
case 1: 
  printf("Wybrales dodawanie liczb:\n");
printf("Podaj wartosc a: ");
 scanf("%d", &a);
 printf("Podaj wartosc b: ");
 scanf("%d", &b);
 printf("Podaj wartosc c: ");
 scanf("%d", &c);
 printf("%d", a+b+c);
printf("\n\n ^^ OTO TWOJ WYNIK ^^\n ###########################################\n URUCHAMIAM 'MENU' PONOWNIE\n"); 
 goto poczatek;
break;
case 2:
  printf("Wybrales mnozenie liczb:\n");
printf("Podaj wartosc a: ");
 scanf("%d", &a);
 printf("Podaj wartosc b: ");
 scanf("%d", &b);
 printf("Podaj wartosc c: ");
 scanf("%d", &c);
 printf("%d", a*b*c);
printf("\n\n ^^ OTO TWOJ WYNIK ^^\n ###########################################\n URUCHAMIAM 'MENU' PONOWNIE\n"); 
    goto poczatek;
break;
 default:
  printf("\n");
  goto poczatek;
break;
  case 4:
printf("Podaj kwote w euro: ");
 scanf("%f", &x);
 printf("%f zl", x*4.25593736);
printf("\n\n ^^ OTO TWOJ WYNIK ^^\n ###########################################\n URUCHAMIAM 'MENU' PONOWNIE\n");
 goto poczatek;
 break;
  case 5:
printf("Podaj kwote w zlotowkach: ");
 scanf("%f", &x);
 printf("%f euro", x*0.2349658);
printf("\n\n ^^ OTO TWOJ WYNIK ^^\n ###########################################\n URUCHAMIAM 'MENU' PONOWNIE\n");
 goto poczatek;
 break;
  case 6:
    for(a==1; a<=100; ++a){
      printf("%d", a);
    }        
  case 99:
    printf("\n\n Program zostal poprawnie wylaczony\n\n");
    break;
}
  return 0;
}
