#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
int main() {
  int su_num(1), su[10005];
  su[1] = 2;
  for (int i = 3; i < 10000000; i = i + 2) {
    bool is_su(true);
    for (int j = 3; j <= sqrt(i); ++j) 
      if (i % j == 0) {
        is_su = false;
        break;
      }
    if (!is_su) {
      continue;
    } else {
      su[++su_num] = i;
    }
    if (su_num == 10000) {
      break;
    }
  }
  int m, n, inline_num(0);
  cin >> m >> n;
  for (int i = m; i <= n; ++i) {
    if (inline_num++) cout << ' ';
    cout << su[i];
    if (inline_num == 10) {
      cout << endl;
      inline_num = 0;
    }
  }
  if (inline_num != 0) cout << endl;
  return 0;
}
