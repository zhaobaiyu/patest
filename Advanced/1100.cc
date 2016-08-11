#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  std::ios::sync_with_stdio(false);
  const vector<string> low{"", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
  const vector<string> high{"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
  int n, num, shi, ge;
  cin >> n;
  string s, s1, s2;
  unsigned j;
  std::getline(cin, s);
  for (int i = 0; i < n; ++i) {
    std::getline(cin, s);
    if (isdigit(s[0])) {
      num = std::stoi(s);
      shi = num/13;
      ge = num%13;
      if (shi != 0 && ge != 0)
        cout << high[shi] << ' ' << low[ge] << endl;
      else if (shi == 0 && ge != 0)
        cout << low[ge] << endl;
      else if (shi != 0 && ge == 0)
        cout << high[shi] << endl;
      else
        cout << "tret" << endl;
    } else {
      if (s == "tret") {
        num = 0;
      } else {
        j = 0;
        while (j < s.size() && s[j] != ' ') ++j;
        if (s[j] != ' ') {
          for (int k = 1; k < 13; ++k) 
            if (low[k] == s)
              num = k;
          for (int k = 1; k < 13; ++k)
            if (high[k] == s)
              num = k*13;
        } else {
          s1 = s.substr(0, j);
          s2 = s.substr(j+1);
          for (int k = 1; k < 13; ++k)
            if (low[k] == s2)
              num = k;
          for (int k = 1; k < 13; ++k)
            if (high[k] == s1)
              num += k*13;
        }
      }
      cout << num << endl;
    }
  }
  return 0;
}
            
