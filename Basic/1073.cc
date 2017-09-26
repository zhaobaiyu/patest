#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<bool> > corr(m + 1, vector<bool>(5, false));
  vector<int> score(m + 1), n_opt(m + 1);
  int tmp;
  char tmp_c;
  for (int i = 1; i <= m; ++i) {
    cin >> score[i] >> n_opt[i] >> tmp;
    for (int j = 0; j < tmp; ++j) {
      cin >> tmp_c;
      corr[i][tmp_c - 'a'] = true;
    }
  }
  
  int max = 0, loc;
  vector<bool> curr_que(5);
  bool has_error, all_right;
  double stu_score;
  vector<vector<int> > n_err(m+1, vector<int>(5, 0));

  // cout << "where1" << endl; ///////////////////
  for (int i = 0; i < n; ++i) {
    stu_score = 0;
    for (int j = 1; j <= m; ++j) {
      has_error = false;
      all_right = true;
      curr_que = corr[j];
      cin >> tmp_c >> tmp;
      // loc = tmp_c - 'a';
      for (int k = 0; k < tmp; ++k) {
        cin >> tmp_c;
        loc = tmp_c - 'a';
        if (!curr_que[loc]) {
          has_error = true;
          all_right = false;
          ++n_err[j][loc];
          if (n_err[j][loc] > max) {
            max = n_err[j][loc];
          }
        } else {
          curr_que[loc] = false;
        }
      }


      // cout << "where3" << endl; //////////////////
      for (int k = 0; k < 5; ++k) {
        if (curr_que[k]) {
          ++n_err[j][k];
          all_right = false;
          if (n_err[j][k] > max) {
            max = n_err[j][k];
          }
        }
      }

      if (all_right) {
        stu_score += score[j];
      } else if (!has_error) {
        stu_score += score[j] / 2.0;
      }
      
      cin >> tmp_c;
    }
    cout << setprecision(1) << fixed << stu_score << endl;
  }

  // cout << "where2" << endl; ///////////////
  if (max == 0) {
    cout << "Too simple" << endl;
  } else {
    for (int i = 1; i <= m; ++i) {
      for (int j = 0; j < 5; ++j) {
        if (n_err[i][j] == max) {
          cout << max << ' ' << i << '-' << char('a' + j) << endl;
        }
      }
    }
  }
  return 0;
}
