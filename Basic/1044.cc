#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main() {
  int n, temp, low_temp, high_temp, find;
  char str1[5], str2[5], c;
  const char *low[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
  const char *high[13] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
  scanf("%d", &n);
  c = getchar(); 
  for (int i = 0; i < n; ++i) {
    str2[0] = '\0';
    scanf("%s", str1);
    c = getchar(); 
    if (c == ' ') {
      scanf("%s", str2);
      c = getchar();
    }
      
    if (isdigit(str1[0])) {
      temp = atoi(str1);
      low_temp = temp%13;
      high_temp = temp/13;
      if (temp == 0)
        printf("tret\n");
      else if (high_temp == 0)
        printf("%s\n", low[low_temp]);
      else if (low_temp == 0)
        printf("%s\n", high[high_temp]);
      else
        printf("%s %s\n", high[high_temp], low[low_temp]);
    } else {
      if (str2[0] == '\0') {
        for (int i = 0; i < 13; ++i) {
          find = 1;
          for (int j = 0; j < 3; ++j) {
            if (str1[j] != low[i][j]) {
              find = 0;
              break;
            }
          }
          if (find) {
            printf("%d\n", i);
            break;
          }
        }
        if (!find) {
          for (int i = 0; i < 13; ++i) {
            find = 1;
            for (int j = 0; j < 3; ++j) {
              if (str1[j] != high[i][j]) {
                find = 0;
                break;
              }
            }
            if (find) {
              printf("%d\n", i*13);
              break;
            }
          }
        }
      } else {
        for (int i = 0; i < 13; ++i) {
          find = 1;
          for (int j = 0; j < 3; ++j) {
            if (str1[j] != high[i][j]) {
              find = 0;
              break;
            }
          }
          if (find) {
            high_temp = i;
            break;
          }
        }
        for (int i = 0; i < 13; ++i) {
          find = 1;
          for (int j = 0; j < 3; ++j) {
            if (str2[j] != low[i][j]) {
              find = 0;
              break;
            }
          }
          if (find) {
            printf("%d\n", high_temp*13 + i);
            break;
          }
        }
      }
    }
  }
  return 0;
}
