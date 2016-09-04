#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<string> name(n);
  vector<string> id(n);
  vector<pair<int, int> > fg, mg;
  string str1, str2;
  int g;
  char ch;
  for (int i = 0; i < n; ++i) {
    cin >> str1 >> ch >> str2 >> g;
    name[i] = str1;
    id[i] = str2;
    if (ch == 'M') {
      mg.emplace_back(g, i);
    } else {
      fg.emplace_back(g, i);
    }
  }
  sort(fg.begin(), fg.end());
  sort(mg.begin(), mg.end());
  if (fg.size() == 0 && mg.size() == 0) {
    cout << "Absent" << endl;
    cout << "Absent" << endl;
    cout << "NA" << endl;
  } else if (fg.size() == 0 && mg.size() != 0) {
    cout << "Absent" << endl;
    cout << name[mg[0].second] << ' ' << id[mg[0].second] << endl;
    cout << "NA" << endl;
  } else if (fg.size() != 0 && mg.size() == 0) {
    cout << name[fg[fg.size() - 1].second] << ' ' << id[fg[fg.size() - 1].second] << endl;
    cout << "Absent" << endl;
    cout << "NA" << endl;
  } else {
    cout << name[fg[fg.size() - 1].second] << ' ' << id[fg[fg.size() - 1].second] << endl;
    cout << name[mg[0].second] << ' ' << id[mg[0].second] << endl;
    cout << fg[fg.size() - 1].first - mg[0].first << endl;
  }
  return 0;
}
