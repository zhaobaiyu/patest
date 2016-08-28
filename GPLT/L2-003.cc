#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, d;
  cin >> n >> d;
  vector<pair<double, double> > price(n);
  for (int i = 0; i < n; ++i) 
    cin >> price[i].second;
  double temp;
  for (int i = 0; i < n; ++i) {
    cin >> temp;
    price[i].first = temp/price[i].second;
  }
  sort(price.begin(), price.end(), greater<pair<double, double>>());
  int i = 0;
  double sum = 0;
  while (d > 0 && i < n) {
    if (d >= price[i].second) 
      sum += price[i].second*price[i].first;
    else
      sum += price[i].first*d;
    d -= price[i].second;
    ++i;
  }
  cout << setprecision(2) << fixed << sum << endl;
  return 0;
}
