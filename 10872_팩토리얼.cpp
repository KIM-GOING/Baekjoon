#include <iostream>
using namespace std;

int n;

int factorial(int num) {
	if (num > 1)
		return num * factorial(num - 1);
	else if (num == 1)
		return num;
	else
		return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	cout << factorial(n);

	return 0;
}