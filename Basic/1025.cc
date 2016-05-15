//天哪！！！终于Accepted！！！题目看错了，我以为反转后的结点完全不变，其实反转后还必须是链表！！！所以一直出错！！！这个题目我做了好多种实现，各种方法，到头来却是审题的问题，我真是要哭晕了！！！
#include <stdio.h>
#include <stdlib.h>
int data[100005], next[100005], ans[100005];
int main() {
  int head, n, k, temp;
  scanf("%d%d%d", &head, &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &temp);
    scanf("%d%d", &data[temp], &next[temp]);
  }
  temp = head;
  int sum = 0;
  while (temp != -1) {
    sum++;
    temp = next[temp];
  }
  if (sum == 0) {
    printf("-1/n");
    return 0;
  }
  
  int *bufptr = (int *)malloc(k*sizeof(int));
  int ans_p = 0;
  int group = sum/k;
  for (int i = 0; i < group; ++i) {
    for (int j = 0; j < k; j++) {
      *bufptr++ = head;
      head = next[head];
    }
    for (int j = 0; j < k; j++) {
      ans[ans_p++] = *--bufptr;
    }
  }

  int last = sum%k;
  for (int i = 0; i < last; ++i) {
    ans[ans_p++] = head;
    head = next[head];
  }

  for (int i = 0; i < sum - 1; ++i) {
    printf("%05d %d %05d\n", ans[i], data[ans[i]], ans[i + 1]);
  }
  printf("%05d %d -1\n", ans[sum - 1], data[ans[sum - 1]]);
  return 0;
}
