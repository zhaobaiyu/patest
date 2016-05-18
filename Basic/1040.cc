#include <stdio.h>
#include <string.h>
char a[100005];
int headtoP[100005], tailtoT[100005];
int main() {
  scanf("%s", a);
  int lena = strlen(a), temp = 0;
  for (int i = 0; i < lena; ++i) {
    if (a[i] == 'P') ++temp;
    headtoP[i] = temp;
  }
  temp = 0;
  for (int i = lena - 1; i >= 0; --i) {
    if (a[i] == 'T') ++temp;
    tailtoT[i] = temp;
  }
  long long sum = 0;
  for (int i = 0; i < lena; ++i) 
    if (a[i] == 'A')
      sum += headtoP[i] * tailtoT[i];
  int sum2 = sum%1000000007;
  printf("%d\n", sum2);
  return 0;
}
