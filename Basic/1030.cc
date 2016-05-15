#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
unsigned array[100005];
int cmp(const void *pa, const void *pb) {
  return *(int *)pa - *(int *)pb;
}
int main() {
  unsigned p;
  int n;
  scanf("%u%u", &n, &p);
  for (int i = 0; i < n; ++i) scanf("%u", &array[i]);
  qsort(array, n, sizeof(unsigned), cmp);
  int px = 0, py = 0, temp = 0, max = 0;
  unsigned temp_mul;
  while (py < n) {
    if (temp_mul != UINT_MAX) { // 防止乘法溢出
      temp_mul = (array[px] * p / p == array[px]) ? array[px] * p : UINT_MAX;
    }
    while (array[py] <= temp_mul && py < n) {
      temp++;
      py++;
    }
    if (temp > max) max = temp;
    px++;
    temp--;
  }
  printf("%d\n", max);
  return 0;
}
