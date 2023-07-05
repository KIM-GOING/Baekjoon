#include <iostream>
using namespace std;

int arr[9];
int sum, goal, num1, num2;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 9; i++) {
		int num;
		cin >> num;
		arr[i] = num;
		sum += num;
	}

	goal = sum - 100;

	int check = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (arr[i] + arr[j] == goal) {
				num1 = arr[i];
				num2 = arr[j];
				check = 1;
				break;
			}
		}
		if (check == 1)
			break;
	}

	for (int i = 0; i < 9; i++)
		if (arr[i] != num1 && arr[i] != num2)
			cout << arr[i] << '\n';

	return 0;
}