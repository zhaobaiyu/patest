/**
 * 用string类型效率不是很高，但这里还是足够了，题目限制时间300，这里不到80
 * 用string真的比c的字符数组好写太多了，还应该熟悉string的各种方法
 * 题目有个词alphanumerical，读题要仔细，看清要求。
 */

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  string s;
  getline(cin, s);
  s += '!'; 
  unordered_map<string, int> m;
  string ss;
  for (auto ch : s) {
    if (!isalpha(ch) && !isdigit(ch)) {
      if (ss != "") { // If s end with alpha, I have added '!' to the end
        if (m.find(ss) == m.end()) {
          m[ss] = 1;
        } else {
          ++m[ss];
        }
      }
      ss = "";
    } else {
      if (isupper(ch)) {
        ch = ch + 'a' - 'A';
      }
      ss += ch;
    }
  }
  int max_sum = -1;
  for (auto iter = m.begin(); iter != m.end(); ++iter) 
    if (iter->second > max_sum) {
      max_sum = iter->second;
      s = iter->first;
    } else if (iter->second == max_sum && iter->first < s) {
      s = iter->first;
    }
  cout << s << ' ' << max_sum << endl;
  return 0;
}
