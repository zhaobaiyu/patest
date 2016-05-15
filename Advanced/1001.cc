#include <iostream>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;
void std_format(int a) {
  if (a < 1000) {
    cout << a;
  } else {
    std_format(a/1000);
    cout << ',';
    printf("%03d", a % 1000);
  }
}
int main() {
  signed int a, b;
  cin >> a >> b;
  a += b;
  if (a < 0) {
    a = -a;
    cout << '-';
  }
  std_format(a);
  cout << endl;
  return 0;
}
  
