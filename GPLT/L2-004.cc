#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
bool isMirror;
int creat_tree(const vector<int> &pre, int begin, int end, vector<pair<int, int> > &tree) {
  if (begin > end) 
    return -1;
  else if (begin == end) {
    tree[begin].first = -1;
    tree[begin].second = -1;
    return begin;
  }
  int root = pre[begin], mid = INT_MAX;
  if (!isMirror) {
    for (int i = begin; i < end; ++i) 
      if (pre[i+1] >= root) {
        mid = i;
        break;
      }
    if (mid == INT_MAX)
      mid = end;
    for (int i = mid + 1; i <= end; ++i) 
      if (pre[i] < root) {
        return -2;
      }
  } else {
    for (int i = begin; i < end; ++i) 
      if (pre[i+1] < root) {
        mid = i;
        break;
      }
    if (mid == INT_MAX)
      mid = end;
    for (int i = mid + 1; i <= end; ++i) 
      if (pre[i] >= root) {
        return -2;
      }
  }
  int temp_l = creat_tree(pre, begin+1, mid, tree);
  if (temp_l == -2)
    return -2;
  int temp_r = creat_tree(pre, mid+1, end, tree);
  if (temp_r == -2)
    return -2;
  tree[begin].first = temp_l;
  tree[begin].second = temp_r;
  return begin;
}

bool isFirst = true;
void post_order(int root, const vector<pair<int, int> > &tree, const vector<int> &pre) {
  if (tree[root].first != -1)
    post_order(tree[root].first, tree, pre);
  if (tree[root].second != -1)
    post_order(tree[root].second, tree, pre);
  if (isFirst) {
    isFirst = false;
    cout << pre[root];
  } else {
    cout << ' ' << pre[root];
  }
}
  
int main() {
  int n;
  cin >> n;
  vector<int> pre(n);
  for (int i = 0; i < n; ++i)
    cin >> pre[i];
  isMirror = (pre[0] <= pre[n-1]) ? false : true;
  vector<pair<int, int> > tree(n);
  int root = creat_tree(pre, 0, n-1, tree);
  //
  // for (int i = 0; i < n; ++i) 
  //cout << pre[i] << ": " << pre[tree[i].first] << ", " << pre[tree[i].second] << endl;
  //
  if (root != -2) {
    cout << "YES" << endl;
    post_order(root, tree, pre);
    cout << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
