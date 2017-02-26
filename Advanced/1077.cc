#include <iostream>
#include <string>
using namespace std;

string pair_str(string s1, string s2) {
  int size1 = s1.size(), size2 = s2.size(), len;
  if (size1 > size2) {
    len = size2 - 1;
    s1 = s1.substr(size1 - size2);
  } else if (size2 < size1) {
    len = size1 - 1;
    s2 = s2.substr(size2 - size1);
  } else {
    len = size1 - 1;
  }
  while (len >= 0 && s1[len] == s2[len]) --len;
  return s1.substr(len + 1);
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  string tmp, ans;
  cin >> n;
  getline(cin, tmp);
  getline(cin, ans);
  for (int i = 1; i < n; ++i) {
    getline(cin, tmp);
    ans = pair_str(tmp, ans);
  }
  if (ans == "") {
    cout << "nai" << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
