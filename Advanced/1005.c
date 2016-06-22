#include <stdio.h>
#include <ctype.h>
int main() {
  int n = 0, c;
  const char *str[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  while ((c = getchar()) != EOF && isdigit(c)) 
    n += c - '0';
  int b = n/100, s = n/10%10, g = n%10;
  if (b != 0) 
    printf("%s %s %s\n", str[b], str[s], str[g]);
  else if (s != 0)
    printf("%s %s\n", str[s], str[g]);
  else
    printf("%s\n", str[g]);
  return 0;
}
