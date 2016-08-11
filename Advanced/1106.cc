#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::queue;

int main() {
  std::ios::sync_with_stdio(false);
  int n, temp1, temp2;
  double p, r;
  cin >> n >> p >> r;
  vector<vector<int> > t(n);
  for (int i = 0; i < n; ++i) {
    cin >> temp1;
    for (int j = 0; j < temp1; ++j) {
      cin >> temp2;
      t[i].push_back(temp2);
    }
  }
  vector<int> level(n);
  level[0] = 0;
  int sum = 0, ans_level;
  queue<int> qu;
  qu.push(0);
  while (!qu.empty()) {
    temp1 = qu.front();
    qu.pop();
    if (sum != 0 && level[temp1] > ans_level)
      break;
    if (t[temp1].empty()) {
      ++sum;
      ans_level = level[temp1];
      continue;
    }
    for (auto iter = t[temp1].cbegin(); iter != t[temp1].cend(); ++iter) {
      level[*iter] = level[temp1] + 1;
      qu.push(*iter);
    }
  }
  double ans = p * pow(1 + r/100, ans_level);
  cout << std::fixed << std::setprecision(4) << ans << ' ' << sum << endl;
  return 0;
}
    
