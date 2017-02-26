#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, left = 0, tmp, p = 1, sum = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    a[tmp] = i;
    if (tmp != i)
      ++left;
  }
  if (a[0] != 0) {
    --left;
  }
  while (left > 0) {
    if (a[0] != 0) {
      tmp = a[0];
      a[0] = a[tmp];
      a[tmp] = tmp;
      ++sum;
      --left;
    } else {
      while (p < n && a[p] == p) ++p;
      a[0] = a[p];
      a[p] = 0;
      ++sum;
    }
  }
  cout << sum << endl;
  return 0;
}
