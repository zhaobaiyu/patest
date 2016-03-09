#include <stdio.h>
int main() {
  int n, temp, n1, n2;
  scanf("%d", &n);
  int wei[4];
  wei[0] = n/1000, wei[1] = n/100%10, wei[2] = n/10%10, wei[3] = n%10;
  if (wei[0] == wei[1] && wei[1] == wei[2] && wei[2] == wei[3]) {
    printf("%d - %d = 0000\n", n, n);
  } else {
    while (n != 6174) {
      wei[0] = n/1000, wei[1] = n/100%10, wei[2] = n/10%10, wei[3] = n%10;
      for (int i = 0; i < 4; ++i) 
        for (int j = i + 1; j < 4; ++j) 
          if (wei[i] < wei[j]) {
            temp = wei[i];
            wei[i] = wei[j];
            wei[j] = temp;
          }
      n1 = wei[0]*1000 + wei[1]*100 + wei[2]*10 + wei[3];
      n2 = wei[3]*1000 + wei[2]*100 + wei[1]*10 + wei[0];
      n = n1 - n2;
      printf("%04d - %04d = %04d\n", n1, n2, n);
    }
  }
  return 0;
}
