#include <iostream>
#include <vector>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, m, tmp1, tmp2, k;
  cin >> n >> m;
  vector<vector<bool> > g(n+1, vector<bool>(n+1, false));
  for (int i = 0; i < m; ++i) {
    cin >> tmp1 >> tmp2;
    g[tmp1][tmp2] = true;
    g[tmp2][tmp1] = true;
  }
  cin >> k;
  bool flag;
  vector<int> test(n+1);
  vector<bool> visited(n, false);
  for (int i = 0; i < k; ++i) {
    cin >> tmp1;
    if (tmp1 != n+1) {
      for (int j = 0; j < tmp1; ++j) 
        cin >> tmp2;
      cout << "NO" << endl;
    } else {
      for (int j = 0; j < tmp1; ++j)
        cin >> test[j];
      if (test[0] != test[n]) {
        cout << "NO" << endl;
        continue;
      }
      for (int kk = 0; kk < n+1; ++kk)
        visited[kk] = false;
      flag = false;
      for (int kk = 0; kk < n; ++kk) {
        if (visited[test[kk]] || !g[test[kk]][test[kk+1]]) {
          cout << "NO" << endl;
          flag = true;
          break;
        } else {
          visited[test[kk]] = true;
        }
      }
      if (!flag)
        cout << "YES" << endl;
    }
  }
  return 0;
}
