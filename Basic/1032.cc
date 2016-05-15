#include <stdio.h>
int a[100005];
int main() {
  int n, temp1, temp2, max_sum = 0, max_num;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &temp1, &temp2);
    a[temp1] += temp2;
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] >= max_sum) { // 序号从1开始，可能只有一家，值为0
      max_sum = a[i];
      max_num = i;
    }
  }
  printf("%d %d\n", max_num, max_sum);
  return 0;
}
