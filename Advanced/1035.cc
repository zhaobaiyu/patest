#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<string, string> > ans;
  string str1, str2;
  bool is_mod;
  for (int i = 0; i < n; ++i) {
    is_mod = false;
    cin >> str1 >> str2;
    for (auto &ch : str2) {
      switch(ch) {
        case '1': ch = '@'; is_mod = true; break;
        case '0': ch = '%'; is_mod = true; break;
        case 'l': ch = 'L'; is_mod = true; break;
        case 'O': ch = 'o'; is_mod = true; break;
      }
    }
    if (is_mod) {
      ans.emplace_back(str1, str2);
    }
  }
  if (ans.size() == 0 && n == 1) {
    cout << "There is 1 account and no account is modified" << endl;
  } else if (ans.size() == 0 && n != 1) {
    cout << "There are " << n << " accounts and no account is modified" << endl;
  } else {
    cout << ans.size() << endl;
    for (unsigned i = 0; i < ans.size(); ++i) {
      cout << ans[i].first << ' ' << ans[i].second << endl;
    }
  }
  return 0;
}
