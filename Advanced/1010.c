// 1010. Radix

/*
  本题在radix小于1000时枚举暴力求解，当radix小于1000找不到时，采用二分查找。
  
  有意思的题目，通过率只有0.08，感觉是PAT甲级通过率最低的题了
  第一个版本题交后，只有部分正确，原来这里的基数并不是进制，所以是存在基数很大的情况，剩下的工作就是解一元高次方程了。
  最终Accepted，但是，如果所有数据都二分查找，在牛客网Accepted，可是在PAT会有部分结果不正确，估计是溢出或者在类型转换时出了问题，不想深究了。
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdint.h>
long long str_to_val(const char *str, long long radix) {
  int len = strlen(str), temp_c;
  long long val = 0;
  /*
  if (pow(radix, len - 1) < 0)
    return -1;
  */
  for (int i = 0; i < len; ++i) {
    if (isdigit(str[i])) {
      temp_c = str[i] - '0';
    } else if (islower(str[i])) {
      temp_c = str[i] - 'a' + 10;
    } else {
      return -1;
    }
    if (temp_c >= radix)
      return -1;
    val += pow(radix, len - 1 - i)*temp_c;
  }
  return val;
}
long long bs_radix(const char *str, long long radix, long long val) { // 二分查找可能的radix
  long long first = 2, last = radix, mid;
  while (first <= last) {
    mid = (first + last)/2;
    long long mid_val = str_to_val(str, mid);

    if (mid_val == -1) { // 当radix到了36以下时就可能出现str_to_val时字符大于radix的情况，这种情况是由于radix太小引起，故查找右半边。
      first = mid + 1;
      continue;
    }

    if (mid_val == val) {
      return mid;
    } else if (mid_val < val) {
      first = mid + 1;
    } else {
      last = mid - 1;
    }
  }
  return -1;
}
long long max_radix(int len) {
  long long ans = INT64_MAX/50;
  for (int i = 0; i < len - 2; ++i) {
    ans = sqrt(ans);
  }
  return ans;
}
int main() {
  char s1[12], s2[12], temp[12];
  int tag, radix;
  scanf("%s%s%d%d", s1, s2, &tag, &radix);
  if (tag == 2) {
    strcpy(temp, s1);
    strcpy(s1, s2);
    strcpy(s2, temp);
  }
  long long val = str_to_val(s1, radix);
  // printf("%lld\n", val); //
  if (val == -1) {
    printf("Impossible\n");
    return 0;
  }
  
  // 这部分是radix小于1000时的暴力枚举
  int is_find = 0;
  long long a[1000];
  for (int i = 2; i < 1000; ++i) {
    a[i] = str_to_val(s2, i);
    if (a[i] == -1)
      continue;
    if (a[i] == val) {
      is_find = 1;
      printf("%d\n", i);
      break;
    }
  }
  if (is_find) 
    return 0;
  // 
  
  int len = strlen(s2);
  long long ans;
  
  if (len == 1) 
    ans = bs_radix(s2, 80, val); // 因为第一次二分就折半，如果radix太小，str_to_val会返回-1，直接产生错误。
  else
    ans = bs_radix(s2, max_radix(len), val);
  
  
  if (ans == -1) {
    printf("Impossible\n");
  } else {
    printf("%lld\n", ans);
  }
  
  return 0;
} 
