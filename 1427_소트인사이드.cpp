#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string number;
	cin >> number;
	int* arr = new int[number.size()];

	for (int i = 0; i < number.size(); i++) {
		int num = number[i] - '0';
		arr[i] = num;
	}

	sort(arr, arr + number.size(), greater<>());

	for (int i = 0; i < number.size(); i++)
		cout << arr[i];

	delete[] arr;

	return 0;
}