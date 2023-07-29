#include <iostream>
using namespace std;

int t;
long long p[101];

long long tri(long long n) {
	if (n > 3) {
		if (p[n - 2] == 0)
			tri(n - 2);
		if (p[n - 3] == 0)
			tri(n - 3);

		p[n] = p[n - 3] + p[n - 2];
	}

	return p[n];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	p[0] = 0;
	p[1] = 1;
	p[2] = 1;
	p[3] = 1;

	cin >> t;

	for (int i = 0; i < t; i++) {
		int num;
		cin >> num;
		cout << tri(num) << '\n';
	}

	return 0;
}