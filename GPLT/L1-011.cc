#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getchar;
using std::vector;

int main() {
  string str1, str2;
  getline(cin, str1);
  getline(cin, str2);
  vector<bool> exist(300, false);
  for (auto ch : str2) {
    exist[ch] = true;
  }
  for (auto ch : str1) 
    if (!exist[ch])
      cout << ch;
  cout << endl;
  return 0;
}
