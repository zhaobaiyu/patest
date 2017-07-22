#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int m, n, a, b, tmp, alt;
  cin >> m >> n >> a >> b >> alt;
  for (int i = 0; i < m; ++i) {
    cin >> tmp;
    if (tmp >= a && tmp <= b) {
      cout << setfill('0') << setw(3) << alt;
    } else {
      cout << setfill('0') << setw(3) << tmp;
    }
    for (int j = 1; j < n; ++j) {
      cin >> tmp;
      cout << ' ';
      if (tmp >= a && tmp <= b) {
        cout << setfill('0') << setw(3) << alt;
      } else {
        cout << setfill('0') << setw(3) << tmp;
      }
    }
    cout << '\n';
  }
  return 0;
}
