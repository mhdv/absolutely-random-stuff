#include <stdio.h>

int main(){
  int tab[10][10];
  int i, j;
  printf("Zawartość oryginalna: \n");
for(i=0; i<3; i++){
      for(j=0; j<7; j++){
	tab[i][j] = i*j;
	printf("%3d\t", tab[i][j]);
	     }
      printf("\n");
 }
 printf("Zawartość po zmianie znaków: \n");
for(i=0; i<3; i++){
      for(j=0; j<7; j++){
	tab[i][j] = i*j*-1;
	printf("%3d\t", tab[i][j]);
	     }
      printf("\n");
 }
}
