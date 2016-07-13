#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <algorithm>

using std::string;
using std::multimap;
using std::cin;
using std::cout;
using std::endl;
using std::stringstream;
using std::getline;
using std::vector;

void find_out(const multimap<string, int> &org, const string &str) {
  auto pos = org.equal_range(str);
  vector<int> temp_v;
  if (pos.first == pos.second) {
    cout << "Not Found" << endl;
  } else {
    for ( ; pos.first != pos.second; ++pos.first) {
      temp_v.push_back(pos.first->second);
    }
    std::sort(temp_v.begin(), temp_v.end());
    std::for_each(temp_v.begin(), temp_v.end(), [] (const int &n) {cout << std::setfill('0') << std::setw(7) << n << endl;});
    /* 这里用printf的时候结果错误，所以当声明 std::ios::sync_with_stdio(false);时，不要混用printf和cout！！！ */
  }
}
     
int main() {
  std::ios::sync_with_stdio(false);  
  int n;
  cin >> n;
  int temp_id;
  string temp_str, key_word;
  multimap<string, int> tit;
  multimap<string, int> aut;
  multimap<string, int> key;
  multimap<string, int> pub;
  multimap<string, int> year;

  for (int i = 0; i < n; ++i) {
    cin >> temp_id;
    getline(cin, temp_str);
    getline(cin, temp_str);
    tit.insert({temp_str, temp_id});
    // tit[temp_str] = temp_id; 不能对multimap使用下标操作
    getline(cin, temp_str);
    aut.insert({temp_str, temp_id});
    getline(cin, temp_str);
    stringstream ss(temp_str);
    while (ss >> key_word) 
      key.insert({key_word, temp_id});
    getline(cin, temp_str);
    pub.insert({temp_str, temp_id});
    getline(cin, temp_str);
    year.insert({temp_str, temp_id});
  }
  int m, ord;
  cin >> m;
  getline(cin, temp_str);
  for (int i = 0; i < m; ++i) {
    getline(cin, temp_str);
    ord = temp_str[0] - '0';
    temp_str = temp_str.substr(3);
    cout << ord << ": " << temp_str << endl;
    switch (ord) {
      case 1: find_out(tit, temp_str); break;
      case 2: find_out(aut, temp_str); break;
      case 3: find_out(key, temp_str); break;
      case 4: find_out(pub, temp_str); break;
      case 5: find_out(year, temp_str); break;
    }
  }
  return 0;
}
