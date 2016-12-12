#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, m, ans;
  int tmp;
  cin >> n >> m;
  vector<int> mask(m);
  vector<int> corr(m);
  for (int i = 0; i < m; ++i) 
    cin >> mask[i];
  for (int i = 0; i < m; ++i)
    cin >> corr[i];
  for (int i = 0; i < n; ++i) {
    ans = 0;
    for (int j = 0; j < m; ++j) {
      cin >> tmp;
      if (tmp == corr[j])
        ans += mask[j];
    }
    cout << ans << endl;
  }
  return 0;
}
