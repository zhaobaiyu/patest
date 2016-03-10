#include <stdio.h>
int main() {
  typedef struct {
    double a, b, c; // a & b may not be integer
  } yuebing;
  int n, d1;
  yuebing yb[1005], temp;
  scanf("%d%d", &n, &d1);
  double d = d1;
  for (int i = 0; i < n; ++i) {
    scanf("%lf", &yb[i].a);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%lf", &yb[i].b);
    yb[i].c = yb[i].b/yb[i].a;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (yb[i].c < yb[j].c) {
        temp = yb[i];
        yb[i] = yb[j];
        yb[j] = temp;
      }
    }
  }
  double sy = 0;
  int i = 0;
  while (d > 0) {
    if (d <= yb[i].a) {
      sy += yb[i].c*d;
    } else {
      sy += yb[i].b;
    }
    d = d - yb[i].a;
    ++i;
    if (i == n) break; // d may > the sum of yb[].a
  }
  printf("%.2lf\n", sy);
  return 0;
}
