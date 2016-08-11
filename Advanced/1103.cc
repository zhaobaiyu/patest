#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <numeric>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::set;

int max_nk;
int kk;
vector<int> final;
int max_sum = 0, max_temp;

void dfs(int n, int k, int pre, const vector<int> &ex, vector<int> &ans) {
  if (k == 1) {
    for (int i = 0; i < max_nk; ++i) 
      if (ex[i] == n) {
        ans[kk - 1] = i + 1;
        max_temp = std::accumulate(ans.begin(), ans.end(), 0);
        if (max_temp > max_sum) {
          max_sum = max_temp;
          final = ans;
        } else if (max_temp == max_sum) {
          final = ans;
        }
        /*
        for (int j = 0; j < kk; ++j) {
          cout << ans[j] << ' ';
        }
        cout << endl;
        */
      } else if (ex[i] > n) {
        break;
      }
    return;
  }
  
  for (int i = pre; i < max_nk; ++i) {
    // cout << "flag1: " << kk - k << ' ' << i << endl; //
    ans[kk - k] = i + 1;
    dfs(n - ex[i], k - 1, i, ex, ans);
  }
  return;
}

int main() {
  std::ios::sync_with_stdio(false);
  int n, k, p;
  cin >> n >> k >> p;
  kk = k;
  max_nk = pow(n-k-1, 1.0/p);
  vector<int> ex(max_nk), ans(k);
  for (int i = 0; i < max_nk; ++i) 
    ex[i] = pow(i + 1, p);
  dfs(n, k, 0, ex, ans);
  
  if (max_sum == 0) {
    cout << "Impossible" << endl;
  } else {
    cout << n << " = " << final[0] << "^" << p;
    for (int i = 1; i < k; ++i) {
      cout << " + " << final[i] << "^" << p;
    }
    cout << endl;
  }
  return 0;
}
  


/*
bool find_ans(int n, int k, const set<int> &ex) {
  bool ans = false;
  int left = n/2, right;
  if (k == 1) {
    if (ex.find(n) != ex.end()) {
      ans = true;
      //
    }
    return ans;
  }
  if (k == 2) {
    while (left >= 1) {
      right = n - left;
      cout << "flag1: " << left << endl; // test
      if (ex.find(left) != ex.end() && ex.find(right) != ex.end()) {
        ans = true;
        //
        break;
      }
      --left;
    }
    return ans;
  }
  
  int high_k, low_k;
  low_k = k/2;
  high_k = k - low_k;

  while (left >= low_k) {
    right = n - left;
    cout << "flag2: " << left << ' ' << right << endl << endl << endl; // test
    if (find_ans(left, low_k, ex) && find_ans(right, high_k, ex)) {
      ans = true;
      //
      break;
    }
    --left;
  }
  return ans;
}
    

int main() {
  int n, k, p;
  cin >> n >> k >> p;
  int max_nk = pow(n-k-1, 1.0/p);
  vector<int> ex(max_nk);
  for (int i = 0; i < max_nk; ++i) 
    ex[i] = pow(i + 1, p);
  set<int> ex_set(ex.begin(), ex.end());

  bool ans = find_ans(n, k, ex_set);
  cout << ans << endl;
  // double base = pow(n/k, 1.0/p);
  // cout << max_nk << endl << base << endl;
  return 0;
}
*/
