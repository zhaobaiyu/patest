#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int n, l, m, tmp;
  cin >> n >> l;
  vector<vector<int> > g(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> m;
    for (int j = 0; j < m; ++j) {
      cin >> tmp;
      g[tmp].push_back(i);
    }
  }
  queue<int> qu;
  vector<int> finded;
  int k;
  cin >> k;
  vector<int> level(n+1);
  vector<bool> did(n+1, false);
  for (int i = 0; i < k; ++i) {
    cin >> tmp;
    qu.push(tmp);
    finded.push_back(tmp);
    did[tmp] = true;
    level[tmp] = 0;
    while (!qu.empty()) {
      tmp = qu.front();
      qu.pop();
      if (level[tmp] == l) 
        continue;
      for (auto &v : g[tmp]) {
        if (!did[v]) {
          finded.push_back(v);
          did[v] = true;
          qu.push(v);
          level[v] = level[tmp] + 1;
        }
      }
    }
    cout << finded.size() - 1 << endl;    
    finded.clear();
    for (int j = 0; j <= n; ++j)
      did[j] = false;
  }
  return 0;
}
