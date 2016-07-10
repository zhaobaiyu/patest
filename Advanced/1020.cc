#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <utility>

using std::map;
using std::vector;
using std::pair;
using std::queue;

vector<int> post, in;
map<int, pair<int, int>> t;

int creat(int post_f, int post_l, int in_f, int in_l) {
  if (post_f > post_l) {
    return -1;
  }
  int root = post[post_l], i;
  for (i = in_f; i <= in_l; ++i) {
    if (in[i] == root) {
      break;
    }
  }
  t[root].first = creat(post_f, post_f + i - in_f - 1, in_f, i - 1);
  t[root].second = creat(post_f + i - in_f, post_l - 1, i + 1, in_l);
  return root;
}

int main() {
  int n, temp;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &temp);
    post.push_back(temp);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &temp);
    in.push_back(temp);
  }
  int root = creat(0, n-1, 0, n-1);
  queue<int> qu;
  printf("%d", root);
  qu.push(root);
  while (!qu.empty()) {
    temp = qu.front();
    qu.pop();
    if (t[temp].first != -1) {
      printf(" %d", t[temp].first);
      qu.push(t[temp].first);
    }
    if (t[temp].second != -1) {
      printf(" %d", t[temp].second);
      qu.push(t[temp].second);
    }
  }
  printf("\n");
  return 0;
}
