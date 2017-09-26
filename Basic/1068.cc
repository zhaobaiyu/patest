#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int n, m, tol, curr;
  cin >> m >> n >> tol;
  vector<vector<int> > a(n+2, vector<int>(m+2));
  
  for (int i = 0; i < n + 2; ++i) {
    a[i][0] = INT_MIN;
    a[i][m+1] = INT_MIN;
  }
  for (int i = 0; i < m + 2; ++i) {
    a[0][i] = INT_MIN;
    a[n+1][i] = INT_MIN;
  }

  unordered_map<int, int> n_exist;
  for (int i = 1; i < n + 1; ++i) {
    for (int j = 1; j < m + 1; ++j) {
      cin >> curr;
      a[i][j] = curr;
      if (n_exist.find(curr) == n_exist.end()) {
        n_exist[curr] = 1;
      } else {
        n_exist[curr] += 1;
      }
    }
  }

  bool check1, check2, check3, has_found = false, has_one = false;
  int ii, jj;
  for (int i = 1; i < n + 1; ++i) {
    for (int j = 1; j < m + 1; ++j) {
      curr = a[i][j];
      if (n_exist[curr] > 1) {
        continue;
      }
      check1 = (abs(a[i - 1][j - 1] - curr) > tol) && (abs(a[i - 1][j] - curr) > tol) && (abs(a[i - 1][j + 1] - curr) > tol);
      check2 = (abs(a[i][j - 1] - curr) > tol) && (abs(a[i][j + 1] - curr) > tol);
      check3 = (abs(a[i + 1][j - 1] - curr) > tol) && (abs(a[i + 1][j] - curr) > tol) && (abs(a[i + 1][j + 1] - curr) > tol);
      if (check1 && check2 && check3) {

        // cout << a[i - 1][j - 1] << ' ' << a[i - 1][j] << ' ' << a[i - 1][j + 1] << endl; /////////////////
        // cout << a[i][j - 1] << ' ' << a[i][j] << ' ' <<a[i][j + 1] << endl; /////////////////
        // cout << a[i + 1][j - 1] << ' ' << a[i + 1][j] << ' ' << a[i+ 1][j+1] << endl;  //////////////////////
        // has_found = true;
        if (has_one) {
          has_found = true;
          cout << "Not Unique" << endl;
          break;
        } else {
          has_one = true;
          ii = i;
          jj = j;
        }
        // break;
      }
    }
    if (has_found) {
      break;
    }
  }
  
  if (!has_found) {
    if (has_one) {
      cout << '(' << jj << ", " << ii << "): " << a[ii][jj] << endl;      
    } else {
      cout << "Not Exist" << endl;      
    }
  }
  return 0;
}
