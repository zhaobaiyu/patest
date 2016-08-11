#include <iostream>
#include <vector>
#include <set>
#include <climits>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::set;

int main() {
  std::ios::sync_with_stdio(false);
  int n, temp;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> temp;
    a[i] = temp;
  }
  vector<bool> may_num(n, false);
  set<int> ans;
  int max = 0, min = INT_MAX;
  for (int i = 0; i < n; ++i)
    if (a[i] > max) {
      max = a[i];
      may_num[i] = true;
    }
  for (int i = n - 1; i >= 0; --i)
    if (a[i] < min) {
      min = a[i];
      if (may_num[i] == true)
        ans.insert(a[i]);
    }
  cout << ans.size() << endl;
  for (auto iter = ans.begin(); iter != ans.end(); ++iter) 
    if (iter == ans.begin()) {
      cout << *iter;
    } else {
      cout << ' ' << *iter;
    }
  cout << endl;
  return 0;
}
