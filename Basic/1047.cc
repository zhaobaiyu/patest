#include <stdio.h>
#include <stdlib.h>
int main() {
  int sum[1005];
  for (int i = 0; i < 1005; ++i) 
    sum[i] = -1;
  int n, temp, temp_num;
  scanf("%d", &n);
  char temp_s[10];
  for (int i = 0; i < n; ++i) {
    scanf("%s%d", temp_s, &temp);
    for (int j = 1; j < 10; ++j) 
      if (temp_s[j] == '-') {
        temp_s[j] = '\0';
        break;
      }
    temp_num = atoi(temp_s);
    if (sum[temp_num] == -1) 
      sum[temp_num] = 0;
    sum[temp_num] += temp;
  }
  int max = -1, max_num;
  for (int i = 0; i < 1005; ++i) {
    if (max < sum[i]) {
      max_num = i;
      max = sum[i];
    }
  }
  printf("%d %d\n", max_num, max);
  return 0;
}
