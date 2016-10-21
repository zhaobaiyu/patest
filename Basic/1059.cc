#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip>
using namespace std;
vector<bool> p3(10001, false);
void getprimes() {
  vector<bool> p1(100, false);
  vector<short> less10{3, 5, 7}, p2;
  for (int i = 0; i < 3; ++i) 
    for (int j = 3*less10[i]; j < 100; j += 2*less10[i]) 
      p1[j] = true;
  for (int i = 3; i < 100; i += 2) 
    if (!p1[i])
      p2.push_back(i);
  int sizep2 = p2.size();
  for (int i = 0; i < sizep2; ++i)
    for (int j = 3*p2[i]; j < 10001; j += 2*p2[i]) 
      p3[j] = true;
  return;
}
/* find all the primes in 10000
vector<short> primes;
void getprimes() {
  vector<bool> p1(100, false), p3(10000, false);
  vector<short> less10{3, 5, 7}, p2;
  primes.push_back(2);
  for (int i = 0; i < 3; ++i) 
    for (int j = 3*less10[i]; j < 100; j += 2*less10[i]) 
      p1[j] = true;
  for (int i = 3; i < 100; i += 2) 
    if (!p1[i])
      p2.push_back(i);
  
  int sizep2 = p2.size();
  for (int i = 0; i < sizep2; ++i)
    for (int j = 3*p2[i]; j < 10000; j += 2*p2[i]) 
      p3[j] = true;
  for (int i = 3; i < 10000; i += 2)
    if (!p3[i])
      primes.push_back(i);
      
  int sizeprimes = primes.size();
  for (int i = 0; i < sizeprimes; ++i)
    cout << ' ' << primes[i];
  cout << endl;
  cout << sizeprimes << endl;  
  return;
}
*/
int main() {
  ios::sync_with_stdio(false);
  int n, k, tmp1;
  cin >> n;
  unordered_map<short, short> d;
  cin >> tmp1;
  d.insert({tmp1, 1});
  getprimes();
  for (int i = 1; i < n; ++i) {
    cin >> tmp1;
    if ((i+1)%2 == 0 || p3[i+1]) 
      d.insert({tmp1, 3});
    else
      d.insert({tmp1, 2});
    // cout << tmp1 << d[tmp1] << endl;
  }
  cin >> k;
  for (int i = 0; i < k; ++i) {
    cin >> tmp1;
    cout << setfill('0') << setw(4) << tmp1 << ": ";
    if (d.find(tmp1) == d.end()) {
      cout << "Are you kidding?" << endl;
      continue;
    }
    switch(d[tmp1]) {
      case 0: cout << "Checked"; break;
      case 1: cout << "Mystery Award"; d[tmp1] = 0; break;
      case 2: cout << "Minion"; d[tmp1] = 0; break;
      case 3: cout << "Chocolate"; d[tmp1] = 0; break;
    }
    cout << endl;
  }
  return 0;
}
