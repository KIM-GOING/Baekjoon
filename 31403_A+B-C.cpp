#include <iostream>
#include <cmath>
using namespace std;

int a, b, c;
long long num;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b >> c;

	cout << a + b - c << '\n';

	int ten = 1;
	int tempB = b;
	while (tempB / 10 != 0) {
		tempB = tempB / 10;
		ten++;
	}
	
	num = a * pow(10, ten) + b - c;

	cout << num;

	return 0;
}