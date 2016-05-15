#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    long long a, b, c;
    cin >> a >> b >> c;
    cout << "Case #" << i + 1 << ": ";
    if (a + b > c)
      cout << "true";
    else
      cout << "false";
    cout << endl;
  }
  return 0;
}
    
