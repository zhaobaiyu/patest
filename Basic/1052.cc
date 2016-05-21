// 这个题目涉及到非Ascii字符，用c语言字符逐个处理会出错，宽字符还有一堆要注意的，所以最后没有逐个处理，而是寻找关键字符，然后用strcpy复制。
#include <stdio.h>
#include <string.h>
int input(char bq[][20]) {
  char str_temp[1000], *pa, *p_first;
  int p = 0, first_find = 0;
  fgets(str_temp, 1000, stdin);
  pa = str_temp;
  while (*pa != '\n') {
    if (*pa == '[') {
      p_first = pa + 1;
      first_find = 1;
    } else if (*pa == ']' && first_find) {
      *pa = '\0';
      strcpy(bq[p++], p_first);
      first_find = 0;
    }
    ++pa;
  }
  return p;
}
int main() {
  char shou[15][20], yan[15][20], kou[15][20];
  int len_shou = input(shou), len_yan = input(yan), len_kou = input(kou);
  int k, temp[5];
  scanf("%d", &k);
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < 5; ++j) {
      scanf("%d", &temp[j]);
    }
    if (temp[0] > len_shou || temp[1] > len_yan || temp[2] > len_kou || temp[3] > len_yan || temp[4] > len_shou) {
      printf("Are you kidding me? @\\/@\n");
      continue;
    }
    if (temp[0] < 1 || temp[1] < 1 || temp[2] < 1 || temp[3] < 1 || temp[4] < 1) { // 测试点1和2，就是针对这一条的，因为题目中只说若序号不存在，所以也包括小于下限，不过我觉得这样真的好无聊，没太大意义！
      printf("Are you kidding me? @\\/@\n");
      continue;
    }
    printf("%s(%s%s%s)%s\n", shou[temp[0]-1], yan[temp[1]-1], kou[temp[2]-1], yan[temp[3]-1], shou[temp[4]-1]);
  }
  return 0;
}
