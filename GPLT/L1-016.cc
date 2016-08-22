#include <iostream>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  int n, sum;
  cin >> n;
  string str;
  const int num[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
  const string m = "10X98765432";
  bool pass = true, right;
  for (int i = 0; i < n; ++i) {
    cin >> str;
    sum = 0;
    right = true;
    for (int j = 0; j < 17; ++j) {
      if (!isdigit(str[j])) {
        right = false;
        break;
      }
      sum += (str[j] - '0') * num[j];
    }
    if (!right) {
      cout << str << endl;
      pass = false;
      continue;
    }
    sum %= 11;
    if (str[17] != m[sum]) {
      cout << str << endl;
      pass = false;
    }
  }
  if (pass) 
    cout << "All passed" << endl;
  return 0;
}
    
