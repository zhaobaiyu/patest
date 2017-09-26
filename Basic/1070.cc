#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<double> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  double ans = a[0];
  for (int i = 1; i < n; ++i) {
    ans = (ans + a[i]) / 2;
  }
  int ans_i = ans;
  cout << ans_i << endl;
  return 0;
}
