#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
  int n, t[105];
  bool a[105];
  cin >> n;
  for (int i = 1; i <= n; ++i) a[i] = false;
  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
    int temp = t[i];
    while (temp != 1) 
      if (temp%2 == 0) {
        temp = temp/2;
        if (temp < 105) a[temp] = true;
      } else {
        temp = (temp*3 + 1)/2;  // read the problem carefully!!!
        if (temp < 105) a[temp] = true;
      }
  }
  bool space_flag = false;
  for (int i = n; i > 0; --i) 
    if (a[t[i]] == 0) {
      if (space_flag) cout << " ";
      cout << t[i];
      space_flag = 1;
    }
  cout << endl;
  return 0;
}
