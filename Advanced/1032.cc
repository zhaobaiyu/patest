#include <cstdio>
#include <vector>
#include <map>
using namespace std;
int main() {
  int add1, add2, n, temp1, temp2;
  char c[2];
  scanf("%d%d%d", &add1, &add2, &n);
  map<int, int> w;
  for (int i = 0; i < n; ++i) {
    scanf("%d%s%d", &temp1, c, &temp2);
    w.insert({temp1, temp2}); 
  }
  vector<int> w1, w2;
  temp1 = add1;
  temp2 = add2;
  while (temp1 != -1) {
    w1.push_back(temp1);
    temp1 = w[temp1];
  } 
  while (temp2 != -1) {
    w2.push_back(temp2);
    temp2 = w[temp2];
  }
  w1.push_back(-1);
  w2.push_back(-1);
  /*
  for(int i = 0; i < w1.size(); ++i) {
    printf("%d ", w1[i]);
  }
  printf("\n");
  for(int i = 0; i < w2.size(); ++i) {
    printf("%d ", w2[i]);
  }
  printf("\n");  
  */
  int i = w1.size() - 1, j = w2.size() - 1;
  while (i >= 0 && j >= 0) {
    if (w1[i] != w2[j]) {
      break;
    }
    --i;
    --j;
  }
  int ans = w1[i+1];
  if (ans == -1) {
    printf("-1\n");
  } else {
    printf("%05d", ans);
  }
  return 0;
}
