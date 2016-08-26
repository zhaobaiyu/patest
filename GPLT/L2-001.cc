#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main() {
  int n, m, s, d;
  cin >> n >> m >> s >> d;
  vector<int> teams(n);
  for (int i = 0; i < n; ++i)
    cin >> teams[i];
  vector<vector<pair<int, int> > > g(n);
  int c1, c2, temp;
  for (int i = 0; i < m; ++i) {
    cin >> c1 >> c2 >> temp;
    g[c1].emplace_back(c2, temp);
    g[c2].emplace_back(c1, temp);
  }
  vector<int> dist(n, INT_MAX);
  dist[s] = 0;
  vector<int> pre(n);
  pre[s] = -1;
  vector<int> path(n, 0);
  path[s] = 1;
  vector<bool> visited(n, false);
  vector<int> has_teams(n, 0);
  has_teams[s] = teams[s];
  int min_dist;
  for ( ; ; ) {
    min_dist = INT_MAX;
    for (int i = 0; i < n; ++i) 
      if (!visited[i] && dist[i] < min_dist) {
        min_dist = dist[i];
        c1 = i;
      }
    if (min_dist == INT_MAX)
      break;
    visited[c1] = true;
    for (auto temp_pair : g[c1]) {
      c2 = temp_pair.first;
      temp = temp_pair.second;
      if (!visited[c2]) {
        if (dist[c2] > dist[c1] + temp) {
          dist[c2] = dist[c1] + temp;
          pre[c2] = c1;
          has_teams[c2] = has_teams[c1] + teams[c2];
          path[c2] = path[c1];
        } else if (dist[c2] == dist[c1] + temp) {
          path[c2] += path[c1];
          if (has_teams[c2] < has_teams[c1] + teams[c2]) {
            pre[c2] = c1;
            has_teams[c2] = has_teams[c1] + teams[c2];
          }
        }
      }
    }
  }
  cout << path[d] << ' ';
  int j = d, all_teams = 0;
  vector<int> ans;
  while (j != -1) {
    all_teams += teams[j];
    ans.push_back(j);
    j = pre[j];
  }
  cout << all_teams << endl << ans[ans.size() - 1];
  for (int i = ans.size() - 2; i >= 0; --i)
    cout << ' ' << ans[i];
  cout << endl;
  return 0;
}
  
      
