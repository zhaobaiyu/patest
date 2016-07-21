#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  std::ios::sync_with_stdio(false);
  int n, temp;
  cin >> n;
  vector<string> s(n+1);
  vector<int> a(n+1), b(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> s[i] >> temp >> b[i];
    a[temp] = i;
  }
  int k;
  cin >> k;
  for (int i = 0; i < k; ++i) {
    cin >> temp;
    cout << s[a[temp]] << ' ' << b[a[temp]] << endl;
  }
  return 0;
}
