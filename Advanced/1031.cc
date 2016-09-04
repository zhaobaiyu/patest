#include <iostream>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int n = s.size(), n1, n2;
  if ((n+2)%3 == 0) {
    n1 = n2 = (n+2)/3;
  } else if ((n+2)%3 == 1) {
    n1 = (n+1)/3;
    n2 = n1+1;
  } else {
    n1 = n/3;
    n2 = n1+2;
  }
  for (int i = 0; i < n1-1; ++i) {
    cout << s[i] << string(n2-2, ' ') << s[n-1-i] << endl;
    
  }
  cout << s.substr(n1-1, n2) << endl;
  return 0;
  
}
