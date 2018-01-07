#include<stdio.h>
int main(){
  int a=1,b;
  do{
    printf("Podaj %d. wartosc parametru: ", a);
    scanf("%d", &b);
    if(b<=5 && b>=-5){
      printf("Aktualna wartosc parametru: %d\n", b);
      ++a;
    }else if(b!=99){
      printf("Bledna wartosc parametru.\n");
      ++a;
    }
  }while(b!=99);
  return 0;
}
