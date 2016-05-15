#include <iostream>
#include <cstdio>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
int main() {
  double a[1005], temp;
  memset(a, 0, sizeof(a));
  int k, k2, nk[20], nk2[10], temp1, ii;
  cin >> k;
  for (int i = 0; i < k; ++i) {
    cin >> temp1;
    cin >> temp;
    if (temp == 0) {
      ii++;
      continue;
    }
    nk[i - ii] = temp1;
    a[temp1] += temp;    
  }
  k -= ii;
  cin >> k2;
  ii = 0;
  for (int i = 0; i < k2; ++i) {
    cin >> temp1;
    cin >> temp;
    if (temp == 0) {
      ii++;
      continue;
    }
    if (a[temp1] != 0) {
      ii++;
    } else {
      nk2[i - ii] = temp1;
    }
    a[temp1] += temp;
  }
  k2 -= ii;
  for (int i = k; i < k + k2; ++i) {
    nk[i] = nk2[i - k];
  }
  k += k2;
  ii = 0;
  for (int i = 0; i < k; ++i) {  // the sum may be 0
    if (a[nk[i]] == 0) {
      for (int j = i; j < k - 1; ++j) {
        nk[j] = nk[j + 1];
      }
      ii++;
    }
  }
  k -= ii;
  for (int i = 1; i < k; ++i) 
    for (int j = i - 1; j >= 0 && nk[j + 1] > nk[j]; j--) {
      temp = nk[j + 1];
      nk[j + 1] = nk[j];
      nk[j] = temp;
    }
  cout << k;
  for (int i = 0; i < k; i++)
    printf(" %d %.1lf", nk[i], a[nk[i]]);
  cout << endl;
  return 0;
}
