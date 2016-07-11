#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
	string n, m;
	cin >> n;
	vector<int> v1(10), v2(10), ans;
	int jinwei = 0, temp1, temp2;
	for (auto iter = n.crbegin(); iter != n.crend(); ++iter) {
		temp1 = *iter - '0';
		++v1[temp1];
		temp2 = (temp1 * 2 + jinwei) % 10;
		ans.push_back(temp2);
		++v2[temp2];
		jinwei = temp1 * 2 / 10;
	}
	if (jinwei != 0) { // 粗心大意！！！这里要考虑首位进位之后的情况！！！
		ans.push_back(jinwei);
		++v2[jinwei];
	}
	if (v1 == v2) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	for (auto iter = ans.crbegin(); iter != ans.crend(); ++iter) {
		cout << *iter;
	}
	cout << endl;
	return 0;
}
