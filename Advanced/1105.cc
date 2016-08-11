#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
  std::ios::sync_with_stdio(false);
  int n, nn, mm;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) 
    cin >> a[i];
  std::sort(a.begin(), a.end(), std::greater<int>());
  for (int i = sqrt(n); i >= 1; --i) 
    if (n%i == 0) {
      mm = n/i;
      nn = i;
      break;
    }
  vector<vector<int> > aa(mm, vector<int>(nn));
  int stat = 4, s = 0, x = mm - 1, z = 0, y = nn - 1, num = 0;
  while (num < n) 
    if (stat == 4) {
      for (int i = z; i <= y; ++i) 
        aa[s][i] = a[num++];
      ++s;
      stat = 1;
    } else if (stat == 1) {
      for (int i = s; i <= x; ++i)
        aa[i][y] = a[num++];
      --y;
      stat = 2;
    } else if (stat == 2) {
      for (int i = y; i >= z; --i) 
        aa[x][i] = a[num++];
      --x;
      stat = 3;
    } else if (stat == 3) {
      for (int i = x; i >= s; --i)
        aa[i][z] = a[num++];
      ++z;
      stat = 4;
    }
  
  
  
  for (int i = 0; i < mm; ++i) {
    cout << aa[i][0];
    for (int j = 1; j < nn; ++j) 
      cout << ' ' << aa[i][j];
    cout << endl;
  }
  // cout << mm << ' ' << nn << endl; // test
  /*
  for (int i = 0; i < n; ++i)
    cout << a[i] << ' ';
  cout << endl;
  */
  return 0;
}

