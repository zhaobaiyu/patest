#include <stdio.h>
#include <stdlib.h>
int main() {
  int n, m, temp1, temp2, realnum[1005];
  char *id[1005], *tempstr;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    tempstr = (char *)malloc(14*sizeof(char));
    scanf("%s%d%d", tempstr, &temp1, &temp2);
    id[temp1] = tempstr;
    realnum[temp1] = temp2;
  }
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &temp1);
    printf("%s %d\n", id[temp1], realnum[temp1]);
  }
  for (int i = 0; i < n; ++i) 
    free(id[i]);
  return 0;
}
