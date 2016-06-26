#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>
using std::vector;
using std::string;
using std::pair;
using std::sort;
using std::cout;
using std::endl;

int time_to_data(int d, int h, int m) {
  return ((d - 1)*24 + h)*60 + m;
}

int acc(int a, int b, const vector<int> &costs) {
  int am = a%60, bm = b%60, ah = a/60%24, bh = b/60%24, ad = a/60/24 + 1, bd = b/60/24 + 1;
  int one_day = 0, bh_temp = 0, ah_temp = 0;
  for (int i = 0; i < 24; ++i) {
    one_day += costs[i]*60;
    if (i < bh)
      bh_temp += costs[i]*60;
    if (i < ah)
      ah_temp += costs[i]*60;
  }
  int sum = bm*costs[bh] - am*costs[ah] + bh_temp - ah_temp + (bd - ad)*one_day;
  printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n", ad, ah, am, bd, bh, bm, b - a, sum/100.0);
  return sum;
}

int main() {
  vector<int> costs;
  int temp;
  for (int i = 0; i < 24; ++i) {
    scanf("%d", &temp);
    costs.push_back(temp);
  }
  int n;
  scanf("%d", &n);  
  vector<pair<string, int> > man;
  /*
  vector<vector<int> > mins_on;
  vector<vector<int> > mins_off;
  */
  vector<vector<pair<int, bool> > > man_mins;
  int month, dd, hh, mm, find_man, temp_data;
  char char_name[25], str_line[10];
  string str_name;
  for (int i = 0; i < n; ++i) {
    scanf("%s%d:%d:%d:%d%s", char_name, &month, &dd, &hh, &mm, str_line);
    temp_data = time_to_data(dd, hh, mm);
    str_name = char_name;
    find_man = -1;
    for (const auto &temp_pair : man) {
      if (temp_pair.first == str_name) {
        find_man = temp_pair.second;
        break;
      }
    }
    if (find_man == -1) {
      /*
      mins_off.emplace_back();
      mins_on.emplace_back();
      man.emplace_back(str_name, mins_off.size() - 1);
      find_man = mins_off.size() - 1;
      */
      man_mins.emplace_back();
      man.emplace_back(str_name, man_mins.size() - 1);
      find_man = man_mins.size() - 1;
    }
    if (strcmp(str_line, "on-line") == 0) {
      // mins_on[find_man].push_back(temp_data);
      // printf("on-line: %d\n", temp_data); // test
      man_mins[find_man].emplace_back(temp_data, true);
    }
    else {
      // mins_off[find_man].push_back(temp_data);
      // printf("off-line: %d\n", temp_data); // test
      man_mins[find_man].emplace_back(temp_data, false);
    }
  }
  sort(man.begin(), man.end());
  int mins_sum;
  for (const auto &temp_man : man) {


    /*
    auto &man_on = mins_on[temp_man.second];
    auto &man_off = mins_off[temp_man.second];
    sort(man_on.begin(), man_on.end());
    sort(man_off.begin(), man_off.end());
    auto on_iter = man_on.begin();
    auto off_iter = man_off.begin();
    mins_sum = 0;
    while (on_iter != man_on.end() && off_iter != man_off.end()) {
      if (*on_iter >= *off_iter) {
        ++off_iter;
      } else {
        mins_sum += acc(*on_iter, *off_iter, costs);
        ++on_iter;
        ++off_iter;
      }
    }
    */
    auto &temp_man_mins = man_mins[temp_man.second];
    sort(temp_man_mins.begin(), temp_man_mins.end());
    auto iter1 = temp_man_mins.begin(), iter2 = iter1 + 1;
    mins_sum = 0;
    while (iter2 != temp_man_mins.end()) {
      if (iter1->second && !iter2->second) {
        if (mins_sum == 0) {
          cout << temp_man.first;
          printf(" %02d\n", month);
        }
        mins_sum += acc(iter1->first, iter2->first, costs);
      }
      ++iter1;
      ++iter2;
    }
    if (mins_sum != 0) { // 题目真没意思，又没说时间为零就不输出，明明说了，“you must print a phone bill for each customer.”，我觉得第一次提交这里错了，不怪我。
      printf("Total amount: $%.2lf\n", mins_sum/100.0);
    }
  }
  return 0;
}
