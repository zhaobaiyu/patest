#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<int> num, ans;
vector<pair<int, int> > t;
int c = 0;
void in_order(int r) {
  if (t[r].first != -1) {
    in_order(t[r].first);
  }
  ans[r] = num[c++];
  if (t[r].second != -1) {
    in_order(t[r].second);
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  num.resize(n);
  ans.resize(n);
  t.resize(n);
  int tmp1;
  vector<bool> is_root(n, true);
  for (int i = 0; i < n; ++i) {
    cin >> t[i].first >> t[i].second;
    if (t[i].first != -1) {
      is_root[t[i].first] = false;
    }
    if (t[i].second != -1) {
      is_root[t[i].second] = false;
    }
  }
  int root;
  for (int i = 0; i < n; ++i) {
    cin >> num[i];
    if (is_root[i] == true) {
      root = i;
    }
  }
  sort(num.begin(), num.end());
  in_order(root);
  queue<int> qu;
  qu.push(root);
  cout << ans[qu.back()];
  while (qu.size() != 0) {
    tmp1 = qu.front();
    qu.pop();
    if (t[tmp1].first != -1) {
      qu.push(t[tmp1].first);
      cout << ' ' << ans[qu.back()];
    }
    if (t[tmp1].second != -1) {
      qu.push(t[tmp1].second);
      cout << ' ' << ans[qu.back()];
    }
  }
  cout << endl;
  return 0;
}
