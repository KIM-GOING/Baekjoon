#include <iostream>
#include <vector>
using namespace std;

int str_fi(int num) {
	if (num == 1)
		return 1;
	if (num == 2)
		return 2;
	if (num == 3)
		return 4;
	else
		return str_fi(num - 2) + str_fi(num - 1) + str_fi(num - 3);
}

int main() {
	int test;
	cin >> test;

	vector <int> arr;
	for (int i = 0; i < test; i++) {
		int number;
		cin >> number;
		arr.push_back(number);
	}

	for (int i = 0; i < test; i++)
		cout << str_fi(arr[i]) << '\n';

	return 0;
}