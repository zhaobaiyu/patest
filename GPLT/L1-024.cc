#include <iostream>
int main() {
  int d;
  std::cin >> d;
  d = ((d + 2)%7 == 0) ? 7 : (d + 2)%7;
  std::cout << d << std::endl;
  return 0;
}
