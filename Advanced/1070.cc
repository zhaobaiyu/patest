/**
 * 这一题有一个测试点几次没通过
 * 原因是部分题目中的变量之说正数，没说正整数，月饼的库存和利润都不该是整型。
 * 千万要仔细审题，把每一个变量已知类型确认正确。
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n;
  double d;
  cin >> n >> d;
  vector<double> inv(n);
  vector<pair<double, int> > pri(n);
  vector<double> ppp(n);
  for (int i = 0; i < n; ++i) {
    cin >> inv[i];
  }
  double tmp_d;
  for (int i = 0; i < n; ++i) {
    cin >> tmp_d;
    pri[i] = make_pair(tmp_d / inv[i], i);
    ppp[i] = tmp_d;
  }
  sort(pri.begin(), pri.end(), greater<pair<double, int> >());
  int i = 0;
  double inven;
  double sum = 0;
  while (i < n) {
    if (d <= 0) {
      break;
    }
    inven = inv[pri[i].second];
    if (inven > d) {
      sum += pri[i].first * d;
    } else {
      sum += ppp[pri[i].second];
    }
    d -= inven;
    ++i;
  }
  cout << setprecision(2) << fixed << sum << endl;
  return 0;
}
