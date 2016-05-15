#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main() {
  char a[85], b[85], c[85], d[85];
  char *pa = a, *pb = b, *pc = c, *pd = d, *pp;
  scanf("%s%s", a, b);
  while (*pa != '\0') {
    if (*pa == *pb) {
      pa++;
      pb++;
    } else {
      *pc++ = *pa++;
    }
  }
  *pc = '\0';
  pc = c;
  while (*pc != '\0') {
    *pc = toupper(*pc);
    pc++;
  }
  pc = c;
  *pd = '\0';
  int find;
  while (*pc != '\0') {
    find = 0;
    pp = d;
    while(*pp != '\0') {
      if (*pp == *pc) {
        find = 1;
        break;
      }
      pp++;
    }
    if (!find) {
      *pd++ = *pc;
      *pd = '\0';
    }
    pc++;
  }
  printf("%s\n", d);
  return 0;
}
