#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <stack>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::pair;
using std::stack;

int count = 0;
void post_traversal(int r, const vector<pair<int, int> > &t) {
  if (t[r].first != 0) 
    post_traversal(t[r].first, t);
  if (t[r].second != 0)
    post_traversal(t[r].second, t);
  if (count == 0)
    cout << r;
  else
    cout << ' ' << r;
  ++count;
}

int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int root, node, pre;
  string str;
  cin >> str >> root;
  pre = root;
  bool is_push = true;
  stack<int> s;
  s.push(root);
  vector<pair<int, int> > t(n+1, {0, 0});
  for (int i = 0; i < 2*n - 1; ++i) {
    cin >> str;
    if (str == "Push") {
      cin >> node;
      s.push(node);
      if (is_push) 
        t[pre].first = node;
      else
        t[pre].second = node;
      is_push = true;
      pre = node;
    } else {
      pre = s.top();
      is_push = false;
      s.pop();
    }
  }
  post_traversal(root, t);
  cout << endl;
  return 0;
}
