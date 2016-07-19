#include <iostream>
#include <string>
#include <set>
#include <utility>
#include <deque>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::set;
using std::pair;
using std::deque;

int main() {
  std::ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  set<pair<int, string> > a;
  string str;
  int temp; 
  for (int i = 0; i < n; ++i) {
    cin >> str >> temp;
    a.insert({-temp, str}); 
  }
  auto iter = a.cbegin();
  deque<string> row;
  int row_end;
  for (int j = 0; j < k; ++j) {
    if(j == 0) {
      row_end = n/k+n%k;
    } else {
      row_end = n/k;
    }
    row.clear();
    for (int i = 0; i < row_end; ++i) {
      if (i%2 == 0) {
        row.push_back(iter->second);
        ++iter;
      } else {
        row.push_front(iter->second);
        ++iter;
      }
    }
    auto r_iter = row.cbegin();
    cout << *(r_iter++);
    for ( ; r_iter != row.cend(); ++r_iter) {
      cout << ' ' << *r_iter; 
    } 
    cout << endl; 
  }
  return 0;
}
