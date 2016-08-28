#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;
int FTtos(int hh, int mm, int ss) {
  return (hh - 8)*3600 + mm*60 + ss;
}
void printtime(int s) {
  printf("%02d:%02d:%02d", s/3600 + 8, s%3600/60, s%3600%60);
}
int main() {
  short n, k, m;
  scanf("%hd", &n);
  short hh, mm, ss, play_t, is_vip;
  // map<int, pair<short, short> > mainq;
  set<tuple<int, short, short> > mainq;
  for (int i = 0; i < n; ++i) {
    scanf("%hd:%hd:%hd%hd%hd", &hh, &mm, &ss, &play_t, &is_vip);
    play_t = (play_t > 120) ? 120 : play_t;
    // mainq.insert({FTtos(hh, mm, ss), {play_t*60, is_vip}});
    mainq.emplace(FTtos(hh, mm, ss), play_t*60, is_vip);
  }
  map<int, short> wait, vip_wait;
  scanf("%hd%hd", &k, &m);
  set<int> tables;
  vector<int> t_sum(k+1, 0);
  int temp;
  vector<bool> is_vip_table(k + 1, false);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &temp);
    is_vip_table[temp] = true;
  }
  for (int i = 1; i <= k; ++i) 
    tables.insert(i);
  int time, time2;
  short int1, int2;
  while (!mainq.empty()) {
    // time = (*mainq.begin()).first;
    time = get<0>(*mainq.begin());
    if (time >= 46800)
      break;
    // int1 = (*mainq.begin()).second.first;
    int1 = get<1>(*mainq.begin());
    // int2 = (*mainq.begin()).second.second;
    int2 = get<2>(*mainq.begin());
    mainq.erase(mainq.begin());
    if (int1 < 10000) {
      if (!tables.empty()) {
        // mainq.insert({time + int1, {0, *tables.begin()}});
        mainq.emplace(time + int1, 10000, *tables.begin());
        ++t_sum[*tables.begin()];
        tables.erase(tables.begin());
        printtime(time);
        printf(" ");
        printtime(time);
        printf(" 0\n");
      } else {
        if (int2 == 1)
          vip_wait.insert({time, int1});
        wait.insert({time, int1});
      }
    } else {
      if (!wait.empty()) {
        if (is_vip_table[int2] && !vip_wait.empty()) {
          time2 = (*vip_wait.begin()).first;
          play_t = (*vip_wait.begin()).second;
          vip_wait.erase(vip_wait.begin());
          wait.erase(wait.find(time2));
        } else {
          time2 = (*wait.begin()).first;
          play_t = (*wait.begin()).second;
          wait.erase(wait.begin());          
          if (!vip_wait.empty() && (*vip_wait.begin()).first == time2) {
            vip_wait.erase(vip_wait.begin());
          }
        }
        // mainq.insert({time + play_t, {0, int2}});
        mainq.emplace(time + play_t, 10000, int2);
        ++t_sum[int2];
        printtime(time2);
        printf(" ");
        printtime(time);
        printf(" %.0lf\n", round((time - time2)/60.0));
      } else {
        tables.insert(int2);
      }
    }
  }
  printf("%d", t_sum[1]);
  for (int i = 2; i <= k; ++i) 
    printf(" %d", t_sum[i]);
  printf("\n");
  return 0;
}
