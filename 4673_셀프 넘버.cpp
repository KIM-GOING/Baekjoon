#include <iostream>
using namespace std;

int d(int n) {
	int num = n;
	int result = n;

	while (num / 10 != 0) {
		int remain = num % 10;
		num = num / 10;
		result += remain;
	}
	result += num % 10;

	return result;
}

int main() {
	const int range = 10000;
	int arr[range] = {0};

	for (int num = 0; num < range; num++) {
		if (d(num+1) > range)
			continue;
		arr[d(num+1) - 1] = 1;
	}

	for (int i = 0; i < range; i++) {
		if(arr[i] == 0)
			cout << i+1 << '\n';
	}

	return 0;
}