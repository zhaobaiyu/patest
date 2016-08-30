#include <iostream>
#include <set>
#include <vector>
#include <iomanip>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<set<int> > sets(n+1);
  int m, temp;
  for (int i = 1; i <= n; ++i) {
    cin >> m;
    for (int j = 0; j < m; ++j) {
      cin >> temp;
      sets[i].insert(temp);
    }
  }
  int k;
  cin >> k;
  int r1, r2, re;
  for (int i = 0; i < k; ++i) {
    re = 0;
    cin >> r1 >> r2;
    for (auto c : sets[r1])
      if (sets[r2].find(c) != sets[r2].end())
        ++re;
    cout << setprecision(2) << fixed << 100.0*re/(sets[r2].size() + sets[r1].size() - re) << "%" << endl;
  }
  return 0;
}
