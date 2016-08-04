#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <tuple>
#include <iomanip>
#include <queue>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::tuple;
using std::set;
using std::string;
using std::get;
using std::setfill;
using std::setw;
using std::priority_queue;
using std::map;
using std::pair;

int main() {
  std::ios::sync_with_stdio(false);
  int n, c;
  cin >> n >> c;
  int id_temp, grade_temp;
  string name_temp;
  if (c == 1) {
    map<int, pair<string, int> > a;
    for (int i = 0; i < n; ++i) {
      cin >> id_temp >> name_temp >> grade_temp;
      a.insert({id_temp, {name_temp, grade_temp}});
    }
    for (auto iter = a.cbegin(); iter != a.cend(); ++iter)
      cout << setfill('0') << setw(6) << iter->first << ' ' << iter->second.first << ' ' << iter->second.second << endl;
  } else if (c == 2) {
    map<pair<string, int>, int> a;
    for (int i = 0; i < n; ++i) {
      cin >> id_temp >> name_temp >> grade_temp;
      a.insert({{name_temp, id_temp}, grade_temp});
    }
    for (auto iter = a.cbegin(); iter != a.cend(); ++iter)
      cout << setfill('0') << setw(6) << iter->first.second << ' ' << iter->first.first << ' ' << iter->second << endl;
  } else {
    map<pair<int, int>, string> a;
    for (int i = 0; i < n; ++i) {
      cin >> id_temp >> name_temp >> grade_temp;
      a.insert({{grade_temp, id_temp}, name_temp});
    }
    for (auto iter = a.cbegin(); iter != a.cend(); ++iter)
      cout << setfill('0') << setw(6) << iter->first.second << ' ' << iter->second << ' ' << iter->first.first << endl;
  }
  
  /* priority_queue
  if (c == 1) {
    priority_queue<tuple<int, string, int>, std::vector<tuple<int, string, int>>, std::greater<tuple<int, string, int>>> a;
    for (int i = 0; i < n; ++i) {
      cin >> id_temp >> name_temp >> grade_temp;
      a.emplace(id_temp, name_temp, grade_temp);
    }
    while (!a.empty()) {
      cout << setfill('0') << setw(6) << get<0>(a.top()) << ' ' << get<1>(a.top()) << ' ' << get<2>(a.top()) << endl;
      a.pop();
    }
  } else if (c == 2) {
    priority_queue<tuple<string, int, int>, std::vector<tuple<string, int, int>>, std::greater<tuple<string, int, int>>> a;
    for (int i = 0; i < n; ++i) {
      cin >> id_temp >> name_temp >> grade_temp;
      a.emplace(name_temp, id_temp, grade_temp);
    }
    while (!a.empty()) {
      cout << setfill('0') << setw(6) << get<1>(a.top()) << ' ' << get<0>(a.top()) << ' ' << get<2>(a.top()) << endl;
      a.pop();
    }
  } else {
    priority_queue<tuple<int, int, string>, std::vector<tuple<int, int, string>>, std::greater<tuple<int, int, string>>> a;
    for (int i = 0; i < n; ++i) {
      cin >> id_temp >> name_temp >> grade_temp;
      a.emplace(grade_temp, id_temp, name_temp);
    }
    while (!a.empty()) {
      cout << setfill('0') << setw(6) << get<1>(a.top()) << ' ' << get<2>(a.top()) << ' ' << get<0>(a.top()) << endl;
      a.pop();
    }
  }
  */

  /*
  if (c == 1) {
    set<tuple<int, string, int>> a;
    for (int i = 0; i < n; ++i) {
      cin >> id_temp >> name_temp >> grade_temp;
      a.insert(std::make_tuple(id_temp, name_temp, grade_temp));
    }
    for (auto iter = a.cbegin(); iter != a.cend(); ++iter) 
      cout << std::setfill('0') << std::setw(6) << get<0>(*iter) << ' ' << get<1>(*iter) << ' ' << get<2>(*iter) << endl;
  } else if (c == 2) {
    set<tuple<string, int, int>> a;
    for (int i = 0; i < n; ++i) {
      cin >> id_temp >> name_temp >> grade_temp;
      a.insert(std::make_tuple(name_temp, id_temp, grade_temp));
    }
    for (auto iter = a.cbegin(); iter != a.cend(); ++iter)
      cout << std::setfill('0') << std::setw(6) << get<1>(*iter) << ' ' << get<0>(*iter) << ' ' << get<2>(*iter) << endl;
  } else {
    set<tuple<int, int, string>> a;
    for (int i = 0; i < n; ++i) {
      cin >> id_temp >> name_temp >> grade_temp;
      a.insert(std::make_tuple(grade_temp, id_temp, name_temp));
    }
    for (auto iter = a.cbegin(); iter != a.cend(); ++iter)
      cout << std::setfill('0') << std::setw(6) << get<1>(*iter) << ' ' << get<2>(*iter) << ' ' << get<0>(*iter) << endl;
  }
  */
  return 0;
}
      
