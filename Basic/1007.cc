#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::sqrt;
int main() {
  int n, a(2), b(3), cai(0);
  cin >> n;
  while (b <= n) {
    bool is_su(true);
    for (int i = 3; i <= int(sqrt(b)) + 1; ++i) 
      if (b % i == 0) {
        is_su = false;
        break;
      }
    if (!is_su) {
      b = b + 2;
      continue;
    } else if (b - a == 2) {
      ++cai;
    }
    a = b;
    b = b + 2;
  }
  cout << cai << endl;
  return 0;
}
