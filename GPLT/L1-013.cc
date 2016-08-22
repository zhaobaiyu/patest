#include <iostream>

int main() {
  int n, a, b = 0;
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    a = 1;
    for (int j = 1; j <= i; ++j) 
      a *= j;
    b += a;
  }
  std::cout << b << std::endl;
  return 0;
}
