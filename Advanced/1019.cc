#include <cstdio>
#include <vector>
#include <stack>

using std::vector;
using std::stack;
int main() {
  int n, b;
  scanf("%d%d", &n, &b);
  stack<int> s;
  vector<int> a;
  if (n == 0) { // 第一次提交时，这里没有考虑，导致n为0时段错误。
    printf("Yes\n0\n");
    return 0;
  }
  while (n != 0) {
    s.push(n%b);
    n /= b;
  }
  while (!s.empty()) {
    a.push_back(s.top());
    s.pop();
  }
  bool is_right = true;
  for (int i = 0; i < a.size()/2; ++i) {
    if (a[i] != a[a.size() - 1 - i]) {
      is_right = false;
      break;
    }
  }
  if (is_right) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  printf("%d", a[0]);
  for (auto iter = a.cbegin() + 1; iter != a.cend(); ++iter) {
    printf(" %d", *iter);
  }
  printf("\n");
  return 0;
}
