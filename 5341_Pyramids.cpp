#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		int base;
		cin >> base;

		if (base == 0)	break;

		int sum = 0;
		for (int i = base; i > 0; i--)
			sum += i;

		cout << sum << '\n';
	}

	return 0;
}