#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  sort(v.begin(), v.end(), greater<int>());
  v.push_back(-1);
  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    /*
    if (v[i] == v[i+1]) {
      continue;
    } else {
    */
      if (i + 1 < v[i]) {
        ans = i + 1;
      } else {
        break;
      }
    
  }
  cout << ans << endl;
  return 0;
  
}
