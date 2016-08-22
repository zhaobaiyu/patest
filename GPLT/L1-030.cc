#include <iostream>
#include <deque>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::deque;
using std::vector;
using std::string;
int main() {
  int n;
  cin >> n;
  vector<bool> sex(n);
  deque<string> dq0, dq1;
  string name;
  bool temp_bool;
  for (int i = 0; i < n; ++i) {
    cin >> temp_bool >> name;
    sex[i] = temp_bool;
    if (sex[i])
      dq1.push_back(name);
    else
      dq0.push_back(name);
  }
  int i = 0;
  while (!dq1.empty()) {
    if (sex[i]) {
      cout << dq1.front() << ' ' << dq0.back() << endl;
      dq1.pop_front();
      dq0.pop_back();
    } else {
      cout << dq0.front() << ' ' << dq1.back() << endl;
      dq0.pop_front();
      dq1.pop_back();
    }
    ++i;
  }
  return 0;
}
