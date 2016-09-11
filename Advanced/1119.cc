#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> preorder;
vector<int> postorder;
unordered_map<int, pair<int, int> > t;
bool is_right = true;
int createt(int preb, int pree, int postb, int poste) {
  if (preb == pree || postb == poste) {
    t.insert({preorder[preb], {-1, -1}});
    return preorder[preb];
  } else if (pree - preb == 1 || poste - postb == 1){
    // cout << "flag1" << endl;    // 
    is_right = false;
    t.insert({postorder[postb], {-1, -1}});
    t.insert({preorder[preb], {postorder[postb], -1}});
    // cout << "FLAG: " << preorder[preb] << endl; //
    return preorder[preb];
  }
  int mid;
  int root = preorder[preb];
  // cout << "flag4: " << root << endl; // 
  for (int i = postb; i < poste; ++i) {
    if (preorder[preb+1] == postorder[i]) {
      // cout << "flag3: " << preorder[preb+1] << endl; //
      mid = i;
      break;
    }
  }
  int left = createt(preb + 1, mid - postb + preb + 1, postb, mid);
  int right = createt(mid - postb + preb + 2, pree, mid + 1, poste);
  t.insert({root, {left, right}});
  return root;
}
bool is_first = false;
void in_order(int root) {
  if (t[root].first != -1) {
    in_order(t[root].first);
  }
  if (!is_first) {
    cout << root;
    is_first = true;
  } else {
    cout << ' ' << root;
  }
  if (t[root].second != -1) {
    in_order(t[root].second);
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;  
  preorder.resize(n);
  postorder.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> preorder[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> postorder[i];
  }
  int root;
  // cout << "flag0" << endl; // 
  root = createt(0, n-1, 0, n-1);
  // cout << "root: " << root << endl;
  if (is_right) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  in_order(root);
  cout << endl;
  return 0;
}
