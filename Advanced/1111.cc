#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int n, m, v1, v2, l_tmp, t_tmp;
  bool one_way;
  cin >> n >> m;
  vector<vector<pair<int, int> > > g1(n), g2(n);
  for (int i = 0; i < m; ++i) {
    cin >> v1 >> v2 >> one_way >> l_tmp >> t_tmp;
    g1[v1].push_back({v2, l_tmp});
    g2[v1].push_back({v2, t_tmp});
    if (!one_way) {
      g1[v2].push_back({v1, l_tmp});
      g2[v2].push_back({v1, t_tmp});
    }
  }
  int ss, dd, min, min_node, nebs;
  cin >> ss >> dd;
  vector<int> dest(n, INT_MAX), pre(n), tmp_time(n, INT_MAX);
  dest[ss] = 0;
  vector<bool> visited(n, false);
  
  for ( ; ; ) {
    min = INT_MAX;
    for (int i = 0; i < n; ++i) 
      if (!visited[i] && dest[i] < min) {
        min = dest[i];
        min_node = i;
      }
    if (min == INT_MAX)
      break;
    visited[min_node] = true;
    nebs = g1[min_node].size();
    for (int i = 0; i < nebs; ++i) {
      pair<int, int> v = g1[min_node][i];
      if (!visited[v.first]) {
        if (dest[min_node] + v.second < dest[v.first]) {
          dest[v.first] = dest[min_node] + v.second;
          tmp_time[v.first] = g2[min_node][i].second + tmp_time[min_node];
          pre[v.first] = min_node;
        } else if (dest[min_node] + v.second == dest[v.first] && tmp_time[min_node] + g2[min_node][i].second < tmp_time[v.first]) {
          tmp_time[v.first] = g2[min_node][i].second + tmp_time[min_node];
          pre[v.first] = min_node;
        }
      }
    }
  }

  vector<int> shortest;
  int tmp = dd, s_paths = 0;
  while (tmp != ss) {
    shortest.push_back(tmp);
    ++s_paths;
    tmp = pre[tmp];
  }
  int s_dest = dest[dd];


  for (int i = 0; i < n; ++i) {
    dest[i] = INT_MAX;
    visited[i] = false;
  }
  dest[ss] = 0;
  vector<int> node_nums(n, INT_MAX);
  node_nums[ss] = 0;
  for ( ; ; ) {
    min = INT_MAX;
    for (int i = 0; i < n; ++i) 
      if (!visited[i] && dest[i] < min) {
        min = dest[i];
        min_node = i;
      }
    if (min == INT_MAX)
      break;
    visited[min_node] = true;
    nebs = g2[min_node].size();
    for (int i = 0; i < nebs; ++i) {
      pair<int, int> v = g2[min_node][i];
      if (!visited[v.first]) {
        if (dest[min_node] + v.second < dest[v.first]) {
          dest[v.first] = dest[min_node] + v.second;
          node_nums[v.first] = node_nums[min_node] + 1;
          pre[v.first] = min_node;
        } else if (dest[min_node] + v.second == dest[v.first] && node_nums[min_node] + 1 < node_nums[v.first]) {
          node_nums[v.first] = node_nums[min_node] + 1;
          pre[v.first] = min_node;
        }
      }
    }
  }
  
  vector<int> fastest;
  tmp = dd;
  int f_paths = 0;
  while (tmp != ss) {
    fastest.push_back(tmp);
    ++f_paths;
    tmp = pre[tmp];
  }
  int f_dest = dest[dd];

  if (shortest == fastest) {
    cout << "Distance = " << s_dest << "; " << "Time = " << f_dest << ": " << ss;
    for (int i = f_paths - 1; i >= 0; --i) {
      cout << " -> " << fastest[i];
    }
    cout << endl;
  } else {
    cout << "Distance = " << s_dest << ": " << ss;
    for (int i = s_paths - 1; i >= 0; --i) {
      cout << " -> " << shortest[i];
    }
    cout << endl;      
    cout << "Time = " << f_dest << ": " << ss;
    for (int i = f_paths - 1; i >= 0; --i) {
      cout << " -> " << fastest[i];
    }
    cout << endl;
  }
  /*
  for (unsigned i = fastest.size() - 1; i >= 0; --i) {  //  这里是一个很隐晦的地方，无符号型递减，然后越界，段错误。在这里debug了太久！！！
    cout << " -> " << fastest[i];
  }
  */
  
  return 0;
}
