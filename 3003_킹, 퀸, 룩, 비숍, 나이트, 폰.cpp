#include <iostream>
using namespace std;

int main() {
	int CHESS[6] = { 1, 1, 2, 2, 2, 8 };
	int chess[6];
	int role = 0;

	for (int i = 0; i < 6; i++) {
		cin >> role;
		chess[i] = role;
	}

	for (int i = 0; i < 6; i++) {
		if (CHESS[i] == chess[i])
			cout << 0 << " ";
		else
			cout << CHESS[i] - chess[i] << " ";
	}

	return 0;
}