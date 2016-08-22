#include <iostream>
#include <cmath>
using namespace std;
int main() {
  int n, m;
  cin >> n;
  int mid;
  bool is_su;
  for (int i = 0; i < n; ++i) {
    cin >> m;
    mid = sqrt(m);
    is_su = true;
    if (m == 1) {
      cout << "No";
    } else if (m == 2) {
      cout << "Yes";
    } else if (m%2 == 0) {
      cout << "No";
    } else {
      for (int j = 3; j <= mid; j += 2) 
        if (m%j == 0) {
          cout << "No";
          is_su = false;
          break;
        }
      if (is_su)
        cout << "Yes";
    }
    cout << endl;
  }
  return 0;
}
