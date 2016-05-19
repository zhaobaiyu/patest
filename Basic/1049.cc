// 关于浮点数运算，有两点需要注意
#include <stdio.h>
int main() {
  int n;
  double temp, sum = 0.0; // 这里要用double，因为float精度不够
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lf", &temp);
    sum += temp * (i + 1) * (n - i); // 这里顺序很重要，temp不能在最后，误差很大
  }
  printf("%.2lf\n", sum);
  return 0;
}
