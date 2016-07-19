#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::string;
using std::queue;


int main() {
  int n;
  cin >> n;
  vector<pair<int, int> > t(n);
  vector<bool> ex(n, false);
  string str1, str2;
  int temp1, temp2;  
  for (int i = 0; i < n; ++i) {
    cin >> str1 >> str2;
    if (str1 == string("-")) {
      temp1 = -1;
    } else {
      temp1 = std::stoi(str1);
      ex[temp1] = true;
    }
    if (str2 == string("-")) {
      temp2 = -1;
    } else {
      temp2 = std::stoi(str2);
      ex[temp2] = true;
    }
    t[i] = {temp1, temp2};
  } 
  int root;
  for (int i = 0; i < n; ++i) {
    if (ex[i] == false) {
      root = i;
      break;
    }
  } 
  queue<int> qu;
  qu.push(root);
  int node;
  bool state = false, is_cbt = true;
  while (!qu.empty()) {
    node = qu.front();
    qu.pop();
    if (t[node].first == -1 && t[node].second != -1) {
      is_cbt = false;
      break; 
    } 
    if (state && (t[node] != std::make_pair(-1, -1))) {
      is_cbt = false;
      break;
    }
    if (!state && (t[node].first == -1 || t[node].second == -1)) {
      state = true;
    }  
    if (t[node].first != -1) {
      qu.push(t[node].first);
    } 
    if (t[node].second != -1) {
      qu.push(t[node].second);
    } 
  }
  if (is_cbt) {
    cout << "YES " << node << endl;
  } else {
    cout << "NO " << root << endl;
  }
  return 0;
}
