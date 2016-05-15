#include <cstdio>
#include <cctype>
int main() {
  int n;
  scanf("%d", &n);
  char c;
  while (isspace(c = getchar()))
    ;
  for (int i = 0; i < n; ++i) printf("%c", c);
  printf("\n");
  int m;
  if (n%2)
    m = (n + 1) / 2 - 2;
  else
    m = n/2 - 2;
  for (int i = 0; i < m; ++i) {
    printf("%c", c);
    for (int j = 0; j < n - 2; ++j) printf("%c", ' ');
    printf("%c\n", c);
  }
  for (int i = 0; i < n; ++i) printf("%c", c);
  printf("\n");
  return 0;
}
