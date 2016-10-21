#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, ans = -1;
  cin >> n;
  vector<int> a(n);
  vector<pair<int, int> > b;
  for (int i = 0; i < n; ++i) 
    cin >> a[i];
  sort(a.begin(), a.end());
  for (int i = 0; i < n; ++i) 
    b.push_back({a[i] - 1, n - i});
  for (int i = 0; i < n; ++i)
    if (b[i].first >= b[i].second) {
      ans = b[i].second;
      break;
    }
  if (ans == -1)
    ans = 0;
  cout << ans << endl;
  return 0;
}
