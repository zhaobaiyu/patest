#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;

int main() {
  std::ios::sync_with_stdio(false);
  int a, b;
  cin >> a >> b;
  int j = 0;
  int sum = 0;
  for (int i = a; i <= b; ++i) {
    sum += i;
    cout << std::setw(5) << i;
    ++j;
    if (j%5 == 0)
      cout << endl;
  }
  if (j%5 != 0)
    cout << endl;
  cout << "Sum = " << sum << endl;
  return 0;
}
