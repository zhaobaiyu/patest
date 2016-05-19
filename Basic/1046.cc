#include <stdio.h>
int main() {
  int n, a1, a2, b1, b2, adrink = 0, bdrink = 0, awin, bwin;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d%d", &a1, &a2, &b1, &b2);
    awin = (a2 == a1 + b1);
    bwin = (b2 == a1 + b1);
    if (awin && !bwin)
      ++bdrink;
    else if (bwin && !awin)
      ++adrink;
  }
  printf("%d %d\n", adrink, bdrink);
  return 0;
}
