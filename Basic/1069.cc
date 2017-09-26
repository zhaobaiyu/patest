#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int m, n, s;
  cin >> m >> n >> s;
  string str;
  unordered_set<string> has_zj;
  for (int i = 0; i < s - 1; ++i) {
    cin >> str;
  }
  int num = 0;
  for (int i = s; i < m + 1; ++i) {
    cin >> str;
    if (num % n == 0) {
      if (has_zj.find(str) != has_zj.end()) {
        continue;
      } else {
        cout << str << endl;
        has_zj.insert(str);
      }
    }
    ++num;
  }
  if (has_zj.size() == 0) {
    cout << "Keep going..." << endl;
  }
  return 0;
}
