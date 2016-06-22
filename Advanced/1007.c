#include <stdio.h>
int main() {
  int k, a[10005], sum = 0, max = -1;
  scanf("%d", &k);
  for (int i = 0; i < k; ++i)
    scanf("%d", &a[i]);
  int i = 0, j, first = a[0], last = a[k - 1];
  while (i < k) {
    if (a[i] < 0) {
      ++i;
      continue;
    }
    sum = 0;
    for (j = i; j < k; ++j) {
      sum += a[j];
      if (sum > max) {
        max = sum;
        first = a[i];
        last = a[j];
      } else if (sum < 0) {
        i = j + 1;
        break;
      }
    }
    if (j == k)
      break;
  }
  if (max == -1)
    max = 0;
  printf("%d %d %d\n", max, first, last);
  return 0;
}
