#include <iostream>
using namespace std;

int n, k;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	int top = 1;
	int bottom = 1;
	int tmp = k;
	for (int i = 0; i < k; i++) {
		top *= n;
		bottom *= tmp;
		n--;
		tmp--;
	}

	cout << top / bottom;

	return 0;
}