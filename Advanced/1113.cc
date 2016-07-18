#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
  int n, temp;
  cin >> n;
  vector<int> d;
  for (int i = 0; i < n; ++i) {
    cin >> temp;
    d.push_back(temp);
  }
  std::sort(d.begin(), d.end());
  int temp1 = 0, temp2 = 0;
  for (int i = 0; i < n/2; ++i) 
    temp1 += d[i];
  for (int i = n/2; i < n; ++i)
    temp2 += d[i];
  cout << ((n%2 == 0) ? 0 : 1) << ' ' << temp2 - temp1 << endl;
  return 0;
}
    
