#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	string* arr = new string[n];
	cin.ignore();

	for (int i = 0; i < n; i++) {
		string name;
		getline(cin, name);
		arr[i] = name;
	}

	for (int i = 0; i < n; i++) {
		cout << i + 1 << ". " << arr[i] << '\n';
	}

	delete[] arr;
	return 0;
}