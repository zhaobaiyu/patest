#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n, tmp, tmp1;
  vector<bool> ans(40, false);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    tmp1 = tmp/1000 + tmp/100%10 + tmp/10%10 + tmp%10;
    ans[tmp1] = true;
  }
  tmp = 0;
  for (int i = 0; i < 40; ++i) 
    if (ans[i])
      ++tmp;
  cout << tmp << endl;
  bool flag = false;
  for (int i = 0; i < 40; ++i) {
    if (ans[i] && !flag) {
      cout << i;
      flag = true;
    } else if (ans[i]) {
      cout << ' ' << i;
    }
  }
  cout << endl;
  return 0;
}
