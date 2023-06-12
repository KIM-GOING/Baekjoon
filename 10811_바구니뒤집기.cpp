#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	int arr[100] = { 0 };

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}

	for (int j = 0; j < m; j++) {
		int a, b;
		cin >> a >> b;
		int basket1 = a-1;
		int basket2 = b-1;
		int center = basket2 - basket1;
		
		if (center % 2 == 0) {
			for (int k = 0; k < center / 2; k++) {
				swap(arr[basket1 + k], arr[basket2 - k]);
			}
		}
		else {
			for (int k = 0; k < (center + 1) / 2; k++) {
				swap(arr[basket1 + k], arr[basket2 - k]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}