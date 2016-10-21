#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
int sum = 0;
void cal(const char &c) {
  // cout << "flag: " << c << endl;
  if (isupper(c)) 
    sum += c - 'A' + 1;
  else if (islower(c))
    sum += c - 'a' + 1;
  return;
}
int main() {
  ios::sync_with_stdio(false);
  string s;
  getline(cin, s);
  for_each(s.begin(), s.end(), cal);
  int sum1 = 0, sum0 = 0;
  while (sum != 0) {
    if (sum%2 == 1)
      ++sum1;
    else
      ++sum0;
    sum /= 2;
  }
  // cout << sum <<endl;
  cout << sum0 << ' ' << sum1 << endl;
  return 0;
}
