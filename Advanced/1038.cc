#include <iostream>
#include <vector>
#include <string> 
#include <algorithm>
using namespace std;
int main() {
  int n;
  // scanf("%d", &n);
  cin >> n;
  vector<vector<pair<string, int> > > num(8);
  // char s[10];
  string s;
  unsigned ii;
  int need_add, add_round;
  for (int i = 0; i < n; ++i) {
    // scanf("%s", s);
    cin >> s;
    ii = 0;
    while (ii < s.size() && s[ii] == '0') 
      ++ii;
    need_add = 8 - s.size();
    add_round = s.size() - ii;
    if (ii != s.size()) {
      for (int j = 0; j < need_add; ++j) {
        s += s[j%add_round + ii];
      }
      // s += s[ii];
      // cout << s << endl; //
      num[ii].emplace_back(s, need_add);
    }
  }
  
  bool first_zero = true;
  for (int i = 7; i >= 0; --i) {
    if (num[i].size() == 0) {
      continue;
    }
    sort(num[i].begin(), num[i].end());
    // cout << i << endl;
    for (auto iter = num[i].begin(); iter != num[i].end(); ++iter) {
      // cout << "flag0: " << i << ' ' << *iter << endl;
      if (first_zero) {
        first_zero = false;
        // cout << "flag1: " << endl; 
        cout << iter->first.substr(i, iter->first.size() - iter->second - i);
      } else {
        // cout << "flag2: " << endl;
        cout << iter->first.substr(0, iter->first.size() - iter->second);
      }
    }
  }
  if (first_zero) {
    // cout << "flag3: " << endl;
    cout << 0 << endl;
  } else {
    cout << endl;
  }
  return 0;
}
