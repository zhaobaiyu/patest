#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <iomanip>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, c;
  cin >> n >> c;
  vector<tuple<int, string, int> > a(n);
  if (c == 1) {
    map<int, int> dict;
    for (int i = 0; i < n; ++i) {
      cin >> get<0>(a[i]) >> get<1>(a[i]) >> get<2>(a[i]);
      dict[get<0>(a[i])] = i;
    }
    for (const auto &p : dict) 
      cout << setfill('0') << setw(6) << get<0>(a[p.second]) << ' '
           << get<1>(a[p.second]) << ' ' << get<2>(a[p.second]) << endl;
  } else if (c == 2) {
    map<pair<string, int>, int> dict;
    for (int i = 0; i < n; ++i) {
      cin >> get<0>(a[i]) >> get<1>(a[i]) >> get<2>(a[i]);
      dict[make_pair(get<1>(a[i]), get<0>(a[i]))] = i;
    }
    for (const auto &p : dict) 
      cout << setfill('0') << setw(6) << get<0>(a[p.second]) << ' '
           << get<1>(a[p.second]) << ' ' << get<2>(a[p.second]) << endl;
  } else if (c == 3) {
    map<pair<int, int>, int> dict;
    for (int i = 0; i < n; ++i) {
      cin >> get<0>(a[i]) >> get<1>(a[i]) >> get<2>(a[i]);
      dict[make_pair(get<2>(a[i]), get<0>(a[i]))] = i;
    }
    for (const auto &p : dict) 
      cout << setfill('0') << setw(6) << get<0>(a[p.second]) << ' '
           << get<1>(a[p.second]) << ' ' << get<2>(a[p.second]) << endl;
  }
  return 0;
}
