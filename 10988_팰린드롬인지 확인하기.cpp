#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;

	int tf = 1;
	if (s.length() % 2 == 0) {
		for (int i = 0; i < s.length() / 2; i++) {
			if (s[i] == s[s.length() - 1 - i])
				continue;
			else {
				tf = 0;
				break;
			}
		}
		cout << tf;
	}
	else {
		for (int i = 0; i < (s.length() - 1) / 2; i++) {
			if (s[i] == s[s.length() - 1 - i])
				continue;
			else {
				tf = 0;
				break;
			}
		}
		cout << tf;
	}

	return 0;
}