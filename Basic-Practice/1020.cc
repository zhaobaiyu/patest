#include <stdio.h>
int main() {
  typedef struct {
    int a, b;
    double c;
  } yuebing;
  int n, d;
  yuebing yb[1005], temp;
  scanf("%d%d", &n, &d);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &yb[i].a);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &yb[i].b);
    yb[i].c = 1.0*yb[i].b/yb[i].a;
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
  }
  printf("%.2lf\n", sy);
  return 0;
}
