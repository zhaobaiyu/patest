#include <cstdio>
#include <cstring>
#include <cstdlib>
int main() {
  const int max_d = 20140907, min_d = 18140905;
  int n, sum = 0, temp_d, temp_y_d = min_d, temp_o_d = max_d;
  char *y_name = (char *)malloc(6*sizeof(char)), *o_name = (char *)malloc(6*sizeof(char)), temp_name[6], date_str[15];
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s%s", temp_name, date_str);
    *(date_str + 4) = *(date_str + 5);
    *(date_str + 5) = *(date_str + 6);
    *(date_str + 6) = *(date_str + 8);
    *(date_str + 7) = *(date_str + 9);    
    *(date_str + 8) = '\0';
    temp_d = atoi(date_str);
    if ((temp_d - min_d) > 0 && (max_d - temp_d) > 0) {
      sum++;
      if (temp_d > temp_y_d) {
        strcpy(y_name, temp_name);
        temp_y_d = temp_d;
      }
      if (temp_d < temp_o_d) {
        strcpy(o_name, temp_name);
        temp_o_d = temp_d;
      }
    }
  }
  if(sum) printf("%d %s %s\n", sum, o_name, y_name); 
  else printf("0\n");  // Stupid!!! Pointless!!!    
  return 0;
}
