#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string n1;
	string n2;
	cin >> n1 >> n2;

	vector<int> num1;
	for (int i = 0; i < n1.size(); i++) {
		num1.push_back(n1[i]);
	}
	vector<int> num2;
	for (int i = 0; i < n2.size(); i++) {
		num1.push_back(n2[i]);
	}

	vector<int> sum;
	string max;
	string min;
	if (n1.size() >= n2.size()) {
		max = n1;
		min = n2;
	}
	else {
		max = n2;
		min = n1;
	}

	int remain = 0;
	int share = 0;
	for (int i = 0; i < max.size(); i++) {
		if (min.size() < i + 1) {
			remain = (max.back() + min.back()) % 10;
			sum.push_back(remain + share);
			share = (max.back() + min.back()) / 10;
			max.pop_back();
			min.pop_back();
		}
		else {
			remain = max.back() % 10;
			sum.push_back(remain + share);
			share = 0;
			max.pop_back();
		}
	}

	for (int i = 0; i < sum.size(); i++) {
		cout << sum[sum.size() - 1 - i];
	}

	return 0;
}