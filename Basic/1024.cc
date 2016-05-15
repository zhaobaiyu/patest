#include <cstdio>
#include <cstdlib>
int main() {
  char a = getchar();
  char ttt[20000];
  char *b = ttt;
  *b = getchar();
  char *pb = b;
  int nb = 1;
  char t = getchar();
  while ((*(++pb) = getchar()) != 'E') {
    nb++;
  }
  *(b + nb) = '\0';
  t = getchar();
  int c = (t == '+') ? 1 : 0;
  int d;
  scanf("%d", &d);

  if (a == '-') putchar(a);
  if (c) {
    if (d >= nb - 1) {
      printf("%s", b);
      for (int i = 1; i <= d - nb + 1; ++i) printf("0");
    } else {
      int i = 0;
      while (i <= d) printf("%c", *(b+i++));
      printf(".");
      while (i < nb) printf("%c", *(b+i++));
    }
  } else {
    if (d == 0) {
      printf("%c.", *b);
      int i = 1;
      while (i < nb) printf("%c", *(b+i++));
    } else {
      printf("0.");
      for(int i = 1; i < d; ++i) printf("0");
      printf("%s", b);
    }
  }
  printf("\n");
  return 0;
}
