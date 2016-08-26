#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  unsigned n;
  char c;
  cin >> n >> c;
  string s;
  std::getline(cin, s);
  std::getline(cin, s);
  if (n > s.size())
    cout << string(n - s.size(), c) << s << endl;
  else
    cout << s.substr(s.size() - n) << endl;
  return 0;
}
