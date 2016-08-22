#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

int main() {
  int n, m;
  char c;
  cin >> n >> c;
  m = std::round(n/2.0);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j)
      cout << c;
    cout << endl;
  }
  return 0;
}
  
