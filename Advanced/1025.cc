#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::multimap;
using std::vector;
using std::pair;

int main() {
  std::ios::sync_with_stdio(false);
  int n, k;
  cin >> n;
  vector<vector<int>> rank(n + 1, vector<int>(101));
  int temp_s;
  string temp_id;
  multimap<pair<int, string>, int> data;
  for (int i = 1; i <= n; ++i) {
    cin >> k;
    for (int j = 0; j < k; ++j) {
      cin >> temp_id >> temp_s;
      ++rank[0][temp_s];
      ++rank[i][temp_s];
      data.insert({{100 - temp_s, temp_id}, i});
    }
  }
  int sum, pre;
  for (int i = 0; i <= n; ++i) {
    sum = 1;
    pre = 0;
    for (int j = 100; j >= 0; --j) 
      if (rank[i][j] != 0) {
        sum += pre;
        pre = rank[i][j];
        rank[i][j] = sum;
      }
  }
  cout << data.size() << endl;
  for (auto iter = data.begin(); iter != data.end(); ++iter) 
    cout << iter->first.second << ' ' << rank[0][100 - iter->first.first] << ' ' << iter->second << ' ' << rank[iter->second][100 - iter->first.first] << endl;
  return 0;
}
