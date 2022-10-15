#include <cstdio>
using namespace std;

int main() {
	int x, y, w, h;
	int arr[4] = { 0 };
	scanf_s("%d", &x);
	scanf_s("%d", &y);
	scanf_s("%d", &w);
	scanf_s("%d", &h);

	arr[0] = x;
	arr[1] = w - x;
	arr[2] = h - y;
	arr[3] = y;

	int min = arr[0];
	for (int i = 0; i < 4; i++) {
		if (min > arr[i])
			min = arr[i];
	}

	printf("%d", min);

	return 0;
}