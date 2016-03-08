#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main() {
  string a;
  int b, r, aa[1005];
  cin >> a >> b;
  for (int i = 0; i < int(a.size()); ++i) {
    aa[i] = int(a[i]) - 48;
  }
  if (aa[0] < b) {
    if (int(a.size()) == 1) cout << 0;
    r = aa[0];
  } else {
    cout << aa[0]/b;
    r = aa[0]%b;
  }
  for (int i = 1; i < int(a.size()); ++i) {
    cout << (r*10 + aa[i])/b;
    r = (r*10 + aa[i])%b;
  }
  cout << ' ' << r << endl;
  return 0;
}
