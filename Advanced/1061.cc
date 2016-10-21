#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  string s[4];
  for (int i = 0; i < 4; ++i) 
    cin >> s[i];
  int size1 = (s[0].size() < s[1].size()) ? s[0].size() : s[1].size();
  int size2 = (s[2].size() < s[3].size()) ? s[2].size() : s[3].size();
  int a, b, c;
  bool cap_c = false;
  for (int i = 0; i < size1; ++i) 
    if (s[0][i] == s[1][i]) {
      if (cap_c) {
        if (isdigit(s[0][i])) {
          b = s[0][i] - '0';
          break;
        }
        else if (s[0][i] <= 'N' && s[0][i] >= 'A') {
          b = s[0][i] - 'A' + 10;
          break;
        }
      }
      if (s[0][i] >= 'A' && s[0][i] <= 'G' && !cap_c) {
        a = s[0][i] - 'A';
        cap_c = true;
      }
    }
  for (int i = 0; i < size2; ++i)
    if (isalpha(s[2][i]) && s[2][i] == s[3][i]) {
      c = i;
      break;
    }
  vector<string> days = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
  // cout << a << ' ' << b << ' ' << c << endl;
  cout << days[a] << ' ' << setfill('0') << setw(2) << b << ':' << setfill('0') << setw(2) << c << endl;
  return 0;
}
