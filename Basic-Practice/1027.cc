#include <cstdio>
#include <cctype>
#include <cmath>
int main() {
  int n, m;
  char c;
  scanf("%d", &n);
  while (isspace(c = getchar()))
    ;
  if (n % 2) {
    m = (n + 1) / 2;
  } else {
    m = n / 2;
  }
  int a = sqrt(m), b = a * 2 - 1;
  int i = a;
  int dec = 1;
  while (i <= a) {
    for (int j = 0; j < a - i; ++j) {
      printf(" ");
    }
    int k = b - 2 * (a - i);
    for (int j = 0; j < k; ++j) {
      printf("%c", c);
    }
    printf("\n");
    if (i == 1) dec = 0;
    if (dec)
      --i;
    else
      ++i;
  }
  printf("%d\n", n - a * a * 2 + 1);
  return 0;
}
