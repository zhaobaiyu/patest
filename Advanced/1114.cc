#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <set>
#include <iomanip>

using std::cin;
using std::cout;
using std::vector;
using std::endl;
using std::map;
using std::pair;
using std::set;

typedef struct mem {
  vector<int> f;
  // int id;
  int set;
  int area;
} mem;

map<int, mem> a;
double avg_set, avg_area;
int min_id, sum_mem;
set<int> checked;
void dfs(const int temp_id) {
  if (checked.find(temp_id) == checked.end()) {
    checked.insert(temp_id);
    avg_area += a[temp_id].area;
    if (temp_id < min_id)
      min_id = temp_id;
    avg_set += a[temp_id].set;
    ++sum_mem;
    for (auto t : a[temp_id].f) 
      dfs(t);
  }
}

void insert_node(int id1, int id2) {
  if (a.find(id2) == a.end()) {
    mem temp_mem;
    temp_mem.area = 0;
    temp_mem.set = 0;
    temp_mem.f.push_back(id1);
    a[id2] = temp_mem;
  } else {
    a[id2].f.push_back(id1);
  }
}
 
int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  // vector<mem> a(n);
  // map<int, int> m;
  int temp_id, fa, ma, ch, ch_sum;
  for (int i = 0; i < n; ++i) {
    cin >> temp_id >> fa >> ma >> ch_sum;
    if (a.find(temp_id) == a.end()) {
      mem temp_mem;
      a[temp_id] = temp_mem;
    }
    if (fa != -1) {
      a[temp_id].f.push_back(fa);
      insert_node(temp_id, fa);
    }
    if (ma != -1) {
      a[temp_id].f.push_back(ma);
      insert_node(temp_id, ma);
    }
    for (int j = 0; j < ch_sum; ++j) {
      cin >> ch;
      a[temp_id].f.push_back(ch);
      insert_node(temp_id, ch);
    }
    cin >> a[temp_id].set >> a[temp_id].area;
  }
  map<pair<double, int>, pair<double, int> > ans;

  // for (int i = 0; i < n; ++i) {
  for (auto iter = a.begin(); iter != a.end(); ++iter) {
    temp_id = iter->first;
    if (checked.find(temp_id) == checked.end()) {
      avg_set = 0;
      avg_area = 0;
      min_id = 100000;
      sum_mem = 0;
      dfs(temp_id);
      avg_area = avg_area/sum_mem;
      avg_area = -avg_area;
      avg_set = avg_set/sum_mem;
      ans.insert({{avg_area, min_id}, {avg_set, sum_mem}});
    }
  }
  cout << ans.size() << endl;
  for (auto iter = ans.begin(); iter != ans.end(); ++iter) 
    cout << std::setfill('0') << std::setw(4) << iter->first.second << ' ' << iter->second.second << ' ' << std::fixed << std::setprecision(3) << iter->second.first << ' ' << -(iter->first.first) << endl;
  return 0;
}
