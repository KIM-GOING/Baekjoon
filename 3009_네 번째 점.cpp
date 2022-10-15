#include <cstdio>
using namespace std;

int main() {
	int arr[3][2] = {};

	for (int i = 0; i < 3; i++) {
		int x, y;
		scanf_s("%d", &x);
		scanf_s("%d", &y);
		arr[i][0] = x;
		arr[i][1] = y;
	}

	int X, Y;
	if (arr[0][0] == arr[1][0])
		X = arr[2][0];
	else {
		if (arr[0][0] == arr[2][0])
			X = arr[1][0];
		else
			X = arr[0][0];
	}

	if (arr[0][1] == arr[1][1])
		Y = arr[2][1];
	else {
		if (arr[0][1] == arr[2][1])
			Y = arr[1][1];
		else
			Y = arr[0][1];
	}

	printf("%d %d", X, Y);

	return 0;
}