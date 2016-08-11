#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;

int main() {
  int n;
  cin >> n;
  double temp, sum = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> temp;
    sum += temp*i*(n - i + 1); // 这里是个坑！！！ 必须temp在前面，不然先算后面会溢出的一塌糊涂！！！
  }
  cout << std::fixed << std::setprecision(2) << sum << endl;
  return 0;
}
