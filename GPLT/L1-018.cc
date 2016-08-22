#include <cstdio>

int main() {
  int hh, mm, k;
  scanf("%d:%d", &hh, &mm);
  if ((hh >= 0 && hh <= 11) || (hh == 12 && mm == 0)) {
    printf("Only %02d:%02d.  Too early to Dang.\n", hh, mm);
  } else {
    k = (mm == 0) ? hh - 12 : hh - 11;
    for (int i = 0; i < k; ++i)
      printf("Dang");
    printf("\n");
  }
  return 0;
}
