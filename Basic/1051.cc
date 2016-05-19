// 此题有大坑！
#include <stdio.h>
#include <math.h>
int main() {
  double r1, p1, r2, p2, r, p;
  scanf("%lf%lf%lf%lf", &r1, &p1, &r2, &p2);
  r = (cos(p1)*cos(p2) - sin(p1)*sin(p2)) * r1 * r2;
  p = (cos(p1)*sin(p2) + sin(p1)*cos(p2)) * r1 * r2;
  if (r > -0.01) // 当r > -0.01时，即使是负数也舍去为0.00，而且此题即使舍为0.00，依然是0.00，而不是0或者不写！！！
    printf("%.2lf", fabs(r));
  else // 只有当r <= -0.01时，前面才会有负号
    printf("-%.2lf", fabs(r));
  if (p > -0.01) // p情况同理
    printf("+%.2lfi", fabs(p));
  else
    printf("-%.2lfi", fabs(p));
  printf("\n");
  return 0;
}
