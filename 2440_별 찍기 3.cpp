#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int m = n;
	for (int j = 0; j < n; j++) {
		for (int i = m; i > 0; i--) {
			cout << '*';
		}
		cout << '\n';
		m--;
	}

	return 0;
}