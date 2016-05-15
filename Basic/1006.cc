#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
  int n;
  cin >> n;
  string s = string(n/100, 'B') + string(n/10%10, 'S');
  for (int i = 1; i <= n%10; ++i) {
    char ge = '0' + i;
    s = s + ge;
  }
  cout << s << endl;
  return 0;
}
