#include <iostream>
#include <string>
using namespace std;

int main() {
	string arr[100] = { "" };

	int num = 0;
	while (1) {
		string s;
		getline(cin, s);
		if (s == "")
			break;
		arr[num] = s;
		num++;
	}

	for (int i = 0; i < num; i++) {
		cout << arr[i] << '\n';
	}

	return 0;
}