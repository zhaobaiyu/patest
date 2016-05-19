#include <stdio.h>
#include <stdlib.h>
int num[100005], ok[100005], final[100005];
int cmp(const void *pa, const void *pb) {
  return *(int *)pa - *(int *)pb;
}
int main() {
  int n, m = 0, max = 0, min = 2000000000;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &num[i]);
  }
  
  for (int i = 0; i < n; ++i) {
    if (max < num[i]) {
      max = num[i];
      ++ok[i];
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    if (min > num[i]) {
      min = num[i];
      ++ok[i];
    }
  }
  
  for (int i = 0; i < n; ++i) 
    if (ok[i] == 2) 
      final[m++] = num[i];
  qsort(final, m, sizeof(int), cmp);
  if (m == 0) { // 第一次提交错误，因为没有考虑这里的 m == 0 的情况
    printf("%d\n", m);
  } else {
    printf("%d\n%d", m, final[0]);
    for (int i = 1; i < m; ++i) 
      printf(" %d", final[i]);
  }
  printf("\n");
  return 0;
}
