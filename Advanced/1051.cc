#include <iostream>
#include <stack>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  unsigned m;
  int n, k, tmp, beg;
  bool ans;
  cin >> m >> n >> k;
  stack<int> st;
  for (int i = 0; i < k; ++i) {
    beg = 1;
    ans = true;
    st.push(0);
    for (int j = 0; j < n; ++j) {
      cin >> tmp;
      if (ans) {
        if (tmp == st.top()) {
          st.pop();
        } else if (tmp > st.top()) {
          for (int x = beg; x < tmp; ++x) {
            st.push(x);
          }
          beg = tmp + 1;
          if (st.size() > m) {
            ans = false;
          }
        } else {
          ans = false;
        }
      }
    }
    if (ans) 
      cout << "YES";
    else
      cout << "NO";
    cout << endl;
    while (!st.empty())
      st.pop();
  }
  return 0;
}
