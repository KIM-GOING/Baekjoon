#include <iostream>
using namespace std;

int main() {
	int n, m;
	int arr[100] = {0};

	cin >> n >> m;

	for (int q = 0; q < m; q++) {
		int i, j, k;
		cin >> i >> j >> k;

		for (int basket = i - 1; basket <= j - 1; basket++) {
			arr[basket] = k;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}