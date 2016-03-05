#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
  int n, m, a[105];
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> a[i];
  while (m--) {
    int temp = a[n - 1];
    for (int i = n - 2; i >= 0; --i) a[i + 1] = a[i];
    a[0] = temp;
  }
  for (int i = 0; i < n - 1; ++i) cout << a[i] << ' ';
  cout << a[n - 1] << endl;
  return 0;
}
