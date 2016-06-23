#include <cstdio>
#include <cmath>
#include <vector>
using std::vector;

bool is_prime(int n) {
  if (n == 2 || n == 3) {
    return true;
  } else if (n == 1) { // 1 不是质数！！！！！！！！！！！！！！！！！
    return false;
  }
  for (int i = 2; i <= sqrt(n); ++i) {
    if (n%i == 0) {
      return false;
    }
  }
  return true;
}
int reverse(int n, int d) {
  vector<int> str;
  while (n != 0) {
    str.push_back(n%d);
    n /= d;
  }
  int i = 1, ans = 0;
  for (vector<int>::iterator it = str.end() - 1; it >= str.begin(); --it) {
    ans += *it*i;
    i *= d;
  }
  return ans;
}

int main() {
  int n, d;
  while(scanf("%d", &n) && n > 0) {
    scanf("%d", &d);
    // printf("%d %d\n", is_prime(n), is_prime(d)); // test is_prime()
    // printf("reverse: %d\n", reverse(n, d)); // test reverse()
    if (is_prime(n) && is_prime(reverse(n, d))) {
      printf("Yes\n"); // 注意结果字符串的大小写啊！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
    } else {
      printf("No\n");
    }
  }
  return 0;
}
