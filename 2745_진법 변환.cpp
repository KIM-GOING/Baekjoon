#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	string n;
	int b;
	vector<int> number;

	cin >> n >> b;

	for (int i = 0; i < n.length(); i++) {
		int num = 0;
		if (n[i] > 64)
			num = n[i] - 55;
		else
			num = n[i] - 48;
		number.push_back(num);
	}

	int sum = 0;
	for (int i = 0; i < number.size(); i++)
		sum += number[i] * pow(b, number.size() - i - 1);

	cout << sum;

	return 0;
}