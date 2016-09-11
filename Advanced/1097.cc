#include <iostream>
#include <cmath>
#include <unordered_map>
#include <set>
#include <vector>
#include <iomanip>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int f, n;
  cin >> f >> n;
  unordered_map<int, pair<int, int> > m;
  int addr, v, next;
  for (int i = 0; i < n; ++i) {
    cin >> addr >> v >> next;
    m.insert({addr, {v, next}});
  }
  vector<pair<int, int> > a, b;
  set<int> s;
  while (f != -1) {
    if (s.find(abs(m[f].first)) == s.end()) {
      a.emplace_back(f, m[f].first);
      s.insert(abs(m[f].first));
    } else {
      b.emplace_back(f, m[f].first);
    }
    f = m[f].second;
  }
  cout << setfill('0') << setw(5) << a[0].first << ' ' << a[0].second;
  for (unsigned i = 1; i < a.size(); ++i) {
    cout << ' ' << setfill('0') << setw(5) << a[i].first << endl;
    cout << setfill('0') << setw(5) << a[i].first << ' ' << a[i].second;
  }
  cout << ' ' << -1 << endl;
  if (b.size() > 0) {
    cout << setfill('0') << setw(5) << b[0].first << ' ' << b[0].second;
    for (unsigned i = 1; i < b.size(); ++i) {
      cout << ' ' << setfill('0') << setw(5) << b[i].first << endl;
      cout << setfill('0') << setw(5) << b[i].first << ' ' << b[i].second;
    }
    cout << ' ' << -1 << endl;
  }
  return 0;
}
