#include <iostream>
#include <string>
#include <unordered_set>
#include <iomanip>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int n, m, sum_stu = 0, sum_obj = 0, tmp;
  cin >> n >> m;
  unordered_set<int> obj;
  for (int i = 0; i < m; ++i) {
    cin >> tmp;
    obj.insert(tmp);
  }
  string str;
  int n_tmp;
  bool has_first;
  for (int i = 0; i < n; ++i) {
    cin >> str >> n_tmp;
    has_first = false;
    for (int j = 0; j < n_tmp; ++j) {
      cin >> tmp;
      if (obj.find(tmp) != obj.end()) {
        ++sum_obj;
        if (!has_first) {
          has_first = true;
          ++sum_stu;
          cout << str << ": " << setfill('0') << setw(4) << tmp;
        } else {
          cout << ' ' << setfill('0') << setw(4) << tmp;
        }
      }
    }
    if (has_first) {
      cout << endl;
    }
  }
  cout << sum_stu << ' ' << sum_obj << endl;
  return 0;
}
