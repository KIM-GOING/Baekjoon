#include <iostream>
#include <string>
using namespace std;

bool palindrome(string a) {
	for (int i = 0; i < a.length() / 2; i++) {
		if (a[i] != a[a.length() - 1 - i])
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		string num;
		cin >> num;

		if (num == "0")	break;
		if (palindrome(num))
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}