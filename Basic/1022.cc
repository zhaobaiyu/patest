#include <iostream>
using std::cin;
using std::cout;
using std::endl;
void jinzhi(int n, int d) {
  if (n == 0) {
    cout << 0;
  }
  else if (n < d && n) {
    cout << n % d;
  } else {
    jinzhi(n/d, d);
    cout << n % d;
  }
}
int main() {
  int a, b, d;
  cin >> a >> b >> d;
  jinzhi(a + b, d);
  cout << endl;
  return 0;
}
