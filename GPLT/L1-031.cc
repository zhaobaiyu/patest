#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int n;
  cin >> n;
  double h, w;
  double std1;
  for (int i = 0; i < n; ++i) {
    cin >> h >> w;
    std1 = (h - 100)*0.9*2;
    if (abs(std1 - w) < std1*0.1) {
      cout << "You are wan mei!" << endl;
    } else if (abs(std1 - w) >= std1*0.1 && std1 < w) {
      cout << "You are tai pang le!" << endl;
    } else {
      cout << "You are tai shou le!" << endl;
    }
  }
  return 0;
}
