#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
vector<int> post_order, in_order;
unordered_map<int, pair<int, int> > t;
int ctree(int pbeg, int pend, int ibeg, int iend) {
  if (pbeg > pend || ibeg > iend) {
    return -1;
  } else if (pbeg == pend || ibeg == iend) {
    t.insert({post_order[pbeg], {-1, -1}});
    return post_order[pbeg];
  } else {
    int mid;
    for (int i = ibeg; i <= iend; ++i) {
      if (in_order[i] == post_order[pend]) {
        mid = i;
        break;
      }
    }
    int left = ctree(pbeg, mid - 1 - ibeg + pbeg, ibeg, mid - 1);
    int right = ctree(mid - ibeg + pbeg, pend - 1, mid + 1, iend);
    t.insert({post_order[pend], {left, right}});
    return post_order[pend];
  }
  
}
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  post_order.resize(n);
  in_order.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> post_order[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> in_order[i];
  }
  int root = ctree(0, n-1, 0, n-1);
  queue<int> qu;
  qu.push(root);
  cout << root;
  int tmp;
  while (qu.size() != 0) {
    tmp = qu.front();
    qu.pop();
    if (t[tmp].first != -1) {
      qu.push(t[tmp].first);
      cout << ' ' << qu.back();
    }
    if (t[tmp].second != -1) {
      qu.push(t[tmp].second);
      cout << ' ' << qu.back();
    }
  }
  cout << endl;
  return 0;
}
