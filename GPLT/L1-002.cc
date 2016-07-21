#include <iostream>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;

int main() {
  int n;
  char c;
  cin >> n >> c;
  int i = 1, j = 1;
  vector<pair<int, int> > a;
  a.push_back({i, j});
  while (j <= 1000) {
    i += 2;
    j += i * 2;
    a.push_back({i, j});
  }
  for (const auto &p : a) 
    if (p.second <= n) {
      i = p.first;
      j = p.second;
    } else {
      break;
    }
  for (int ii = i; ii > 0; ii -= 2) {
    for (int jj = 0; jj < (i - ii)/2; ++jj)
      cout << ' ';
    for (int jj = 0; jj < ii; ++jj)
      cout << c;
    cout << endl;
  }
  for (int ii = 3; ii <= i; ii += 2) {
    for (int jj = 0; jj < (i - ii)/2; ++jj)
      cout << ' ';
    for (int jj = 0; jj < ii; ++jj) 
      cout << c;
    cout << endl;
  }
  cout << n - j << endl;
  // cout << i << j << endl;
  return 0;
}
