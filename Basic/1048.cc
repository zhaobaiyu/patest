#include <stdio.h>
#include <string.h>
int main() {
  char a[105], b[105], c[105], temp_c;
  scanf("%s %s", a, b);
  int lena = strlen(a), lenb = strlen(b), yu;
  for (int i = 0; i < lena/2; ++i) {
    temp_c = a[i];
    a[i] = a[lena - 1 - i];
    a[lena - 1 - i] = temp_c;
  }
  for (int i = 0; i < lenb/2; ++i) {
    temp_c = b[i];
    b[i] = b[lenb - 1 - i];
    b[lenb - 1 - i] = temp_c;
  }
  
  if (lena > lenb) {
    for (int i = lenb; i < lena; ++i) 
      b[i] = '0';
    b[lena] = '\0';
    lenb = lena;
  } else {
    for (int i = lena; i < lenb; ++i)
      a[i] = '0';
    a[lenb] = '\0';
    lena = lenb;
  }
  
  for (int i = 0; i < lena; i += 2) {
    yu = (a[i] - '0' + b[i] - '0')%13;
    switch (yu) {
      case 10: c[i] = 'J'; break;
      case 11: c[i] = 'Q'; break;
      case 12: c[i] = 'K'; break;
      default: c[i] = yu + '0';
    }
  }
  for (int i = 1; i < lena; i += 2) {
    yu = b[i] - a[i];
    if (yu < 0)
      yu += 10;
    c[i] = yu + '0';
  }
  c[lena] = '\0';
  for (int i = 0; i < lena/2; ++i) {
    temp_c = c[i];
    c[i] = c[lena - 1 - i];
    c[lena - 1 - i] = temp_c;
  }
  printf("%s\n", c);
  return 0;
}
