#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>

using namespace std;

bool is_legal(const string &s) {
  unsigned pos = 0, dotnum = 0;
  if (s[0] == '-') pos++;
  while (pos < s.size()) {
    if (!isdigit(s[pos]) && s[pos] != '.') return false;
    if (s[pos] == '.') {
      ++dotnum;
      if (pos < s.size() - 3)
        return false;
    }
    ++pos;
  }
  if (dotnum > 1)
    return false;
  return true;
}

int main() {
  int n;
  cin >> n;
  string str;
  double sum = 0, temp;
  int num = 0;
  for (int i = 0; i < n; ++i) {
    cin >> str;
    if (is_legal(str)) {
      temp = stof(str);
      if (temp < -1000 || temp > 1000) {
        cout << "ERROR: " << str << " is not a legal number" << endl;
      } else {
        ++num;
        sum += stof(str);
      }
    } else {
      cout << "ERROR: " << str << " is not a legal number" << endl;
    }
  }
  if (num == 0) {
    cout << "The average of 0 numbers is Undefined" << endl;
  } else if (num == 1) {
    cout << "The average of 1 number is " << fixed << setprecision(2) << sum << endl;
  } else {
    cout << "The average of " << num << " numbers is " << fixed << setprecision(2) << sum/num << endl;
  }
  return 0;
}
