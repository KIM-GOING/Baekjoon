#include <iostream>
using namespace std;

int main() {
	int n, v;
	int arr[100] = { 0 };
	int count = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr[i] = num;
	}

	cin >> v;

	for (int i = 0; i < n; i++) {
		if (arr[i] == v)
			count++;
	}

	cout << count;

	return 0;
}