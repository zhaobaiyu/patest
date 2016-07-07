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

  // test
  /*
  temp_i = 0;
  for (const auto &vex_temp : vex) {
    printf("#%d need: %d known: %d dist: %d pre: %d bike: %d max_bike: %d\n", temp_i++, vex_temp.need, vex_temp.known, vex_temp.dist, vex_temp.pre, vex_temp.bike, vex_temp.max_bike);
    for (const auto &vex_edge_test : vex_temp.edge) {
      printf("\tto %d, time: %d\n", vex_edge_test.first, vex_edge_test.second);
    }
  }
  */
  // test

  printf("%d ", vex[sp].max_bike);
  PrintPath(sp, vex);
  printf(" %d\n", vex[sp].max_bike - vex[sp].bike);

  return 0;
}
