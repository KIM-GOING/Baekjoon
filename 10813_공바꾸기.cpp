#include <iostream>
using namespace std;

int main() {
	int n, m;
	int arr[100] = { 0 };
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}
	
	for (int q = 0; q < m; q++) {
		int i, j;
		cin >> i >> j;

		int temp_i, temp_j;

		temp_i = arr[i - 1];
		temp_j = arr[j - 1];

		arr[i - 1] = temp_j;
		arr[j - 1] = temp_i;
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}