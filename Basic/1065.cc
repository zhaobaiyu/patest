#include <iostream>
#include <set>
#include <unordered_map>
#include <iomanip>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, tmp1, tmp2, m;
  cin >> n;
  unordered_map<int, int> map_a;
  set<int> set_b;
  for (int i = 0; i < n; ++i) {
    cin >> tmp1 >> tmp2;
    map_a.insert({tmp1, tmp2});
    map_a.insert({tmp2, tmp1});
  }
  cin >> m;
  bool tmp2not;
  for (int i = 0; i < m; ++i) {
    cin >> tmp1;
    if (map_a.find(tmp1) == map_a.end()) {
      set_b.insert(tmp1);
    } else {
      tmp2 = map_a[tmp1];
      // tmp1not = (set_b.find(tmp1) == set_b.end());
      tmp2not = (set_b.find(tmp2) == set_b.end());
      if (/*tmp1not && */ tmp2not) {
        set_b.insert(tmp1);
      } else if (/*tmp1not && */ !tmp2not) {
        set_b.erase(tmp2);
      }
    }
  }
  cout << set_b.size() << endl;
  bool flag = false;
  for (auto iter = set_b.cbegin(); iter != set_b.cend(); ++iter) {
    if (!flag) {
      flag = true;
      cout << setfill('0') << setw(5) << *iter;
    } else {
      cout << ' ' << setfill('0') << setw(5) << *iter;
    }
  }
  if (set_b.size() != 0) 
    cout << endl;
  return 0;
}
