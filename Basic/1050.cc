#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int m[10005][10005], array[10005];
int cmp(const void *pa, const void *pb) {
  return *(int *)pb - *(int *)pa;
}
int main() {
  int n, col, row;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) 
    scanf("%d", &array[i]);
  qsort(array, n, sizeof(int), cmp);
  for (int i = sqrt(n); i >= 1; --i) 
    if (n%i == 0) {
      col = i;
      row = n/i;
      break;
    }
  
  int left = 0, right = col - 1, top = 0, bottom = row - 1, col_temp = 0, row_temp = 0, p = 0;
  while (p < n) {
    while (col_temp <= right) 
      m[row_temp][col_temp++] = array[p++];
    if (p >= n) break;    
    ++top;
    ++row_temp;
    --col_temp;
    while (row_temp <= bottom) 
      m[row_temp++][col_temp] = array[p++];
    if (p >= n) break;
    --right;
    --col_temp;
    --row_temp;
    while (col_temp >= left)
      m[row_temp][col_temp--] = array[p++];
    if (p >= n) break; // 这里是一个坑，如果没有判断，下面一个循环将会执行，在只剩竖排的情况下会出错！需要注意。
    --bottom;
    --row_temp;
    ++col_temp;
    while (row_temp >= top)
      m[row_temp--][col_temp] = array[p++];
    if (p >= n) break;    
    ++left;
    ++col_temp;
    ++row_temp;
  }
  
  for (int i = 0; i < row; ++i) {
    printf("%d", m[i][0]);
    for (int j = 1; j < col; ++j) {
      printf(" %d", m[i][j]);
    }
    printf("\n");
  }
  return 0;
}
