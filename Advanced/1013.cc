#include <cstdio>
#include <vector>
using std::vector;
using std::iterator;

void dfs(const vector<vector<int> > &g, int lost, int first, vector<bool>& cnt) { // vector 改变数值要用引用, 数值不变的前面要加const
  cnt[first] = true;
  // printf("%d ", first); // test
  for (vector<int>::const_iterator it = g[first].cbegin(); it < g[first].cend(); ++it) {
    if (*it != lost && cnt[*it] == false) {
      dfs(g, lost, *it, cnt);
    }
  }
}

int main() {
  int n, m, k, temp1, temp2;
  scanf("%d%d%d", &n, &m, &k);
  vector<vector<int> > graph(n+1);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &temp1, &temp2);
    graph[temp1].push_back(temp2);
    graph[temp2].push_back(temp1);
  }
  for (int i = 0; i < k; ++i) {
    scanf("%d", &temp1);
    vector<bool> cnt(n+1, false);
    temp2 = 0;
    int j = 1;
    for (vector<bool>::iterator it = cnt.begin() + 1; it < cnt.end(); ++it, ++j) {
      if (*it == false && j != temp1) {
        temp2++;
        // printf("%d: ", j); // test
        dfs(graph, temp1, j, cnt);
        // printf("\n"); // test
      }
    }
    printf("%d\n", temp2 - 1);
  }
  return 0;
}
    
