#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  map<string, pair<int, string> > p;
  string str1, str2;
  int w;
  bool str1in, str2in;
  for (int i = 0; i < n; ++i) {
    cin >> str1 >> str2 >> w;
    str1in = p.find(str1) != p.end();
    str2in = p.find(str2) != p.end();
    if (!str1in && !str2in) {
      p.insert({str1, {w, str1}});
      p.insert({str2, {w, str1}});
    } else if (str1in && str2in) {
      p[str1].first += w;
      p[str2].first += w;
      while (p[str2].second != str2) {
        str2 = p[str2].second;
      }
      p[str2].second = p[str1].second;
    } else if (str1in && !str2in) {
      p[str1].first += w;
      p[str2] = {w, p[str1].second};
    } else if (!str1in && str2in) {
      p[str1] = {w, p[str2].second};
      p[str2].first += w;
    }
  }
  map<string, pair<int, int> > ans;
  for (auto iter = p.begin(); iter != p.end(); ++iter) {
    str1 = iter->first;
    str2 = str1;
    while (p[str2].second != str2) {
      str2 = p[str2].second;
    }
    if (ans.find(str2) != ans.end()) {
      ans[str2].first += 1;
      ans[str2].second += p[str1].first;
    } else {
      ans.insert({str2, {1, p[str1].first}});
    }
    if (p[str1].first > p[str2].first) {
      p[str2].second = str1;
      p[str1].second = str1;
      ans.insert({str1, ans[str2]});
      ans.erase(str2);
    }    
  }
  int sum = 0;
  vector<pair<string, int> > ans_v;
  for (auto iter = ans.begin(); iter != ans.end(); ++iter) {
    if (iter->second.second/2 > k && iter->second.first > 2) {
      ++sum;
      ans_v.emplace_back(iter->first, iter->second.first);
      // cout << iter->first << ' ' << iter->second.first << ' ' << iter->second.second << endl; // 
    }
  }
  cout << sum << endl;
  for (auto iter = ans_v.begin(); iter != ans_v.end(); ++iter)
    cout << iter->first << ' ' << iter->second << endl;
  return 0;
}
