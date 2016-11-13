#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

vector<int> a(4);
int x, y;
int get_digit(int n) {
  a[0] = n/1000;
  a[1] = n%1000/100;
  a[2] = n%1000%100/10;
  a[3] = n%1000%100%10;
  sort(a.begin(), a.end());
  x = a[0]*1000 + a[1]*100 + a[2]*10 + a[3];
  y = a[3]*1000 + a[2]*100 + a[1]*10 + a[0];
  int sub = y - x;
  return sub;
}
int main() {
  int n;
  cin >> n;
  int ans = get_digit(n);
  while (ans != 0 && ans != 6174) {
    cout << setfill('0') << setw(4) << y << " - " << setw(4) << x << " = " << setw(4) << ans << endl;
    n = ans;
    ans = get_digit(n);
  }
  cout << setfill('0') << setw(4) << y << " - " << setw(4) << x << " = " << setw(4) << ans << endl;
  return 0;
}
