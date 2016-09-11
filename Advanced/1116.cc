#include <iostream>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;
int is_prime(int a) {
  if (a == 2 || a == 3) {
    return 1;
  } else if (a%2 == 0) {
    return 0;
  }
  int mid = sqrt(a);
  for (int i = 3; i <= mid; i += 2) {
    if (a%i == 0) {
      return 0;
    }
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  map<int, int> m;
  int tmp;
  cin >> tmp;
  m.insert({tmp, 1});
  for (int i = 2; i <= n; ++i) {
    cin >> tmp;
    m.insert({tmp, i});
  }
  int mm;
  cin >> mm;
  set<int> is_check;
  for (int i = 0; i < mm; ++i) {
    cin >> tmp;
    cout << setfill('0') << setw(4) << tmp << ": ";
    if (is_check.find(tmp) != is_check.end()) {
      cout << "Checked" << endl;
    } else if (m.find(tmp) == m.end()) {
      cout << "Are you kidding?" << endl;
    } else if (m[tmp] == 1) {
      cout << "Mystery Award" << endl;
      is_check.insert(tmp);
    } else if (is_prime(m[tmp]) == 1) {
      cout << "Minion" << endl;
      is_check.insert(tmp);
    } else {
      cout << "Chocolate" << endl; 
      is_check.insert(tmp);
    }
  }
  return 0;
}
