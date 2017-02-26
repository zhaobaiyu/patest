#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool is_prime(int i) {
  int t = 3, sqt = sqrt(i);
  while (t <= sqt) {
    if (i % t == 0) {
      return false;
    } else {
      t += 2;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  int m, n;
  cin >> m >> n;
  vector<int> rr{0};
  if (m == 1) {
    ++m;
  } else if (m % 2 == 1) {
    while (!is_prime(m))
      m += 2;
  } else if (m != 2 && m % 2 == 0) {
    ++m;
    while (!is_prime(m))
      m += 2;
  }
  int i = 1, pre = 0, sq = 1;
  if (m == 2) {
    rr.push_back(1);
  } else {
    while (sq != pre) {
      rr.push_back(sq);
      pre = sq;
      ++i;
      sq = i * i % m;
    }
  }
  int rr_size = rr.size();
  vector<bool> a(m, false);
  int tmp, re;
  cin >> tmp;
  re = tmp % m;
  a[re] = true;
  cout << re;
  bool is_find;
  for (int i = 1; i < n; ++i) {
    cin >> tmp;
    re = tmp % m;
    is_find = false;
    for (int j = 0; j < rr_size; ++j) {
      tmp = (re + rr[j]) % m;
      if (!a[tmp]) {
        a[tmp] = true;
        is_find = true;
        cout << ' ' << tmp;
        break;
      }
    }
    if (!is_find) {
      cout << " -";
    }
  }
  cout << endl;
  return 0;
}
