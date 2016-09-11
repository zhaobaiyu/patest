#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int sqrtn = sqrt(n);
  int ii = 2, m, max_sum = 0, front, end, jj;
  while (ii <= sqrtn) {
    m = n;
    jj = ii;
    while (m%jj == 0) {
      m /= jj;
      ++jj;
    }
    if (jj - ii > max_sum) {
      max_sum = jj - ii;
      front = ii;
      end = jj - 1;
    }
    ++ii;
  }
  if (max_sum == 0) {
    max_sum = 1;
    front = n;
    end = n;
  }
  cout << max_sum << endl;
  cout << front;
  for (int i = front + 1; i <= end; ++i) {
    cout << '*' << i;
  }
  cout << endl;
  return 0;
}
