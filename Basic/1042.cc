#include <stdio.h>
#include <ctype.h>
int sum[26];
int main() {
  char c;
  int max = 0, max_c;
  while ((c = getchar()) != '\n') 
    if (islower(c))
      ++sum[c - 'a'];
    else if (isupper(c))
      ++sum[c - 'A'];
  for (int i = 0; i < 26; ++i) 
    if (max < sum[i]) {
      max = sum[i];
      max_c = i;
    }
  printf("%c %d\n", 'a' + max_c, max);
  return 0;
}
