#include <stdio.h>
#include <limits.h>
int n, m, c1, c2, a[505][505], k, t[505], is_visit[505], temp1, temp2, sp = INT_MAX, mt, sp_sum;
void dfs(int c) {
  // printf("%d ", c); //  test
  is_visit[c] = 1;
  temp2 += t[c];
  for (int i = 0; i < n; ++i) 
    if (a[c][i] != 0) {
      if (i == c2) {
        temp1 += a[c][i];
        temp2 += t[i];
        if (temp1 < sp) {
          sp = temp1;
          mt = temp2;
          sp_sum = 1;
        } else if (temp1 == sp) {
          sp_sum++;
          if (temp2 > mt) 
            mt = temp2;
        }
        temp1 -= a[c][i];
        temp2 -= t[i];
        // printf("2\n"); // test
      } else if (!is_visit[i]) {
        temp1 += a[c][i];
        dfs(i);
        temp1 -= a[c][i];
      }
    }
  is_visit[c] = 0;
  temp2 -= t[c];
}
      
int main() {
  scanf("%d%d%d%d", &n, &m, &c1, &c2);
  for (int i = 0; i < n; ++i)
    scanf("%d", &t[i]);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &temp1, &temp2);
    scanf("%d", &a[temp1][temp2]);
    a[temp2][temp1] = a[temp1][temp2];
  }
  /*
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      printf("%d ", a[i][j]);
    printf("\n");
  }
  */
  temp1 = 0;
  temp2 = 0;
  if (c1 == c2) {
    sp_sum = 1;
    mt = t[c1];
  } else {
    dfs(c1);
  }
  printf("%d %d\n", sp_sum, mt);
  return 0;
}
