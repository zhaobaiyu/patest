#include <stdio.h>
int main() {
  int m = 0, count = 0;
  scanf("%d", &m);
  while (m > 1) {
    count++;
    if (m % 2 == 1) {
      m = (3*m + 1)/2;
    } else {
      m = m/2;
    }
  }
  printf("%d\n", count);
  return 0;
}
