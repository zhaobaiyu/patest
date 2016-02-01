#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
  int n;
  cin >> n;
  string name_str[10000], num_str[10000];
  int grade[10000], max_grade = -1, min_grade = 101, min_order, max_order;
  for (int i = 0; i < n; ++i) {
    cin >> name_str[i] >> num_str[i] >> grade[i];
    if (grade[i] > max_grade) {
      max_order = i;
      max_grade = grade[i];
    }
    if (grade[i] < min_grade) {
      min_order = i;
      min_grade = grade[i];
    }
  }
  cout << name_str[max_order] << " " << num_str[max_order] << endl;
  cout << name_str[min_order] << " " << num_str[min_order] << endl;
  return 0;
}
