#include <stdio.h>
#include <string.h>
int main() {
  char str[1005];
  scanf("%s", str);
  int sum[10];
  memset(sum, 0, sizeof(sum));
  for (int i = 0; i < strlen(str); ++i) {
    sum[str[i] - '0']++;
  }
  for (int i = 0; i < 10; ++i) {
    if (sum[i]) {
      printf("%d:%d\n", i, sum[i]);
    }
  }
  return 0;
}
