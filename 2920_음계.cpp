#include <iostream>
#include <string>
using namespace std;

int scale[8];
string result[3] = { "ascending", "descending","mixed" };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 8; i++)
		cin >> scale[i];

	int check = 0;

	for (int i = 0; i < 7; i++) {	//ascending
		if (scale[i] + 1 != scale[i + 1]) {
			if (scale[i] == 8 && scale[i + 1] == 1)
				continue;
			check = 1;
			break;
		}
	}

	if (check == 1) {
		for (int i = 0; i < 7; i++) {	//descending
			if (scale[i] - 1 != scale[i + 1]) {
				if (scale[i] == 1 && scale[i + 1] == 8)
					continue;
				check = 2;
				break;
			}
		}
	}

	cout << result[check];

	return 0;
}