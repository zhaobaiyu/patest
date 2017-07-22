#include <iostream>
#include <string>

using namespace std;

int main() {
  string str, tmp;
  int n, iter = 0;
  cin >> str >> n;
  getline(cin, tmp);
  getline(cin, tmp);
  while (tmp != "#") {
    if (tmp == str) {
      cout << "Welcome in" << endl;
      break;
    } else {
      cout << "Wrong password: " << tmp << endl;
      ++iter;
      if (iter == n) {
        cout << "Account locked" << endl;
        break;
      }
      getline(cin, tmp);
    }
  }
  return 0;
}
