#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <set>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::set;
using std::queue;
using std::map;
using std::string;

void s_family(map<int, pair<bool, pair<int, int> > > &t, int temp, set<int> &set_temp) {
  queue<pair<int, int> > s;
  s.push({temp, 1});
  int cur, ord;
  pair<int, int> p;
  //cout << temp << "::" << endl; // 
  while (!s.empty() && s.front().second <= 5) {
    cur = s.front().first;
    //cout << cur << ":" << endl; // 
    ord = s.front().second;
    s.pop();
    p = t[cur].second;
    set_temp.insert(cur);
    if (p.first != -1) {
      //cout << cur << ":" << p.first << endl; //
      s.push({p.first, ord+1});
    }
    if (p.second != -1) {
      //cout << cur << ":" << p.second << endl; //
      s.push({p.second, ord+1});
    }
  }
  //cout << endl; // 
}
  
int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  map<int, pair<bool, pair<int, int> > > t;
  int id_temp, fu_temp, mu_temp;
  string s_temp;
  bool is_male;
  for (int i = 0; i < n; ++i) {
    cin >> id_temp >> s_temp >> fu_temp >> mu_temp;
    if (s_temp == "M") 
      is_male = true;
    else
      is_male = false;
    t[id_temp] = {is_male, {fu_temp, mu_temp}};
    if (fu_temp != -1 && t.find(fu_temp) == t.end()) 
      t[fu_temp] = {true, {-1, -1}};
    if (mu_temp != -1 && t.find(mu_temp) == t.end())
      t[mu_temp] = {false, {-1, -1}};
  }
  int k, temp1, temp2;
  set<int> set1, set2;
  cin >> k;
  for (int i = 0; i < k; ++i) {
    cin >> temp1 >> temp2;
    if (t[temp1].first == t[temp2].first) {
      cout << "Never Mind" << endl;
    } else {
      set1.clear();
      set2.clear();
      s_family(t, temp1, set1);
      s_family(t, temp2, set2);
      bool is_find = false;
      for (auto h : set1) {
        if (set2.find(h) != set2.end()) {
          cout << "No" << endl;
          //cout << h << endl; //
          is_find = true;
          break;
        }
      }
      if (!is_find)
        cout << "Yes" << endl;
    }
  }
  return 0;
}
