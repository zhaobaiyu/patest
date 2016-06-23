// 这一题主要考察小数部分的四舍五入，因为数据简单，所以直接转换为整型处理。
#include <stdio.h>
int main() {
  double w, t, l, a[3];
  for (int i = 0; i < 3; ++i) {
    scanf("%lf%lf%lf", &w, &t, &l);
    if (w > l && w > t) {
      a[i] = w;
      printf("W ");
    } else if (t > w && t > l) {
      a[i] = t;
      printf("T ");
    } else {
      a[i] = l;
      printf("L ");
    }
  }
  int b[3];
  for (int i = 0; i < 3; ++i)
    b[i] = a[i]*10;
  int ans = (b[0]*b[1]*b[2]*65 - 100000)*2;
  int y = ans%1000;
  if (y >= 500) {
    ans = ans/1000 + 1;
  } else {
    ans = ans/1000;
  }
  double ans_d = ans/100.0;
  printf("%.2lf\n", ans_d);
  return 0;
}
