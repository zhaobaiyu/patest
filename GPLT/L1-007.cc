#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  int n;
  cin >> n;
  vector<string> py = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
  if (n < 0) {
    cout << "fu ";
    n = -n;
  }
  vector<int> ans;
  while (n/10 != 0) {
    ans.push_back(n%10);
    n /= 10;
  }
  ans.push_back(n%10);
  auto i = ans.size() - 1;
  while (i > 0) {
    cout << py[ans[i]] << ' ';
    --i;
  }
  cout << py[ans[0]] << endl;
  return 0;
}
