#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <cmath>
using namespace std;
int main () {
  ios::sync_with_stdio(false);
  int first, n, temp, k, next;
  cin >> first >> n;
  map<int, pair<int, int> > list;
  for (int i = 0; i < n; ++i) {
    cin >> temp >> k >> next;
    list.insert({temp, {k, next}});
  }
  vector<pair<int, int> > v1, v2;
  set<int> keys;
  next = first;
  int temp_key;
  pair<int, int> temp_pair;
  while (next != -1) {
    temp_pair = list[next];
    temp_key = temp_pair.first;
    if (keys.find(abs(temp_key)) == keys.end()) {
      keys.insert(abs(temp_key));
      v1.emplace_back(next, temp_key);
    } else {
      v2.emplace_back(next, temp_key);
    }
    next = temp_pair.second;
  }
  cout << setfill('0') << setw(5) << v1[0].first << ' ' << v1[0].second;
  for (unsigned i = 1; i < v1.size(); ++i) {
    cout << ' ' << setfill('0') << setw(5) << v1[i].first << endl;
    cout << setfill('0') << setw(5) << v1[i].first << ' ' << v1[i].second;
  }
  cout << ' ' << -1 << endl;
  if (v2.size() > 0) {
    cout << setfill('0') << setw(5) << v2[0].first << ' ' << v2[0].second;
    for (unsigned i = 1; i < v2.size(); ++i) {
      cout << ' ' << setfill('0') << setw(5) << v2[i].first << endl;
      cout << setfill('0') << setw(5) << v2[i].first << ' ' << v2[i].second;
    }
    cout << ' ' << -1 << endl;
  }
  return 0;
}
