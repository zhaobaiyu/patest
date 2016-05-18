#include <stdio.h>
long long toknut(int a, int b, int c) {
  return 493*a + 29*b + c;
}

int main() {
  int a1, b1, c1, a2, b2, c2;
  scanf("%d.%d.%d %d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2);
  long long ans = toknut(a2, b2, c2) - toknut(a1, b1, c1);
  if (ans < 0) {
    printf("-");
    ans = -ans;
  }
  int a3 = ans/493, b3 = ans%493/29, c3 = ans%493%29;
  printf("%d.%d.%d\n", a3, b3, c3);
  return 0;
}
