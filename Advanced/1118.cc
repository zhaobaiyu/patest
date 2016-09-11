#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int tmp, tmp2;
  unordered_map<int, int> birds;
  int this_tree;
  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    if (tmp > 0) {
      cin >> tmp2;
      if (birds.find(tmp2) == birds.end()) {
        birds.insert({tmp2, -1});
        this_tree = tmp2;
      } else {
        while (birds[tmp2] > 0) {
          tmp2 = birds[tmp2];
        }
        this_tree = tmp2;
      }
      for (int j = 1; j < tmp; ++j) {
        cin >> tmp2;
        if (birds.find(tmp2) == birds.end()) {
          birds.insert({tmp2, this_tree});
          --birds[this_tree];
        } else {
          while (birds[tmp2] > 0) {
            tmp2 = birds[tmp2];
          }
          birds[this_tree] += birds[tmp2];
          birds[tmp2] = this_tree;
        }
      }
    }
  }
  
  
  int sum1 = 0, sum2 = 0;
  for (auto iter = birds.begin(); iter != birds.end(); ++iter) {
    if (iter->second < 0) {
      ++sum1;
      sum2 += iter->second;
      // cout << ' ' << iter->first << ':' << iter->second;
    }
  }
  sum2 = -sum2;
  cout << sum1 << ' ' << sum2 << endl;
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> tmp >> tmp2;
    while (birds[tmp] > 0) {
      tmp = birds[tmp];
    }
    while (birds[tmp2] > 0) {
      tmp2 = birds[tmp2];
    }
    if (tmp == tmp2) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
