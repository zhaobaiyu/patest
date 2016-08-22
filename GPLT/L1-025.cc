#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int num(string s) {
  if(s[0] == '+')
    s = s.substr(1);
  for (auto ch : s) 
    if (!isdigit(ch)) 
      return -1;
  int a = std::stoi(s);
  if (a < 1 || a > 1000)
    return -1;
  return a;
}

int main() {
  string str_a, str_b, c;
  std::getline(cin, c);
  std::istringstream ss(c);
  int a, b;
  if (c[0] == ' ') {
    a = -1;
    str_b = c.substr(1);
    b = num(str_b);
  } else {
    ss >> str_a;
    getline(ss, str_b);
    str_b = str_b.substr(1);
    a = num(str_a), b = num(str_b);
  }
  if (a != -1 && b != -1)
    cout << a << " + " << b << " = " << a + b << endl;
  else if (a == -1 && b != -1)
    cout << "? + " << b << " = ?" << endl;
  else if (a != -1 && b == -1)
    cout << a << " + ? = ?" << endl;
  else if (a == -1 && b == -1)
    cout << "? + ? = ?" << endl;
  return 0;
}
