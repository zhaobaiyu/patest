#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
  int n, tmp1, tmp2;
  double sum;
  cin >> n;
  double max = -1;
  for (int i = 0; i < n; ++i) {
    cin >> tmp1 >> tmp2;
    sum = sqrt(tmp1 * tmp1 + tmp2 * tmp2);
    if (sum > max) {
      max = sum;
    }
  }
  cout << setprecision(2) << fixed << max << endl;
  return 0;
}
    
