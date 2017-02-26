#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

double ans = 0, p, r;
vector<vector<int> > t;
void dfs(int node, int l) {
  if (t[node][0] == 0) {
    ans += t[node][1] * p * pow((1 + r / 100), l);
  } else {
    for (int i = 1; i <= t[node][0]; ++i) {
      dfs(t[node][i], l+1);
    }
  }
  return;
}

int main() {
  ios::sync_with_stdio(false);
  int n, tmp, tmp1;
  cin >> n >> p >> r;
  t.resize(n);
  // vector<vector<int> > t(n);
  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    t[i].push_back(tmp);
    if (tmp == 0) {
      cin >> tmp1;
      t[i].push_back(tmp1);
    }
    for (int j = 0; j < tmp; ++j) {
      cin >> tmp1;
      t[i].push_back(tmp1);
    }
  }
  dfs(0, 0);
  cout << setprecision(1) << fixed << ans << endl;
  return 0;
}
