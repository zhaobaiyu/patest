#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
  char name[10]; // 第一次提交时犯了低级错误，8位字符的串只分配了8个空间，导致答案错误，要小心啊！
  int height;
} student;
int cmp(const void *pa, const void *pb) {
  student *a = *(student **)pa, *b = *(student **)pb; // 这里要超级小心，超级细心！！！cmp的参数是指向待比较的数组内的元素，而数组内元素本身又是指针，所以**才定位到指向数据的指针
  if (a->height == b->height) 
    return strcmp(a->name, b->name);
  else 
    return (b->height - a->height);
}
void output(student *stu[], int first, int last) {
  int len = last - first + 1;
  if (len == 1) {
    printf("%s", stu[first]->name);
  }
  else if (len%2 == 0) {
    printf("%s", stu[last]->name);
    for (int i = last - 2; i >= first; i -= 2)
      printf(" %s", stu[i]->name);
    for (int i = first; i <= last; i += 2)
      printf(" %s", stu[i]->name);
  } else {
    printf("%s", stu[last - 1]->name);
    for (int i = last - 3; i >= first; i -= 2)
      printf(" %s", stu[i]->name);
    for (int i = first; i <= last; i += 2)
      printf(" %s", stu[i]->name);
  }
  printf("\n");
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  student *stu[10005];
  for (int i = 0; i < n; ++i) {
    stu[i] = (student *)malloc(sizeof(student));
    scanf("%s%d", stu[i]->name, &stu[i]->height);
  }
  qsort(stu, n, sizeof(student *), cmp);
  int first_sum = n/k + n%k;
  output(stu, 0, first_sum - 1);
  while (first_sum < n) {
    output(stu, first_sum, first_sum + n/k - 1);
    first_sum += n/k;
  }
  return 0;
}
