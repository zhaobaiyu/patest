#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
int main() {
  int n;
  scanf("%d", &n);
  char *name[105];
  int is_id[105];
  int all_passed = 1;
  memset(is_id, 1, sizeof(is_id)); // The 3rd parameter is the sum of bytes, NOT the size of array element!!!
  const int qz[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
  const char const_m[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'}; 
  for (int i = 0; i < n; ++i) {
    name[i] = (char *)malloc(19*sizeof(char));
    while (isspace(*name[i] = getchar()))
      ;
    for (int j = 1; j < 18; ++j) 
      *(name[i] + j) = getchar();
    *(name[i] + 18) = '\0';
  }
  for (int i = 0; i < n; ++i) {
    int jy = 0;
    for (int j = 0; j < 17; ++j) {
      char t_c = *(name[i] + j);
      if (isdigit(t_c)) {
        jy += (t_c - '0') * qz[j];
      } else {
        is_id[i] = 0;
        break;
      }
    }
    if (!is_id[i]) {
      printf("%s\n", name[i]);
      all_passed = 0;
    }
    else {
      jy %= 11;
      if (const_m[jy] != *(name[i] + 17)) {
        is_id[i] = 0;
        printf("%s\n", name[i]);
        all_passed = 0;
      }
    }
  }
  if (all_passed) printf("All passed\n");
  return 0;
}
