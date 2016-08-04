#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
  vector<int> a(3);
  int tmp1, tmp2;
  cin >> a[0] >> a[1] >> a[2];
  cout << '#';
  for (int i = 0; i < 3; ++i) {
    tmp1 = a[i]/13;
    tmp2 = a[i]%13;
    switch (tmp1) {
      case 10: cout << 'A'; break;
      case 11: cout << 'B'; break;
      case 12: cout << 'C'; break;
      default : cout << tmp1;
    }
    switch (tmp2) {
      case 10: cout << 'A'; break;
      case 11: cout << 'B'; break;
      case 12: cout << 'C'; break;
      default : cout << tmp2;
    }    
  }
  cout << endl;
  return 0;
}
