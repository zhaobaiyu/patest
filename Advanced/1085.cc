#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
  int n, p, temp;
  cin >> n >> p;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> temp;
    a[i] = temp;
  }
  std::sort(a.begin(), a.end(), std::greater<int>());
  int i = 0, j;
  temp = a[i] / p;
  bool zc = (a[i] % p == 0) ? true : false;
  if (a[n - 1] > temp || (a[n - 1] == temp && zc)) {
    j = n - 1;
  } else {
    for (int k = n - 2; k >= 0; --k) 
      if ((!zc && a[k] > temp && a[k + 1] <= temp) || (zc && a[k] >= temp && a[k + 1] < temp)) {
        j = k;
        break;
      }
  }
  
  int max_dist = 0;
  while (j < n) {
    temp = a[i] / p;
    zc = (a[i] % p == 0) ? true : false;
    while (j < n) {
      if (j == n - 1 && (a[n - 1] > temp || (a[n - 1] == temp && zc))) {
        max_dist = std::max(max_dist, j - i + 1);
      } else if ((!zc && a[j] > temp && a[j + 1] <= temp) || (zc && a[j] >= temp && a[j + 1] < temp)) {
        max_dist = std::max(max_dist, j - i + 1);
        break;
      } 
      ++j;
    }
    ++i;
  }
  cout << max_dist << endl;
  return 0;
}
