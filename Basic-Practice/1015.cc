#include <iostream>
using std::cin;
using std::cout;
using std::endl;
typedef struct {
  int id, de, cai, lei;
} stu;
void shuru(stu stux[], int stux_num, int id_tt, int de_tt, int cai_tt) {
  stux[stux_num].id = id_tt;
  stux[stux_num].de = de_tt;
  stux[stux_num].cai = cai_tt;
}
void paixu(stu stux[], int stux_num) {
  stu temp;
  for (int i = 0; i < stux_num; ++i) {
    for (int j = i + 1; j < stux_num; ++j) {
      if (stux[i].de + stux[i].cai < stux[j].de + stux[j].cai) {
        temp = stux[i];
        stux[i] = stux[j];
        stux[j] = temp;
      }
     else if (stux[i].de + stux[i].cai == stux[j].de + stux[j].cai && stux[i].de < stux[j].de) {
        temp = stux[i];
        stux[i] = stux[j];
        stux[j] = temp;
      }
     else if (stux[i].de + stux[i].cai == stux[j].de + stux[j].cai && stux[i].de == stux[j].de && stux[i].id > stux[j].id) {
        temp = stux[i];
        stux[i] = stux[j];
        stux[j] = temp;
      }
    }
  }
}
int main() {
  int n, l, h, id_t, de_t, cai_t;
  stu stu1[100005], stu2[100005], stu3[100005], stu4[100005];
  int stu1_num(0), stu2_num(0), stu3_num(0), stu4_num(0);
  cin >> n >> l >> h;
  for (int i = 0; i < n; ++i) {
    cin >> id_t >> de_t >> cai_t;
    if (de_t < l || cai_t < l) continue;
    if (de_t >= h && cai_t >= h) {
      shuru(stu1, stu1_num, id_t, de_t, cai_t);
      stu1_num++;
    } else if (de_t >= h) {
      shuru(stu2, stu2_num, id_t, de_t, cai_t);
      stu2_num++;
    } else if (de_t >= cai_t) {
      shuru(stu3, stu3_num, id_t, de_t, cai_t);
      stu3_num++;
    } else {
      shuru(stu4, stu4_num, id_t, de_t, cai_t);
      stu4_num++;
    }
  }
  paixu(stu1, stu1_num);
  paixu(stu2, stu2_num);
  paixu(stu3, stu3_num);
  paixu(stu4, stu4_num);
  cout << stu1_num + stu2_num + stu3_num + stu4_num << endl;
  for (int i = 0; i < stu1_num; ++i) {
    cout << stu1[i].id << ' ' << stu1[i].de << ' ' << stu1[i].cai << endl;
  }
  for (int i = 0; i < stu2_num; ++i) {
    cout << stu2[i].id << ' ' << stu2[i].de << ' ' << stu2[i].cai << endl;
  }
  for (int i = 0; i < stu3_num; ++i) {
    cout << stu3[i].id << ' ' << stu3[i].de << ' ' << stu3[i].cai << endl;
  }
  for (int i = 0; i < stu4_num; ++i) {
    cout << stu4[i].id << ' ' << stu4[i].de << ' ' << stu4[i].cai << endl;
  }  
  return 0;
}
