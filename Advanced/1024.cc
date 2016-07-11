#include <iostream>
#include <string>
#include <algorithm>

using std::string;
using std::reverse;
using std::stoll;
using std::cin;
using std::cout;
using std::endl;
using std::to_string;

bool p_num(const string &temp) {
  string str_temp = temp;
  reverse(str_temp.begin(), str_temp.end());
  if (str_temp == temp) {
    return true;
  } else {
    return false;
  }
}

void add_str(const string &str1, const string &str2, string &ans) {
  string str_temp;
  int jinwei = 0, temp;
  for (int i = str1.size() - 1; i >= 0; --i) {
    temp = str1[i] - '0' + str2[i] - '0' + jinwei;
    jinwei = temp/10;
    temp %= 10;
    /*
    if (temp >= 10) {
      temp = temp - 10;
      jinwei = 1;
    } else {
      jinwei = 0;
    }
    */
    str_temp.push_back(temp + '0');
  }
  if (jinwei != 0) {
    str_temp.push_back(jinwei + '0');
  }
  ans = str_temp;
  reverse(ans.begin(), ans.end());
}

int main() {
  string str_n, ans_str, temp_str;
  int k;
  cin >> str_n >> k;
  int i = 0;
  // while (i < str_n.size() && str_n[i] == '0')  ++i;
  // str_n = str_n.substr(i);
  for (i = 0; i < k; ++i) {
    if (p_num(str_n)) {
      break;
    }
    temp_str = str_n;
    reverse(temp_str.begin(), temp_str.end());
    add_str(str_n, temp_str, ans_str);
    str_n = ans_str;    
    // test
    // cout << "test " << i << ": "<< str_n << ' ' << temp_str << ' ' << ans_str << endl;
  }
  cout << str_n << endl << i << endl;
  return 0;
}