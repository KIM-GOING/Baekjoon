#include <iostream>
#include <string>
using namespace std;

int main() {
	int testCase;
	string arr[20] = {""};
	cin >> testCase;

	int num = 0;
	for (int i = 0; i < testCase; i++) {
		string s;
		cin >> s;
		arr[num] = s[0];
		arr[num + 1] = s[s.length() - 1];
		num += 2;
	}
	num = 0;

	for (int i = 0; i < testCase; i++) {
		cout << arr[num] << arr[num + 1] << "\n";
		num += 2;
	}

	return 0;
}