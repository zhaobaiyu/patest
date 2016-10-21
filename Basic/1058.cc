#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, m, tmp, tmp2, tmpsum;
  char c, tmpc;
  cin >> n >> m;
  vector<int> ti(m, 0), score(m), err(m, 0);
  for (int i = 0; i < m; ++i) {
    cin >> score[i] >> tmp >> tmp2;
    for (int j = 0; j < tmp2; ++j) {
      cin >> c;
      ti[i] += 1 << (c - 'a');
    }
  }
  for (int i = 0; i < n; ++i) {
    tmpsum = 0;
    for (int j = 0; j < m; ++j) {
      tmp2 = 0;
      cin >> tmpc >> tmp;
      for (int k = 0; k < tmp; ++k) {
        cin >> c;
        tmp2 += 1 << (c - 'a');
      }
      cin >> tmpc;
      if (tmp2 == ti[j])
        tmpsum += score[j];
      else
        ++err[j];
    }
    cout << tmpsum << endl;
  }
  int max_err = *max_element(err.cbegin(), err.cend());
  if (max_err == 0) {
    cout << "Too simple";
  } else {
    cout << max_err;
    for (int i = 0; i < m; ++i)
      if (err[i] == max_err) 
        cout << ' ' << i+1;
  }
  cout << endl;
  return 0;
}
      
