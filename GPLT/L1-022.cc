#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
  int n, ou = 0, ji = 0, temp;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> temp;
    if (temp % 2 == 0)
      ++ou;
    else
      ++ji;
  }
  cout << ji << ' ' << ou << endl;
  return 0;
}
