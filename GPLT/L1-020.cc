#include <iostream>
#include <set>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::set;

int main() {
  std::ios::sync_with_stdio(false);
  int n, k, m, id;
  cin >> n;
  set<int> s;
  for (int i = 0; i < n; ++i) {
    cin >> k;
    if (k == 1)
      cin >> id;
    else {
      for (int j = 0; j < k; ++j) {
        cin >> id;
        s.insert(id);
      }
    }
  }
  cin >> m;
  int sum = 0;
  for (int i = 0; i < m; ++i) {
    cin >> id;
    if (s.find(id) == s.end()) {
      if (sum != 0)
        cout << ' ';
      cout << std::setfill('0') << std::setw(5) << id;
      ++sum;
      s.insert(id);
    }
  }
  if (sum == 0)
    cout << "No one is handsome";
  cout << endl;
  return 0;
}
