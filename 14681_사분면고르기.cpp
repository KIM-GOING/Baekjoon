#include <cstdio>
using namespace std;

int main() {
	int x, y;
	scanf_s("%d", &x);
	scanf_s("%d", &y);

	int space = 0;
	if (x > 0) {
		if (y > 0)
			space = 1;
		else
			space = 4;
	}
	else {
		if (y > 0)
			space = 2;
		else
			space = 3;
	}

	printf("%d", space);

	return 0;
}