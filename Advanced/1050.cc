#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);
  unordered_set<char> is_exist;
  for (auto ch: s2) {
    is_exist.insert(ch);
  }
  for (auto ch: s1) {
    if (is_exist.find(ch) == is_exist.end()) {
      cout << ch;
    }
  }
  cout << endl;
  return 0;
}
