#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int T, k;
  cin >> T >> k;
  int n1, t, n2;
  bool b;
  for (int i = 0; i < k; ++i) {
    cin >> n1 >> b >> t >> n2;
    if (t > T) {
      cout << "Not enough tokens.  Total = " << T << "." << endl;
    } else {
      if ((b && n2 > n1) || (!b && n2 < n1)) {
        T += t;
        cout << "Win " << t << "!  Total = " << T << "." << endl;
      } else {
        T -= t;
        cout << "Lose " << t << ".  Total = " << T << "." << endl;
        if (T == 0) {
          cout << "Game Over." << endl;
          break;
        }
      }
    }
  }
  return 0;
}
