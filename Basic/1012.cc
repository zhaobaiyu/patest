#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::fixed;
int main() {
  int n;
  int num, yu, a1(0), a2(0), a3(0), a5(0), a2_flag(0), a4_sum(0), a4_flag(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> num;
    yu = num%5;
    if (yu == 0 && num%2 == 0) {
      a1 += num;
    } else if (yu == 1) {
      if ((a2_flag++)%2 == 0)
        a2 += num;
      else
        a2 -= num;
    } else if (yu == 2) {
      a3++;
    } else if (yu == 3) {
      a4_sum += num;
      ++a4_flag;
    } else if (yu == 4) {
      if (a5 < num) a5 = num;
    }
  }
  if (a1 == 0)
    cout << 'N';
  else
    cout << a1;

  cout << ' ';
  
  if (a2_flag == 0)
    cout << 'N';
  else
    cout << a2;

  cout << ' ';  
  
  if (a3 == 0)
    cout << 'N';
  else
    cout << a3;

  cout << ' ';  

  if (a4_flag == 0)
    cout << 'N';
  else {
    cout.precision(1);
    cout << fixed << a4_sum*1.0/a4_flag;
  }

  cout << ' ';  

  if (a5 == 0)
    cout << 'N';
  else
    cout << a5;
  cout << endl;
  return 0;
}
