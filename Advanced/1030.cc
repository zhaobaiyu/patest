#include <iostream>
#include <vector>
#include <tuple>
#include <climits>

using namespace std;

void printpath(int s, int d, const vector<int> &pre) {
  if (s != d) 
    printpath(s, pre[d], pre);
  cout << d << ' ';
}

int main() {
  ios::sync_with_stdio(false);
  int n, m, s, d, c1, c2, temp_d, temp_c;
  cin >> n >> m >> s >> d;
  vector<vector<pair<int, pair<int, int> > > > g(n);
  for (int i = 0; i < m; ++i) {
    cin >> c1 >> c2 >> temp_d >> temp_c;
    g[c1].push_back({c2, {temp_d, temp_c}});
    g[c2].push_back({c1, {temp_d, temp_c}});    
  }
  vector<int> visited(n, false);
  vector<pair<int, int> > dc(n, make_pair(INT_MAX, 0));
  dc[s].first = 0;
  vector<int> pre(n);
  pre[s] = -1;
  int min_dist;
  for ( ; ; ) {
    min_dist = INT_MAX;
    for (int i = 0; i < n; ++i) 
      if (!visited[i] && dc[i].first < min_dist) {
        min_dist = dc[i].first;
        c1 = i;
      }
    if (min_dist == INT_MAX)
      break;
    visited[c1] = true;
    for (const auto &pp : g[c1]) {
      c2 = pp.first;
      temp_d = pp.second.first;
      temp_c = pp.second.second;
      if (!visited[c2]) {
        if (dc[c2].first > dc[c1].first + temp_d) {
          dc[c2].first = dc[c1].first + temp_d;
          pre[c2] = c1;
          dc[c2].second = dc[c1].second + temp_c;
        } else if (dc[c2].first == dc[c1].first + temp_d && dc[c2].second > dc[c1].second + temp_c) {
          pre[c2] = c1;
          dc[c2].second = dc[c1].second + temp_c;
        }
      }
    }
  }
  printpath(s, d, pre);
  cout << dc[d].first << ' ' << dc[d].second << endl;
  return 0;
}
      
