#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int k = 0; k < t; k++) {
		int x, y;
		cin >> x >> y;
		int distance = y - x;

		int count = 1;
		int sum = distance;
		int min = 0;
		while (sum > 0) {
			for (int i = 0; i < 2; i++) {
				if (sum <= 0)
					break;
				sum = sum - count;
				min++;
			}
			if (sum <= 0)
				break;
			count++;
		}
		cout << min << '\n';
	}

	return 0;
}