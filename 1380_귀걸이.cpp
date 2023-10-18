#include <iostream>
#include <string>
using namespace std;

bool arr[101];
string names[101];
int scene = 1;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while(1) {
		int girl;
		cin >> girl;

		if (girl == 0)
			break;

		string input;
		getline(cin, input);

		for (int i = 1; i <= girl; i++) {
			getline(cin, names[i]);
			arr[i] = false;
		}

		for (int i = 0; i < 2 * girl - 1; i++) {
			int num;
			cin >> num;
			char alpha;
			cin >> alpha;

			if (arr[num] == true)
				arr[num] = false;
			else
				arr[num] = true;
		}

		for (int i = 1; i <= girl; i++)
			if (arr[i] == true)
				cout << scene << ' ' << names[i] << '\n';

		scene++;
	}

	return 0;
}