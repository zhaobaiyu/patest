// It is very hard for me to solve this problem by myself.
// I have tried many times, and eventually it is ACcepted!!!
#include <cstdio>
#include <cstdlib>
typedef struct {
  int id, de, cai;
  bool is_select;
} stu;
stu stu1[100000];
int no[100000];
int cmp(const void *pa, const void *pb); //   void px(int qd, int zd);

int main() {
  int n, l, h;
  scanf("%d%d%d", &n, &l, &h);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", &stu1[i].id, &stu1[i].de, &stu1[i].cai);
    if(stu1[i].de < l || stu1[i].cai < l)
      stu1[i].is_select = true;
    else
      stu1[i].is_select = false;
  }

  int c1 = 0;
  for (int i = 0; i < n; ++i) {
    if (stu1[i].de >= h && stu1[i].cai >= h) {
      stu1[i].is_select = true;
      no[c1++] = i;
    }
  }
  qsort(&no[0], c1, sizeof(no[0]), cmp);
  
  int c2 = c1;
  for (int i = 0; i < n; ++i) {
    if (!stu1[i].is_select && stu1[i].de >= h) {
      stu1[i].is_select = true;
      no[c2++] = i;
    }
  }
  qsort(&no[c1], c2 - c1, sizeof(no[0]), cmp);  //  c2 - c1 is the sum!!! NOT c2!!!

  int c3 = c2;
  for (int i = 0; i < n; ++i) {
    if (!stu1[i].is_select && stu1[i].cai < h && stu1[i].de >= stu1[i].cai) {
      stu1[i].is_select = true;
      no[c3++] = i;
    }
  }
  qsort(&no[c2], c3 - c2, sizeof(no[0]), cmp);

  int c4 = c3;
  for (int i = 0; i < n; ++i) {
    if (!stu1[i].is_select) {
      no[c4++] = i;
    }
  }
  qsort(&no[c3], c4 - c3, sizeof(no[0]), cmp);

  printf("%d\n", c4);
  for (int i = 0; i < c4; ++i) {
    printf("%d %d %d\n", stu1[no[i]].id, stu1[no[i]].de, stu1[no[i]].cai);
  }
  return 0;
}

int cmp(const void *pa, const void *pb) {
  int a = *(int *)pa, b = *(int *)pb;
  if (stu1[a].de + stu1[a].cai < stu1[b].de + stu1[b].cai)
    return 1;
  else if (stu1[a].de + stu1[a].cai == stu1[b].de + stu1[b].cai && stu1[a].de < stu1[b].de)
    return 1;
  else if (stu1[a].de + stu1[a].cai == stu1[b].de + stu1[b].cai && stu1[a].de == stu1[b].de && stu1[a].id > stu1[b].id)
    return 1;
  else return -1;
}
