#include <iostream>
using namespace std;

int t, n, m;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	for (int u = 0; u < t; u++) {
		long long top = 1, bottom = 1;
		cin >> n >> m;

		int temp = m;
		for (int i = 0; i < n; i++) {
			top *= temp;
			bottom *= i + 1;
			if (top % bottom == 0) {
				top = top / bottom;
				bottom = 1;
			}
			temp--;
		}

		cout << top / bottom << '\n';
	}


	return 0;
}