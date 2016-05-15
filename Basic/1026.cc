#include <cstdio>
int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  double t = (b - a) / 100.0;
  if (t - int(t) >= 0.5) {
    a = int(t) + 1;
  } else {
    a = int(t);
  }
  int h = a / 3600;
  int m = (a - h * 3600) / 60;
  int s = a - h * 3600 - m * 60;
  printf("%02d:%02d:%02d\n", h, m, s);
  return 0;
}
