#include <stdio.h>
int main() {
  int n, last = 0, temp, sum = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &temp);
    temp -= last;
    last += temp;
    if (temp > 0)
      sum += temp*6;
    else if (temp < 0)
      sum += (-1*temp)*4;
    sum += 5;
  }
  printf("%d\n", sum);
  return 0;
}
