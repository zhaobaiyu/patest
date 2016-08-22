#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
  std::ios::sync_with_stdio(false);
  int a, b, n, a1, a2, b1, b2, a_drink = 0, b_drink = 0;
  bool is_a = false, is_b = false, a_win, b_win;
  cin >> a >> b >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a1 >> a2 >> b1 >> b2;
    if (is_a || is_b)
      continue;
    a_win = (a1 + b1 == a2) ? false : true;
    b_win = (a1 + b1 == b2) ? false : true;
    if (a_win && !b_win)
      ++b_drink;
    if (!a_win && b_win)
      ++a_drink;
    if (a < a_drink) 
      is_a = true;
    else if (b < b_drink)
      is_b = true;
  }
  if (is_a) 
    cout << "A" << endl << b_drink << endl;
  else if (is_b)
    cout << "B" << endl << a_drink << endl;
  return 0;
}
