#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<int> base(1001, 0);

int find_base(int a) {
  while (base[a] != base[base[a]])
    a = base[a];
  return base[a];
}

int main() {
  std::ios::sync_with_stdio(false);
  int n, temp, first, child, base_temp;
  cin >> n;
  char c;
  vector<int> ans(1001, 0);
  for (int i = 0; i < n; ++i) {
    cin >> temp >> c >> first;
    if (base[first] != 0) {
      first = find_base(first);
      ++ans[first];
    } else {
      base[first] = first;
      ans[first] = 1;
    }
    for (int j = 1; j < temp; ++j) {
      cin >> child;
      if (base[child] == 0) {
        base[child] = first;
      } else {
        base_temp = find_base(child);
        ans[first] += ans[base_temp];
        ans[base_temp] = 0;
        base[base_temp] = first;
      }
    }
  }
  std::sort(ans.begin(), ans.end(), std::greater<int>());
  int sum = 0;
  for (int i = 0; i < 1001; ++i)
    if (ans[i] != 0) {
      ++sum;
    } else {
      break;
    }
  cout << sum << endl << ans[0];
  for (int i = 1; i < 1001; ++i)
    if (ans[i] != 0)
      cout << ' ' << ans[i];
    else
      break;
  cout << endl;
  return 0;
}
