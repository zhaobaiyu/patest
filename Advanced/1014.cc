#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using std::queue;
using std::vector;
using std::pair;
using std::min_element;

int main() {
  int n, m, k, q, sum_time = 0, nm;
  const int end_time = 540;
  scanf("%d%d%d%d", &n, &m, &k, &q);
  vector<queue<int> > win(n); //windows from 0 to n-1, queues from 0 to m-1
  // priority_queue<pair<int, int> > priq;
  vector<pair<int, int> > qu_first;
  vector<int> mins(k+1), ans(k+1); // customers from 1 to k
  for (auto it = mins.begin() + 1; it != mins.end(); ++it) 
    scanf("%d", &(*it));
  if (k > n*m)
    nm = n*m;
  else
    nm = k;
  int i = 1, win_num = 0;
  while (i <= nm) {
    win[win_num++].push(i);
    ++i;
    win_num %= n;
  }
  i = 0;
  for (const auto &qu : win) 
    if (!qu.empty()) // 第一次提交没想起这里。需要注意！！！
      qu_first.emplace_back(mins[qu.front()], i++);
    // priq.push(mins[it->front()], i);  
  int pop_time, pop_queue, pop_man, next_man = nm + 1;
  while (!qu_first.empty()) {
    auto pop_iter = min_element(qu_first.begin(), qu_first.end());
    pop_queue = pop_iter->second;
    pop_time = pop_iter->first;
    // pop_time = priq.top().first;
    // pop_queue = priq.top().second;
    pop_man = win[pop_queue].front();
    sum_time += pop_time;
    /*
    if (sum_time - mins[pop_man] > end_time)
      break;
    */
    if (sum_time - mins[pop_man] < end_time) // 又是审题不仔细。天真的以为是要在关门前服务完，但实际上题目要求在关门前开始服务就可以，否则sorry。！！！
      ans[pop_man] = sum_time;
    win[pop_queue].pop();
    for (auto &qu : qu_first) 
      qu.first -= pop_time;
    if (next_man <= k) {
      win[pop_queue].push(next_man++);
    } 
    if (!win[pop_queue].empty()) {
      pop_iter->first = mins[win[pop_queue].front()];
    } else {
      qu_first.erase(pop_iter);
    }
  }

  /* test
  for (auto it = ans.begin() + 1; it != ans.end(); ++it) 
    printf("%d\n", *it);
  */
  int temp, hh, mm, temp_time;
  for (int j = 0; j < q; ++j) {
    scanf("%d", &temp);
    temp_time = ans[temp];
    if (temp_time == 0) {
      printf("Sorry\n");
    } else {
      hh = temp_time/60 + 8;
      mm = temp_time%60;
      printf("%02d:%02d\n", hh, mm);
    }
  }
  return 0;
}
