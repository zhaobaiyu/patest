#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
  string str, word[85];
  int j(0);
  getline(cin, str);
  for (string::size_type i = 0; i < str.size(); ++i) 
    if (str[i] != ' ')
      word[j] += str[i];
    else
      ++j;
  for (int k = j; k > 0; --k) cout << word[k] << ' ';
  cout << word[0] << endl;
  return 0;
}
