#include <stdio.h>
#include <limits.h>
#include <string.h>
int time_to_int(const char *time) {
  return ((time[0] - '0')*10 + time[1] - '0')*3600 + ((time[3] - '0')*10 + time[4] - '0')*60 + (time[6] - '0')*10 + time[7] - '0';
}
int main() {
  int n;
  scanf("%d", &n);
  char temp_id[18], temp_time1[10], temp_time2[10], login_in_id[18], login_out_id[18];
  int login_in = INT_MAX, login_out = -1, time1, time2;
  for (int i = 0; i < n; ++i) {
    scanf("%s %s %s", temp_id, temp_time1, temp_time2);
    time1 = time_to_int(temp_time1);
    time2 = time_to_int(temp_time2);
    if (time1 < login_in) {
      strcpy(login_in_id, temp_id);
      login_in = time1;
    }
    if (time2 > login_out) {
      strcpy(login_out_id, temp_id);
      login_out = time2;
    }
  }
  printf("%s %s\n", login_in_id, login_out_id);
  return 0;
}
