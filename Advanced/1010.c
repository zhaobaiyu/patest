#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
long long str_to_val(const char *str, int radix) {
  int len = strlen(str), temp_c;
  long long val = 0;
  for (int i = 0; i < len; ++i) {
    if (isdigit(str[i])) {
      temp_c = str[i] - '0';
    } else if (islower(str[i])) {
      temp_c = str[i] - 'a' + 10;
    } else {
      return -1;
    }
    if (temp_c >= radix)
      return -1;
    val += pow(radix, len - 1 - i)*temp_c;
  }
  return val;
}
int main() {
  char s1[12], s2[12], temp[12];
  int tag, radix;
  scanf("%s%s%d%d", s1, s2, &tag, &radix);
  if (tag == 2) {
    strcpy(temp, s1);
    strcpy(s1, s2);
    strcpy(s2, temp);
  }
  long long val = str_to_val(s1, radix);
  // printf("%lld\n", val); //
  if (val == -1) {
    printf("Impossible\n");
    return 0;
  }
  int is_find = 0;
  long long a[37];
  for (int i = 2; i < 37; ++i) {
    a[i] = str_to_val(s2, i);
    if (a[i] == -1)
      continue;
    if (a[i] == val) {
      is_find = 1;
      printf("%d\n", i);
      break;
    }
  }
  if (!is_find)
    printf("Impossible\n");
  return 0;
} 
