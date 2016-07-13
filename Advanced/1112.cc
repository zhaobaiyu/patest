#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::vector;

int main() {
  string::size_type k;
  cin >> k;
  string a;
  cin >> a;
  map<char, bool> if_s;
  vector<char> ans, ans_temp;
  string::size_type i = 0, j;
  while (i < a.size()) {
    auto iter = if_s.find(a[i]);
    if (iter != if_s.end() && !iter->second) {
      ++i;
      continue;
    }
    j = 1;
    while (j < k && i + j < a.size() && a[i] == a[i + j]) ++j;
    if (j != k) {
      if_s[a[i]] = false;
      i += j - 1;
    } else {
      if (iter == if_s.end()) {
        if_s[a[i]] = true;
        ans_temp.push_back(a[i]);
      }
      i += j;
    }
  }
  for (const auto &cc : ans_temp) 
    if (if_s[cc])
      ans.push_back(cc);
  for (const auto &cc : ans) 
    cout << cc;
  cout << endl;
  i = 0;
  while (i < a.size()) {
    cout << a[i];
    if (std::find(ans.begin(), ans.end(), a[i]) == ans.end())
      ++i;
    else
      i += k;
  }
  cout << endl;
  return 0;
}
