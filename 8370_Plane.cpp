#include <iostream>
using namespace std;

int n1, n2, k1, k2;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n1 >> k1 >> n2 >> k2;

	cout << (n1 * k1) + (n2 * k2);

	return 0;
}