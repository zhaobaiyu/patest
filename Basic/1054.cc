#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int main() {
  int n, k = 0, lens, is_error, temp_flag;
  double sum = 0, temp_f;
  char s[100];
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    is_error = 0;
    if (!isdigit(s[0]) && s[0] != '.' && s[0] !='-') {
      printf("ERROR: %s is not a legal number\n", s);
      // printf("flag1 %s\n", s); //      
      continue;
    }
    lens = strlen(s);
    for (int j = 1; j < lens; ++j) 
      if (!isdigit(s[j]) && s[j] != '.') { //我都要哭了！把这里第二个s[j]写成s[0]，debug了很久！真是无语了！细心细心细心！！！
        printf("ERROR: %s is not a legal number\n", s);
        // printf("flag2 %s\n", s); //
        is_error = 1;
        break;
      }
    if (is_error) continue;
    for (int j = 0; j < lens; ++j) 
      if (s[j] == '.') {
        temp_flag = 1;
        for (int k = j + 1; k <= j + 3; ++k) {
          if (s[k] == '\0') {
            temp_flag = 0;
            break;
          }
        }
        if (temp_flag) {
          printf("ERROR: %s is not a legal number\n", s);
          // printf("flag3 %s\n", s); //
          is_error = 1;
          break;
        }
        if (s[j+1] == '.' || s[j+2] == '.') {
          printf("ERROR: %s is not a legal number\n", s);
          // printf("flag4 %s\n", s); //
          is_error = 1;
          break;
        }
        break;
      }
    if (is_error) continue;
    temp_f = atof(s);
    if (temp_f < -1000 || temp_f > 1000) {
      printf("ERROR: %s is not a legal number\n", s);
      continue;
    }
    ++k;
    sum += temp_f;
  }
  if (k == 0)
    printf("The average of 0 numbers is Undefined\n");
  else if (k == 1) // 第一遍提交没注意到这里的number不一样。审题审题审题！！！
    printf("The average of 1 number is %.2lf\n", sum);
  else
    printf("The average of %d numbers is %.2lf\n", k, sum/k);
  return 0;
}
