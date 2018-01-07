#include<stdio.h>

int main(){
  int a, b, c, d, e, gej=666;
 menu:
  printf("#####################################M\n");
  printf("## ------M-I-L-I-O-N-E-R-Z-Y------ ##E\n");
  printf("#####################################H\n");
  printf("## ------------------------------- ##O\n");
  printf("## --1)-Z-A-G-R-A-J--------------- ##W\n");
  printf("## --2)-K-U-B-A------------------- ##\n");
  printf("## --3)-W-Y-J-D-Z----------------- ##\n");
  printf("## ------------------------------- ##\n");
  printf("#####################################\n");
  printf("\n");
  printf("\n");
  printf("#######################################\n");
  printf("## -P-O-D-A-J--N-U-M-E-R--O-P-C-J-I- ##\n");
  printf("#######################################\n");
  printf("## -W-P-I-S-Z-(1,2,3): ");
  scanf("%d", &e);
  printf("\n\n\n");
  printf("######M-M-M-M-M-M-M-M-M-M-M-M-M-M######\n");
  printf("######I-I-I-I-I-I-I-I-I-I-I-I-I-I######\n");
  printf("######L-L-L-L-L-L-L-L-L-L-L-L-L-L######\n");
  printf("######I-I-I-I-I-I-I-I-I-I-I-I-I-I######\n");
  printf("######O-O-O-O-O-O-O-O-O-O-O-O-O-O######\n");
  printf("######N-N-N-N-N-N-N-N-N-N-N-N-N-N######\n");
  printf("######E-E-E-E-E-E-E-E-E-E-E-E-E-E######\n");
  printf("######R-R-R-R-R-R-R-R-R-R-R-R-R-R######\n");
  printf("######Z-Z-Z-Z-Z-Z-Z-Z-Z-Z-Z-Z-Z-Z######\n");
  printf("######Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y-Y######\n");
  printf("\n\n");
  switch (e) {
  default: goto menu; break;
  case 3: goto koniec; break;
  case 2:
    printf("## - K - U - B - A - - T - O - : ##\n\n");
    scanf("%d", &a);
    if(a==gej){
      printf("BRAWO - - TO - - POPRAWNA - - ODPOWIEDZ!\n\n");
      goto menu; break;
    }else{
      printf("NIESTETY, ALE KUBA TO - - - - GEJ\n\n");
      goto menu; break;
    }
  }
 koniec:
  return 0;
}
