#include <stdio.h>
int main() {
  int a[105][105], b[105][105], temp;
  int n, middle[105];
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[0][i]);
  }
  for (int i = 0; i < n; ++i)
    scanf("%d", &middle[i]);
  
  for (int i = 0; i < n - 1; ++i) { // 插入排序
    for (int j = i; j >= 0; --j) {
      if (a[0][j + 1] < a[0][j]) {
        temp = a[0][j + 1];
        a[0][j + 1] = a[0][j];
        a[0][j] = temp;
      }
    }
    for (int j = 0; j < n; ++j) {
      a[i+1][j] = a[0][j];
    }
  }
  
  int find, find_a;
  for (int i = 1; i < n; ++i) { // 在插入排序结果中查找
    find = 1;
    for (int j = 0; j < n; ++j) {
      if (middle[j] != a[i][j]) {
        find = 0;
        break;
      }
    }
    if (find) {
      find_a = i;
      break;
    }
  }
  
  if (find) { // 如果在插入排序中找到，则输出
    printf("Insertion Sort\n");
    printf("%d", a[find_a + 1][0]);
    for (int i = 1; i < n; ++i) {
      printf(" %d", a[find_a + 1][i]);
    }
    printf("\n");
  } else { // 如果没找到，则开始归并排序，迭代法归并
    ;
  }
  return 0;
}
