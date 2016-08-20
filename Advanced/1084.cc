#include <iostream>
#include <string>
#include <set>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::set;

int main() {
  std::ios::sync_with_stdio(false);
  string str1, str2;
  cin >> str1 >> str2;
  string::size_type i = 0, j = 0;
  char ch1, ch2;
  set<char> s;
  // cout << "flag1: " << str1 << endl; // test
  // cout << "flag2: " << str2 << endl;   // test
  while (i < str1.size()) {
    ch1 = toupper(str1[i]);
    // cout << "flag2: " << ch1 << endl; // test
    if (j == str2.size()) {
      if (s.find(ch1) == s.end()) {
        cout << ch1;
        s.insert(ch1);
      }
    } else {
      ch2 = toupper(str2[j]);
      if (ch1 == ch2) {
        ++j;
      } else if (s.find(ch1) == s.end()) {
        cout << ch1;
        s.insert(ch1);
      }
    }
    ++i;
  }
  cout << endl;
  return 0;
}
