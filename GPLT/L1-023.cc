#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main() {
  std::ios::sync_with_stdio(false);
  string s;
  cin >> s;
  vector<int> sum(4, 0), test(4, 0);
  for (auto c : s) 
    switch(c) {
      case 'g':
      case 'G': ++sum[0]; break;
      case 'p':
      case 'P': ++sum[1]; break;
      case 'l':
      case 'L': ++sum[2]; break;
      case 't':
      case 'T': ++sum[3]; break;
    }
  
  while (sum != test) {
    if (sum[0] != 0) {
      cout << 'G';
      --sum[0];
    }
    if (sum[1] != 0) {
      cout << 'P';
      --sum[1];
    }
    if (sum[2] != 0) {
      cout << 'L';
      --sum[2];
    }
    if (sum[3] != 0) {
      cout << 'T';
      --sum[3];
    }
  }
  cout << endl;
  return 0;
}
