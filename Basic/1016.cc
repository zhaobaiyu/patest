#include <iostream>
#include <string>
#include <cmath>
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main() {
  int a_num(0), b_num(0), pa(0), pb(0);
  string a, da, b, db;
  cin >> a >> da >> b >> db;
  for (auto ch : a) {
    if (ch == da[0]) {
      a_num++;
    }
  }
  for (auto ch : b) {
    if (ch == db[0]) {
      b_num++;
    }
  }
  if (a_num == 0) {
    pa = 0;
  } else {
    for (int i = 0; i < a_num; ++i) {
      pa += (int(da[0]) - 48)*pow(10, i);
    }
  }
  if (b_num == 0) {
    pb = 0;
  } else {
    for (int i = 0; i < b_num; ++i) {
      pb += (int(db[0]) - 48)*pow(10, i);
    }
  }
  cout << pa + pb << endl;
  return 0;
}
