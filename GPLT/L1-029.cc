#include <iostream>
#include <iomanip>
using namespace std;
int main() {
  int n;
  cin >> n;
  double ans = (n - 100)*0.9*2;
  cout << setprecision(1) << fixed << ans << endl;
  return 0;
}
