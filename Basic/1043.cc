#include <stdio.h>
#include <string.h>
int main() {
  char str[10005];
  int a[6];
  scanf("%s", str);
  int len = strlen(str);
  for (int i = 0; i < len; ++i) 
    switch (str[i]) {
      case 'P': ++a[0]; break;
      case 'A': ++a[1]; break;
      case 'T': ++a[2]; break;
      case 'e': ++a[3]; break;
      case 's': ++a[4]; break;
      case 't': ++a[5]; break;
    }
  int sum = 0;
  char pat[] = "PATest";
  for (int i = 0; i < 6; ++i) sum += a[i];
  while (sum != 0) 
    for (int i = 0; i < 6; ++i) 
      if (a[i] > 0) {
        putchar(pat[i]);
        --a[i];
        --sum;
      }
  putchar('\n');
  return 0;
}
