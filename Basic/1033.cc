#include <stdio.h>
#include <ctype.h>
int main() {
  char a[50], b[100005];
  char *pa = a, *pb = b;
  int temp_c;
  while ((temp_c = getchar()) != '\n' && temp_c != '\r') *pa++ = temp_c;
  *pa = '\0';
  scanf("%s", b);
  pa = a;
  while (*pa != '\0') {
    pb = b;
    if (isalpha(*pa)) {
      temp_c = tolower(*pa);
      while (*pb != '\0') {
        if (*pb == *pa || *pb == temp_c) *pb = ' ';
        pb++;
      }
    } else if (*pa == '+') {
      while (*pb != '\0') {
        if (isupper(*pb)) *pb = ' ';
        pb++;
      }
    } else {
      while (*pb != '\0') {
        if (*pb == *pa) *pb = ' ';
        pb++;
      }
    }
    pa++;
  }
  pb = b;
  while (*pb != '\0') {
    if (*pb != ' ') printf("%c", *pb);
    pb++;
  }
  printf("\n");
  return 0;
}
