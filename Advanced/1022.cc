#include <iostream>
#include <string>
#include <map>

using std::string;
using std::multimap;
using std::cin;
using std::cout;
using std::endl;

int main() {
  int n;
  cin >> n;
  int temp_id;
  string temp_str;
  multimap<string, int> tit;
  multimap<string, int> aut;
  multimap<string, int> key;
  multimap<string, int> pub;
  multimap<string, int> year;

  for (int i = 0; i < n; ++i) {
    cin >> temp_id;
    getline(cin, temp_str);
    tit[temp_str] = temp_id;
    getline(cin, temp_str);
    aut[temp_str] = temp_id;
    getline(cin, temp_str);


    getline(cin, temp_str);
    pub[temp_str] = temp_id;
    getline(cin, temp_str);
    year[temp_str] = temp_id;

  }
  int m, ord;
  cin >> m;
  string temp_str2;
  for (int i = 0; i < m; ++i) {
    getline(cin, temp_str);
    ord = temp_str[0];
    temp_str2 = string(temp_str.begin() + 3, temp_str.end());
    
    }
  }
}
