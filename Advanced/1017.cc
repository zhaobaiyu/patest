#include <cstdio>
#include <vector>
#include <algorithm>

using std::vector;
using std::pair;

int time_to_s(const int &h, const int &m, const int &s) {
  return (h*60 + m)*60 + s;
}  

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<pair<int, int> > man;
  int hh, mm, ss, serve_min;
  int open_t = 8*3600, close_t = 17*3600; // 8:00, 17:00
  for (int i = 0; i < n; ++i) {
    scanf("%d:%d:%d%d", &hh, &mm, &ss, &serve_min);
    if (serve_min > 60)
      serve_min = 60;
    man.emplace_back(time_to_s(hh, mm, ss), serve_min*60);
  }
  std::sort(man.begin(), man.end());
  vector<int> wins;
  int sum = 0, time = 8*3600;
  int i = 0;
  while (i < k && i < n && man[i].first <= open_t) {
    wins.push_back(man[i].second);
    sum += open_t - man[i].first;
    // printf("flag1: %d\n", sum); // test
    ++i;
  }
  int gap_time;
  while (i < n && man[i].first <= close_t) {
    if (time < man[i].first) {
      gap_time = man[i].first - time;
      std::for_each(wins.begin(), wins.end(), [gap_time] (int &i) {/* return i - gap_time; */ i -= gap_time;});
      std::sort(wins.begin(), wins.end(), std::greater<int>());
      wins.erase(std::find_if(wins.begin(), wins.end(), [] (int &i) {return i <= 0;}), wins.end());
      time = man[i].first;
    } else {
      sum += time - man[i].first;
      // printf("flag2: %d\n", sum); // test      
    }
    if (wins.size() < k) {
      wins.push_back(man[i].second);
    } else {
      gap_time = *std::min_element(wins.begin(), wins.end());
      std::for_each(wins.begin(), wins.end(), [gap_time] (int &i) {/* return i - gap_time; */ i -= gap_time;});
      std::sort(wins.begin(), wins.end(), std::greater<int>());
      wins.erase(std::find_if(wins.begin(), wins.end(), [] (int &i) {return i <= 0;}), wins.end());
      wins.push_back(man[i].second);
      sum += gap_time;
      // printf("flag3: %d\n", sum); // test      
      time += gap_time;
    }
    ++i;
  }
  // printf("i: %d\n", i); //
  double ans = sum/60.0/i;
  printf("%.1lf\n", ans);
  return 0;
}
