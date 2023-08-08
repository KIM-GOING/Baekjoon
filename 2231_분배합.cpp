#include <iostream>
using namespace std;

int n, result;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 1; i < n; i++) {
		int sum = i;
		int l = i;
		int r = 1000000;
		while (r != 0) {
			sum += l / r;
			l = l % r;
			r = r / 10;
		}

		if (sum == n) {
			result = i;
			break;
		}
	}

	cout << result;

	return 0;
}