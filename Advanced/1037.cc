#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  int nc, np, temp;
  vector<long long> ncpos, ncneg;
  vector<long long> nppos, npneg;
  cin >> nc;
  for(int i = 0; i < nc; ++i) {
    cin >> temp;
    if (temp > 0)
      ncpos.push_back(temp);
    else if (temp < 0)
      ncneg.push_back(temp);
  }
  cin >> np;
  for(int i = 0; i < np; ++i) {
    cin >> temp;
    if (temp > 0)
      nppos.push_back(temp);
    else if (temp < 0)
      npneg.push_back(temp);
  }  
  sort(ncpos.begin(), ncpos.end(), greater<int>());
  sort(ncneg.begin(), ncneg.end());
  sort(nppos.begin(), nppos.end(), greater<int>());
  sort(npneg.begin(), npneg.end());  
  unsigned i = 0, j = 0;
  unsigned long long sum = 0;
  while (i < ncpos.size() && j < nppos.size()) {
    sum += ncpos[i]*nppos[j];
    ++i;
    ++j;
  }
  i = 0;
  j = 0;
  while (i < ncneg.size() && j < npneg.size()) {
    sum += ncneg[i]*npneg[j];
    ++i;
    ++j;
  }  
  cout << sum << endl;
}
