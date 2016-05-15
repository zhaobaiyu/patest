#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
  int n, jy(0), jp(0), js(0), j[3], y[3];
  for (int i = 0; i < 3; ++i) {
    j[i] = 0;
    y[i] = 0;
  }
  string str1;
  cin >> n;
  getline(cin, str1);
  for (int i = 0; i < n; ++i) {
    getline(cin, str1);
    if (str1 == "B C" || str1 == "C J" || str1 == "J B") {
      ++jy;
      switch(str1[0]) {
        case 'B': ++j[0];break;
        case 'C': ++j[1];break;
        case 'J': ++j[2];break;
      }
    } else if (str1 == "C B" || str1 == "J C" || str1 == "B J") {
      ++js;
      switch(str1[2]) {
        case 'B': ++y[0];break;
        case 'C': ++y[1];break;
        case 'J': ++y[2];break;
      }
    } else {
      ++jp;
    }
  }
  cout << jy << ' ' << jp << ' ' << js << endl
       << js << ' ' << jp << ' ' << jy << endl;
  int temp1 = -1, temp_num1 = -1, temp2 = -1, temp_num2 = -1;
  for (int i = 0; i < 3; ++i) {
    if (j[i] > temp1) {
      temp1 = j[i];
      temp_num1 = i;
    }
    if (y[i] > temp2) {
      temp2 = y[i];
      temp_num2 = i;
    }
  }
  string str2("BCJ");
  cout << str2[temp_num1] << ' ' << str2[temp_num2] << endl;
  return 0;
}  
