#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <climits>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::string;
using std::pair;

void printpath(int dest, const vector<int> &pre, const vector<string> &redict) {
  if (dest != 0)
    printpath(pre[dest], pre, redict);
  cout << redict[dest] << "->";
}
  
int main() {
  std::ios::sync_with_stdio(false);
  int n, k, int_temp;
  string str_temp, str1, str2;
  cin >> n >> k;
  map<string, unsigned> dict;
  vector<int> hap(n); // hap[0] not defined
  vector<string> redict(n);
  cin >> str_temp;
  dict[str_temp] = 0;
  redict[0] = str_temp;
  for (int i = 1; i < n; ++i) {
    cin >> str_temp >> int_temp;
    dict[str_temp] = i;
    redict[i] = str_temp;
    hap[i] = int_temp;
  }
  vector<vector<pair<int, int> > > g(n);
  for (int i = 0; i < k; ++i) {
    cin >> str1 >> str2 >> int_temp;
    g[dict[str1]].emplace_back(dict[str2], int_temp);
    g[dict[str2]].emplace_back(dict[str1], int_temp);
  }
  /* test
  for (int i = 0; i < n; ++i) {
    cout << i << " : " << redict[i] << ' ';
    for (const auto &pair_temp : g[i]) 
      cout << "<" << pair_temp.first << ":" << redict[pair_temp.first] << ", " << pair_temp.second << "> ";
    cout << endl;
  }
  */
  vector<int> dist(n, INT_MAX), happ(n), city(n), pre(n), choice(n);
  vector<bool> visited(n, false);
  dist[0] = 0;
  happ[0] = 0;
  city[0] = 0;
  pre[0] = -1;
  choice[0] = 1;
  int min_dist;
  int node, node_temp, d_temp;
  for ( ; ; ) {
    node = -1;
    min_dist = INT_MAX;
    for(int i = 0; i < n; ++i) 
      if (!visited[i] && dist[i] < min_dist) {
        min_dist = dist[i];
        node = i;
      }
    if (node == -1) 
      break;
    visited[node] = true;
    // cout << node << ": " << endl; //
    
    for (const auto &pair_temp : g[node]) {
      node_temp = pair_temp.first;
      d_temp = pair_temp.second;
      if (!visited[node_temp]) {
        if (dist[node_temp] == dist[node] + d_temp) {
          // cout << node_temp << " : " << node << endl; // 
          choice[node_temp] += choice[node];
        }        
        if (dist[node_temp] > dist[node] + d_temp) {
          // cout << "flag2: " << node_temp << endl; //
          dist[node_temp] = dist[node] + d_temp;
          happ[node_temp] = happ[node] + hap[node_temp];
          city[node_temp] = city[node] + 1;
          pre[node_temp] = node;
          choice[node_temp] = choice[node];
        } else if (dist[node_temp] == dist[node] + d_temp && happ[node_temp] < happ[node] + hap[node_temp]) {
          // cout << "flag3: " << node_temp << endl; //          
          happ[node_temp] = happ[node] + hap[node_temp];
          city[node_temp] = city[node] + 1;
          pre[node_temp] = node;
        } else if (dist[node_temp] == dist[node] + d_temp && happ[node_temp] == happ[node] + hap[node_temp] && city[node_temp] > city[node] + 1) {
          // cout << "flag4: " << node_temp << endl; //          
          city[node_temp] = city[node] + 1;
          pre[node_temp] = node;
        }
      }
    }
  }

  int dest = dict["ROM"];
  // cout << "flag A:" << choice[temp_city] << endl; //
  cout << choice[dest] << ' ' << dist[dest] << ' ' << happ[dest] << ' ' << happ[dest]/city[dest] << endl;
  printpath(pre[dest], pre, redict);
  cout << "ROM" << endl;
  return 0;
}
  
