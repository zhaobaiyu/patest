#include <stdio.h>
#include <ctype.h>
#include <string.h>
int sum[62], need[62];
int main() {
  char a[1005], b[1005];
  scanf("%s%s", a, b);
  int lena = strlen(a), lenb = strlen(b);
  for (int i = 0; i < lena; ++i) {
    if (isdigit(a[i])) {
      ++sum[a[i] - '0'];
    } else if (islower(a[i])) {
      ++sum[a[i] - 'a' + 10];
    } else {
      ++sum[a[i] - 'A' + 36];
    }
  }
  for (int i = 0; i < lenb; ++i) {
    if (isdigit(b[i])) {
      ++need[b[i] - '0'];
    } else if (islower(b[i])) {
      ++need[b[i] - 'a' + 10];
    } else {
      ++need[b[i] - 'A' + 36];
    }
  }
  int find = 1, yu = 0, que = 0;
  for (int i = 0; i < 62; ++i) {
    if (sum[i] < need[i]) {
      find = 0;
      que += need[i] - sum[i];
    }
    if (find)
      yu += sum[i] - need[i];
  }
  if (find) 
    printf("Yes %d\n", yu);
  else
    printf("No %d\n", que);
  return 0;
}
