#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
  int xishu, zhishu;
  bool first_flag(true);
  while (cin >> xishu >> zhishu) {
    if (first_flag && zhishu == 0) {
      cout << 0 << ' ' << 0;
      break;
    }
    if (zhishu == 0) continue;
    if (!first_flag) cout << ' ';
    first_flag = false;
    cout << xishu*zhishu << ' ' << zhishu - 1;
  }
  cout << endl;
  return 0;
}
