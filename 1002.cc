#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
string pinyin(unsigned n) {
  string hypy;
  switch (n) {
    case 0: hypy = "ling"; break;
    case 1: hypy = "yi"; break;
    case 2: hypy = "er"; break;
    case 3: hypy = "san"; break;
    case 4: hypy = "si"; break;
    case 5: hypy = "wu"; break;
    case 6: hypy = "liu"; break;
    case 7: hypy = "qi"; break;
    case 8: hypy = "ba"; break;
    case 9: hypy = "jiu"; break;
  }
  return hypy;
}
int main() {
  char shu;
  unsigned sum = 0;
  unsigned n = 0;
  while (cin >> shu) {
    unsigned shuzi = shu;
    sum += shuzi;
    n += 1;
  }
  sum = sum - n*48;
  unsigned bai = sum/100, shi = sum/10%10, ge = sum%10;
  if (bai == 0 && shi == 0)
    cout << pinyin(ge) << endl;
  else if (bai == 0 && shi != 0)
    cout << pinyin(shi) << " " << pinyin(ge) << endl;
  else
    cout << pinyin(bai) << " " << pinyin(shi) << " " << pinyin(ge) << endl;
  return 0;
}
