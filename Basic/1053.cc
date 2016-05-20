#include <stdio.h>
int main() {
  int n, d, x = 0, y = 0, day, temp_d;
  double e, temp_e;
  scanf("%d%lf%d", &n, &e, &d);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &day);
    temp_d = 0;
    for (int j = 0; j < day; ++j) {
      scanf("%lf", &temp_e);
      if (temp_e < e)
        ++temp_d;
    }
    if (temp_d > day/2) {
      if (day > d) 
        ++y;
      else
        ++x;
    }
  }
  printf("%.1lf%% %.1lf%%\n", double(x)/n*100, double(y)/n*100);
  return 0;
}
