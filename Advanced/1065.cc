#include <iostream>
#include <climits>
using namespace std;

int main() {
  int t;
  cin >> t;
  long a, b, c;
  for (int i = 0; i < t; ++i) {
    cin >> a >> b >> c;
    if (a > 0 && b > 0 && a > LONG_MAX - b) {
      cout << "Case #" << i + 1 << ": true" << endl;
    } else if (a < 0 && b < 0 && a < LONG_MIN - b) {
      cout << "Case #" << i + 1 << ": false" << endl;
    } else {
      cout << "Case #" << i + 1 << ": " << (a + b > c ? "true" : "false") << endl;
    }
  }
  return 0;
}
