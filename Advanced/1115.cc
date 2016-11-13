#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
  int n, tmp, node;
  cin >> n;
  vector<pair<int, pair<int, int> > > t(n); // 这里出现一个小bug，找了半天……  这里已经设置了数量n，可是刚开始没细心，还在下面push_back，自然出错了……而且容易找到……
  cin >> tmp;
  t[0].first = tmp;
  t[0].second = {-1, -1};
  for (int i = 1; i < n; ++i) {
    cin >> tmp;
    t[i] = {tmp, {-1, -1}};
    node = 0;
    while (node != -1) 
      if (tmp <= t[node].first) {
        if (t[node].second.first == -1) {
          t[node].second.first = i;
          node = -1;
        } else {
          node = t[node].second.first;
        }
      } else {
        if (t[node].second.second == -1) {
          t[node].second.second = i;
          node = -1;
        } else {
          node = t[node].second.second;
        }
      }
  }
  queue<int> qu;
  vector<int> level_sum, level(n);
  int level_tmp = -1;
  level[0] = 0;
  qu.push(0);
  while (!qu.empty()) {
    tmp = qu.front();
    qu.pop();
    if (level_tmp < level[tmp]) {
      ++level_tmp;
      level_sum.push_back(0);
    }
    ++level_sum[level[tmp]];
    if (t[tmp].second.first != -1) {
      qu.push(t[tmp].second.first);
      level[t[tmp].second.first] = level[tmp] + 1;
    }
    if (t[tmp].second.second != -1) {
      qu.push(t[tmp].second.second);
      level[t[tmp].second.second] = level[tmp] + 1;
    }
  }
  cout << level_sum[level_sum.size() - 1] << " + " << level_sum[level_sum.size() - 2] << " = " << level_sum[level_sum.size() - 1] + level_sum[level_sum.size() - 2] << endl;
  return 0;
}
