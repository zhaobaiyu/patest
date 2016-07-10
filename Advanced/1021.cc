// 暴力求解，PAT上有一个测试点跑了950ms，而此题限制在1500ms，性能不好。
// 下次要重写
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using std::queue;
using std::vector;

int n;
bool has_c = false;
void dfs(const vector<vector<int>> &g, vector<bool> &ved, int root, vector<int> &last1) {
  ved[root] = true;
  for (const auto i : g[root]) {
    if (i != last1[root]) {
      if (ved[i]) {
        has_c = true;
        return;
      }
      last1[i] = root;
      dfs(g, ved, i, last1);
    }
  }
}

int bfs(const vector<vector<int>> &g, int root, vector<int> &last2) {
  queue<int> qu;
  vector<int> sum(n + 1);
  qu.push(root);
  sum[root] = 0;
  int temp;
  while (!qu.empty()) {
    temp = qu.front();
    qu.pop();
    for (const auto i : g[temp]) {
      if (i != last2[temp]) {
        last2[i] = temp;
        qu.push(i);
        sum[i] = sum[temp] + 1;
      }
    }
  }
  return sum[temp];
}

int main() {
  scanf("%d", &n);
  vector<vector<int>> g(n + 1);
  int temp1, temp2;
  for (int i = 0; i < n - 1; ++i) {
    scanf("%d%d", &temp1, &temp2);
    g[temp1].push_back(temp2);
    g[temp2].push_back(temp1);
  }

  vector<bool> dfs_ved(n + 1);
  int sum1 = 0;
  for (int i = 1; i <= n; ++i) {
    if (dfs_ved[i] == false) {
      vector<int> last1(n + 1);
      last1[i] = -1;
      dfs(g, dfs_ved, i, last1);
      ++sum1;
    }
  }
  if (sum1 != 1) {
    printf("Error: %d components\n", sum1);
    return 0;
  } else if (has_c) {
    printf("Error: 1 components\n");
    return 0;
  }

  vector<int> bfs_ans(n + 1);
  for (int i = 1; i <= n; ++i) {
    vector<int> last2(n + 1);
    last2[i] = -1;
    bfs_ans[i] = bfs(g, i, last2);
  }
  int max = *std::max_element(bfs_ans.begin(), bfs_ans.end());
  for (int i = 1; i <= n; ++i) {
    if (bfs_ans[i] == max) {
      printf("%d\n", i);
    }
  }
  return 0;
}
