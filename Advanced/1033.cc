#include <cstdio>
#include <vector>
#include <algorithm>
int cmax, d, davg, n, dfull;
vector<pair<int, double> > gast;
double cal(int beg, int end, int gas_b, int gas_e) {
  if (end - beg == 1 && gast[end].first - gast[beg].first > dfull) {
    return -1; 
  }
  
  
}
using namespace std;
int main() {
  scanf("%d%d%d%d", &cmax, &d, &davg, &n);
  dfull = cmax*davg;
  int temp;
  double temp_d;
  for (int i = 0; i < n; ++i) {
    scanf("%lf%d", &temp_d, &temp);
    if (temp < d) {
      gast.emplace_back(temp, temp_d);
    }
  }
  sort(gast.begin(), gast.end());
  gast.emplace_back(d, 0);
  n = gast.size();
  cal(0, n-1, 0, 0, gast);
  //
  for (int i = 1; i <= n; ++i) {
    printf("%d %lf\n", gast[i].first, gast[i].second);
  }
  //
  return 0;
}
