#include <iostream>
using namespace std;
int main() {
  int n, c, sum = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> c;
    sum += c*(n - 1)*11;
  }
  cout << sum << endl;
  return 0;
}
