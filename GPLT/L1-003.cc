#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  string s;
  vector<int> n(10, 0);
  cin >> s;
  for (const auto &ch : s) 
    ++n[ch - '0'];
  for (int i = 0; i < 10; ++i) 
    if (n[i] != 0) 
      cout << i << ':' << n[i] << endl;
  return 0;
}
