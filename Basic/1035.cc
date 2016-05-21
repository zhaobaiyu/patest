#include <stdio.h>
int main() {
  int a[105][105], b[105][105], temp;
  int n, middle[105];
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[0][i]);
  }
  for (int i = 0; i < n; ++i)
    b[0][i] = a[0][i];
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
    int *pa = b[0];
    temp = 1;
    int seg, start;
    for (seg = 1; seg < n; seg += seg) {
      for (start = 0; start < n; start += seg + seg) {
        int low = start, mid = (start + seg) < n ? (start + seg) : n, high = (start + seg + seg) < n ? (start + seg + seg) : n;
        int k = low;
        int start1 = low, end1 = mid, start2 = mid, end2 = high;
        while (start1 < end1 && start2 < end2)
          b[temp][k++] = pa[start1] < pa[start2] ? pa[start1++] : pa[start2++];
        while (start1 < end1)
          b[temp][k++] = pa[start1++];
        while (start2 < end2)
          b[temp][k++] = pa[start2++];
      }
      pa = b[temp++];
    }
    for (int i = 1; i < temp; ++i) { // 在插入排序结果中查找
      find = 1;
      for (int j = 0; j < n; ++j) {
        if (middle[j] != b[i][j]) {
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
      printf("Merge Sort\n");
      printf("%d", b[find_a + 1][0]);
      for (int i = 1; i < n; ++i) {
        printf(" %d", b[find_a + 1][i]);
      }
      printf("\n");    
    }
  }
  return 0;
}
