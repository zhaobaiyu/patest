#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int n, m, id, tmp, tmp1;
  cin >> n >> m;
  vector<vector<int> > t(n+1);
  for (int i = 1; i <= m; ++i) {
    cin >> id >> tmp;
    for (int j = 0; j < tmp; ++j) {
      cin >> tmp1;
      t[id].push_back(tmp1);
    }
  }
  queue<int> qu;
  qu.push(1);
  int tmp_l = 0;
  vector<int> level(n+1), level_num;
  level[1] = 1;
  level_num.push_back(0);
  level_num.push_back(1);
  while (!qu.empty()) {
    tmp = qu.front();
    qu.pop();
    if (level[tmp] != tmp_l) {
      ++tmp_l;
      level_num.push_back(0);
    }
    level_num[tmp_l+1] += t[tmp].size();
    for (auto &v : t[tmp]) {
      level[v] = level[tmp] + 1;
      qu.push(v);
    }
  }
  tmp = 0;
  for (unsigned i = 1; i < level_num.size(); ++i) 
    if (level_num[i] > tmp) {
      tmp = level_num[i];
      tmp1 = i;
    }
  cout << tmp << ' ' << tmp1 << endl;
  return 0;
}
