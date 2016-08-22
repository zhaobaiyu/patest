#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int main() {
  string s;
  cin >> s;
  map<int, int, greater<int>> arr;
  for (auto c : s) 
    arr.emplace(c, 0);
  int i = 0;
  cout << "int[] arr = new int[]{";
  for (auto &pair : arr) {
    if (i == 0)
      cout << pair.first - '0';
    else
      cout << ',' << pair.first - '0';
    pair.second = i;
    ++i;
  }
  cout << "};" << endl << "int[] index = new int[]{";
  i = 0;
  for (auto c : s) {
    if (i == 0)
      cout << arr[c];
    else
      cout << ',' << arr[c];
    ++i;
  }
  cout << "};" << endl;
  return 0;
}
