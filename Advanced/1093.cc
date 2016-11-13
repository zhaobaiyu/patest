#include <iostream>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  long long p_sum = 0, t_sum = 0, sum = 0;
  for (auto &ch : s) 
    if (ch == 'T')
      ++t_sum;
  // cout << "flag1: " << t_sum << endl;    //
  for (auto &ch : s)
    if (ch == 'P')
      ++p_sum;
    else if (ch == 'T')
      --t_sum;
    else if (ch == 'A') {
      // cout << "flag2: " << p_sum << ' ' << t_sum << ' ' << sum << endl;
      sum += (p_sum * t_sum) % 1000000007;
      // cout << "flag3: " << sum << endl;
      sum %= 1000000007;
      // cout << "flag4: " << sum << endl;
    }
  cout << sum <<endl;
  return 0;
}
