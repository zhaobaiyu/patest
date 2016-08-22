#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  std::vector<int> a(3);
  std::cin >> a[0] >> a[1] >> a[2];
  std::sort(a.begin(), a.end());
  std::cout << a[0];
  std::cout << "->" << a[1] << "->" << a[2] << std::endl;
  return 0;
}
  
