#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1001][3];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int r, g, b;
		cin >> r >> g >> b;

		arr[i][0] = r;
		arr[i][1] = g;
		arr[i][2] = b;
	}

	for (int i = 1; i < n; i++) {
		arr[i][0] = min(arr[i - 1][1], arr[i - 1][2]) + arr[i][0];
		arr[i][1] = min(arr[i - 1][0], arr[i - 1][2]) + arr[i][1];
		arr[i][2] = min(arr[i - 1][0], arr[i - 1][1]) + arr[i][2];
	}

	int m = arr[n - 1][0];
	for (int i = 1; i < 3; i++) {
		m = min(m, arr[n - 1][i]);
	}
	cout << m;

	return 0;
}