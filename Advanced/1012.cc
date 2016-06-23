#include <cstdio>
#include <vector>
#include <algorithm>
using std::vector;
using std::sort;
using std::greater;
int n, m;
vector<int> rank(vector<int> grades) {
  int temp = 0, i = 100, j = 0;
  vector<int> rank_temp(101);
  while (i >= 0 && j < n) {
    if (i == grades[j]) {
      rank_temp[i] = temp + 1;
      ++j;
    } else {
      --i;
      temp = j;
    }
  }
  return rank_temp;
}

int main() {
  int temp, temp_c, temp_m, temp_e, temp_a, id_temp;
  scanf("%d%d", &n, &m);
  vector<int> id(1000000, -1), c_grades, m_grades, e_grades, a_grades;
  for (int i = 0; i < n; ++i) {
    scanf("%d %d %d %d", &temp, &temp_c, &temp_m, &temp_e);
    id[temp] = i;
    c_grades.push_back(temp_c);
    m_grades.push_back(temp_m);
    e_grades.push_back(temp_e);
    a_grades.push_back((temp_c + temp_m + temp_e)/3);
  }
  vector<int> c_grades_temp(c_grades), m_grades_temp(m_grades), e_grades_temp(e_grades), a_grades_temp(a_grades);
  sort(c_grades_temp.begin(), c_grades_temp.end(), greater<int>());
  sort(m_grades_temp.begin(), m_grades_temp.end(), greater<int>());
  sort(e_grades_temp.begin(), e_grades_temp.end(), greater<int>());
  sort(a_grades_temp.begin(), a_grades_temp.end(), greater<int>());  
  vector<int> c_rank(rank(c_grades_temp)), m_rank(rank(m_grades_temp)), e_rank(rank(e_grades_temp)), a_rank(rank(a_grades_temp));
  for (int i = 0; i < m; ++i) {
    scanf("%d", &temp);
    id_temp = id[temp];
    if (id_temp == -1) {
      printf("N/A\n");
      continue;
    } else {
      temp_a = a_rank[a_grades[id_temp]];
      temp_c = c_rank[c_grades[id_temp]];
      temp_m = m_rank[m_grades[id_temp]];
      temp_e = e_rank[e_grades[id_temp]];
      if (temp_a <= temp_c && temp_a <= temp_m && temp_a <= temp_e) 
        printf("%d A\n", temp_a);
      else if (temp_c <= temp_a && temp_c <= temp_m && temp_c <= temp_e)
        printf("%d C\n", temp_c);
      else if (temp_m <= temp_a && temp_m <= temp_c && temp_m <= temp_e)
        printf("%d M\n", temp_m);
      else if (temp_e <= temp_a && temp_e <= temp_c && temp_e <= temp_m)
        printf("%d E\n", temp_e);
    }
  }
  return 0;
}
