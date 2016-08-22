#include <iostream>
#include <string>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  string str;
  cin >> str;
  bool neg = (str[0] == '-') ? true : false;
  int sum = (neg) ? str.size() - 1 : str.size();
  bool odd = ((str[str.size() - 1] - '0')%2 == 0) ? true : false;
  int sum2 = 0;
  for (auto ch : str)
    if (ch == '2')
      ++sum2;
  double ans = 1.0*sum2/sum;
  if (neg)
    ans *= 1.5;
  if (odd)
    ans *= 2;
  ans *= 100;
  cout << std::setprecision(2) << std::fixed << ans << "%" << endl;
  return 0;
}
