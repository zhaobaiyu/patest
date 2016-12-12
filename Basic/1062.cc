#include <cstdio>
#include <iostream>
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}
int main() {
  int n1, m1, n2, m2, k;
  scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);
  if (n1 * m2 > n2 * m1) {
    std::swap(n1, n2);
    std::swap(m1, m2);
  }
  int n = 1, flag = 0;
  while (n1 * k >= n * m1) ++n;
  while (m2 * n < n2 * k) {
    if (gcd(n, k) == 1) {
      if (flag == 0) {
        printf("%d/%d", n, k);
        flag = 1;
      } else {
        printf(" %d/%d", n, k);
      }
    }
    ++n;
  }
  printf("\n");
  return 0;
}
