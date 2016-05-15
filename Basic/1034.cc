#include <cstdio>
int main() {
  long a, b, c, d;  // If a is int and a == -2147483648, -a will OVERFLOW!!! So using long.
  scanf("%ld/%ld %ld/%ld", &a, &b, &c, &d);
  void cal(long a, long b, long c, long d, char f);
  cal(a, b, c, d, '+');
  cal(a, b, c, d, '-');
  cal(a, b, c, d, '*');
  cal(a, b, c, d, '/');
  return 0;
}

void cal(long a, long b, long c, long d, char f) {
  void hj(long x, long y);
  hj(a, b);
  printf(" %c ", f);
  hj(c, d);
  printf(" = ");
  switch (f) {
    case '+' : hj(a*d+b*c, b*d); break;
    case '-' : hj(a*d-b*c, b*d); break;
    case '*' : hj(a*c, b*d); break;
    case '/' : hj(a*d, b*c); break;
  }
  printf("\n");
}

void hj(long x, long y) {
  int neg = 0;
  int flag = 1;
  if (y == 0) {
    printf("Inf");
    return;
  } else if (x == 0) {
    printf("0");
    return;
  } else if (x < 0 && y > 0) {
    x *= -1;
    neg = 1;
  } else if (x > 0 && y < 0) {
    y *= -1;
    neg = 1;
  } else if (x < 0 && y < 0) {
    x *= -1;
    y *= -1;
  } 
  if (neg) printf("(-");
  if (x%y == 0) {
    printf("%ld", x/y);
    flag = 0;
  } else if (x > y) {
    printf("%ld ", x/y);
    x %= y;
  }
  long gcd(long x, long y);
  if (flag) {
    long xy_gcd = gcd(x, y);
    printf("%ld/%ld", x/xy_gcd, y/xy_gcd);
  }
  if (neg) printf(")");
}

long gcd(long x, long y) {
  if (y == 0) return x;
  return gcd(y, x%y);
}
