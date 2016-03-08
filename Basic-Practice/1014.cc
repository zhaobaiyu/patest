#include <iostream>
#include <string>
#include <cctype>
using std::string;
using std::cin;
using std::cout;
using std::endl;
const string week_str = "MONTUEWEDTHUFRISATSUN";
int main() {
  string str1, str2, str3, str4;
  int num1;
  cin >> str1 >> str2 >> str3 >> str4;
  bool find_first(false);
  for (string::size_type i = 0; i < 65; ++i) {
    if (!find_first) {
      if (!isupper(str1[i]) || !isupper(str2[i])) continue;
      if (str1[i] == str2[i]) {
        num1 = int(str1[i]) - 65;
        if (num1 > 6) continue;
        cout << string(week_str, num1*3, 3) << ' ';
        find_first = true;
        continue;
      }
    }
    if (str1[i] == str2[i]) {
      if (isdigit(str1[i])) {
        cout << '0' << str1[i] << ':';
        break;
      }
      num1 = int(str1[i]) - 65;
      if (isalpha(str1[i]) && num1 >= 0 && num1 <= 13) {
        cout << num1 + 10 << ':';
        break;
      }
    }
  }
  for (string::size_type i = 0; i < 65; ++i) {
    if (!isalpha(str3[i]) || !isalpha(str4[i])) continue;
    if (str3[i] == str4[i]) {
      if (i < 10) {
        cout << '0' << i << endl;
        break;
      } else {
        cout << i << endl;
        break;
      }
    }
  }
  return 0;
}
