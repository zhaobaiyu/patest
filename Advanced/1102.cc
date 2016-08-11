#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::vector;
using std::string;
using std::getline;
using std::queue;

void invert(int root, vector<pair<int, int> > &t) {
  if (t[root].first != -1) 
    invert(t[root].first, t);
  if (t[root].second != -1)
    invert(t[root].second, t);
  /*
  int temp = t[root].first;
  t[root].first = t[root].second;
  t[root].second = temp;
  */
  std::swap(t[root].first, t[root].second);
  return;
}

int order = 0;
void in_order(const int root, const vector<pair<int, int> > &t) {
  if (t[root].first != -1)
    in_order(t[root].first, t);
  if (order == 0) 
    cout << root;
  else 
    cout << ' ' << root;
  ++order;
  if (t[root].second != -1)
    in_order(t[root].second, t);
  return;
}

int main() {
  int n, root;
  cin >> n;
  string s;
  getline(cin, s);
  vector<pair<int, int> > t(n);
  vector<bool> is_root(n, true);
  for (int i = 0; i < n; ++i) {
    getline(cin, s);
    if (s[0] == '-') 
      t[i].first = -1;
    else {
      t[i].first = s[0] - '0';
      is_root[t[i].first] = false;
    }
    if (s[2] == '-')
      t[i].second = -1;
    else {
      t[i].second = s[2] - '0';
      is_root[t[i].second] = false;
    }
  }
  for (int i = 0; i < n; ++i)
    if (is_root[i]) {
      root = i;
      break;
    }
  invert(root, t);
  queue<int> qu;
  int temp;
  qu.push(root);
  cout << root;
  while (!qu.empty()) {
    temp = qu.front();
    qu.pop();
    if (t[temp].first != -1) {
      cout << ' ' << t[temp].first;
      qu.push(t[temp].first);
    }
    if (t[temp].second != -1) {
      cout << ' ' << t[temp].second;
      qu.push(t[temp].second);
    }
  }
  cout << endl;
  in_order(root, t);
  cout << endl;
  return 0;
}
    
