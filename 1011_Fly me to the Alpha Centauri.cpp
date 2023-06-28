#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int k = 0; k < t; k++) {
		int x, y;
		cin >> x >> y;
		int distance = y - x;

		int sum = 0;
		int count = 1;
		for (int i = 1; i <= distance; i += 2) {
			for (int j = 1; j <= 2; j++) {
				sum = count;
				count++;
			}
		}
	}

	return 0;
}