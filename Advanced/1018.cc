#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;

vector<vector<int> > min_roads;
vector<int> temp_road;
vector<int> temp_road2;
vector<vector<int> > pre;

void dfs(int r, int d) { // r is the start of search, but the problem station, d is the PBMC
  temp_road.push_back(r);
  if (r == d) {
    temp_road2 = temp_road;
    std::reverse(temp_road2.begin(), temp_road2.end());
    min_roads.push_back(temp_road2);
    return;
  }
  for (auto temp : pre[r]) {
    dfs(temp, d);
    temp_road.pop_back();
  }
  return;
}

int main() {
  std::ios::sync_with_stdio(false);
  int cc, n, sp, m;
  cin >> cc >> n >> sp >> m;
  cc /= 2;
  vector<int> c(n+1);
  c[0] = cc;
  for (int i = 1; i <= n; ++i) 
    cin >> c[i];
  int c1, c2, t;
  vector<vector<pair<int, int> > > road(n+1);
  for (int i = 0; i < m; ++i) {
    cin >> c1 >> c2 >> t;
    road[c1].push_back({c2, t});
    road[c2].push_back({c1, t});
  }
  vector<int> dist(n+1, INT_MAX);
  dist[0] = 0;
  vector<bool> known(n+1, false);
  pre.assign(n+1, {});
  int min_dist;
  for ( ; ; ) { // dijkstra algorithm
    min_dist = INT_MAX;
    c1 = -1;
    for (int i = 0; i <= n; ++i) 
      if (!known[i] && dist[i] < min_dist) {
        min_dist = dist[i];
        c1 = i;
      }
    if (c1 == -1)
      break;
    known[c1] = true;
    for (const auto &temp_pair : road[c1]) {
      c2 = temp_pair.first;
      t = temp_pair.second;
      if (!known[c2]) {
        if (dist[c1] + t < dist[c2]) {
          dist[c2] = dist[c1] + t;
          pre[c2] = {c1};
        } else if (dist[c1] + t == dist[c2]) {
          pre[c2].push_back(c1);
        }
      }
    }
  }
  
  dfs(sp, 0);

  int diff, exist, need, min_need = INT_MAX, min_exist = INT_MAX;
  for (const auto &v : min_roads) {
    exist = 0;
    need = 0;
    for (const auto &temp : v) {
      diff = cc - c[temp];
      if (diff < 0) 
        exist += -diff;
      else if (diff > 0 && exist > diff) 
        exist -= diff;
      else if (diff > 0 && exist < diff) {
        need += diff - exist;
        exist = 0;
      }
    }
    if (need < min_need || (need == min_need && exist < min_exist)) {
      min_need = need;
      min_exist = exist;
      temp_road = v;
    }
  }
  cout << min_need << ' ' << temp_road[0];
  for (unsigned i = 1; i < temp_road.size(); ++i) 
    cout << "->" << temp_road[i];
  cout << ' ' << min_exist << endl;
  return 0;
}
  
      



/*
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;
typedef struct vex_t {
  int need;
  bool known;
  int dist;
  int pre;
  int bike;
  int max_bike;
  vector<pair<int, int> > edge;
} vex_t;
void PrintPath(const int i, const vector<vex_t> &vex) {
  if (vex[i].pre != -1) {
    PrintPath(vex[i].pre, vex);
    printf("->");
  }
  printf("%d", i);
}
int main() {
  int cmax, n, sp, m, temp_0;
  scanf("%d%d%d%d", &cmax, &n, &sp, &m);
  cmax /= 2; // cmax is the best num
  vector<vex_t> vex(n + 1);
  auto vex_iter = vex.begin();
  vex_iter->need = 0;
  vex_iter->known = false;
  vex_iter->dist = 0;
  vex_iter->pre = -1;
  vex_iter->max_bike = 0;
  vex_iter->bike = 0;
  for (auto iter = vex.begin() + 1; iter != vex.end(); ++iter) {
    // cin >> iter->need;
    scanf("%d", &temp_0);
    iter->need = cmax - temp_0;
    iter->known = false;
    iter->dist = INT_MAX;
    iter->pre = -1;
  }
  int temp1, temp2, temp3;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &temp1, &temp2, &temp3);
    vex[temp1].edge.emplace_back(temp2, temp3);
    vex[temp2].edge.emplace_back(temp1, temp3);
  }
  int dist_min, max_bike_min, temp_i, vex_i, bike_temp, max_bike_temp;
  vex_t *vex_temp_p;
  for ( ; ; ) {
    dist_min = INT_MAX;
    max_bike_min = INT_MAX;
    vex_temp_p = nullptr;
    temp_i = 0;
    for (auto &vex_temp : vex) {
      if (!vex_temp.known) {
        if (vex_temp.dist < dist_min) {
          dist_min = vex_temp.dist;
          max_bike_min = vex_temp.max_bike;
          vex_temp_p = &vex_temp;
          vex_i = temp_i;
        } else if (vex_temp.dist == dist_min && vex_temp.max_bike < max_bike_min) {
          max_bike_min = vex_temp.max_bike;
          vex_temp_p = &vex_temp;
          vex_i = temp_i;
        }
      }
      ++temp_i;
    }
    if (vex_temp_p == nullptr) {
      break;
    }
    vex_temp_p->known = true;
    for (auto &path_temp : vex_temp_p->edge) {
      if (!vex[path_temp.first].known) {
        bike_temp = vex_temp_p->bike + vex[path_temp.first].need;
        max_bike_temp = (bike_temp > vex_temp_p->max_bike) ? bike_temp : vex_temp_p->max_bike;
        if (vex_temp_p->dist + path_temp.second < vex[path_temp.first].dist) {
          vex[path_temp.first].dist = vex_temp_p->dist + path_temp.second;
          vex[path_temp.first].pre = vex_i;
          vex[path_temp.first].bike = bike_temp;
          vex[path_temp.first].max_bike = max_bike_temp;
        } else if (vex_temp_p->dist + path_temp.second == vex[path_temp.first].dist && max_bike_temp < vex[path_temp.first].max_bike) {
          vex[path_temp.first].pre = vex_i;
          vex[path_temp.first].bike = bike_temp;
          vex[path_temp.first].max_bike = max_bike_temp;
        }
      }
    }
  } // main for loop

  printf("%d ", vex[sp].max_bike);
  PrintPath(sp, vex);
  printf(" %d\n", vex[sp].max_bike - vex[sp].bike);

  return 0;
}
*/
