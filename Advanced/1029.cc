#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int n1, n2, dist;
vector<int> a;
vector<int> b;
int main() {
  std::ios::sync_with_stdio(false);
  cin >> n1;
  a.assign(n1, 0);
  for (int i = 0; i < n1; ++i)
    cin >> a[i];
  cin >> n2;
  b.assign(n2, 0);
  for (int i = 0; i < n2; ++i)
    cin >> b[i];
  dist = (n1 + n2 - 1)/2;
  int k = 0, i = 0, j = 0;
  while (k < dist) {
    if (i == n1) 
      break;
    else if (j == n2)
      break;
    else if (a[i] < b[j])
      ++i;
    else
      ++j;
    ++k;
  }
  if (i == n1) {
    j += dist - k;
    cout << b[j];
  }
  else if (j == n2) {
    i += dist - k;
    cout << a[i];
  } else if (a[i] < b[j])
    cout << a[i];
  else
    cout << b[j];
  cout << endl;
  return 0;
}
    
