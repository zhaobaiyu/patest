#include <cstdio>
#include <vector>
#include <map>
#include <set>


using std::vector;
using std::set;
using std::map;

int main() {
  int n;
  scanf("%d", &n);
  int temp1, temp2, temp3, temp4;
  bool temp_b;
  map<int, pair<int> > a;
  set<int> vip;
  for (int i = 0; i < n; ++i) {
    scanf("%d:%d:%d %d %d", &temp1, &temp2, &temp3, &temp4, &temp_b);
    temp1 = ((temp1 - 8)*60 + temp2)*60 + temp3;
    temp2 = temp4*60;
    a.insert({temp1, temp2});
    if (temp_b)
      vip.insert(temp1);
  }
  int k, m;
  scanf("%d%d", &k, &m);
  
