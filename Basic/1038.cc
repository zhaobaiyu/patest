#include <stdio.h>
int a[100005], b[100005], c[101];
int main() {
  int n, k, temp;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  scanf("%d", &k);
  for (int i = 0; i < k; ++i) {
    scanf("%d", &b[i]);
  }
  for (int i = 0; i < 101; ++i) {
    temp = 0;
    for (int j = 0; j < n; ++j) 
      if (a[j] == i)
        ++temp;
    c[i] = temp;
  }
  printf("%d", c[b[0]]);
  for (int i = 1; i < k; ++i) {
    printf(" %d", c[b[i]]);
  }
  printf("\n");
  return 0;
}
