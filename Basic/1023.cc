#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
  int a[10], flag, find = 0;
  for (int i = 0; i < 10; ++i) {
    cin >> a[i];
    if (!find && i && a[i]) {
      flag = i;
      a[i]--;
      find = 1;
    }
  }
  cout << flag;
  for (int i = 0; i < 10; ++i) 
    for (int j = 0; j < a[i]; ++j) 
      cout << i;
  cout << endl;
  return 0;
}
