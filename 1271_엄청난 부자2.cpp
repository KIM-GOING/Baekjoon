//½ÇÆÐ

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long double n;
	long double m;
	cin >> n >> m;


	long double a = n / m;
	long double b = n % m;

	cout << a << '\n' << b;

	return 0;
}